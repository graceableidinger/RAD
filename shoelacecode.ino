#include <Vex.h>
Vex Seesaw;
Adafruit_DCMotor *motorA = Seesaw.setMotor(1);
Adafruit_DCMotor *motorB = Seesaw.setMotor(2);
Adafruit_DCMotor *motorC = Seesaw.setMotor(3);
Adafruit_DCMotor *motorD = Seesaw.setMotor(4);

void setup() {
  Seesaw.begin();
}
void shoetie(){
  Seesaw.moveMotor(motorD, 20, 3);
  delay(1000);
  Seesaw.moveMotor(motorB, -20, 3);
  delay(1000);
  Seesaw.moveMotor(motorC, -14, 2);
  Seesaw.moveMotor(motorA, -12, 2);
  delay(1000);
  Seesaw.moveMotor(motorD, -20, 3);
  delay(1000);
  Seesaw.moveMotor(motorB, 20, 3);
  delay(1000);
  Seesaw.moveMotor(motorC, 12, 2);
  Seesaw.moveMotor(motorA, 10, 2);
  Seesaw.moveMotor(motorD, -20, 3);
  delay(1000);
  Seesaw.moveMotor(motorB, 20, 3);
  delay(1000);
}
void reset(){
    Seesaw.moveMotor(motorC, -10, 1);
    Seesaw.moveMotor(motorA, -10, 1);
}
void loop() {
  shoetie();
  //reset();
  Seesaw.end();
}
