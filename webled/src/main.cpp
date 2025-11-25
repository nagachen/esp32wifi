#include <Arduino.h>
#include <WebServer.h>

const char *ssid = "Google8aaa";
const char *password = "5161naga";

WebServer server(80);
const byte LED = 2;

void handleRoot()
{
  String HTML ="<a href=\"/on\">開啟LED</a><br>";
  HTML +="<a href=\"/off\">關閉LED</a>";
  server.send(200,"text/html;charset=UTF-8",HTML);
}

void handleNotFound()
{
  server.send(404, "text/plain;charset=UTF-8", "can't find file");
}

void handleLedOn(){
  digitalWrite(LED,HIGH);
}

void handleLedOff(){
  digitalWrite(LED,LOW);

}

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  pinMode(LED, OUTPUT);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFI Connected!!");
  Serial.print("My IP = ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/on",handleLedOn);
  server.on("/off",handleLedOff);

  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("Server is running...");
}

void loop()
{
  server.handleClient();
}
