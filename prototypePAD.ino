#include <PS2X_lib.h>
#include <Wire.h>
//#include <Adafruit_PWMServoDriver.h>

// PS2 controller
PS2X ps2x; // create PS2 Controller Class
int error = 0; 
byte type = 0;
byte vibrate = 0;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//left motor wheels
#define IN1leftfront 5
#define IN2leftfront 4
#define IN3leftback 3
#define IN4leftback 2

//right motor wheels
#define IN1rightfront 9
#define IN2rightfront 8
#define IN3rightback 7
#define IN4rightback 6
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Servo
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN 125
#define SERVOMAX 575  //Try to find max and min angle servo
uint8_t servoBottom = 13, servoTop = 14, servoMouth = 15;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  // all about motor
  pinMode(IN1leftfront, OUTPUT);
  pinMode(IN2leftfront, OUTPUT);
  pinMode(IN3leftback, OUTPUT);
  pinMode(IN4leftback, OUTPUT);
  pinMode(IN1rightfront, OUTPUT);
  pinMode(IN2rightfront, OUTPUT);
  pinMode(IN3rightback, OUTPUT);
  pinMode(IN4rightback, OUTPUT);
  _stop();
  // Servo
  //pwm.begin();
  //pwm.setPWMFreq(60);
  //yield();
  Serial.setTimeout(1);

  // PS2 CONTROLLER DETRECTION ZONE////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  error = ps2x.config_gamepad(13,11,10,12, true, true);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error

   // Check for error
   if(error == 0){
    Serial.println("Found Controller, configured successful");
   }
     
   else if(error == 1)
    Serial.println("No controller found, check wiring or reset the Arduino");
     
   else if(error == 2)
    Serial.println("Controller found but not accepting commands");
    
   else if(error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it.");
     
   // Check for the type of controller
   type = ps2x.readType();
   switch(type) {
    case 0:
      Serial.println("Unknown Controller type");
      break;
    case 1:
      Serial.println("DualShock Controller Found");
      break;
    case 2:
      Serial.println("GuitarHero Controller Found");
      break;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  // put your main code here, to run repeatedly:
   if(error == 1) //skip loop if no controller found
      return; 
    
   else { //DualShock Controller
    
      ps2x.read_gamepad(false, vibrate); // disable vibration of the controller
  
       // Perform movements based on D-pad buttons
       
       // MOVE FORWARD
       if(ps2x.Button(PSB_PAD_UP)) {
          forward();
          Serial.println("Move forward");
        }
        // TURN RIGHT
        if(ps2x.Button(PSB_PAD_RIGHT)){
          right();
          Serial.println("Turn right");
        }
        // TURN LEFT
        if(ps2x.Button(PSB_PAD_LEFT)){
          left();
          Serial.println("Turn left");
        }
        // MOVE BACK
        if(ps2x.Button(PSB_PAD_DOWN)){
          backward();         
          Serial.println("Move back");
        }  
        if (!ps2x.Button(PSB_PAD_DOWN) && !ps2x.Button(PSB_PAD_UP) && !ps2x.Button(PSB_PAD_RIGHT) && !ps2x.Button(PSB_PAD_LEFT)) {
          _stop();
        }
            
   delay(50);
   }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Define-Function
void forward()  //1
{
  //leftfrontwheel
  digitalWrite(IN1leftfront, HIGH);
  digitalWrite(IN2leftfront, LOW);
  //leftbackwheel
  digitalWrite(IN3leftback, HIGH);
  digitalWrite(IN4leftback, LOW);
  //rightfrontwheel
  digitalWrite(IN1rightfront, HIGH);
  digitalWrite(IN2rightfront, LOW);
  //rightbackwheel
  digitalWrite(IN3rightback, HIGH);
  digitalWrite(IN4rightback, LOW);
}

void backward() //2
{
  //leftfrontwheel
  digitalWrite(IN1leftfront, LOW);
  digitalWrite(IN2leftfront, HIGH);
  //leftbackwheel
  digitalWrite(IN3leftback, LOW);
  digitalWrite(IN4leftback, HIGH);
  //rightfrontwheel
  digitalWrite(IN1rightfront, LOW);
  digitalWrite(IN2rightfront, HIGH);
  //rightbackwheel
  digitalWrite(IN3rightback, LOW);
  digitalWrite(IN4rightback, HIGH);
}

void right() //4
{
  //leftfrontwheel
  digitalWrite(IN1leftfront, HIGH);
  digitalWrite(IN2leftfront, LOW);
  //leftbackwheel
  digitalWrite(IN3leftback, HIGH);
  digitalWrite(IN4leftback, LOW);
  //rightfrontwheel
  digitalWrite(IN1rightfront, LOW);
  digitalWrite(IN2rightfront, HIGH);
  //rightbackwheel
  digitalWrite(IN3rightback, LOW);
  digitalWrite(IN4rightback, HIGH);
}

void left() //3
{
  //leftfrontwheel
  digitalWrite(IN1leftfront, LOW);
  digitalWrite(IN2leftfront, HIGH);
  //leftbackwheel
  digitalWrite(IN3leftback, LOW);
  digitalWrite(IN4leftback, HIGH);
  //rightfrontwheel
  digitalWrite(IN1rightfront, HIGH);
  digitalWrite(IN2rightfront, LOW);
  //rightbackwheel
  digitalWrite(IN3rightback, HIGH);
  digitalWrite(IN4rightback, LOW);
}

void _stop() //0
{
  //leftfrontwheel
  digitalWrite(IN1leftfront, LOW);
  digitalWrite(IN2leftfront, LOW);
  //leftbackwheel
  digitalWrite(IN3leftback, LOW);
  digitalWrite(IN4leftback, LOW);
  //rightfrontwheel
  digitalWrite(IN1rightfront, LOW);
  digitalWrite(IN2rightfront, LOW);
  //rightbackwheel
  digitalWrite(IN3rightback, LOW);
  digitalWrite(IN4rightback, LOW);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Servo Translate
int AngleToPulse(int ang) { //angle to pulse
  int pulse = map(ang, 0, 180, SERVOMIN , SERVOMAX);
  Serial.print("Angle: "); Serial.print(ang);
  Serial.print(" pulse: "); Serial.println(pulse);
  return pulse;
}
