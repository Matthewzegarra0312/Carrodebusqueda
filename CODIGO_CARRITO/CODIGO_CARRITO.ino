// Proyecto final Grupo 9
#include <Servo.h>

char myChar;
//Puente h L298N
int IN1 = 9;
int IN2 = 10;
int IN3 = 11;
int IN4 = 12;

Servo ServoUD, ServoRL;

int anguloUD=90;
int anguloRL=90;

void setup() {
  Serial.begin(9600);
  Serial.println("VINCULACIÓN LISTA#");
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  ServoUD.attach(8);
  ServoRL.attach(7);
}

void loop() {
  while(Serial.available()){
    myChar=Serial.read();
    Serial.print(myChar);
    Serial.print("#");
    if(myChar=='U'){
      adelante();
    }
    if(myChar=='D'){
      atras();
    }
    if(myChar=='L'){
      izquierda();
    }
    if(myChar=='R'){
      derecha();
    }
    if(myChar=='p'){
      parar();
    }
   //CONTROL DE CAMARA ARRIBA Y ABAJO
    if(myChar=='X') {
      anguloUD+=10;
     }//incrementamos 10
    else if(myChar=='Y') {
      anguloUD-=10;
     }//decrementamos 10
     anguloUD=constrain(anguloUD,0,180);//restringimos el valor de 0 a 180
     ServoUD.write(anguloUD); 
   //CONTROL DE CAMARA DERECHA E IZQUIERDA
      if(myChar=='A') {
      anguloRL+=10;
     }//incrementamos 10
    else if(myChar=='O') {
      anguloRL-=10;
     }//decrementamos 10
     anguloRL=constrain(anguloRL,0,180);//restringimos el valor de 0 a 180
     ServoRL.write(anguloRL);  
  }
  
 
}//FIN VOID LOOP

void adelante(){
  digitalWrite (IN1,HIGH);
  digitalWrite (IN2,LOW);
  digitalWrite (IN3,HIGH);
  digitalWrite (IN4,LOW);
}

void atras(){
  digitalWrite (IN1,LOW);
  digitalWrite (IN2,HIGH);
  digitalWrite (IN3,LOW);
  digitalWrite (IN4,HIGH);
}

void izquierda(){
  digitalWrite (IN1,HIGH);
  digitalWrite (IN2,LOW);
  digitalWrite (IN3,LOW);
  digitalWrite (IN4,LOW);
}

void derecha(){
  digitalWrite (IN1,LOW);
  digitalWrite (IN2,LOW);
  digitalWrite (IN3,HIGH);
  digitalWrite (IN4,LOW);
}

void parar(){
  digitalWrite (IN1,LOW);
  digitalWrite (IN2,LOW);
  digitalWrite (IN3,LOW);
  digitalWrite (IN4,LOW);
}
