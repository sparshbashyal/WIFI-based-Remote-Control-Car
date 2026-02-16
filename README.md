# WIFI-based-Remote-Control-Car
This project transforms a Wemos D1 Mini (ESP8266) into a high-performance, mobile-responsive RC car controller. Unlike standard web-controlled projects that require constant page refreshes, this implementation uses JavaScript (AJAX/Fetch API) and CSS Grid to create a professional, low-latency D-Pad interface.

📌 Project Overview

This project demonstrates how to:

Host a web server on ESP8266

Serve HTML, CSS, and JavaScript directly from microcontroller

Control DC motors using GPIO pins

Implement PWM speed control

Send real-time commands via HTTP GET request

The system allows directional control:

Forward

Backward

Left

Right

Stop (automatic when button released)

🎮 Features

✅ Wi-Fi based control

✅ ESP8266 Web Server (Port 80)

✅ Mobile-friendly D-Pad interface

✅ Real-time control using AJAX requests

✅ PWM motor speed control

✅ Automatic stop on button release

✅ Touch and mouse support

🧠 How It Works

ESP8266 connects to a Wi-Fi network.

A web server runs on port 80.

User opens ESP8266 IP address in browser.

A D-Pad control webpage loads.

When a button is pressed:

JavaScript sends HTTP GET request like /front

ESP8266 reads the request and calls rotatemotor()

Motor driver receives direction + PWM signals.

-Motor Logic

| Function | Right Motor | Left Motor |
| -------- | ----------- | ---------- |
| Forward  | +Speed      | +Speed     |
| Backward | -Speed      | -Speed     |
| Left     | +Speed      | -Speed     |
| Right    | -Speed      | +Speed     |
| Stop     | 0           | 0          |

🌐 Web Interface

The interface includes:

Grid-based D-Pad layout

CSS styled buttons

JavaScript AJAX background requests

onmousedown and ontouchstart for movement

onmouseup and ontouchend for stop

🔩 Hardware Components

ESP8266 D1 Mini

L298N / L293D Motor Driver

2 DC Motors

RC Car Chassis

Battery Pack

Jumper Wires

⚙️ Setup Instructions
1️⃣ Install Arduino IDE

Download from: https://www.arduino.cc

2️⃣ Add ESP8266 Board Support

Go to Preferences

Add ESP8266 Board Manager URL

Install ESP8266 package

3️⃣ Select Board

Tools → Board → LOLIN (Wemos) D1 Mini

4️⃣ Upload Code

Update Wi-Fi credentials:

Upload to ESP8266

5️⃣ Run

Open Serial Monitor

Note the IP address

Enter IP in browser

Start controlling 🚗

📊 System Flow

Power ON

Connect to Wi-Fi

Start Web Server

Wait for client request

Decode HTTP command

Rotate motors accordingly

Repeat loop

📚 Learning Outcomes

ESP8266 Wi-Fi programming

Embedded web server implementation

GPIO motor control

PWM speed control

Real-time web-based control

Hardware–software integration


🔮 Future Improvements

Speed slider control

Obstacle detection sensor

Camera streaming

Password-protected access

Autonomous driving mode

Battery voltage monitoring

👨‍💻 Author

Sprash Bashyal

Electronics & Communication Engineering

Interest Areas: Embedded Systems | Robotics | IoT

📜 License

This project is developed for educational and learning purposes.
Feel free to modify and improve.

⭐ If you like this project, consider starring the repository!
