// Definisikan pin tempat LED onboard terhubung
// Untuk Arduino Nano ESP32, LED_BUILTIN sudah didefinisikan ke pin LED onboard.
const int ledPin = 23;
const int ledPin2 = 22;

void setup() {
  // Fungsi setup() hanya berjalan sekali saat board pertama kali menyala atau di-reset

  // Mengatur pin LED sebagai OUTPUT.
  // Ini memberitahu ESP32 bahwa kita akan mengirim sinyal ke pin ini
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // Fungsi loop() berjalan berulang-ulang tanpa henti setelah setup() selesai
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin2, LOW);     // Mematikan LED
  delay(1000);                   // Menunggu selama 1000 milidetik (1 detik)

  digitalWrite(ledPin, LOW);     // Mematikan LED
  digitalWrite(ledPin2, HIGH);     // Mematikan LED
  delay(1000);                   // Menunggu selama 1000 milidetik (1 detik)
}