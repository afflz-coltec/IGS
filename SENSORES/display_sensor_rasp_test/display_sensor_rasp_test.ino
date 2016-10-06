#include <LiquidCrystal.h>
#include "SHT1X.h"

//variables for storing values
float a_temp = 0;
float a_humi = 0;
float s_humi = 0;
float s_temp = 0;
float l_lumi = 0;
float l_temp = 0;
float ex_time = 0;


//Create an instance of the SHT1X sensor
SHT1x sht15(7, 8);//Data, SCK

//delacre output pins for powering the sensor
int shsensor = A0;
int stsensor = A1;//http://www.ti.com/lit/ds/symlink/lm35.pdf
int llsensor = A2;
int ltsensor = A3;//http://www.ti.com/lit/ds/symlink/lm235.pdf



float a = 0.0 , b=0.0;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);




void setup() {
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  printLcd("__  GARDUINO  __","",1000);


  Serial.begin(9600); // Open serial connection to report values to host
  pinMode(shsensor,INPUT);
  pinMode(stsensor,INPUT);
  pinMode(llsensor,INPUT);
  pinMode(ltsensor,INPUT);
}


void loop()
{
  readSensor();
  raspPrint();
  lcdPrint();
}

//-------------------------------------------------------------------------------------------

void printLcd(String p1,float p2, String p3,int t) {

  lcd.setCursor(0,0);
  lcd.print(p1);

  lcd.setCursor(0,1);
  lcd.print(p2);
  lcd.print(p3);

  usefullDelay (t);
}

void printLcd(String p1,String p2,int t) {

  lcd.setCursor(0,0);
  lcd.print(p1);

  lcd.setCursor(0,1);
  lcd.print(p2);

  usefullDelay (t);
}

void usefullDelay(int t){

for (int i = 0; i < t/1000; i++){
    readSensor();
    raspPrint();    
  }
  
  lcd.clear();

}

//-------------------------------------------------------------------------------------------
void readSensor()
{
  // Read values from the sensor
  a_temp = sht15.readTemperatureC();
  a_humi = sht15.readHumidity();
  s_temp = lm35_read();
  s_humi = ((1023 - analogRead(shsensor))/10.24);
  l_lumi = (analogRead(llsensor)/10.24);
  l_temp = lm335_read();
  ex_time = millis();
}

//-------------------------------------------------------------------------------------------
void lcdPrint()
{
  printLcd("||  GARDUINO  ||","",2500);
  printLcd("1_Temperatura =",      a_temp,"C",1500);
  printLcd("1_Umidade =",  a_humi,"%",1500);
  printLcd("2_Temperatura =",    s_temp,"C",1500);
  printLcd("2_Umidade =", s_humi,"%",1500);
  printLcd("3_Temperatura =",      l_temp,"C",1500);
  printLcd("3_Lux =",      l_lumi,"%",1500);

}
void raspPrint()
{
  Serial.println(a_temp);
  Serial.println(a_humi);
  Serial.println(s_temp);
  Serial.println(s_humi);
  Serial.println(l_temp);
  Serial.println(l_lumi);
  Serial.println(ex_time);


}
float lm335_read()
{
  float temp = (((analogRead(ltsensor)/10.24)*5.0)-268.30);

  b=(a+temp)/2;
  a=temp;

  return b;
}
float lm35_read()
{
  analogReference(INTERNAL);
  float temp = ((analogRead(stsensor))/9.31*5.0)+5;
  analogReference(DEFAULT);

  return temp;
}
