#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

int LED = 15;
//LED 15'e bağlı
int cnchk = 0;
String postData = "";
String payload;

void setup() {
  Serial.begin(115200);
  pinMode (LED, OUTPUT);//Specify that LED pin is output
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

}

void loop() {
    WiFi.begin("MuhE_Kat1_AP2", "");
    delay(100);
    cnchk = 0;
    Serial.println("Will Try to Connect WiFi...");
    while (WiFi.status() != WL_CONNECTED && cnchk < 10) {
      digitalWrite(LED, HIGH);
      delay(1000);
      Serial.println("Trying to Connect WiFi...");
      cnchk = cnchk + 1;
      digitalWrite(LED, LOW);
      delay(1000);
    }
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("Couldnt Connect to WiFi...");
    }
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("WiFi Connected");
    }

  delay(1000);
  if (WiFi.status() == WL_CONNECTED)
  {
    digitalWrite(LED, HIGH);
    delay(5000);
    digitalWrite(LED, LOW);
    delay(5000);
    postData = "http://vyamacli.com/IoT/iot_mysql_select.php";
    Serial.println(postData);
    WiFiClient client;

    HTTPClient http;
    http.setTimeout(30000);
    Serial.println("Client begin...");

    if (http.begin(client, postData)) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
    
    Serial.println("Client stopped...");
    digitalWrite(LED, LOW);

    if (payload == "id: 5 - Name: Johnx 179 30")
    {
      digitalWrite(LED, HIGH);
      delay(5000);
      digitalWrite(LED, LOW);
      Serial.println("veri doğru");
      
      }
    delay(15000);
  }
}
