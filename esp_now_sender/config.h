#pragma once

// REPLACE WITH YOUR RECEIVER MAC Address
uint8_t receiverAddress[] = {0xE8, 0x6B, 0xEA, 0xF4, 0xC4, 0xD8};

uint8_t channel;
int8_t resetwifi_Button = 22;
String SSID = "An_D";
String PASSWORD = "2764fundy";
String AP_SSID = "Esp32_Receiver";
String AP_PASSWORD = "87654321";

// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
  char a[32];
  int b;
  float c;
  bool d;
} struct_message;