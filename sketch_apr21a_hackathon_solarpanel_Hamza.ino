/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  base code found here.
  
  Later,
  Modified April 2018
  by Hamza Memon to implement two servos 
  and photoresistors for control
  
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int sensorValue1;
int sensorValue2;
//int pos = 0;    // variable to store the servo position
int pos;
void setup() {
  myservo.attach(9);
  Serial.begin(9600);// attaches the servo on pin 9 to the servo object
}

void loop() {
  
  sensorValue1 = analogRead(A0);
  sensorValue2 = analogRead(A1);
  // print out the value you read:
  Serial.println("1");
  Serial.println(sensorValue1);
  Serial.println("2");
  Serial.println(sensorValue2);
  int check = 1;
  static int counter = 1;
  static int counter2 = 1;
  while (check)
  {
    if (sensorValue1 < sensorValue2 && sensorValue2 > 100) {
     // pos = 0;
      counter2 = 1;
      if (counter == 2) {
        pos = 180;
        myservo.write(pos);
        check = 0;
      }
      for (pos; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        mUpdateValues();

        if (sensorValue1 > sensorValue2) {
          //check = 0;
          break;

        }
        if (pos == 180) {
          counter = 2;
        }
        //      Serial.println("Breaking");
        //      break;
        myservo.write(pos);
        delay(15);
        //mUpdateValues();
      }
    }

    if (sensorValue1 > sensorValue2 && sensorValue1 > 100) {
      //pos = 180;
      counter = 1;
      if (counter2 == 2) {
        pos = 0;
        myservo.write(pos);
        check = 0;
      }
      for (pos ; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        mUpdateValues();
        if (sensorValue1 < sensorValue2) {
          //check = 0;
          break;
        }

        if (pos == 0) {
          counter2 = 2;
        }
        myservo.write(pos);
        delay(15);  // waits 15ms for the servo to reach the position
        mUpdateValues(); 
        }
      //pos = 180;
    }
    check = 0 ;
  }
}
int mUpdateValues(){
  sensorValue1 = analogRead(A0);
  sensorValue2 = analogRead(A1);
}




