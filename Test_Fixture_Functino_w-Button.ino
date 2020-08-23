#include <Servo.h>

Servo s8;  // create servo object to control a servo

int pos8 = 0;    // variable to store the servo position
int buttonPin = 4;          //  buttonPin set to pin 4
int oldButtonState = 0;
int newButtonState;

float calibration_factor = -92070; // Load Cell Calibration Factor -10000 For 100g - 1000g
#define DOUT  3
#define CLK  2

void setup() {
  Serial.begin(9600);
  s8.attach(8);          // attaches the servo on pin 8 to the servo object
  s8.writeMicroseconds(1500);              // tell servo to go to position in variable 'pos'
  pinMode(buttonPin,INPUT);          // set the internal pull up resistor, unpressed button is HIGH
}

void loop()
{
  newButtonState = digitalRead(buttonPin);          // reads the digital state of buttonPin with digitalRead() function and stores the variable state

    Serial.println(newButtonState);
    delay(150);
  
  if(oldButtonState == 0 && newButtonState != oldButtonState){
    s8.write(0);
    for (pos8 = 0; pos8 <= 180; pos8 += 1) // goes from 0 degrees to 180 degrees
    {
      s8.write(pos8);                 // in steps of 1 degree
      delay(15);                    // waits 15ms for the servo to reach the position
    }
    for (pos8 = 180; pos8 >= 0; pos8 -= 1) // goes from 180 degrees to 0 degrees
    {
       s8.write(pos8);              // tell servo to go to position in variable 'pos'
       delay(15);                   // waits 15ms for the servo to reach the position
    }

    oldButtonState = 0;

  }
  else{
    s8.write(10);
    oldButtonState = newButtonState;
    delay(100);
  }
}
