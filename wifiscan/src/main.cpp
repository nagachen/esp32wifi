#include <Arduino.h>
#include <WiFi.h>

const char *ssid = "Google8aaa";
const char *passwdord = "5161naga";

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, passwdord);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi_Connected");
  Serial.print("My IP=");
  Serial.println(WiFi.localIP());

  Serial.print("Submask=");
  Serial.println(WiFi.subnetMask());
  {
    /* code */
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
}
