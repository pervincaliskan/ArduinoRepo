#include <WiFi.h>
#include <HTTPClient.h>

//const char* ssid     = "Hasan";
//const char* password = "hasan0944";

int r=23;
int g=22;
int b=21;
int u=1;
String r1;
String g1;
String b1;
String d;
int cnchk = 0;
String postData = "";

void setup() {
  Serial.begin(115200);
  pinMode (r, OUTPUT);
  pinMode (g,OUTPUT );
  pinMode (b, OUTPUT );


  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  
  WiFi.begin("deniztelefon", "robotics");

  
}

void loop() {
    delay(100);
    cnchk = 0;
    Serial.println("Will Try to Connect WiFi...");
    while (WiFi.status() != WL_CONNECTED && cnchk < 10) {
      Serial.println("Trying to Connect WiFi...");
      cnchk = cnchk + 1;
      
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
    digitalWrite(r, HIGH);
    delay(5000);
    digitalWrite(r, LOW);
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
    //digitalWrite(r, LOW);

    if (payload == "id: 5 - Name: Johnx 179 30<br>")
    {
      u=payload.length();
      
      r1=payload.substring(0,1);
      g1=payload.substring(1,2);
      b1=payload.substring(2,3);
      d=payload.substring(3,u);   
  }
  Serial.println(r1);
  Serial.println(g1);
  Serial.println(b1);
  Serial.println(d);
}
 }
