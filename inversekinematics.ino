#include <Servo.h>
#include "math.h"
  
  Servo servo1;
  Servo servo2;
  Servo servo3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  

  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);

}

//units in cm
float x = 20;
float y = 5;
float z = 0;

//units in degrees
float angle1 = 90;
float angle2 = 90;
float angle3 = 90;

//units in cm
int k = 12;
int kz = 0;
int kx = 0;
int l = 10;
float m = 0;

float t = 0;
void loop() {

t = t + .01;

//3*t**5/320000 - 3*t**4/6400 + t**3/160 + 10
//12*t**5/625 - 6*t**4/25 + 4*t**3/5 + 10
//18*t**5/625 - 9*t**4/25 + 6*t**3/5 + 5
x = 18*pow(t,5)/625 - 9*pow(t,4)/25 + 6*pow(t,3)/5+5;
y = 0;
z = 0;

if (sqrt(x*x+y*y)<3) continue;

m = sqrt((z*z+x*x)); //nope lazy don't cary if not having kx is inconsistent

angle1 = 180*atan((float)y/x)/3.1415;

//angle2 = 180-(180/3.1415)*acos((k^2-l^2+m^2)/(2*k*m))-(180/3.1415)*asin((z-kz)/m);

angle2 = (180/3.1415)*asin((float)z/m) + (180/3.1415)*acos((float)(k*k-l*l+m*m)/(2*k*m)); //THIS IS NOT ONE TO ONE TO THE PAPER YOU DUMBASS STOP FORGETTING

angle3 = (180/3.1415)*acos((float)(k*k+l*l-m*m)/(2*k*l));

//ofsets for physical servo positions
angle1 = angle1 + 90;
angle2 = angle2 + 50;
angle3 = 270 - angle3;

if (angle1>180) angle1 = 180;
if (angle1<0) angle1 = 0;

if (angle1>180) angle1 = 180;
if (angle1<0) angle1 = 0;

if (angle2>180) angle2 = 180;
if (angle2<0) angle2 = 0;

if (angle3>180) angle3 = 180;
if (angle3<0) angle3 = 0;


if (t<5){
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
}

}
