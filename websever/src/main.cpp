#include <Arduino.h>
#include <WebServer.h>

const char *ssid = "Google8aaa";
const char *password = "5161naga";

WebServer server(80);

void handleRoot(){
  server.send(200,"text/html;charset=UTF-8","Hello new world");
}

void handleNotFound(){
  server.send(404,"text/plain;charset=UTF-8","can't find file");
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid,password);

  while (WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFI Connected!!");
  Serial.print("My IP = ");
  Serial.println(WiFi.localIP());

  server.on("/",handleRoot);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("Server is running...");

}

void loop() {
  server.handleClient();
}

