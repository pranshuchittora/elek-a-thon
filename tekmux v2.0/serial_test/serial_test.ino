#include<Wire.h>
#define adr 0x29
int val;
int val2;
#include <Servo.h>
Servo myservo;
Servo myservo1;
Servo myservo2;
////////////////////////////////////////////////////////////////
byte data[18] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte add[18] = {0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66};
int i, y;
byte lsb_x;
byte msb_x;
byte lsb_y;
byte msb_y;
byte lsb_z;
byte msb_z;
int acc_x;
int acc_y;
int acc_z;
int result_final;
//
byte lsb_yaw;
byte msb_yaw;
double yaw_offset = 0;
double yaw = 0;
//
byte lsb_roll;
byte msb_roll;
double roll_offset = 0;
double roll = 0;
//
byte lsb_pitch;
byte msb_pitch;
double pitch_offset = 0;
double pitch = 0;
//
//
void setup() {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(adr);
  Wire.write(0x3D);
  Wire.write(0x0C);
  Wire.endTransmission();
  delay(10);////////////
  ///
  bno_initialize();
  myservo.attach(9);
  myservo1.attach(10);
  myservo2.attach(11);
  myservo2.write(1000);
}
//

void loop() {
//  bno();//accel//
  bno_angle();//angle
//  servo_run();//
}
