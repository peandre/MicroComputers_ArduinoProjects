/* Traffic Light with Interrupt
 * By :
 * Rivera Pagan, Rafael #72860
 * Irizarry Suarez, Gian # 74071
 * Melendez Medina, Pedro # 65475
 * September, 2015
*/

#define verde 10
#define roja 8
#define amarilla 9
#define peaton 12

const int ButtonPin = 2;
int pressbutton;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(roja, OUTPUT);
  pinMode(amarilla, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(peaton, OUTPUT);
  pinMode(ButtonPin, INPUT);
  
  attachInterrupt(INT0,Interrupcion,FALLING);
  
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
    
  pressbutton = 0;
  
  Serial.println("Seven Segment");
  Serial.println("0");
  
  //prende verde
  digitalWrite(verde, HIGH);   
  WaitVerde(); 
  digitalWrite(verde, LOW);
  
  //prende amarilla
  digitalWrite(amarilla, HIGH);   
  WaitAmarilla();         
  digitalWrite(amarilla, LOW);
  
   //prende roja
   digitalWrite(roja, HIGH);   
   WaitRoja();             
   digitalWrite(roja, LOW);
  
}

void Oprimido()
{
  pressbutton = 0;
  // si led amarillo esta prendido apagalo
  if(digitalRead(amarilla)==1)
    {
      digitalWrite(amarilla, LOW);
    }
  // si led verde esta prendido apagalo
  if(digitalRead(verde)==1)
    {
      digitalWrite(verde, LOW);
    }
  // si led rojo esta apagado, enciende amarilla  
  if(digitalRead(roja)==0)
    {
      digitalWrite(amarilla, HIGH);
      delay(1000);
      digitalWrite(amarilla, LOW);
    }
    
  digitalWrite(roja, HIGH);
  digitalWrite(peaton, HIGH);
  
  Serial.println("4");
  //prendo el 4 en seven segment
  delay(1000);
  Serial.println("3");
  //prendo el 3 en seven segment
  delay(1000);
  Serial.println("2");
  //prendo el 2 en seven segment
  delay(1000);
  Serial.println("1");
  //prendo el 1 en seven segment
   delay(1000);
   Serial.println("0");
  digitalWrite(roja, LOW);
  digitalWrite(peaton, LOW);
  //prendo el 0 en seven segment
  loop();
}
//interrupt modifica el valor de pressbutton, si el boton no ha sido oprimido
void Interrupcion()
{
  if(digitalRead(peaton)==0)
    {
      pressbutton++;
    }
}

// luz verde 5 segundos
void WaitVerde()
{
  for (int i = 0;i<100;i++)
  {
    delay(50);
    if (pressbutton>=1)
    {
      Oprimido();
    }
  }
}

//luz amarilla 1 segundo
void WaitAmarilla()
{
  for (int i = 0;i<20;i++)
  {
    delay(50);
    if (pressbutton>=1)
    {
      Oprimido();
    }
  }
}

//luz roja 4 segundos
void WaitRoja()
{
  for (int i = 0;i<80;i++)
  {
    delay(50);
    if (pressbutton>=1)
    {
      Oprimido();
    }
  }
}
