#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 
int analogButtonPin = 0;
int scoreTeamBlue = 0;
int scoreTeamRed = 0;

void setup() {
  // set pullup mode for multi button
  pinMode(A0, INPUT);
  digitalWrite(A0, HIGH);
  
  lcd.begin(16, 2);
  lcd.print("Press start");
}

void loop() {
  int val = analogRead(analogButtonPin);
  
  if(val >= 500 && val <= 599)
  {
    // button 1 (start game)
    scoreTeamBlue = 0;
    scoreTeamRed = 0;
    
    lcd.setCursor(0,0);
    lcd.print("BLUE         RED");
    outputScore();
  }
  if(val >= 400 && val <= 499)
  {
    // button 2 (score blue)
    scoreTeamBlue = scoreTeamBlue + 1;    
    outputScore(); 
  }
  if(val >= 300 && val <= 399)
  {
    // button 3 (score red)
    scoreTeamRed = scoreTeamRed + 1;    
    outputScore();
  }
  if(val >= 200 && val <= 299)
  {
    // button 4 (end game)
    scoreTeamBlue = 0;
    scoreTeamRed = 0;

    lcd.clear();
    lcd.print("Press start");
  }
  
  delay(300);

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

