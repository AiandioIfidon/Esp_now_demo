#ifndef WIFI_CONNECT

void wifiConnect(String ssid, String password, String ap_ssid, String ap_password){
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    if (digitalRead(Bluetooth_Button) == HIGH){
    return;
    };
    delay(3000);
    Serial.println("Connecting to ");
    Serial.println(ssid);
  }

  Serial.println("Successfully connected to ");
  Serial.println(ssid);
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Wifi Channel: ");
  Serial.println(WiFi.channel());
  int channel = WiFi.channel();
  WiFi.softAP(ap_ssid, ap_password, channel, 0);
  Serial.println("SoftAP Started!");
  Serial.print("SoftAP IP Address: ");
  Serial.println(WiFi.softAPIP());

}

#endif