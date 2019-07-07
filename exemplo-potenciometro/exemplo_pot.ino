int pot = A5;
int valPot = 0;

void setup(){
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop(){
  
  
  valPot = analogRead(pot);
  valPot = map(valPot, 0, 1023, 0, 255);
  Serial.println(valPot);
}
