#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);


void setup(){
  lcd.begin(16,2);
  
}

void loop(){
  
  int i, k, linha = 0;

  
  for(i = 0; i < 16; i++){
    lcd.clear();
    lcd.setCursor(i, linha);
    lcd.print("J");
    delay(200);
    
    if(i == 15 && linha == 0){
      i = -1;
      linha = 1;
    }
    
    
  }
  
  for(i = 15; i >= 0; i--){
    lcd.clear();
    lcd.setCursor(i, linha);
    lcd.print("J");
    delay(200);
    
    if(i == 0 && linha == 1){
      i = 16;
      linha = 0;
    }
    
    
  }
  
  
 
  
}
