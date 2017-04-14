

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
//  pinMode(enA, OUTPUT);
//  pinMode(enB, OUTPUT);
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

void loop() {
for(int i=0;i<255;i++){
    mpower(1, 1, i); 
  mpower(2, 1, i); 
  delay(10);
  }

for(int i=255;i>-1;i--){
    mpower(1, 1, i); 
  mpower(2, 1, i); 
  delay(10);
  }
for(int i=0;i<255;i++){
    mpower(1, -1, i); 
  mpower(2, -1, i); 
  delay(10);
  }

for(int i=255;i>-1;i--){
    mpower(1, -1, i); 
  mpower(2, -1, i); 
  delay(10);
  }


}



