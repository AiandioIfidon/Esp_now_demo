#ifndef WIFI_CONNECT

void wifiConnect(String ssid, String password){

  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED)
  {
    if (digitalRead(resetwifi_Button) == HIGH){
    return;
    };
    delay(3000);
    Serial.println("Connecting to ");
    Serial.println(ssid);
  }

  Serial.println("Successfully connected to ");
  Serial.println(ssid);
  channel = WiFi.channel(); // checks for the channel of the wifi network
  Serial.print("Channel for esp now: ");
  Serial.println(channel);

  WiFi.disconnect();
  while (WiFi.status() != WL_DISCONNECTED){
  if (digitalRead(resetwifi_Button) == HIGH){
  return;
  };
  delay(1000);
  Serial.println("Disconnecting from  ");
  Serial.println(ssid);
  }



}

#endif