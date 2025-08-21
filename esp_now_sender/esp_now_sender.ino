#include <esp_now.h>
#include <WiFi.h>

// REPLACE WITH YOUR RECEIVER MAC Address.
uint8_t broadcastAddress[] = {0x8C, 0x4F, 0x00, 0x3D, 0x30, 0x94};

// Struct to send data
// Must match the receiver structure
typedef struct struct_message {
  bool a;
  bool b;
  bool c;
  bool d;
} struct_message;

// create instance of struct_message used for sending
struct_message myData;

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
 
void setup() {
  Serial.begin(112500);
  WiFi.begin();
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  WiFi.channel(6);
  // Callback function when the data is sent
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer(the receiver esp32)
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}
 
void loop() {
  // Set values to send. This can be changed but larger messages takes more time with weak antenna.
  myData.a = true;
  myData.b = false;
  myData.c = true;
  myData.d = false;
  
  // Send message via ESP-NOW
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
  delay(50);
}