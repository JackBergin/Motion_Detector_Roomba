/*
Name:
Date:
Class: WPI 1.0
Description: Makes the robot mirrior the tendencies of 
a roomba with a motion sensor infront of it to avoid wall 
collisions.
*/

#include <SoftwareSerial.h>

//int LED=13;
volatile int state = LOW;
char getstr;
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int ENA = 5;
int ENB = 11;
int ABS = 135;

void setup()
{
  //For the car motors
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ENA, HIGH);
  pinMode(ENB, HIGH);

  //For the motion detectors
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int motion = digitalRead(2);
  getstr = Serial.read();

  //Uses bluetooth to turn the car on and off like a roomba
  if (getstr = 'o')
  {
    if (motion)
    {
      Serial.println("Motion Detected");
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH); //Reverse left wheels
      digitalWrite(in3, HIGH); //Reverse right wheels
      digitalWrite(in4, LOW);
      Serial.println("Back");
      delay(100);

      digitalWrite(in1, HIGH); //Forward on left wheels
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH); //Backward on right wheels
      digitalWrite(in4, LOW);
      Serial.println("Left");
      delay(100);
    }
    else
    {
      Serial.println("---No Motion Detected---");
      digitalWrite(in1, HIGH); //Left wheels
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH); //Right wheels
      Serial.println("Forward");
    }
  }

  if (getstr = 'f')
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    Serial.println("Stop");
  }
  //delay(100);
}
