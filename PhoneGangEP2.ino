void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:#include <Wire.h>
#include <Servo.h>
#define IN1left 5
#define IN2left 4
#define IN1right 3
#define IN2right 2
int irfr = A5, irfl = A1, irbr = A4, irbl = A0;
int vfr = 0, vfl = 0, vbr = 0, vbl = 0;
Servo myservo;
/////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(IN1left, OUTPUT);
  pinMode(IN2left, OUTPUT);
  pinMode(IN1right, OUTPUT);
  pinMode(IN2right, OUTPUT);
  myservo.attach(7);
  myservo.write(180);
}

void loop() 
// 1
  forward(); delay(3000); //3 วินาที
  _stop();
// 2
  right(); delay(500);
  _stop();
  forward(); delay(2000); //2 วินาที
  _stop();
// 3
  right(); delay(500);
  _stop();
  forward(); delay(1000); //1 วินาที
  _stop();
// 4
  right(); delay(500);
  _stop();
  forward(); delay(1000); //1 วินาที
  _stop();
// 5
  left(); delay(500);
  _stop();
  forward(); delay(3000); //3 วินาที
  _stop();
  myservo.write(180); delay(500);
  myservo.write(85); delay(500);
// 6
  backward(); delay(1000);
  _stop();
// 7 
  left(); delay(500);
  _stop();
  forward(); delay(5000); //5 วินาที
  _stop();
// 8
  right(); delay(500);
  _stop();
  forward(); delay(1000); //1 วินาที
  _stop();
  right(); delay(500);
  _stop();
  forward(); delay(3000); //3 วินาที
  _stop();
  myservo.write(180); delay(500);
  myservo.write(85); delay(500);
// 9
  bakcward(); delay(3000); //3 วินาที
  _stop();
// 10
  left(); delay(500);
  _stop();
  forward(); delay(3000); //3 วินาท
// 11
  right(); delay(500);
  _stop();
  forward(); delay(2000); //2 วินาที
  _stop();
// 12
  backward(); delay(2000); //2 วินาที
  _stop();
// 13
  left(); delay(500);
  _stop();
  forward(); delay(1000); //1 วินาที
  _stop();
// 14
  left(); delay(500);
  _stop():
  forward(); delay(1000); //1 วินาที
  _stop();
// 15
  left(); delay(500);
  _stop();
  forward(); delay(1000); //1 วินาที
  _stop();
// 16
  left(); delay(500);
  _stop();
  forward(); delay(1000); //1 วินาที
  _stop();
  myservo.write(180); delay(500);
  myservo.write(85); delay(500);
// 17
  backward(); delay(1000); //1 วินาที
  _stop();
// 18
  left(); delay(500);
  _stop();  
  forward(); delay(3000); //3 วินาที
  _stop();
  myservo.write(180); delay(500);
  myservo.write(85); delay(500);
// 19
  backward(); delay(1000); //1 วินาที
  _stop();
// 20
  right(); delay(500);
  _stop();
  forward(); delay(1000); //1 วินาที
  _stop();
// 21
  forward(); delay(1000); //1 วินาที
  _stop();
// 22
  right(); delay(500); //5 ;bokmu
  _stop();
  forward(); delay(1000); //1 วินาที
  _stop();
// 23
  left(); delay(500);
  _stop():
  forward(); delay(2000); //2 วินาที
  _stop();
// 24
  left(); delay(500);
  _stop():
  forward(); delay(1000); //1 วินาที
  _stop();
// 26
  right(); delay(500);
  _stop():
  forward(); delay(5000); //5 วินาที
  _stop(); 
// 27
  right(); delay(500);
  _stop();
  forward(); delay(1000); //1 วินาท
  _stop();
// 28
  right(); delay(500);
  _stop();
  forward(); delay(1000); // 1 วินาท
  _stop();
// 29
  left(); delay(500);
  _stop();
  forward(); delay(1000); 1 วินาที
  _stop();
// 30
  left(); delay(500);
  _stop();
  forward(); delay(3000); 3 วินาที
  _stop();
// 31
  left(); delay(500);
  _stop();
  forward(); delay(4000); 4 วินาที
  _stop();
}
/////////////////////////////////////////////
//Define-Function
void forward()  //1
{
  //leftfrontwheel
  digitalWrite(IN1left, HIGH);
  digitalWrite(IN2left, LOW);
  //leftbackwheel
  digitalWrite(IN1right, HIGH);
  digitalWrite(IN2right, LOW);
}

void backward() //2
{
  //leftfrontwheel
  digitalWrite(IN1left, LOW);
  digitalWrite(IN2left, HIGH);
  //leftbackwheel
  digitalWrite(IN1right, LOW);
  digitalWrite(IN2right, HIGH);
}

void right() //4
{
  //leftfrontwheel
  digitalWrite(IN1left, LOW);
  digitalWrite(IN2left, HIGH);
  //leftbackwheel
  digitalWrite(IN1right, HIGH);
  digitalWrite(IN2right, LOW);
}

void left() //3
{
  //leftfrontwheel
  digitalWrite(IN1left, HIGH);
  digitalWrite(IN2left, LOW);
  //leftbackwheel 
  digitalWrite(IN1right, LOW);
  digitalWrite(IN2right, HIGH);
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

}
