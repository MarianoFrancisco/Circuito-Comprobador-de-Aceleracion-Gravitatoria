//Incluimos libreria servo y lo definimos
#include <Servo.h>
Servo servo;
//Definimos constantes -> 90 grados=0, 105 grados=15, 120 grados=30, 135 grados=45
#define CEROGRADOS 90
#define QUINCEGRADOS 105
#define TREINTAGRADOS 120
#define CUARENTAYCINCOGRADOS 135
#define ENTRADASERVO 2
#define BOTONQUINCE 3
#define BOTONTREINTA 4
#define BOTONCUARENTAYCINCO 5
//definimos variable lectora de botones
int estado;
//definimos prototipos para cambiar a quince, treinta, cuarenta y cinco grados
void cambiarQuinceGrados();
void cambiarTreintaGrados();
void cambiarCuarentaCincoGrados();
//inicializaciones
void setup()
{//definimos en que pin está el servo y lo iniciamos en 0 grados
  servo.attach(ENTRADASERVO);
  servo.write(CEROGRADOS);
  //definimos que los 3 botones serán de entrada y ubicados en 3,4,5
  pinMode(BOTONQUINCE, INPUT);
  pinMode(BOTONTREINTA, INPUT);
  pinMode(BOTONCUARENTAYCINCO, INPUT);
}
//ciclo
void loop(){
  //llamamos metodos que verifican qué boton se presionó y se cambian los grados
  cambiarQuinceGrados();
  cambiarTreintaGrados();
  cambiarCuarentaCincoGrados();
}
//metodo para cambiar a quince grados el servomotor
void cambiarQuinceGrados(){
  //leemos la entrada en el pin 3, si se presionó cambia a 15 grados
  estado = digitalRead(BOTONQUINCE);
  if(estado==LOW){
  	servo.write(QUINCEGRADOS);
  }
}
//metodo para cambiar a treinta grados el servomotor
void cambiarTreintaGrados(){
  //leemos la entrada en el pin 4, si se presionó cambia a 30 grados
  estado = digitalRead(BOTONTREINTA);
  if(estado==LOW){
  	servo.write(TREINTAGRADOS);
  }
}
//metodo para cambiar a cuarenta y cinco grados el servomotor
void cambiarCuarentaCincoGrados(){
  //leemos la entrada en el pin 3, si se presionó cambia a 45 grados
  estado = digitalRead(BOTONCUARENTAYCINCO);
  if(estado==LOW){
  	servo.write(CUARENTAYCINCOGRADOS);
  }
}