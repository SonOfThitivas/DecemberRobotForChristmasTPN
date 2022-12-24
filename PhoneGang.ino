#include <Wire.h>
#include <Servo.h>
#define IN1left 5
#define IN2left 4
#define IN1right 3
#define IN2right 2
int irfr = A5, irfl = A1, irbr = A4, irbl = A0;
int vfr = 0, vfl = 0, vbr = 0, vbl = 0;
//Servo myservo;
/////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IN1left, OUTPUT);
  pinMode(IN2left, OUTPUT);
  pinMode(IN1right, OUTPUT);
  pinMode(IN2right, OUTPUT);
//  myservo.attach(7);
}

void loop() {
  // put your main code here, to run repeatedly:
  //myservo.write(150);
  go();
  right(); delay(1500);
}
/////////////////////////////////////////////
void go() {
  while (true) {
    vfr = analogRead(irfr);
    vfl = analogRead(irfl);
    vbr = analogRead(irbr);
    vbl = analogRead(irbl);            
    Serial.print("FrontRight = " ); Serial.print(vfr);
    Serial.print(" FrontLeft = " ); Serial.print(vfl);
    Serial.print(" BackRight = " ); Serial.print(vbr);
    Serial.print(" BackLeft = " ); Serial.println(vbl);

    if ((vfr > 500) || (vfl < 1023)) {
      forward();
    } else if ((vfr > 0) || (vfl < 500)) {
      _stop();
      delay(1000);
      backward();
      delay(1500);
      break;
    }
  }
}

//Define-Function
void forward()  //1
{
  //leftfrontwheel
  digitalWrite(IN1left, 128);
  digitalWrite(IN2left, LOW);
  //leftbackwheel
  digitalWrite(IN1right, 128);
  digitalWrite(IN2right, LOW);
}

void backward() //2
{
  //leftfrontwheel
  digitalWrite(IN1left, LOW);
  digitalWrite(IN2left, 128);
  //leftbackwheel
  digitalWrite(IN1right, LOW);
  digitalWrite(IN2right, 128);
}

void right() //4
{
  //leftfrontwheel
  digitalWrite(IN1left, LOW);
  digitalWrite(IN2left, 128);
  //leftbackwheel
  digitalWrite(IN1right, 128);
  digitalWrite(IN2right, LOW);
}

void left() //3
{
  //leftfrontwheel
  digitalWrite(IN1left, 128);
  digitalWrite(IN2left, LOW);
  //leftbackwheel 
  digitalWrite(IN1right, LOW);
  digitalWrite(IN2right, 128);
}

void _stop() //0
{
  //leftfrontwheel
  digitalWrite(IN1left, LOW);
  digitalWrite(IN2left, LOW);
  //leftbackwheel
  digitalWrite(IN1right, LOW);
  digitalWrite(IN2right, LOW);
}
