//16155019 Deniz Aşkar
//17155946 Hasan Hamuı
//18155034 Pervin Çalışkan
#include <WiFi.h>
#include <HTTPClient.h>
int cnchk=0;
String postData="";
String gelenData="";
String msg="grup22";
//String gmsg="";
String gon="";
//bizim grup 22
void setup() {
 
  WiFi.disconnect(); 
  Serial.begin(115200);
  Serial.println("\nI2C Scanner"); 
  WiFi.mode(WIFI_STA); 
  WiFi.begin("Wokwi-GUEST", "");
 

  
  
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
         int splitIndex=msg.indexOf('-');
         gon=msg.substring(0,splitIndex);
       msg=msg.substring(splitIndex+1,(msg.length()-1));
     postData="http://www.vyamacli.com/IoT/iot_chat_insert.php?gon=22&al="+gon+"&msg='"+msg+"'";
     gelenData="http://vyamacli.com/IoT/iot_chat_select.php?grup=22";
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
    delay(500);
    Serial.println("mesaj okuma");
    http.begin(gelenData);
    int httpCode2 = http.GET();
    String gelenpayload = http.getString(); 
    Serial.println(httpCode2);
    Serial.println(gelenpayload);
    Serial.println(gelenData);
    Serial.println("Client stopped...");
    
      }
   
}
 }
