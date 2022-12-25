#include <PS2X_lib.h>
#include <Wire.h>
#include <Servo.h>

// PS2 controller
PS2X ps2x; // create PS2 Controller Class
int error = 0; 
byte type = 0;
byte vibrate = 0;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//left motor wheels
#define IN1left 5
#define IN2left 4
#define IN1right 3
#define IN2right 2

Servo myservo; 

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {  
  // put your setup code here, to run once:
  Serial.begin(57600);
  // all about motor
  pinMode(IN1left, OUTPUT);
  pinMode(IN2left, OUTPUT);
  pinMode(IN1right, OUTPUT);
  pinMode(IN2right, OUTPUT);
  myservo.attach(7);
  Serial.setTimeout(1);

  // PS2 CONTROLLER DETRECTION ZONE////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  error = ps2x.config_gamepad(13,12,10,11, true, true);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error

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

        if(ps2x.Button(PSB_BLUE)){ //X
          myservo.write(70);
        }

        if(ps2x.Button(PSB_PINK)){ //Square
          myservo.write(110);
        }
            
   delay(50);
   }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
