#include <LiquidCrystal.h>

// Variables globales
int distancia = 50;
int temp1;
int temp2;
float Tiempo;
float velocidad;
int flag1 = 0;
int flag2 = 0;

// Entradas de los sensores
int entrada1 = 9;
int entrada2 = 8;

// Led que indica el encendido del primer sensor
int led1 = 10;

// Pin del buzzer
const int pinBuzzer = 13; //Constante que contiene el numero del pin de Arduino al cual conectamos un buzzer pasivo

// Freguencias que utilizara el buzzer
const int frecuencias[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};//Arreglo que contiene las frecuencias que queremos escuchar en nuestro buzzer
const int numFrecuencias = 10;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  // Configuracion de lcd y mensaje inicial
  lcd.begin(16, 2);
  lcd.print("Proyecto");
  lcd.setCursor(0,1);
  lcd.print("Arqui1");
  lcd.setCursor(0,0);

  // Configuracion de las entradas de los sensores
  pinMode(entrada1, INPUT);
  pinMode(entrada2, INPUT);

  // Configuracion de el pines de salida  
  pinMode(led1, OUTPUT);  
  digitalWrite(led1, LOW);
  // Configuracion del Monitor serial
  Serial.begin(9600);
  Serial.println("Tiempo,Velocidad");
}

void loop()
{ 
  // Esperamos que se detecte algo en el primer sensor
  if(digitalRead (entrada1) == LOW && flag1==0){
    temp1 = millis(); // Se captura el tiempo
    flag1=1; // Se activa la bandera
    digitalWrite(led1, HIGH); // Se enciende el led
  }

  // Esperamos a que se detecte algo en el segundo sensor
  if(digitalRead (entrada2) == LOW && flag2==0){
    temp2 = millis(); 
    flag2=1;
  }
  // Si ambas banderas estan activadas se procede a hacer el calculo de tiempo
  if (flag1==1 && flag2==1){
    // Si el tiempo1 es menor se hace el calculo de datos
  	if(temp1 < temp2){
      Tiempo = temp2 - temp1; // Obtenemos el tiempo total
      float t = Tiempo/1000; // Transformamos el tiempo a segundos
      velocidad = distancia / t; // Calculamos la distancia
      lcd.print("T: ");
      lcd.print(t);
      lcd.print(" D: ");
      lcd.print(distancia);
      lcd.setCursor(0,1);
      lcd.print("V: ");
      lcd.print(velocidad,1);  
      for (int i = 5; i < numFrecuencias; i++)
      {
        // Ejecutamos el buzzer
        tone(pinBuzzer, frecuencias[i]);
        delay(750);
      }
      // Limpiamos todos los datos
      noTone(pinBuzzer);
      lcd.clear();
      flag1 = 0;
      flag2 = 0;
      digitalWrite(led1, LOW);
      Serial.print(t);
      Serial.print(",");
      Serial.println(velocidad);
    } else {
      // Si el tiempo 1 es mayor el tiempo2 Muestra un error en la LCD
      // Cierra todos los datos
      lcd.clear();
      lcd.print("ERROR");
      lcd.setCursor(0, 1);
      lcd.print("Repitelo");
      delay(3000);
      lcd.clear();
      flag1 = 0;
      flag2 = 0;
      digitalWrite(led1, LOW);
    }
    lcd.print("Proyecto");
    lcd.setCursor(0,1);
    lcd.print("Arqui1");
    lcd.setCursor(0,0);
  }
}
	
