

#include "BluetoothSerial.h"
#include <LiquidCrystal_I2C.h>


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
int lcdColumns = 16;
int lcdRows = 2;
// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test55"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  lcd.init();                    
  lcd.backlight();
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
    
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
    lcd.print(SerialBT.read());
  }
  delay(20);
  
}
