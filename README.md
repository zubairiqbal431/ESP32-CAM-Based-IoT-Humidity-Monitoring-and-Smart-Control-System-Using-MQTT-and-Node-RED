\#  Smart IoT Environmental Monitoring and Control System (ESP32 + MQTT Architecture)



\##  Abstract

This project presents a real-time IoT-based environmental monitoring and control system designed using ESP32 microcontroller architecture. The system measures humidity using a DHT22 sensor, processes data locally, and transmits it through MQTT protocol to a cloud-based broker (HiveMQ). The data is visualized using a Node-RED dashboard, enabling real-time monitoring and control.



A rule-based embedded control system is implemented to simulate actuator behavior using an LED (fan simulation) and a buzzer for alarm conditions.



The architecture is designed to be scalable and hardware-independent, allowing implementation on any ESP32-based platform.



\---



\##  System Architecture

This follows a \*\*publish/subscribe IoT architecture\*\*, enabling decoupled and scalable communication between devices and applications.



\---



\##  Role of MQTT Broker (Core System Component)



The MQTT broker acts as the central communication hub of the system.



Instead of direct device-to-device communication, all data flows through the broker.



\### ✔ Functional Role:

\- Receives sensor data from ESP32 (Publisher)

\- Forwards data to subscribed clients (Node-RED, dashboards, apps)

\- Enables multiple consumers simultaneously

\- Maintains asynchronous communication flow



👉This decoupling is essential for scalable IoT systems.



\---



\##  Control Logic



The system uses deterministic threshold-based logic:



\- Humidity < 60% → System OFF  

\- Humidity 60–80% → Fan ON (LED simulation)  

\- Humidity > 80% → Fan ON + Alarm ON  



This logic represents a basic embedded decision-making system for environmental automation.



\---



\##  Why MQTT is Used Instead of HTTP 



The choice of MQTT over HTTP is based on \*\*protocol architecture compatibility for IoT systems\*\*, not only bandwidth efficiency.



\###  HTTP Limitations in IoT Systems

HTTP is designed for web communication, not continuous sensor streaming. It introduces the following constraints:



\- Each transmission requires a full request–response cycle  

\- Repeated TCP session overhead for frequent updates  

\- Large header overhead per message (\~300–1000 bytes per request)  

\- Inefficient for real-time telemetry systems  

\- Requires polling or repeated requests for updates  



This makes HTTP unsuitable for embedded systems with continuous data flow requirements.



\---



\###  MQTT Advantages



MQTT is specifically designed for IoT and embedded systems:



\- Lightweight publish/subscribe model  

\- Persistent connection (no repeated handshakes)  

\- Minimal message overhead (\~20–50 bytes per message)  

\- Real-time asynchronous communication  

\- Supports multiple subscribers simultaneously  



In continuous sensor streaming scenarios, MQTT can reduce network load by up to 80–90% compared to HTTP-based polling systems.



\---



\##  MQTT Broker vs HTTP Server (Core Concept Difference)



| Feature | MQTT Broker | HTTP Server |

|--------|------------|-------------|

| Communication Model | Publish/Subscribe | Request/Response |

| Device Coupling | Decoupled | Direct coupling |

| Scalability | High | Limited in IoT streaming |

| Real-time Support | Excellent | Limited |

| Efficiency for sensors | Very High | Low |



&#x20;Therefore, MQTT is structurally more compatible with IoT sensor networks.



\---



\##  Current Implementation Note



In the current prototype:

\- LED is used as a \*\*simulation of a fan actuator\*\*

\- Buzzer is used for alarm indication



This abstraction ensures safe testing of embedded control logic before integrating physical actuators such as DC fans or relay modules.




\---



\##  System Deployment Scope



\### Current Mode:

\- Local WiFi-based communication

\- ESP32 publishes data to MQTT broker

\- Node-RED dashboard visualizes real-time sensor values



\### Future Expansion:

This system is designed for scalability toward advanced IoT systems:



\-  Global access using cloud MQTT brokers or tunneling (Ngrok)

\-  ESP32-CAM integration for environmental image capture

\-  Cloud database logging (AWS IoT / Firebase)

\-  Mobile application for remote monitoring

\-  AI-based environmental prediction system



\---



\##  Hardware Used

\- ESP32-CAM

\- DHT22 Humidity Sensor

\- LED (Fan simulation)

\- Buzzer (Alarm system)

\- External power supply



\---



\## 💻 Software Stack

\- Embedded C++ (Arduino Framework)

\- MQTT Protocol (HiveMQ Broker)

\- Node-RED Dashboard

\- IoT Publish/Subscribe Architecture



\---
\##[ Watch demo vedio](https://drive.google.com/drive/folders/1aTgCIu-RdU1NHLs0ZZ09jbVFBXD9Cp9O)



\##  Author



Zubair Iqbal  

Bachelor of Science in Electronics  

Government College University, Lahore, Pakistan  



📧 Email: izubair431@gmail.com  

🔗 LinkedIn:www.linkedin.com/in/zubair-iqbal-03a9a1333 



\---



\##  Conclusion

This project demonstrates a complete IoT embedded system integrating real-time sensing, MQTT-based communication, and automated decision-making. The architecture follows a scalable publish/subscribe model, making it suitable for extension into industrial monitoring systems, smart agriculture, and vision-enabled IoT applications using ESP32-CAM.

