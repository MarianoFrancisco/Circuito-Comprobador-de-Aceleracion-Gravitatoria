#include <Servo.h>
#define CEROGRADOS 90
#define QUINCEGRADOS 105
#define TREINTAGRADOS 120
#define CUARENTAYCINCOGRADOS 135
#define ENTRADASERVO 2
#define BOTONQUINCE 3
#define BOTONTREINTA 4
#define BOTONCUARENTAYCINCO 5
Servo servo;
void cambiarQuinceGrados();
void cambiarTreintaGrados();
void cambiarCuarentaCincoGrados();
void setup()
{//90 grados=0, 105 grados=15, 120 grados=30, 135 grados=45
  servo.write(CEROGRADOS);
  pinMode(BOTONQUINCE, INPUT);
  servo.attach(ENTRADASERVO);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(BOTONQUINCE), cambiarQuinceGrados, RISING);
  attachInterrupt(digitalPinToInterrupt(BOTONTREINTA), cambiarTreintaGrados, RISING);
  attachInterrupt(digitalPinToInterrupt(BOTONCUARENTAYCINCO), cambiarCuarentaCincoGrados, RISING);
}

void loop(){
  
}
void cambiarQuinceGrados(){
  servo.write(QUINCEGRADOS);
}
void cambiarTreintaGrados(){
  servo.write(TREINTAGRADOS);
}
void cambiarCuarentaCincoGrados(){
  servo.write(CUARENTAYCINCOGRADOS);
}