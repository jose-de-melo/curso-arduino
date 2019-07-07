// Emissor

int LDR = A0;


void setup(){
  Serial.begin(9600);
  pinMode(LDR, INPUT);
}

void loop(){
  int valor = analogRead(LDR);
  valor = map(valor, 0, 1023, 100, 0);
  
  
  Serial.write(valor);
  
  delay(1000);
  
  
}
