#include <esp_now.h>
#include <WiFi.h>

// Struct example to receive data
// Must match the sender structure
typedef struct struct_message {
  bool a;
  bool b;
  bool c;
  bool d;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Up: ");
  Serial.println(myData.a);
  Serial.print("Down: ");
  Serial.println(myData.b);
  Serial.print("Left: ");
  Serial.println(myData.c);
  Serial.print("Right: ");
  Serial.println(myData.d);
  Serial.println();
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(112500);
  WiFi.begin();
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  WiFi.channel(6); // Set channel to 6. Must match on the receiver side
  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));
}
 
void loop() {

}