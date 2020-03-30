int sensorPin = 0;    				  

int ledred1 = 13; //red     
int ledyellow1 = 12; //yellow
int ledgreen1 = 11;//green
int ledred2 = 9;//red
int ledyellow2 = 10;//yellow
int ledgreen2 = 7;//green
int ledred3 = 5;//red
int ledyellow3 = 8;//yellow
int ledyellow4 = 6;//green

int sensorValue = 0;  
int Value_new;
int Value_new2;
int randomNum;
void red()
{
  digitalWrite(ledred1, HIGH); 
  digitalWrite(ledred2, HIGH); 
  digitalWrite(ledred3, HIGH); 
  delay(200);                 
  digitalWrite(ledred1, LOW);
  digitalWrite(ledred2, LOW); 
  digitalWrite(ledred3, LOW); 
  delay(200);         
}
void yellow()
{
  digitalWrite(ledyellow1, HIGH); 
  digitalWrite(ledyellow2, HIGH); 
  digitalWrite(ledyellow3, HIGH); 
  digitalWrite(ledyellow4, HIGH); 

  delay(200);                 
  digitalWrite(ledyellow1, LOW);
  digitalWrite(ledyellow2, LOW); 
  digitalWrite(ledyellow3, LOW);
  digitalWrite(ledyellow4, LOW); 
  delay(200);         
}
void green()
{
  digitalWrite(ledgreen1, HIGH); 
  digitalWrite(ledgreen2, HIGH); 
  delay(200);                 
  digitalWrite(ledgreen1, LOW);
  digitalWrite(ledgreen2, LOW); 
  delay(200);         
}

void blink_All()
{
  digitalWrite(ledgreen1, HIGH); 
  digitalWrite(ledgreen2, HIGH); 
  digitalWrite(ledyellow1, HIGH); 
  digitalWrite(ledyellow2, HIGH); 
  digitalWrite(ledyellow3, HIGH); 
  digitalWrite(ledyellow4, HIGH); 
  digitalWrite(ledred1, HIGH); 
  digitalWrite(ledred2, HIGH); 
  digitalWrite(ledred3, HIGH);
  delay(200);
  digitalWrite(ledgreen1, LOW); 
  digitalWrite(ledgreen2, LOW); 
  digitalWrite(ledyellow1, LOW); 
  digitalWrite(ledyellow2, LOW); 
  digitalWrite(ledyellow3, LOW); 
  digitalWrite(ledyellow4, LOW); 
  digitalWrite(ledred1, LOW); 
  digitalWrite(ledred2, LOW); 
  digitalWrite(ledred3, LOW);
  delay(200);

}

void blink_one_color_group()
{
	for (int i = 0; i < 36; i++)
    {
      
		
    	if (i>= 1 & i < 10)
        {
        	  	digitalWrite(ledred1, HIGH); 
  			  	digitalWrite(ledred2, HIGH); 
              	digitalWrite(ledred3, HIGH);
              	digitalWrite(ledyellow1, LOW);
  				digitalWrite(ledyellow2, LOW); 
  				digitalWrite(ledyellow3, LOW); 
  				digitalWrite(ledyellow4, LOW);
          		delay(500);
        }
      	else if (i>= 10 & i < 20)
        {
        	    digitalWrite(ledred1, LOW); 
  			  	digitalWrite(ledred2, LOW); 
              	digitalWrite(ledred3, LOW);
              	digitalWrite(ledyellow1, HIGH);
  				digitalWrite(ledyellow2, HIGH); 
  				digitalWrite(ledyellow3, HIGH); 
  				digitalWrite(ledyellow4, HIGH);
          		digitalWrite(ledgreen1, LOW);
          		digitalWrite(ledgreen2, LOW);
          		delay(500);
        }
      	else if (i>= 20 & i < 28)
        {
        		digitalWrite(ledyellow1, LOW);
  				digitalWrite(ledyellow2, LOW); 
  				digitalWrite(ledyellow3, LOW); 
  				digitalWrite(ledyellow4, LOW);
          		digitalWrite(ledgreen1, HIGH);
          		digitalWrite(ledgreen2, HIGH);
          		delay(500);
          		
        }
      	else if (i>= 28 & i < 30)
        {
        	    digitalWrite(ledgreen1, LOW);
          		digitalWrite(ledgreen2, LOW);
          		delay(400);
          		digitalWrite(ledgreen1, HIGH);
          		digitalWrite(ledgreen2, HIGH);
          		delay(400);
          		digitalWrite(ledgreen1, LOW);
          		digitalWrite(ledgreen2, LOW);
          		delay(400);
          		digitalWrite(ledgreen1, HIGH);
          		digitalWrite(ledgreen2, HIGH);
          		delay(400);
          		digitalWrite(ledgreen1, LOW);
          		digitalWrite(ledgreen2, LOW);
        }  
     	else if (i>= 30 & i < 36)
        {
        	    digitalWrite(ledred1, LOW); 
  			  	digitalWrite(ledred2, LOW); 
              	digitalWrite(ledred3, LOW);
              	digitalWrite(ledyellow1, HIGH);
  				digitalWrite(ledyellow2, HIGH); 
  				digitalWrite(ledyellow3, HIGH); 
  				digitalWrite(ledyellow4, HIGH);
          		digitalWrite(ledgreen1, LOW);
          		digitalWrite(ledgreen2, LOW);
          		delay(500);
        }
      	else 
      	{
      		    digitalWrite(ledred1, LOW);
  				digitalWrite(ledred2, LOW); 
  				digitalWrite(ledred3, LOW);
        		digitalWrite(ledgreen1, LOW);
        		digitalWrite(ledgreen2, LOW);
          		delay(500);
      	}
    } 
}

