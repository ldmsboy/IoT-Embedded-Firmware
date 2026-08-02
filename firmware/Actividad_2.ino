/**********************************************************************
  Filename    : ButtonAndLed
  Description : Control led by button.
  Auther      : Luis Daniel Mendez Sosa 1106120
  Modification: 2022/05/21
**********************************************************************/
int LED = 15;
int pin_BOTON = 2;
byte ledPins[] = {13, 12, 14, 27, 26, 25, 33, 32, 35, 34};
byte potencia[] = {25,50,75,100,125,150,175,200,225,250};
int cPines = 10;
int i = 0;

#define CHN       0   //define the pwm channel
#define FRQ       1000  //define the pwm frequency
#define PWM_BIT   8     //define the pwm precision

void setup() 
{
  ledcSetup(CHN, FRQ, PWM_BIT); //setup pwm channel
  ledcAttachPin(LED, CHN);  //attach the led pin to pwm channel
  pinMode(pin_BOTON, INPUT);
  for (int j = 0; j < cPines ; j++) {
    pinMode(ledPins[j], OUTPUT); //colocar todos los pines del LEDBAR en OUTPUT 
  }
  
  Serial.begin(9600);
  aLeds(); //en caso de que hayan leds prendidos, apagar.

}
//Varia la potencia el led
void FnPotencia()
{
  ledcWrite(CHN, potencia[i]);
  digitalWrite(ledPins[i], HIGH);
  Serial.println(ledPins[i]);
  Serial.println(potencia[i]);
}

void aLeds(){
  for(int j=0;j<10;j++){
      digitalWrite(ledPins[j], LOW);
  }
  ledcWrite(CHN, 0);  
}
void loop() 
{
  
  if (digitalRead(pin_BOTON) == LOW)
  {
    if (i==10){
      i=0;
      aLeds();
      while(digitalRead(pin_BOTON) == LOW){
      
      }
    }
    else{
      Serial.println(i);
      FnPotencia();
      while(digitalRead(pin_BOTON) == LOW){
      
      }
      delay(100);
      i = i + 1;
    }
  }
}
