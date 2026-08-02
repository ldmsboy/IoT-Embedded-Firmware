int num = 0;
int i = 0; 
int ledCounts;
byte colores[] = {4, 15, 2};


void setup() {
  
  ledCounts = sizeof(colores);
  for (int i = 0; i < ledCounts; i++) {
  pinMode(colores[i], OUTPUT);
  }

  Serial.begin(9600);
  Serial.println(String("\n Bienvenido! Para continuar por favor ")
                + String(" Eliga una de las siguientes opciones: \n")
                + String(" Escriba la palabra random para mostrar los colores rojo, verde y azul aleatoriamente. (Se presentaran 10 veces dichos colores al azar)\n")
                + String(" Escriba las siguientes palabras para mostrar los colores rojo, verde y azul segÃºn se le asigne: \n")
                + String(" El rojo  \n")
                + String(" El azul  \n")
                + String(" El verde \n")
                + String(" selecione \"Nueva Linea\" abajo y haga clic en el botÃ³n enviar para la interacciÃ³n. \n"));
              
}

void loop() {

digitalWrite(colores[0], HIGH);
digitalWrite(colores[1], HIGH);
digitalWrite(colores[2], HIGH);
char inChar = Serial.read();

if (Serial.available()) { 

      if (inChar == 'random'){
        while (num <= 10){
              i = rand() % (1 + 2);
        digitalWrite(colores[i], LOW);
        delay (1000);
        digitalWrite(colores[i], HIGH);
        num = num + 1;
        }
         num -= 0;
     }

       if (inChar =='rojo'){
      digitalWrite(colores[0], LOW);
      delay (10000);
      digitalWrite(colores[0], HIGH);
      }
      if (inChar == 'azul'){
      digitalWrite(colores[1], LOW);
      delay (10000);
      digitalWrite(colores[1], HIGH);
      }
      if (inChar == 'verde'){
      digitalWrite(colores[2], LOW);
      delay (10000);
      digitalWrite(colores[2], HIGH);
      }
  } 
}
