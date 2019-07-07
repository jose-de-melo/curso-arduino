int pot = A5;
int valPot = 0;
int led = 13;

void setup(){
  pinMode(pot, INPUT);
  pinMode(led, OUT0PUT);
  Serial.begin(9600);
}

void loop(){
  
  
  valPot = analogRead(pot);
  valPot = map(valPot, 0, 1023, 500, 2000);
  
  digitalWrite(led, HIGH);
  delay(valPot);
  digitalWrite(led, LOW);
  delay(valPot);
  
  
}
