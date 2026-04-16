# Smart IoT Environmental Monitoring and Control System (ESP32 + MQTT Architecture)

## Abstract

This project presents a real-time IoT-based environmental monitoring and control system using an ESP32 microcontroller. Humidity is measured via a DHT22 sensor and transmitted using MQTT to a HiveMQ broker. A Node-RED dashboard enables real-time monitoring and control.

A rule-based control system simulates actuators using an LED (fan) and buzzer (alarm). The design is scalable and hardware-independent.

---

## System Architecture

The system follows a **publish/subscribe IoT architecture**, enabling scalable and decoupled communication between devices.

---

## MQTT Broker Role

The MQTT broker acts as the central communication hub:

- Receives data from ESP32 (Publisher)  
- Sends data to Node-RED and clients (Subscribers)  
- Enables multiple users simultaneously  
- Maintains asynchronous communication  

---

## Control Logic

- Humidity < 60% → System OFF  
- Humidity 60–80% → Fan ON (LED)  
- Humidity > 80% → Fan ON + Alarm  

---

## Why MQTT Instead of HTTP

### HTTP Limitations

- Request–response overhead  
- Large headers  
- Not suitable for real-time streaming  
- Requires polling  

### MQTT Advantages

- Lightweight protocol  
- Persistent connection  
- Low data overhead  
- Real-time communication  
- Multi-client support  

---

## MQTT vs HTTP

| Feature        | MQTT                  | HTTP                |
|---------------|----------------------|---------------------|
| Model         | Publish/Subscribe    | Request/Response    |
| Coupling      | Decoupled            | Direct              |
| Scalability   | High                 | Limited             |
| Real-time     | Excellent            | Limited             |
| Efficiency    | High                 | Low                 |

---

## Current Implementation

- LED → Fan simulation  
- Buzzer → Alarm indication  

---

## Deployment Scope

### Current

- Local WiFi system  
- MQTT communication  
- Node-RED dashboard  

### Future Work

- Cloud integration  
- ESP32-CAM video monitoring  
- Mobile application  
- AI-based prediction system  

---

## Hardware

- ESP32-CAM  
- DHT22 Sensor  
- LED  
- Buzzer  

---

## Software

- Arduino (C++)  
- MQTT (HiveMQ)  
- Node-RED  

---

## Demo Video

*(Add your video link here)*

---

## Conclusion

This project demonstrates a complete IoT system integrating sensing, MQTT communication, and automated control. Its scalable architecture makes it suitable for smart homes, agriculture, and industrial monitoring.

---

## Author

**Zubair Iqbal**  
BS Electronics  
Government College University, Lahore  

📧 izubair431@gmail.com  
🔗 LinkedIn: https://www.linkedin.com/in/zubair-iqbal-03a9a1333
