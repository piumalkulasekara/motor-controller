#include <SoftwareSerial.h> 
/*Car setups*/
//M1
int in1 = 3;//8;
int in2 = 4;//9;

//M2
int in3 = 6;//10;
int in4 = 7;//11;

SoftwareSerial BTserial(15, 14); // initilizing the RX | TX


void setup()
{
 Serial.begin(9600);
  BTserial.begin(9600); //start the bluetooth connection
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}
/*
   mpower(motor number,rotation,speed);

  motor number
  1-1st motor
  2-2nd motor

  rotation
  1-Forword
  0-Stop
  -1- Backword

  speed
  0-255 PWM value

*/
void mpower(int motor, int rotation, int spd)
{
  int pwm;
  int pA;
  int pB;
  if (motor == 1)
  {
    pA = in1;
    pB = in2;
  }
  else if (motor == 2)
  {
    pA = in3;
    pB = in4;
  }
  else
  {
    return;
  }

  if (rotation == 0)
  {
    digitalWrite(pA, LOW);
    digitalWrite(pB, LOW);
  }
  else if (rotation == 1)
  {
    digitalWrite(pA, HIGH);
    digitalWrite(pB, LOW);
  }
  else if (rotation == -1)
  {
    digitalWrite(pA, LOW);
    digitalWrite(pB, HIGH);
  }
  analogWrite(pwm, spd);

}
void forwardMotors()
{
  mpower(1, -1, 255);
  mpower(2, -1, 255);

}

void reversMotors()
{
  mpower(1, 1, 255);
  mpower(2, 1, 255);
}

void turnLeft()
{
  mpower(1, 0, 0);
  mpower(2, 1, 255);
}

void turnRight()
{
  mpower(1, 1, 255);
  mpower(2, 0, 0);
}

void breakMotors()
{
  mpower(1, 0, 0);
  mpower(2, 0, 0);
}

void loop()
{
// Look for new cards (This Method is only to detect a tag)
  if ( check_rfid_tag_availability)
  {
    /*
      *Here the code to control car 
      */
    if (Serial.available() > 0)
    {
      data = Serial.read();


