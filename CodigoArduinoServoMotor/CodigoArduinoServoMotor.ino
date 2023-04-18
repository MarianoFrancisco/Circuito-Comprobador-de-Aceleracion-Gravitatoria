// Incluimos libreria servo y lo definimos
#include <Servo.h>
Servo servo;
// Definimos constantes -> 90 grados=0, 105 grados=15, 120 grados=30, 135 grados=45
#define CEROGRADOS 90
#define QUINCEGRADOS 105
#define TREINTAGRADOS 120
#define CUARENTAYCINCOGRADOS 135
#define ENTRADASERVO 2
#define BOTONQUINCE 3
#define BOTONTREINTA 4
#define BOTONCUARENTAYCINCO 5
#define BOTONCERO 6
// definimos variable de posicion grados
int posicionGrado = CEROGRADOS;
// definimos prototipos para cambiar grados y cambiar grados lentamente
void cambiarGrados(int grados, int boton);
void cambiarGradoLento(int grados);
// inicializaciones
void setup()
{ // definimos en que pin está el servo y lo iniciamos en 0 grados
  servo.attach(ENTRADASERVO);
  servo.write(CEROGRADOS);
  // definimos que los 3 botones serán de entrada y ubicados en 3,4,5
  pinMode(BOTONQUINCE, INPUT);
  pinMode(BOTONTREINTA, INPUT);
  pinMode(BOTONCUARENTAYCINCO, INPUT);
}
// ciclo
void loop()
{
  /*llamamos metodos que verifican qué boton se presionó y se cambian los grados
  leemos la entrada en el pin 6, si se presionó cambia a 45 grados*/
  cambiarGrados(CEROGRADOS, BOTONCERO);
  // leemos la entrada en el pin 3, si se presionó cambia a 45 grados
  cambiarGrados(QUINCEGRADOS, BOTONQUINCE);
  // leemos la entrada en el pin 4, si se presionó cambia a 45 grados
  cambiarGrados(TREINTAGRADOS, BOTONTREINTA);
  // leemos la entrada en el pin 5, si se presionó cambia a 45 grados
  cambiarGrados(CUARENTAYCINCOGRADOS, BOTONCUARENTAYCINCO);
}
// metodo para cambiar grados del servomotor
void cambiarGrados(int grados, int boton)
{
  // leemos el boton que se presionó
  if (digitalRead(boton) == LOW)
  {
    // cambiamos los grados lentamente
    cambiarGradoLento(grados);
  }
}
// metodo para cambiar de manera lenta los grados del servomotor
void cambiarGradoLento(int grados)
{
  // verificamos si el grado es mayor, irá en descenso
  if (posicionGrado > grados)
  {
    for (int i = posicionGrado; i >= grados; i--)
    {
      servo.write(i);
      delay(30);
      posicionGrado = i;
    } // verificamos si el grado es menor, irá en aumento
  }
  else if (posicionGrado < grados)
  {
    for (int i = posicionGrado; i <= grados; i++)
    {
      servo.write(i);
      delay(75);
      posicionGrado = i;
    }
  }
}