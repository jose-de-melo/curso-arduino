
/** Leds acendendo em tempos diferentes e um zumbador simplismente sintonizado */

int intervalo = 2000, intervalo2 = 1000, intervalo3 = 500;

unsigned int previous =0, previous2 =0, previous3 =0;

int ledState = LOW, ledState2 = LOW, ledState3 = LOW; 




void setup(){
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  


}

void loop(){
  unsigned int atual = millis();
  
  if(atual - previous > intervalo){
    previous = atual ;
    
    if(ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
      
    
    digitalWrite(2, ledState);
 
  }
  
  unsigned int atual2 = millis();
  
  if(atual2 - previous2 > intervalo2){
    previous2 = atual2 ;
    
    if(ledState2 == LOW)
      ledState2 = HIGH;
    else
      ledState2 = LOW;
      
    
    digitalWrite(3, ledState2);
 
  }
  
  unsigned int atual3 = millis();
  
  if(atual3 - previous3 > intervalo3){
    previous3 = atual3 ;
    
    if(ledState3 == LOW)
      ledState3 = HIGH;
    else
      ledState3 = LOW;
      
    
    digitalWrite(4, ledState3);
 
  }
  
  int i;
  
  for(i = 0; i < 10; i++){
      tone(5, (i + 1)* 10, 8);
      delay(100);
      
  }
  
  noTone(5);
  

}
