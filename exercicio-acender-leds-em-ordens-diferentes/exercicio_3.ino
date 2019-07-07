int leds[] = {2,3,4,5,9 ,8,7,6};

int btn0 = 11, btn1 = 10;

int intervalo = 250, intervalo2 = 500;
int direcao = 1;
unsigned long pM = 0, pM2 = 0;

int contador;



void setup(){
  
  pinMode(btn0, INPUT_PULLUP);
  pinMode(btn1, INPUT_PULLUP);
  
  for(contador = 0; contador < 8; contador++){
    pinMode(leds[contador], OUTPUT);
  }
  contador = 0;
}

void loop(){
  unsigned long cM = millis();
  
  if(cM - pM > intervalo){
    pM = cM;
    digitalWrite(leds[contador], HIGH);
    
    if(cM - pM2 > intervalo2){
      pM2 = cM;
      if(digitalRead(btn0) == 1){
        digitalWrite(leds[contador], LOW);
        contador +=direcao;
      }
    }
        
  }
  
  if(digitalRead(btn1) == 0){
    digitalWrite(leds[contador], LOW);
    direcao *= -1;
  }
  
  if(contador <= -1){
    contador = 7;
  }
  
  
  if(contador == 8)
    contador = 0;

}
