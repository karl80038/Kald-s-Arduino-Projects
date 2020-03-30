const int sensorPin = 0;
const int potPin = 1;

const int ledPin = 9;

const int button1Pin = 2; 

int lightLevel, high = 0, low = 1023;  // создадим глобальные переменные для уровней яркости high (высокий), low (низкий):
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers
int state = HIGH;      // the current state of the output pin
int previous = LOW;    // the previous reading from the input pin
bool lightState = false;

int potValue;
void setup()

{

  pinMode(ledPin, OUTPUT);
  pinMode(button1Pin, INPUT);

  Serial.begin(9600); // //Serial monitori seadistamine (для отладки, чтобы увидеть показания датчиков)

}

void loop()

{

    potValue = analogRead(potPin);

  if (potValue > 0)
  {
    
 	lightLevel = analogRead(sensorPin); //loeme mõõdetud analoogväärtuse
	
  	autoTune();


   	analogWrite(ledPin, lightLevel);


  	Serial.print(lightLevel);     // prindime tulemused Serial Monitori (вывод данных с фоторезистора (0-1023))

  	Serial.println(""); 
    
    
    
   }
  else
  {
    analogWrite(ledPin, 0);


  }


  
 


}

void manualTune()

{

  lightLevel = map(lightLevel, 300, 800, 0, 255); // kaardistame selle analoogväljundi vahemikku (будет от 300 темно, до 800 (светло)). 

  lightLevel = constrain(lightLevel, 0, 255);

} 



void autoTune()

{

   if (lightLevel < low)   // если уровень "lightLevel" меньше 1023, то присвоим

  {                      

    low = lightLevel;     // теперь самым "низким" ~ 800

  }

  if (lightLevel > high)

  {

    high = lightLevel;

  }

  lightLevel = map(lightLevel, low+0, high-30, 0, 255);

  lightLevel = constrain(lightLevel, 0, 255);

}