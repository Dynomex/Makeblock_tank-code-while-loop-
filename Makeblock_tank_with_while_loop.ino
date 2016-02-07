#include <Makeblock.h>
#include <SoftwareSerial.h>
#include <Wire.h>

MeUltrasonicSensor ultraSensor3(PORT_3);
MeDCMotor dcMotor1_m(M1);
MeDCMotor dcMotor2_m(M2);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  double dist = ultraSensor3.distanceCm(); //reads sensor
  while ( dist < 35 ) // loops until distance equals 35 or more
  {
    dcMotor1_m.run(200);
    dcMotor2_m.run(200); //makes turn left
    delay(10); //delays for ten milliseconds
    dist = ultraSensor3.distanceCm(); //reads sensor again
    
  }
 
    dcMotor1_m.run(50);
    dcMotor2_m.run(-50); //makes go forward 
    delay(10); //delays for ten milliseconds
  
  
  }
