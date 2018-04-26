#include <Servo.h>
Servo myServo;  int pos;
int SensVal; int SensValTwo;
String sensorOne = "Sensor one: "; String sensorTwo = "Sensor Two: ";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(9);
}

void loop() {
  //declared functions
  mUpdateValues();
  detectLocation();
  setTozero();
}


//function to aid in location of sun
int detectLocation() {
  //create a loop to detect movement of the sun at time t
  for (pos; SensVal > SensValTwo; pos += 1) {
    myServo.write(pos);
    delay(15);
    mUpdateValues();
  }

}

//private function for updating analog read A0 and A1
int mUpdateValues() {
  SensVal = analogRead(A0);
  SensValTwo = analogRead(A1);
  return (SensVal, SensValTwo);
}
void setTozero() {
  while (pos > 1) {
    pos -= 1;
  }
}

