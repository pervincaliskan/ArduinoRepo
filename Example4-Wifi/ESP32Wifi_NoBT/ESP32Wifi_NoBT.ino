#include <WiFi.h>
#include <HTTPClient.h>

int LED = 15; 

//HTTP Variables
String postData = "";
String t = "temp=";

//WiFi Input Variables
String ssid = "Mersin Universitesi"; // wifi ssid
String password = ""; // wifi password

void setup() {
  Serial.begin(115200);
  pinMode (LED, OUTPUT);//Specify that LED pin is output
  digitalWrite(LED, HIGH);
  delay(2000);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  delay(100);
  digitalWrite(LED, LOW);
}

void loop() {
  int wifi_connect = 0;
  int temp_err = 0;
  
  if (WiFi.status() != WL_CONNECTED)
  {
  WiFi.begin("Mersin Universitesi", "");
    while (WiFi.status() != WL_CONNECTED) {
      delay(5000);
      Serial.println("Trying to Connect WiFi...");
      wifi_connect = wifi_connect + 1;
      if (wifi_connect == 10)
      {
        ESP.restart();
        }
    }
  }
    
  //delay(1000);
  if (WiFi.status() == WL_CONNECTED)
  {
    digitalWrite(LED, HIGH);
    delay(2000);
    digitalWrite(LED, LOW);
    delay(10000);

    postData = "https://www.vyamacli.com/IoT/iot_three.php";
    Serial.println(postData);

    HTTPClient http;
    Serial.println("Client begin...");
    http.begin(postData);             //Specify request destination
    http.setConnectTimeout(30000);
    http.setTimeout(30000);
    
    int httpCode = http.GET();
    String payload = http.getString();    //Get the response payload
    Serial.println(httpCode);
    Serial.print("Gelen Data: ");
    Serial.println(payload);
    Serial.println("Client stopped...");
    Serial.println("-----------------------");
    digitalWrite(LED, LOW);
    if(temp_err == 1){ESP.restart();}
    delay(10000);
  }
}
