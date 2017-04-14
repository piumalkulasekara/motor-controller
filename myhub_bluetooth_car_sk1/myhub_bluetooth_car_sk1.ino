#include <SoftwareSerial.h>

//M1
//int enA = 10;
int in1 = 3;
int in2 = 4;
//M2
//int enB = 5;
int in3 = 6;
int in4 = 7;


void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("STARTING...");
//  pinMode(enA, OUTPUT);
//  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(13, OUTPUT);
}
int x = 0;//input of pads via BT
int y = 0;//input of pads via BT

int m1d = 0; //Direction of Motor 1
int m1s = 0; //Speed of Motor 1

int m2d = 0; //Direction of Motor 2
int m2s = 0; //Speed of Motor 2
long ltime = millis();

void breakMotors()
{
  mpower(1, 0, 0);
  mpower(2, 0, 0);
}

void loop() {
  if (Serial.available()) {
    //X44Y66
    char c = Serial.read();
    Serial.println(c);
    if (c == 'X') 
    {
      x = Serial.parseInt();
    } else if (c == 'Y') 
    {
      y = Serial.parseInt();
    }

    digitalWrite(13, HIGH);
    m1s = map(y, -50, 50, -255, 255);
    m2s = map(y, -50, 50, -255, 255);



    int m1_bal = 0;
    int m2_bal = 0;

    if (x < -15) {
      m1_bal = map(x, -15, -50, 0, m1s * 2);
    } else if (x > 15) {
      m2_bal = map(x, 15, 50, 0, m2s * 2);
    }

    m1s -= m1_bal;
    m2s -= m2_bal;

    if (m1s < 0) {
      m1d = 1;
      m1s = m1s * -1;
    } else {
      m1d = -1;

    }
    if (m2s < 0) {
      m2d = 1;
      m2s = m2s * -1;
    } else {
      m2d = -1;

    }
    mpower(1, m1d, m1s + 40);
    mpower(2, m2d, m2s + 40);
    delay(80);


  
}else{
  breakMotors();

   
}
  
  



  m1s = 0;
  m2s = 0;
  m1d = 0;
  m2d = 0;
  mpower(1, 0, 0);
  mpower(2, 0, 0);
  digitalWrite(13, LOW);
  //Serial.println("0");
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

void mpower(int motor, int rotation, int spd) {
  int pwm;
  int pA;
  int pB;
  if (motor == 1) {
//    pwm = enA;
    pA = in1;
    pB = in2;
  } else if (motor == 2) {
//    pwm = enB;
    pA = in3;
    pB = in4;
  } else {
    return;
  }

  if (rotation == 0) {
    digitalWrite(pA, LOW);
    digitalWrite(pB, LOW);
  } else if (rotation == 1) {
    digitalWrite(pA, HIGH);
    digitalWrite(pB, LOW);
  } else if (rotation == -1) {
    digitalWrite(pA, LOW);
    digitalWrite(pB, HIGH);
  }
  analogWrite(pwm, spd);

}
