/*
 * By :
 * Rivera Pagan, Rafael #72860
 * Irizarry Suarez, Gian # 74071
 * Melendez Medina, Pedro # 65475
 * Augost, 2015
*/
int num=1000;
#define verde 10
#define roja 8
#define amarilla 9
#define peaton 13
unsigned long lastInterrupt;
const int ButtonPin = 2;
int ledState = HIGH;       // the current state of the output of LED Peaton
int ButtonState;          // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

long lastDebounceTime=0;
long debounceDelay = 50;


void setup() {
 
 Serial.begin(9600);

  pinMode(roja, OUTPUT);
  pinMode(amarilla, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(peaton,OUTPUT);
  //pinMode(ButtonPin,INPUT);
  pinMode(ButtonPin,INPUT_PULLUP);// for interrupt Button 
 
  //digitalWrite(peaton,ledState);
  attachInterrupt(INT0,GreenToRed,CHANGE);//Interrupt Button 

}

// the loop function runs over and over again forever
void loop() {
 int reading = digitalRead(ButtonPin);

 //int peatonState = GreenToRed();
 // if(peatonState == LOW){
  // digitalWrite(peaton,peatonState);
  //delay(6000);
  //}
  Serial.println(reading);
 RedToGreen();
 GreenToRed();
}//end LOOP
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void RedToGreen(){
  // luz roja
  digitalWrite(roja, HIGH);
  delay(3000);           
  digitalWrite(roja, LOW);    
 
    // luz verde
  digitalWrite(verde, HIGH);   
  delay(5000);           
  digitalWrite(verde, LOW);
 
}//end

void GreenToRed(){

//int reading = digitalRead(ButtonPin);

//int valor = LOW;
// luz verde
  digitalWrite(verde, HIGH);   
  delay(5000);           
  digitalWrite(verde, LOW);
  //if(reading != lastButtonState){
 //  valor = HIGH;
//}
 // Luz amarilla
  digitalWrite(amarilla, HIGH);   
  delay(3000);           
  digitalWrite(amarilla, LOW);  
 
   // Luz roja
  digitalWrite(roja, HIGH);
  //delay(3000);           
  //digitalWrite(roja, LOW);    
 
  //return valor;
}//end
void PeatonF(){
  if(millis() - lastInterrupt > 100) // we set a 10ms no-interrupts window
  {
   Serial.println("******Entro a interrupt");
   ledState = !ledState; 
   lastInterrupt = millis();
  }
}


