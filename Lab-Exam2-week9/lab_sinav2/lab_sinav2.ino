#include <WiFi.h>
#include <HTTPClient.h>
int cnchk=0;
String postData="";
String msg="grup22";
//String gmsg="";
// karşı gtup 77 
//bizim grup 22
void setup() {
 
  WiFi.disconnect(); 
  Serial.begin(115200);
  Serial.println("\nI2C Scanner"); 
  WiFi.mode(WIFI_STA); 
  WiFi.begin("iPhone", "anasmezar");
 

  
  
}

void loop() {
    delay(100);
    cnchk=0;
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
         
    delay(1000);
   
    delay(1000);
      if(Serial.available()){
         msg= Serial.readString(); 
       msg=msg.substring(0,(msg.length()-1));
     postData="http://www.vyamacli.com/IoT/iot_chat_insert.php?gon=22&al=77&msg='"+msg+"'";
     // postData="http://vyamacli.com/IoT/iot_chat_insert.php?gon=99&al=25&msg=%27"+msg;
    HTTPClient http;
    Serial.println("Client begin...");
    http.begin(postData);             //Specify request destination
    http.setConnectTimeout(30000);
    http.setTimeout(30000);

    int httpCode = http.GET();
    String payload = http.getString();    //Get the response payload
    Serial.println(httpCode);
    Serial.println(payload);
    Serial.println(postData);
    // gelenData="http://vyamacli.com/IoT/iot_chat_select.php?grup=77"
    Serial.println("Client stopped...");
    
      }
   
}
 }
