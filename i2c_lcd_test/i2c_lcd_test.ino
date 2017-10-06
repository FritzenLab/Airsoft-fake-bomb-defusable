  
// Programa : Display LCD 16x2 e modulo I2C
// http://www.arduinoecia.com.br/2014/12/modulo-i2c-display-16x2-arduino.html
// Autor : Arduino e Cia

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

int segundosatual = 0;
int segundosantigos = 0;
int segundosrelogio = 60; 
 
void setup()
{
 lcd.begin (16,2);
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
}
 
void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Bomba Armada");

  segundosatual = millis()/1000;
  
  if (segundosatual >= (segundosantigos + 1)){ // Se passou 1000mS, conta mais um segundo
      segundosantigos = segundosatual;
      segundosrelogio = segundosrelogio - 1;
      if(segundosrelogio <= 1){
          lcd.setCursor(0,0);
          lcd.print("BOOOOMMMMM"); 
      } else{
          lcd.setCursor(0,1);
          lcd.print(segundosrelogio);
      }
    
  }
  
  

  
}
