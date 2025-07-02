#include <WiFi.h>          
#include <WebServer.h>     
#include <DHT.h>           

const char* ssid_ap = "UMI Connect"; 
const char* password_ap = "umiukhuwah"; 

const int LED_LIVING_ROOM_PIN = 2; 
const int DHT_PIN = 4;             
#define DHTTYPE DHT11              

DHT dht(DHT_PIN, DHTTYPE); 

WebServer server(80); 

bool lampLivingRoomState = false; 

void handleRoot() {
  String html = "<html><head><title>ESP32 Smart Home API</title></head><body>";
  html += "<h1>Welcome to ESP32 Smart Home API!</h1>";
  html += "<p>Use the following endpoints:</p>";
  html += "<ul>";
  html += "<li><code>/api/light/livingroom?state=on/off</code> (GET) - Control Living Room Light</li>";
  html += "<li><code>/api/sensors</code> (GET) - Get Temperature and Humidity</li>";
  html += "</ul>";
  html += "<p>Current Living Room Light State: " + String(lampLivingRoomState ? "ON" : "OFF") + "</p>";
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    html += "<p>DHT Sensor: Failed to read!</p>";
  } else {
    html += "<p>Temperature: " + String(t) + " &deg;C</p>";
    html += "<p>Humidity: " + String(h) + " %</p>";
  }
  
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleLivingRoomLight() {
  String responseMessage = "";
  if (server.hasArg("state")) { 
    String state = server.arg("state");
    state.toLowerCase(); 

    if (state == "on") {
      digitalWrite(LED_LIVING_ROOM_PIN, HIGH);
      lampLivingRoomState = true;
      responseMessage = "Lampu Ruang Tamu berhasil dinyalakan.";
    } else if (state == "off") {
      digitalWrite(LED_LIVING_ROOM_PIN, LOW);
      lampLivingRoomState = false;
      responseMessage = "Lampu Ruang Tamu berhasil dimatikan.";
    } else {
      responseMessage = "Nilai 'state' tidak valid. Gunakan 'on' atau 'off'.";
      server.send(400, "application/json", "{\"status\":\"error\", \"message\":\"" + responseMessage + "\"}");
      return; 
    }
    
    server.send(200, "application/json", "{\"status\":\"success\", \"message\":\"" + responseMessage + "\", \"device\":\"livingRoom\", \"state\":" + (lampLivingRoomState ? "true" : "false") + "}");
  } else {
    responseMessage = "Parameter 'state' tidak ditemukan. Contoh: /api/light/livingroom?state=on";
    server.send(400, "application/json", "{\"status\":\"error\", \"message\":\"" + responseMessage + "\"}");
  }
}

void handleSensorData() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  String jsonResponse = "{";
  if (isnan(h) || isnan(t)) {
    jsonResponse += "\"status\":\"error\", \"message\":\"Failed to read from DHT sensor!\"";
    Serial.println("Failed to read from DHT sensor!");
  } else {
    jsonResponse += "\"status\":\"success\", ";
    jsonResponse += "\"temperature\":" + String(t) + ", ";
    jsonResponse += "\"humidity\":" + String(h);
    Serial.print("Temperature: "); Serial.print(t); Serial.print("°C ");
    Serial.print("Humidity: "); Serial.print(h); Serial.println("%");
  }
  jsonResponse += "}";
  
  
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", jsonResponse);
}


void setup() {
  Serial.begin(115200);
  delay(100);

  pinMode(LED_LIVING_ROOM_PIN, OUTPUT);
  digitalWrite(LED_LIVING_ROOM_PIN, LOW); 

  dht.begin(); 

  Serial.print("Setting up ESP32 as Access Point: ");
  Serial.println(ssid_ap);

  WiFi.softAP(ssid_ap, password_ap); 
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Access Point IP address: ");
  Serial.println(IP);
  
  server.on("/", HTTP_GET, handleRoot); 
  server.on("/api/light/livingroom", HTTP_GET, handleLivingRoomLight); 
  server.on("/api/sensors", HTTP_GET, handleSensorData); 

  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Headers", "Content-Type");

  server.onNotFound([](){
    if (server.method() == HTTP_OPTIONS) {
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.sendHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
      server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
      server.send(204); 
    } else {
      server.send(404, "text/plain", "Not Found");
    }
  });

  server.begin(); 
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient(); 
}