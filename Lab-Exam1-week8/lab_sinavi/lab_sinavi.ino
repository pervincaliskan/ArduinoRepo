#include <WiFi.h>
#include <HTTPClient.h>
int chnck=0;
String postData="";
String temps;
int red=23;
const int freq=5000;
const int ledChannel=0;
const int resolution=8;
void setup() {
  ledcSetup(ledChannel,freq,resolution);
  ledcAttachPin(ledChannel,red);
  WiFi.disconnect(); 
  Serial.begin(115200);
  pinMode(red,OUTPUT);
  Serial.println("\nI2C Scanner"); 
  WiFi.mode(WIFI_STA); 
  WiFi.begin("iPhone", "anasmezar");
  analogReadResolution(34);
  
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
    int adcVal=analogRead(34);
    float analogVolts=analogReadMilivolts(34);
    float tempC=analogVolts/10;
    Serial.print("adc analog value=%d\n,adcVal");
    Serial.print("adc milivolts value=%f\n,analogVolts");
    Serial.print(tepmC,2);
    temps=(String)tempC;
    if(tempC==25){
      postData="https://vyamacli.com/IoT/insert_data_lab.php?grup=22&rgb='100'&blink='the temperature is high'";
    }
    dutycycle=255;
    Serial.println(postData);
    if(tempC<=20){
      digitalWrite(red,LOW);
    }
    else if(tempC>25){
      ledcWrite(ledChannel,dutycycle);
    }
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
    

   
}
 }
