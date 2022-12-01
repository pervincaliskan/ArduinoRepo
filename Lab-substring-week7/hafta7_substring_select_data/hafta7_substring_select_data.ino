#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
int lcdRows=16;
int lcdColumns=2;
LiquidCrystal_I2C lcd(0x27,16,2);
//const char* ssid     = "Hasan";
//const char* password = "hasan0944";


String r1= "";
String g1= "";
String b1= "";
String d= "";
int cnchk = 0;
String postData = "";
int u;
void setup() {
  WiFi.disconnect();
  Wire.begin();
  Serial.begin(115200);
  lcd.init();                     
  
  lcd.backlight();
  Serial.println("\nI2C Scanner");
  
  WiFi.mode(WIFI_STA);
  
  WiFi.begin("iPhone", "anasmezar");

  
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
    
    postData = "https://vyamacli.com/IoT/select_data_lab.php?grup=22";
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
    

    if (payload == "010ESP32 ile denemeler")
    {
      u=payload.length();
      
      r1=payload.substring(0,8);
      g1=payload.substring(9,12);
      b1=payload.substring(13,u);
        
  }
  lcd.setCursor(0,0);
  lcd.print(r1);
  lcd.setCursor(0,8);
  lcd.print(g1);
  lcd.setCursor(1,0);
  lcd.print(b1);
  
}
 }
