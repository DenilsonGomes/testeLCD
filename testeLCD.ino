/*
 * Autor: Denilson Gomes Vaz da Silva
 * Graduando em Engenharia da Computação - UFC
 * 
 * Programa teste para LCD 16x2
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
 LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Cria o objeto lcd

 //--Setup
 void setup() {
  lcd.begin(16, 2); //Inicia o display
  Serial.begin(9600); //Inicia o monitor serial
}

//--Loop
void loop() {
  
  //Exibir mensagem inicial
  lcd.setCursor(0, 0); //Coloco o cursor na linha 0 e coluna 0
  lcd.print("Denilson Gomes"); //Exibe meu nome na primeira linha
  lcd.setCursor(0, 1); //Move o cursor para a linha 1 e coluna 0
  lcd.print("Engenheiro"); //Exibe a palavra

  //Piscar cursor
  lcd.blink(); //Liga o piscar cursor
  delay(3000); //Espera 3s
  lcd.noBlink(); //Desliga o piscar cursor
  delay(3000); //Espera 3s

  //Ativar/descativar cursor
  lcd.cursor(); //Ativa o mostrar cursor
  delay(3000); //Espera 3s
  lcd.noCursor(); //Desliga o mostrar cursor
  delay(3000); //Espera 3s

  //Piscar display
  lcd.noDisplay(); //Para de exibir o conteudo
  delay(500); //Espera 0.5s
  lcd.display(); //Exibe o conteudo
  delay(500); //Espera 0.5s

  //Deslizar conteudo
  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    lcd.scrollDisplayLeft(); //Deslizar para esquerda
    delay(250);
  }

  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    lcd.scrollDisplayRight(); //Deslizar para a direita
    delay(250);
  }

  //Exibir conteudo lido da serial
  lcd.clear(); //Limpa o display
  lcd.setCursor(0,0); //move o cursor
  lcd.print("Lendo da serial"); //IMprime a mensagem
  delay(2000); //espera 2s
  if (Serial.available()){ //Se tiver algo na serial
    delay(100); //espera 0.1s
    lcd.setCursor(0,1); //Move o cursor
    while (Serial.available() > 0){ //Enquanto tiver algo na serial
      lcd.write(Serial.read()); //Imprime oq tiver na serial
    }
    delay(1000); //Espera 1s
  }

  //Mudar sentido da escrita(Normal=esq -> Dir)
  lcd.clear(); //Limpa o display
  lcd.setCursor(6,0); //move o cursor
  lcd.print("Invertendo sentido da escrita!"); //Imprime a mensagem
  for(int i=0;i<20;i++){ //para i de 0 a 20
    lcd.scrollDisplayLeft(); //Desliza o display da dir para esq
    delay(400); //espera 0.4s
  }
  lcd.clear(); //Limpa o display
  lcd.setCursor(0,1); //Move o cursor
  for(int i=0;i<10;i++){ //i de 0 a 9
    if(i==5){ //Se i == 5
      lcd.rightToLeft(); //Inverte o sentido
    }
    lcd.print(i); //printa i
    delay(1000); //Espera 1s
  }
  lcd.clear(); //Limpa o display
}
