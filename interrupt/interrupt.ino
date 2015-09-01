#define verde 10

const int ButtonPin = 2;
int state = LOW;
unsigned long lastInterrupt;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(verde, OUTPUT);
  attachInterrupt(INT0,Prende,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(ButtonPin);
 
  if(state ==HIGH){
  digitalWrite(verde,state);
  }
  //delayMicroseconds(3000000);
  Serial.println("Salio a interrupt");
}

void Prende(){

  //digitalWrite(verde, HIGH);
  //delayMicroseconds(3000000);       
  //digitalWrite(verde, LOW); 
  if(millis() - lastInterrupt > 100) // we set a 10ms no-interrupts window
  {
   Serial.println("******Entro a interrupt");
   state = !state; 
   lastInterrupt = millis();
  }
}




