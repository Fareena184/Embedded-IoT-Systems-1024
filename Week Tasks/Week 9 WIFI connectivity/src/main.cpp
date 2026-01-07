/*
   ESP32 Webserver + Static IP + LED Control
*/

#include <WiFi.h>

// ----- WiFi Credentials -----
const char* ssid     = "Fs";
const char* password = "112233fs";

// ----- Static IP Configuration -----
IPAddress local_IP(10, 177, 113, 80);     // ESP32 Static IP
IPAddress gateway(10, 106, 15, 1);       // Gateway (router IP)
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);        // Optional
IPAddress secondaryDNS(8, 8, 4, 4);      // Optional

// ----- Web Server -----
WiFiServer server(80);

// Built-in LED (GPIO 2)
const int LED_PIN = 2;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // ----- Configure Static IP -----
  Serial.println("Setting Static IP...");
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STATIC IP FAILED!");
  } else {
    Serial.print("Static IP set: ");
    Serial.println(local_IP);
  }

  // ----- Connect to WiFi -----
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n WiFi Connected!");
  Serial.print("ESP32 IP: ");
  Serial.println(WiFi.localIP());

  // Start web server
  server.begin();
  Serial.println("Web server started!");
}

void loop() {

  WiFiClient client = server.available();
  if (!client) return;   // No client → exit

  Serial.println("\nNew Client Connected");

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // ----- LED Control -----
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED → ON");
  }
  if (request.indexOf("/LED=OFF") != -1) {
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED → OFF");
  }

  // ----- HTML Webpage -----
  String htmlPage =
    "<!DOCTYPE html><html><body>"
    "<h1>ESP32 LED Control</h1>"
    "<p><a href=\"/LED=ON\"><button style='font-size:20px;'>TURN ON</button></a></p>"
    "<p><a href=\"/LED=OFF\"><button style='font-size:20px;'>TURN OFF</button></a></p>"
    "</body></html>";

  // ----- Send HTTP Response -----
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();
  client.println(htmlPage);

  delay(1);
  client.stop();
  Serial.println("Client Disconnected");
}
