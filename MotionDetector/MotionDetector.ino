void setup() 
{
   pinMode(2, INPUT);
   pinMode(13, OUTPUT);
   Serial.begin(9600);
}

void loop() 
{
   int motion = digitalRead(2);
   if (motion)
   {
       Serial.println("Motion Detected");
       digitalWrite(12, HIGH);
       delay(100);
   }
   else
   {
       Serial.println("---No Motion Detected---");
       digitalWrite(12, LOW);
   }
   //delay(100);
}
