#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 
int analogButtonPin = 0;
int scoreTeamBlue = 0;
int scoreTeamRed = 0;
unsigned long prevActionMillis = millis();

void setup() {
  // set output mode to turn on off contrast
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  
  // set pullup mode for multi button
  pinMode(A0, INPUT);
  digitalWrite(A0, HIGH);
  
  lcd.begin(16, 2);
  lcd.print("Press start");
}

void loop() {
  int val = analogRead(analogButtonPin);
  
  if(val >= 400 && val <= 500)
  {
    lcd.display();
    digitalWrite(13, HIGH);
    
    // button 1 (start game)
    scoreTeamBlue = 0;
    scoreTeamRed = 0;
    
    lcd.setCursor(0,0);
    lcd.print("BLUE         RED");
    outputScore();
    
    prevActionMillis = millis();
  }
  if(val >= 300 && val <= 400)
  {
    lcd.display();
    digitalWrite(13, HIGH);
    
    // button 2 (score red)
    scoreTeamRed = scoreTeamRed + 1;    
    outputScore(); 
    
    prevActionMillis = millis();
  }
  if(val >= 200 && val <= 300)
  {
    lcd.display();
    digitalWrite(13, HIGH);
    
    // button 3 (score blue)
    scoreTeamBlue = scoreTeamBlue + 1;        
    outputScore();
    
    prevActionMillis = millis();
  }
  
  if(millis() - prevActionMillis > 10000)
  {
    lcd.noDisplay();
    digitalWrite(13, LOW); 
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

