#include <Servo.h>

Servo s8;  // create servo object to control a servo

int pos8 = 0;    // variable to store the servo position
bool state = false;
char temp;

#define DOUT  3
#define CLK  2

void setup() {
  Serial.begin(9600);
  s8.attach(8);          // attaches the servo on pin 8 to the servo object
  s8.writeMicroseconds(1500);              // tell servo to go to position in variable 'pos'
}

void loop()
{
  if(Serial.available()){
    s8.write(0);
    temp = Serial.read();

    if(temp == '1'){

       state = true;
    }
    else if(temp == '0'){
      state = false;
      s8.write(0);
    }

    else;

  }

  if(state == true){
    Serial.println("Servo is on");

    for (pos8 = 0; pos8 <= 60; pos8 += 1) // goes from 0 degrees to 180 degrees
    {
      s8.write(pos8);                 // in steps of 1 degree
      delay(15);                    // waits 15ms for the servo to reach the position
    }
    for (pos8 = 60; pos8 >= 0; pos8 -= 1) // goes from 180 degrees to 0 degrees
    {
       s8.write(pos8);              // tell servo to go to position in variable 'pos'
       delay(15);                   // waits 15ms for the servo to reach the position
    }

  }
  else{
    Serial.println("Servo is off");
    delay(150);
  }

}
