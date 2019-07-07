int led = 2, led2 = 3, motor = 4;
const long intervalo = 1000, intervalo2 = 500;
unsigned long millis_anterior = 0, millis_anterior2 = 0;
int ledState = LOW, ledState2 = LOW ;

void setup(){
    pinMode(led, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(motor, OUTPUT);

}

void loop(){
    unsigned long millis_atual = millis();
    digitalWrite(motor, HIGH);
    
    
    if(millis_atual - millis_anterior >= intervalo){
        millis_anterior = millis_atual;
        
        if(ledState == LOW){
          ledState = HIGH;
        }
        else{
          ledState = LOW;
        }
        
        digitalWrite(led, ledState);
    
    }
    
    
    unsigned long millis_atual2 = millis();
    
    if(millis_atual2 - millis_anterior2 >= intervalo2){
        millis_anterior2 = millis_atual2;
        
        if(ledState2 == LOW){
          ledState2 = HIGH;
        }
        else{
          ledState2 = LOW;
        }
        
        digitalWrite(led2, ledState2);
    
    }
}
