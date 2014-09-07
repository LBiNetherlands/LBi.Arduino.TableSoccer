#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 
int analogButtonPin = 0;
int scoreTeamBlue = 0;
int scoreTeamRed = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Press start");
}

void loop() {
  int val = analogRead(analogButtonPin);
  
  if(val >= 900 && val <= 1100)
  {
    // button 1 (start game)
    scoreTeamBlue = 0;
    scoreTeamRed = 0;
    
    lcd.setCursor(0,0);
    lcd.print("BLUE         RED");
    outputScore();
  }
  if(val >= 700 && val <= 899)
  {
    // button 2 (score blue)
    scoreTeamBlue = scoreTeamBlue + 1;    
    outputScore(); 
  }
  if(val >= 600 && val <= 699)
  {
    // button 3 (score red)
    scoreTeamRed = scoreTeamRed + 1;    
    outputScore();
  }
  if(val >= 500 && val <= 599)
  {
    // button 4 (end game)
    scoreTeamBlue = 0;
    scoreTeamRed = 0;

    lcd.clear();
    lcd.print("Press start");
  }
  
  delay(200);

}

void outputScore()
{
  lcd.setCursor(6,1);
  lcd.print(formatNumber(scoreTeamBlue) + "-" + formatNumber(scoreTeamRed)); 
}

String formatNumber(int number)
{
  String numberToString = String(number);
  
  if(number < 10)
  {
    return String("0" + numberToString); 
  }
  
  return numberToString;
}

