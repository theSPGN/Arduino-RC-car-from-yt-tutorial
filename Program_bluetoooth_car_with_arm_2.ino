#include <AFMotor.h>
#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
int pos1=140;
int pos2=130;
int pos3=123;
int pos4=90;

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char command; 

void setup() 
{       
   myservo1.attach(9);
   myservo2.attach(10);
   myservo3.attach(11);
   myservo4.attach(6);
   Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop(){
  myservo1.write(pos1);
  myservo2.write(pos2);
  myservo3.write(pos3);
  myservo4.write(pos4);
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Serial.println(command);
    Stop(); 
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    case 'P':
      if(pos3<127) openx();
      else closex();
      break;
       }
  } 
  if(command =='J') goup2();
  if(command =='I') godown2();
  if(command =='H') goup1();
  if(command =='G') godown1();
  if(command =='K'){
    if(pos4 >=110) pos4=90;
    else if(pos4 ==90) pos4=70;
    else if(pos4 <= 70){
      pos4=90;
      delay(100);
      pos4=110;
      
      }
    else pos4 = 90;
       
  }
 
    
}


void closex(){
  pos3 =123;
  }
void openx(){
  pos3 =130;
  
}

void godown1(){
  pos1-=1;
  delay(20);
              }
    
void goup1(){
  pos1+=1;
  delay(20);
            }
    
void godown2(){
  pos2+=1;
  delay(20);
              }
    
void goup2(){
  pos2-=1;
  delay(20);
            }

void forward()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(255);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(255);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}

void back()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void left()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
}

void right()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
} 

void Stop()
{
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0); //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0); //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
}
