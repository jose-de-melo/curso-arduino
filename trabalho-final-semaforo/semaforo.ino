int leds[] = {2,3,4,5,6,7}, i, j;
int sem1[] = {2,3,4}, sem2[] = {7,6,5};
int intervalo = 0, intervalo2 = 0, verde1 = 0, verde2 =0, vermelho1 =0 , vermelho2= 0;
unsigned long previous = 0, previous2 = 0;
int cor = 0;

int millisAmarelo = 0, millisAmarelo2 = 0;

String cores[3] = {"Verde", "Amarelo", "Vermelho"};

int ultimo = 0;

int sinal = 1;

bool verificador = false;

int b1 = 11, b2 = 12, b3 = 13;

void setup()
{
  Serial.begin(9600);
  pinMode(A5, INPUT);
  for(i = 0 ; i < 6 ; i++){
  	pinMode(leds[i], OUTPUT);
  }
  
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  
}

void loop()
{
  intervalo = analogRead(A5);
  intervalo = map(intervalo, 0,1023, 2000, 10000);


  
  unsigned long tempoAtual = millis();
  
  if(digitalRead(b1)){
      if(digitalRead(0)){
        
      }else{
      
        if(ultimo == 2){
          sinal *= -1;
          ultimo = 1;
        }else{
          ultimo = 1;
        }
      
      
    
        cor = 1;
        warning();
        previous = tempoAtual;
     }
  }
  
  
   
   if(digitalRead(b2)){
      if(digitalRead(7)){
        
      }else{
        if(ultimo == 1){
          sinal *= -1;
          ultimo = 2;
         }else{
          ultimo = 2;
        }
      
        cor = 1;
        warning();
        previous = tempoAtual;
      }
    
       
      
   }
   
   
   if(digitalRead(b3)){
     if(verificador != true){
       for(i = 0; i< 3; i++){
         if(digitalRead(sem1[i])){
           Serial.print("Estado semaforo 1 (esquerda): ");
           Serial.println(cores[i]);
         } 
       }
       
       for(j = 0; j< 3; j++){
         if(digitalRead(sem2[j])){
           Serial.print("Estado semaforo 2 (direita): ");
           Serial.println(cores[j]);
         } 
       }
       
       Serial.print("Tempo para transicao: ");
       Serial.println(intervalo - (tempoAtual - previous));
       verificador =  true;
     }
   }else{
     verificador =  false;
   }
    
  if(tempoAtual - previous > intervalo){

    
    
    previous = tempoAtual;
    
    if(cor == 0){
    	opened();
    }
    
    else if(cor == 1){
    	warning();
    }
    
    if(cor == 3 || cor == -1){
      sinal *= -1;
      cor += 2*sinal;
    }
        
    

   
   if(cor == 3){
      cor = 0;
    }
    
  
  }
  
    
  
}

void warning(){
        if(sinal == -1)
          digitalWrite(leds[1], HIGH);
      	else
          digitalWrite(leds[4], HIGH);
          
        digitalWrite(leds[0], LOW);
      	digitalWrite(leds[5], LOW);
      	cor += sinal;
        delay(1000);
        if(sinal == 1)
          closed();
        else
          opened();
}

void closed(){
        digitalWrite(leds[0], HIGH);
      	digitalWrite(leds[3], HIGH);
        digitalWrite(leds[2], LOW);
      	digitalWrite(leds[5], LOW);
        digitalWrite(leds[1], LOW);
      	digitalWrite(leds[4], LOW);
        cor += sinal;
}

void opened(){
        digitalWrite(leds[2], HIGH);
      	digitalWrite(leds[5], HIGH);
        digitalWrite(leds[0], LOW);
      	digitalWrite(leds[3], LOW);
        digitalWrite(leds[1], LOW);
      	digitalWrite(leds[4], LOW);
      	cor += sinal;
}


