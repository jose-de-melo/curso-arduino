int redpin=A2;
int greenpin=A3;
int bluepin=A4;


long previousMillis = 0,previousMillis2 = 0;
long ledInterval = 500, ledRGB = 500; 
int led = 10, estado = 0;
int ledState = LOW;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(A5, INPUT);

}


void loop()
{
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis > ledInterval){
  	previousMillis = currentMillis;
    
    if(ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    
    digitalWrite(led, ledState);
  
  }
  
  ledRGB = map(analogRead(A5), 0,1023, 500, 5000);
  
  unsigned long currentMillis2 = millis();
  
  if(currentMillis2 - previousMillis2 > ledRGB){
    previousMillis2 = currentMillis2;
    
    if(estado == 0){
      setCor(1023,0,0);
      estado = 1;
    }
    
    else if(estado == 1){
      setCor(0,1023,0);
      estado = 2;
    }
    
   else if(estado == 2){
      setCor(0,0,1023);
      estado = 3;
    }
    
    else if(estado == 3){
      setCor(220,800, 0);
      estado = 4;
    }
    
    else{
      setCor(0, 1023 , 1023);
      estado = 0;
    }
  
  }
  
}

void setCor(int red, int green, int blue){
	analogWrite(redpin,red);
  	analogWrite(greenpin, green);
  	analogWrite(bluepin, blue);

}
