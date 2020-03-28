#include <Servo.h>

Servo servoMotor;        //initialize a servo object for the connected servo

int angle = 0;
void setup() {
  servoMotor.attach(A2);
}


void loop() {
  for (angle = 0; angle < 180; angle += 1)   
  {
    servoMotor.write(angle);                
    delay(5
    y);
  }

  delay(1000);
  for (angle = 180; angle >= 1; angle -= 5) 
  {
    servoMotor.write(angle); 
    delay(5);
  }

  delay(1000);
}
