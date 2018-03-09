// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 9, en = 8, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Current Temp:");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  
  int rawVoltage = analogRead(A0); //reads raw voltage from the LM35 output
  int celciusTemp = rawVoltage * 0.48828125;
  celciusTemp = celciusTemp * 1.8 + 32;//converts that into celcus
  Serial.println(celciusTemp); //prints celcius to Serial monitor
  delay(500);
  // print the number of seconds since reset:
  lcd.print(celciusTemp);
}
