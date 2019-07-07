#include <Ultrasonic.h>

#define pino_trigger 10
#define pino_echo 9

Ultrasonic us(pino_trigger, pino_echo);

#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

unsigned long pM = 0;
int intervalo = 200;


void setup(){
  lcd.begin(3,1);
  
}

void loop(){
 
    lcd.clear();
    lcd.print(us.Ranging(CM));
  
    if(us.Ranging(CM) < 10){
      digitalWrite(8, HIGH);
    }
    else{
      digitalWrite(8, LOW);
    }
    
    delay(2000);
  
}
  
