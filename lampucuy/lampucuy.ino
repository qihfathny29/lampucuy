// Pin LED
const int espLed = 2;   // LED onboard ESP32
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 19;
const int ledPin4 = 23;

bool dapurLedState = false;
bool tamuLedState = false;
bool makanLedState = false;
bool toiletLedState = false;

#include <WiFi.h>
#include <WebServer.h>

WebServer server(80); // Gunakan port 80

// WiFi credentials
const char* ssid = "Hotspot_SMKN40";
const char* password = "jayaraya40";

void setup() {
  // Inisialisasi Serial Monitor
  Serial.begin(115200);

  // Konfigurasi pin sebagai OUTPUT
  pinMode(espLed, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  // Matikan semua LED awalnya
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);

  // Koneksi WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);

  // Indikator LED selama mencoba terhubung ke WiFi
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(espLed, LOW);  // LED mati
    delay(500);
    digitalWrite(espLed, HIGH); // LED nyala
    delay(500);
  }

  // Setelah terhubung, LED tetap menyala
  digitalWrite(espLed, HIGH);
  Serial.println("");
  Serial.println("Connected to WiFi network:");
  Serial.println(WiFi.localIP()); // Tampilkan alamat IP lokal

  // Routing server
  server.on("/dapur", HTTP_GET, getDapurLed);
  server.on("/tamu", HTTP_GET, getTamuLed);
  server.on("/makan", HTTP_GET, getMakanLed);
  server.on("/toilet", HTTP_GET, getToiletLed);

  server.on("/dapur", HTTP_POST, setDapurLed);
  server.on("/tamu", HTTP_POST, setTamuLed);
  server.on("/makan", HTTP_POST, setMakanLed);
  server.on("/toilet", HTTP_POST, setToiletLed);

  server.begin();
  Serial.println("Server started...");
}

void loop() {
  server.handleClient(); // Perbaiki typo: handleClient()
}

void setDapurLed() {
  dapurLedState = !dapurLedState;
  digitalWrite(ledPin1, dapurLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", dapurLedState ? "ON" : "OFF");
}

void setTamuLed() {
  tamuLedState = !tamuLedState;
  digitalWrite(ledPin2, tamuLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", tamuLedState ? "ON" : "OFF");
}

void setMakanLed() {
  makanLedState = !makanLedState;
  digitalWrite(ledPin3, makanLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", makanLedState ? "ON" : "OFF");
}
void setToiletLed() {
  toiletLedState = !toiletLedState;
  digitalWrite(ledPin4, toiletLedState ? HIGH : LOW); // Gunakan ledPin4 untuk toilet
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", toiletLedState ? "ON" : "OFF");
}

void getDapurLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", dapurLedState ? "ON" : "OFF");
}

void getTamuLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", tamuLedState ? "ON" : "OFF");
}

void getMakanLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", makanLedState ? "ON" : "OFF");
}
void getToiletLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", toiletLedState ? "ON" : "OFF");
}