void blink_one_random_color_group()
{
  
	randomNum = random(6);
  	Serial.print(randomNum);
  	digitalWrite(ledred1, LOW);
  	digitalWrite(ledred2, LOW); 
  	digitalWrite(ledred3, LOW); 
    digitalWrite(ledyellow1, LOW);
  	digitalWrite(ledyellow2, LOW); 
  	digitalWrite(ledyellow3, LOW);
    digitalWrite(ledyellow4, LOW);
  	digitalWrite(ledgreen1, LOW);
 	digitalWrite(ledgreen2, LOW);
  	if (randomNum == 3)
    {
   		digitalWrite(ledred1, HIGH);
  		digitalWrite(ledred2, HIGH); 
  		digitalWrite(ledred3, HIGH);
      	delay(500);

    }
  	else if (randomNum == 4)
    {
		digitalWrite(ledyellow1, HIGH);
  		digitalWrite(ledyellow2, HIGH); 
  		digitalWrite(ledyellow3, HIGH);
    	digitalWrite(ledyellow4, HIGH);
      	delay(500);

    } 
  	else if (randomNum == 5)
    {
    	digitalWrite(ledgreen1, HIGH);
 	   	digitalWrite(ledgreen2, HIGH);
        delay(500);

    }
  	
	delay(500);
}


void setup() 
{         
  pinMode(ledred1,OUTPUT);
  pinMode(ledred2,OUTPUT);
  pinMode(ledred3,OUTPUT);
  pinMode(ledyellow1,OUTPUT);
  pinMode(ledyellow2,OUTPUT);
  pinMode(ledyellow3,OUTPUT);
  pinMode(ledgreen1,OUTPUT);
  pinMode(ledgreen2,OUTPUT);
  pinMode(ledyellow4,OUTPUT); 
}

void loop() 
{          
  Value_new = analogRead(sensorPin);
  Serial.print(Value_new);

  Value_new2=map(Value_new,0,1023,0,5);
  
  if (Value_new2 == 0)
  {
    red();
  }
  else if(Value_new2 == 1)
  {
    yellow();
  }
  else if (Value_new2 == 2)
  {
    green();
  }
  else if (Value_new2 == 3)
  {
  	blink_All();
  }
  else if (Value_new2 == 4)
  {
  	blink_one_color_group();
  }
  else if (Value_new2 == 5)
  {
  	blink_one_random_color_group();
  }  
  else
  {
    digitalWrite(ledred1, LOW);
  	digitalWrite(ledred2, LOW); 
  	digitalWrite(ledred3, LOW); 
    digitalWrite(ledyellow1, LOW);
  	digitalWrite(ledyellow2, LOW); 
  	digitalWrite(ledyellow3, LOW);
    digitalWrite(ledyellow4, LOW); 

  }
    
}