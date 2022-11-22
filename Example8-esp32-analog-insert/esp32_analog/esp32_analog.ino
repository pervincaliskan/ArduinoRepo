void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  
  //set the resolution to 12 bits (0-4096)
  analogReadResolution(12);
  
}

void loop() {
  // read the analog / millivolts value for pin 15:
  int adcVal = analogRead(15);
  float analogVolts = analogReadMilliVolts(15);
  float tempC = analogVolts / 10;
  
  // print out the values you read:
  Serial.printf("ADC analog value = %d\n",adcVal);
  Serial.printf("ADC millivolts value = %f\n",analogVolts);
  Serial.println(tempC, 2);
  
  delay(1000);  // delay in between reads for clear read from serial
}
