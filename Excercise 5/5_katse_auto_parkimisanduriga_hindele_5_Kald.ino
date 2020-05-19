#define ECHO_PIN 8

#define TRIG_PIN 7

int motor1Pin1 = 3; // vasakpoolne viik 2 (L293D)

int motor1Pin2 = 4; // vasakpoolne viik 7 (L293D) 

int motor2Pin1 = 5; // parempoolne viik 7 (L293D) 

int motor2Pin2 = 6; // parempoolne viik 2 (L293D) 

int enablePin1 = 9; // vasakpoolne viik 1(L293D)

int enablePin2 = 10; // parempoolne viik 8(L293D)

int driveSpeed = 255;

int tempo = 30;

const int buzzerPin = 11;

void setup()
{
 
 	// sisendid 
  
   	pinMode(ECHO_PIN, INPUT);

 	//väljundid 

 	pinMode(motor1Pin1, OUTPUT); 

 	pinMode(motor1Pin2, OUTPUT); 
  
   	pinMode(motor2Pin1, OUTPUT); 
  
   	pinMode(motor2Pin2, OUTPUT); 

 	pinMode(enablePin1, OUTPUT); 
  
   	pinMode(enablePin2, OUTPUT); 
  
  	pinMode(buzzerPin, OUTPUT);
  
    pinMode(TRIG_PIN, OUTPUT);

 	// aktiveeri mootor 1 

 	digitalWrite(enablePin1, HIGH); 
    
  	// aktiveeri mootor 2
  
   	digitalWrite(enablePin2, HIGH); 
  
  	Serial.begin(960);

}

void loop()
{
  	int prevMeasurement;
  	int newMeasurement;
  	int speedTarget;
  	newMeasurement = measure();

  	Serial.println(newMeasurement);
        
	
  	if (newMeasurement > prevMeasurement)
    {

		driveSpeed = prevMeasurement - newMeasurement;

    }
  
  	if (newMeasurement < prevMeasurement)
    {

      	driveSpeed = prevMeasurement + newMeasurement;
      
    }
  
      if (newMeasurement > 5 )
      {
      	tone(buzzerPin,1000);
     	delay(50);
   	 	noTone(buzzerPin);
     	delay(newMeasurement*5);
 		delay(100); 
      }
  
  	if (newMeasurement <= 5 & newMeasurement > 0)
    {
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
      tone(buzzerPin,1000);
      
    }

  	prevMeasurement = newMeasurement;
  	Serial.println(driveSpeed);

  	digitalWrite(motor1Pin1, HIGH);
  	digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
  	digitalWrite(motor2Pin2, HIGH);
  	analogWrite(enablePin1, driveSpeed);
  	analogWrite(enablePin2, driveSpeed);
  
}

int measure()
{
	digitalWrite(TRIG_PIN, HIGH);
  	digitalWrite(TRIG_PIN, LOW);
  
  	int distance = pulseIn(ECHO_PIN, HIGH, 15000)/50;
  	
  	return constrain(distance, 0 ,250);
}


