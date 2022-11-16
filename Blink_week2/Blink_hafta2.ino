

int pin=15;
int blue=2;
int green=4;
int red=16;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pin,INPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  int value =analogRead(pin);
  Serial.println(value);
  if(0<value & value<1000){
    digitalWrite(blue,HIGH);
     digitalWrite(green,LOW);
      digitalWrite(red,LOW);
    
  }
   if(1000<value & value<2000){
    digitalWrite(green,HIGH);
    
  }
   if(2000<value & value<3000){
    digitalWrite(red,HIGH);
    
  }
  
}
