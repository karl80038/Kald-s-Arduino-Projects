//Code written by Karl-Erik Kald aka Karl80038
//Date: 02/05/2020
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {

for (int i = 0; i < 100; i++) 
{
      for (int i = 0; i < 12; i++)
    {
        if (i >= 0 & i < 8) 
        {
        digitalWrite(13, HIGH);
        delay(1000);
        }

        if (i >= 5 & i < 8)
        {
          digitalWrite(12, HIGH);
            delay(1000);
        }
        if (i >= 8)
        {
          digitalWrite(13, LOW);
            digitalWrite(12, LOW);
            digitalWrite(11, HIGH);
            delay(1000);
        }
    }
    
  for (int i = 0; i < 3; i++)  
  {
        
     digitalWrite(11, HIGH);
     delay(500);
     digitalWrite(11, LOW);
     delay(500);
  }
    digitalWrite(12, HIGH);
    delay(1000);
    digitalWrite(12, LOW);
    
}
// !!!OLD CODE!!!
// put your main code here, to run repeatedly:
//  digitalWrite(13, HIGH); //Activate output 13
//  delay(10000);           // Wait for 10000 millisecond(s)
//  digitalWrite(12, HIGH); //Activate output 12
//  delay(3000); // Wait for 3000 millisecond(s)
//  digitalWrite(13, LOW);  // Deactivate output 13
//  digitalWrite(12, LOW);  // Deactivate output 12
// // Wait for 1000 millisecond(s)
//  digitalWrite(11, HIGH); // Activate output 11
//  delay(10000);           // Wait for 10000 millisecond(s)
//  digitalWrite(11, LOW);
//  delay(500);
//  digitalWrite(11, HIGH);
//  delay(500);
//  digitalWrite(11, LOW);
//  delay(500);
//  digitalWrite(11, HIGH);
//  delay(500);
//  digitalWrite(11, LOW);
//  delay(500);
//  digitalWrite(11, HIGH);
//  delay(500);
//  digitalWrite(11, LOW);
//  digitalWrite(12, HIGH);
//  delay(5000);
//  digitalWrite(12, LOW);
}
