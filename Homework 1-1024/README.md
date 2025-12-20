# ESP32 Webserver & Blynk Cloud Folder

## Purpose
This folder demonstrates how to use an **ESP32 microcontroller** for real-time **temperature and humidity monitoring** and cloud interfacing using **Blynk Cloud**. It includes both **webserver-based local monitoring** and **cloud-based remote monitoring**.

## ESP32 Webserver Explanation
- **WebServer server(80);**  
  Creates a web server on the ESP32 listening on **port 80**, the default for HTTP. This allows access to the web page using only the ESP32 IP address.

- **server.on("/", handleRoot);**  
  Defines a route for the root URL. When accessed in a browser, the `handleRoot()` function runs, sending the HTML page with sensor data.

- **server.handleClient();**  
  Placed inside `loop()` to continuously check for client requests. Without it, the ESP32 would stop responding to web requests.

- **server.send(200, "text/html", html);**  
  Sends the HTML web page to the browser. `200` indicates success, `"text/html"` specifies the content type, and `html` contains the page content.

- **Sensor Reading Strategy**  
  - Displaying **last measured values**: fast, reliable, avoids frequent sensor reads.  
  - Taking a **fresh reading** in `handleRoot()`: slower, may cause errors if read too often.

- **Button-Based Sensor Update**  
  Pressing a physical button triggers a new sensor reading and updates the **OLED display**.

- **Meta Refresh Tag**  
  Automatically refreshes the web page at a fixed interval to show updated sensor values.

- **Common Issues & Solutions**  
  - Wi-Fi connection failure → verify SSID/password.  
  - Web page not loading → ensure server is started and `handleClient()` is called.  
  - Slow/frequent sensor reads → store values instead of reading every request.  
  - Dynamic IP changes → use static IP.  
  - Button bounce → implement debounce delay.

## Blynk Cloud Interfacing Explanation
- **Template ID**  
  Identifies the Blynk Cloud template. Must match the cloud template to display data correctly.

- **Auth Token**  
  Authenticates a specific device to the Blynk Cloud.

- **Virtual Pins**  
  Software-defined pins (e.g., V0, V1) used to send and receive data. Preferred over physical pins for cloud communication.

- **BlynkTimer**  
  Allows timed tasks without blocking the main program, unlike `delay()`.

- **Workflow**  
  1. Create a **Blynk Template** with virtual pins for temperature and humidity.  
  2. Connect ESP32 using **Template ID** and **Auth Token**.  
  3. Read sensor values and send them using `Blynk.virtualWrite()`.  
  4. Display real-time sensor data on the Blynk dashboard.

- **Common Issues & Solutions**  
  - Wi-Fi failures → check credentials.  
  - Incorrect Template ID/Auth Token → verify cloud template.  
  - Wrong virtual pin mapping → ensure proper assignment.  
  - Sensor misconfiguration → match sensor type in code.

## Conclusion
This folder provides **local monitoring via ESP32 webserver** and **remote monitoring via Blynk Cloud**. Proper handling of **sensor readings, web requests, virtual pins, and timers** ensures reliable real-time temperature and humidity monitoring.
