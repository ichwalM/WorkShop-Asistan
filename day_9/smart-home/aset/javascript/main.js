// Status perangkat
let deviceStates = {
    livingRoom: false,
    bedroom: false,
    kitchen: false,
    fanLiving: false,
    fanBedroom: false,
    alarm: false,
    garage: false
};

// Fungsi toggle perangkat
function toggleDevice(device) {
    deviceStates[device] = !deviceStates[device];
    const toggle = event.currentTarget;
    const statusElement = document.getElementById(device + 'Status');

    if (deviceStates[device]) {
        toggle.classList.add('active');
        statusElement.textContent = getOnText(device);
        statusElement.className = 'device-status status-on';
    } else {
        toggle.classList.remove('active');
        statusElement.textContent = getOffText(device);
        statusElement.className = 'device-status status-off';
    }

    // Simulasi mengirim command ke Arduino
    sendToArduino(device, deviceStates[device]);
}

function getOnText(device) {
    switch (device) {
        case 'alarm': return 'Aktif';
        default: return 'Nyala';
    }
}

function getOffText(device) {
    switch (device) {
        case 'alarm': return 'Nonaktif';
        default: return 'Mati';
    }
}

// Kontrol semua lampu
function turnAllLights(action) {
    const lights = ['livingRoom', 'bedroom', 'kitchen'];
    const isOn = action === 'on';

    lights.forEach(light => {
        deviceStates[light] = isOn;
        const toggle = document.querySelector(`[onclick="toggleDevice('${light}')"]`);
        const statusElement = document.getElementById(light + 'Status');

        if (isOn) {
            toggle.classList.add('active');
            statusElement.textContent = 'Nyala';
            statusElement.className = 'device-status status-on';
        } else {
            toggle.classList.remove('active');
            statusElement.textContent = 'Mati';
            statusElement.className = 'device-status status-off';
        }
    });

    sendToArduino('allLights', isOn);
}

// Kontrol pintu garasi
function controlGarage(action) {
    deviceStates.garage = action === 'open';
    const statusElement = document.getElementById('doorStatus');

    if (action === 'open') {
        statusElement.textContent = 'Terbuka';
        statusElement.className = 'device-status status-on';
    } else {
        statusElement.textContent = 'Tertutup';
        statusElement.className = 'device-status status-off';
    }

    sendToArduino('garage', action);
}

// Mode darurat
function emergencyMode() {
    alert('Mode darurat diaktifkan! Semua lampu nyala, alarm aktif.');
    turnAllLights('on');

    // Aktifkan alarm
    deviceStates.alarm = true;
    const alarmToggle = document.querySelector(`[onclick="toggleDevice('alarm')"]`);
    const alarmStatus = document.getElementById('alarmStatus');
    alarmToggle.classList.add('active');
    alarmStatus.textContent = 'Aktif';
    alarmStatus.className = 'device-status status-on';

    sendToArduino('emergency', true);
}

// Simulasi komunikasi dengan Arduino
function sendToArduino(device, state) {
    console.log(`Mengirim ke Arduino: ${device} = ${state}`);

    // Di sini Anda bisa menambahkan kode untuk:
    // 1. Mengirim HTTP request ke ESP32/Arduino dengan WiFi
    // 2. Menggunakan WebSocket untuk komunikasi real-time
    // 3. Menggunakan MQTT broker

    // Contoh dengan fetch API:
    /*
    fetch('/api/control', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify({
            device: device,
            state: state,
            timestamp: new Date().toISOString()
        })
    })
    .then(response => response.json())
    .then(data => {
        console.log('Arduino response:', data);
    })
    .catch(error => {
        console.error('Error:', error);
        updateConnectionStatus(false);
    });
    */
}

// Update status koneksi
function updateConnectionStatus(connected) {
    const status = document.getElementById('connectionStatus');
    const indicator = document.querySelector('.connection-indicator');

    if (connected) {
        status.textContent = 'Terhubung ke Arduino';
        indicator.style.background = '#4ade80';
    } else {
        status.textContent = 'Koneksi terputus';
        indicator.style.background = '#f87171';
    }
}

// Simulasi data sensor
function updateSensorData() {
    // Update suhu
    const temp = Math.floor(Math.random() * 15) + 20; // 20-35°C
    document.getElementById('temperature').textContent = temp;
    document.getElementById('tempProgress').style.width = `${(temp - 15) * 2}%`;

    let tempCondition = 'Normal';
    if (temp > 30) tempCondition = 'Panas';
    else if (temp < 22) tempCondition = 'Dingin';
    document.getElementById('tempCondition').textContent = tempCondition;

    // Update kelembaban
    const humidity = Math.floor(Math.random() * 40) + 40; // 40-80%
    document.getElementById('humidity').textContent = humidity;
    document.getElementById('humidityProgress').style.width = `${humidity}%`;

    let humidityCondition = 'Ideal';
    if (humidity > 70) humidityCondition = 'Lembab';
    else if (humidity < 50) humidityCondition = 'Kering';
    document.getElementById('humidityCondition').textContent = humidityCondition;
}

// Update data sensor setiap 5 detik
setInterval(updateSensorData, 5000);

// Simulasi koneksi
setTimeout(() => updateConnectionStatus(true), 1000);