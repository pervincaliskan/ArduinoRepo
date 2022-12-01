#include <WiFi.h>
#include <HTTPClient.h>
#include<LiquidCrystal_I2C.h>

int lcdColumns=16;
int lcdRows=2;
LiquidCrystal_I2C lcd(0x27,lcdColumns,lcdRows);



const char* ssid = "Redmi 9A";
const char* password = "88888887";

//Your Domain name with URL path or IP address with path
String serverName = "http://vyamacli.com/IoT/select_data_lab.php?grup=22";


unsigned long lastTime = 0;

unsigned long timerDelay = 5000;

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(115200); 

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}

void loop() {
  //Send an HTTP POST request every 10 minutes
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;

      
      http.begin(serverName.c_str());
      
      // If you need Node-RED/server authentication, insert user and password below
      //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        String rgbData = payload.substring(0, 8);
        String _delayValue = payload.substring(9, 12);
        String _delayValue2 = payload.substring(13, 22);
        int delayValue = _delayValue.toInt();

        if(rgbData[0] == '0')
        {
        
          lcd.setCursor(0,0);
          lcd.print(rgbData);
           lcd.print(_delayValue);
            lcd.setCursor(0,1);
            lcd.print(_delayValue2);
        }

        

        Serial.println(payload);

      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}
