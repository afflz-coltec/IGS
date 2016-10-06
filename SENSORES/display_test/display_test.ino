#include <LiquidCrystal.h>

// Setup the LiquidCrystal library with the pin numbers we have
// physically connected the module to.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int lastUpdate = 0;  
int currentIndex = 0;  
char* lyrics[] = {  
  "Drink all the...", 
  "     BOOZE!     ",
  "Hack all the... ",
  "    THINGS!     " 
};

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("OI");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0,1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
