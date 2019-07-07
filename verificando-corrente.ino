void setup(){
    Serial.begin(9600);
    pinMode(2, OUTPUT);
}


void loop(){
  int corrente = digitalRead(2);
  
  
  if(corrente == LOW){
    Serial.print("Corrente baixa\n");
    
  }
  else{
    Serial.print("Corrente alta\n");
  }
  
  delay(1000);
}
