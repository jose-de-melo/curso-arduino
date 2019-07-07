// Receptor
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup()
{
  Serial.begin(9600);
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
}
 
void loop()
{
  if(Serial.available() > 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Valor recebido : ");
    lcd.setCursor(0,1);
    lcd.print(Serial.read());
    delay(1000);
    
  }
}
