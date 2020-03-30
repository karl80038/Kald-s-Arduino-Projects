//Antud koodis on vaja kasutada LiquidCrystal.h ja Servo.h teeke
#include <LiquidCrystal.h>
#include  <Servo.h>

const int tempPin = 0;
LiquidCrystal lcd(12,11,5,4,3,2);
byte customChar[8] = {
	0b01110,
	0b01010,
	0b01110,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};
byte customChar2[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b11111,
	0b01110,
	0b00100,
	0b00000
};
byte customChar3[8] = {
	0b00000,
	0b00000,
	0b01000,
	0b01100,
	0b01110,
	0b01100,
	0b01000,
	0b00000
};
//Säilitame sellesse muutujasse servomootori praeguse asendi
int servoAngleTemp = 0;
int servoAngle = 0;
//Loome Servomootori jaoks uue objekti nimega servo1
Servo servo1; 


void setup()
{
  	//"Teavitame" servomuutujat, et servomootor on ühendatud pin 9-ga
	servo1.attach(9);
    lcd.createChar(0, customChar);
    lcd.createChar(1, customChar2);
    lcd.createChar(2, customChar3);
  	lcd.begin(16,2);

}

void loop()
{
  	//Temperatuuriandur annab meile pingeväärtuse
	float voltage, degreesC, degreesF;
  
  	voltage = getVoltage(tempPin);
  
  	//Teisendame pinge Celsiuseks
	degreesC = (voltage - 0.5) * 100.0;
  
  	//Teisendame pinge Fahrenheit'i
  	degreesF = degreesC * (9.0/5.0) + 32.0;
  
	//Loeme servoanduri praeguse nurga ja salvestame ta muutujasse
  
  	//Kirjutame LCD-ekraanile väärtused

  	lcd.setCursor(0, 0);
    lcd.write((uint8_t)0);
  	lcd.print("C/F");
    lcd.write((uint8_t)1);
  	lcd.print(" Ang");
    lcd.write((uint8_t)2);
    lcd.print(servoAngle);
    lcd.write((uint8_t)0);
    lcd.setCursor(0, 1);
    lcd.print(degreesC);
  	lcd.print("/");
  	lcd.print(degreesF);

  	/*Servomootori nurka saab muuta, kui kirjutame tema muutujasse
  	  uue väärtuse, kasutades selleks servoobjekt.write(väärtus)*/
  
	if (degreesC > 0 & degreesC < 10 & servoAngle != 30)
    { 
      //if (servoAngle < 30)
      //{
    	for (int position = 0; position < 31; position += 2)
        {
        	servo1.write(position);

            servoAngleTemp = position;
            delay(20);  
        }
    //}
 /*     if (servoAngle > 30) 
      {
      	for (int position = 0; position == 30; position --)
        {
        	servo1.write(position);
            servoAngle = position;
          	delay(20);
        }
      } */
    }
  	
  	if (degreesC >= 10 & degreesC < 20 & servoAngle != 60)
    {

    	for (int position = 0; position < 61; position += 2)
        {
        	servo1.write(position);
            servoAngleTemp = position;
          	delay(20);
        }
      
    }
  	
  	if (degreesC >= 20 & degreesC < 35 & servoAngle != 120)
    {
    	for (int position = 0; position < 121; position += 2)
        {
        	servo1.write(position);
            servoAngleTemp = position;
          	delay(20);
        }

    }
  	if (degreesC >= 35 & servoAngle != 180)
    {

        for (int position = 0; position == 181; position --)
        {
        	servo1.write(position);
            servoAngleTemp = position;
          	delay(20);
        }		
      
    }
	servoAngle = servoAngleTemp;
  	


}

float getVoltage(int pin)
{
	return (analogRead(pin) * 0.004882814);
}