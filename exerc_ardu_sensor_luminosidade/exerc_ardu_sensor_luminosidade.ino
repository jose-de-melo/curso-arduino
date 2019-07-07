void setup(){
  Serial.begin(9600);
  pinMode(A5, INPUT);
}
void loop(){
  Serial.println(analogRead(A5));
  delay(50);
}

