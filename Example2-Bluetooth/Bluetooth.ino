#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

// the number of the LED pin
const int ledPin = 2;  // 
String k;
int m = 1;

// setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Pervin"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
    // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin, ledChannel);
}

void loop() {
  if (SerialBT.available()) {
    k = SerialBT.readString();
    //Serial.write(SerialBT.read());
    Serial.println(k);
    m = k.toInt();
    Serial.println(m);
  }

  if (m==0) {m = 1;}
  
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle = dutyCycle + m){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);   
    delay(15);
  }
  
}
