/*
 * Autor: Denilson Gomes Vaz da Silva
 * Gradundo em Engenharia da Computação - UFC
 * 
 * Programa teste para LCD 16x2
 * 
 * Circuito:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 
 * Este programa usa a biblioteca "LiquidCrystal" que já está embutida na IDE do Arduino.
 * Então é só usar galera!!
 * 
 * Baseado no exemplo:
 * http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld
 */

 //--Bibliotecas
 #include <LiquidCrystal.h>
 
 //--Variaveis e Constantes
 const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;

 //--Objetos
 LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 //--Setup
 void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(1, 0);
  lcd.print("Denilson Gomes");
  lcd.setCursor(3, 1);
  lcd.print("Engenheiro");
}

void loop() {
  //lcd.setCursor(0, 1);
  //lcd.print(millis() / 1000);
}
