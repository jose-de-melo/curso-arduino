//Carrega a biblioteca do sensor ultrassonico
#include <NewPing.h> // Sonar
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>

//Define os pinos para o trigger e echo
#define pino_trigger 6
#define pino_echo 7
 
//Inicializa o sensor nos pinos definidos acima
NewPing sonar(pino_trigger, pino_echo, 400);
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensor = A0, btn = 13;

int apertado = 0;

int op = 0; // op = 0 -> sensor de luminosidade ; op = 1 -> sensor ultrassonico

float cmMsec = 5, cm2;

unsigned int previous = 0, intervalo = 500;

void setup(){
  pinMode(btn, INPUT);
  pinMode(sensor, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}


void loop(){
  int valorSensorLDR = 0;
  
  
  if(digitalRead(btn)){
    if(apertado == 0){
      apertado = 1;    
      if(op == 0){    
        lcd.clear();
        op = 1;
      }else{
        lcd.clear();
        op = 0;
      }
    }
      
  }else{
    apertado = 0;
  }
  
  cm2 = sonar.ping_cm();
  if(cm2 != 0)
    cmMsec = cm2;
 
  

  valorSensorLDR = analogRead(sensor);
  valorSensorLDR = map(valorSensorLDR, 0, 1023,0, 1000);
  
  if(op == 0){
      lcd.setCursor(0,0);
      lcd.print("Sensor de luz:");
      lcd.setCursor(0,1);
      lcd.print(valorSensorLDR);
  }
  else{
      lcd.setCursor(0,0);
      lcd.print("Sensor de som:");
      lcd.setCursor(0,1);
      lcd.print(cmMsec);
      
  }
  
  
 
  
}


