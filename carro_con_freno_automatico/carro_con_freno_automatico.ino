#include <Buzzer.h>

const int Trigger = 3;   //Pin digital 3 para el Trigger del sensor
const int Echo = 2;   //Pin digital 2 para el Echo del sensor

Buzzer buzzer(10, 11);

void setup() {
  buzzer.begin(10);
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  /////
  pinMode(12, OUTPUT); //pin como salida
  digitalWrite(12, HIGH);
  }

void loop() {
  
  
  //buzzer.sound(NOTE_A3, 500);
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  if(d<50 && d >=40){
    buzzer.sound(NOTE_A3, 100);
  }else if(d<40 && d >=30){
      buzzer.sound(NOTE_A4, 50);
  }else if(d<30 && d >=25){
    buzzer.sound(NOTE_A5, 25);
  }else if(d<30 && d >=0){
    buzzer.sound(NOTE_A7, 100);
    digitalWrite(12, LOW);
  }else{
     digitalWrite(12, HIGH);
  }
  delay(50);
}
