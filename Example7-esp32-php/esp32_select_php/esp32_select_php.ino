#include <WiFi.h>
#include <HTTPClient.h>

int LED = 15;
//LED 15'e bağlı
int cnchk = 0;
String postData = "";

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
    WiFi.begin("Mersin Universitesi", "");
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
    postData = "https://vyamacli.com/IoT/iot_mysql_select.php";
    Serial.println(postData);

    HTTPClient http;
    Serial.println("Client begin...");
    http.begin(postData);             //Specify request destination
    http.setConnectTimeout(30000);
    http.setTimeout(30000);

    int httpCode = http.GET();
    String payload = http.getString();    //Get the response payload
    Serial.println(httpCode);
    Serial.println(payload);
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
