//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int vermelho = 10, amarelo = 9, verde = 8;
int sensor = 6;

int valorSensor = 0;

void setup()
{
  
  	pinMode(vermelho, OUTPUT);
  	pinMode(verde, OUTPUT);
  	pinMode(amarelo, OUTPUT);
  	pinMode(sensor, INPUT);
  
  	
	//Define o número de colunas e linhas do LCD
  	lcd.begin(16, 2);
}
void loop()
{
  lcd.clear();
  valorSensor = digitalRead(sensor);
  valorSensor = map(valorSensor, 0, 1023, 0, 100);
  
  lcd.print(valorSensor);
  
  
  
  if(valorSensor <= 30){
  	digitalWrite(vermelho, HIGH);
	digitalWrite(amarelo, LOW);
	digitalWrite(verde, LOW);
  }
  else if( valorSensor > 30 && valorSensor <= 60){
  	digitalWrite(vermelho, LOW);
    digitalWrite(amarelo, HIGH);
    digitalWrite(verde, LOW);
  }
  else{
  	digitalWrite(vermelho, LOW);
    digitalWrite(amarelo, LOW);
    digitalWrite(verde, HIGH);
  }
  
  delay(200);
  
   
}
