

#include <LiquidCrystal.h>

int distancia = 50;
int temp1;
int temp2;
float Tiempo;
float velocidad;
int flag1 = 0;
int flag2 = 0;

int entrada1 = 9;
int entrada2 = 8;

int led1 = 10;

const int pinBuzzer = 13; //Constante que contiene el numero del pin de Arduino al cual conectamos un buzzer pasivo

const int frecuencias[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};//Arreglo que contiene las frecuencias que queremos escuchar en nuestro buzzer
const int numFrecuencias = 10;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2);
  
  pinMode(entrada1, INPUT);
  pinMode(entrada2, INPUT);
  
  pinMode(led1, OUTPUT);
  
  
    digitalWrite(led1, LOW);
  
  Serial.begin(9600);
}

void loop()
{ 
  if(digitalRead (entrada1) == HIGH && flag1==0){
    temp1 = millis(); 
    flag1=1;
    digitalWrite(led1, HIGH);
  }

  if(digitalRead (entrada2) == HIGH && flag2==0){
    temp2 = millis(); 
    flag2=1;
    for (int i = 5; i < numFrecuencias; i++)
  {
   tone(pinBuzzer, frecuencias[i]);
   delay(1000);
  }
  noTone(pinBuzzer);
  }

  if (flag1==1 && flag2==1){
  	Tiempo = temp2 - temp1;
    float t = Tiempo/1000;
    velocidad = distancia / t;
    lcd.print("Tiempo: ");
    lcd.print(t);
    lcd.print(" D: ");
    lcd.print(distancia);
    lcd.setCursor(0,1);
    lcd.print("V: ");
    lcd.print(velocidad,1);
    delay(4000);
    lcd.clear();
    flag1 = 0;
    flag2 = 0;
    digitalWrite(led1, LOW);
  }
}
	
