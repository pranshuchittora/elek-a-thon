void bno() {
  Wire.beginTransmission(adr);
  Wire.write(0x2C);
  Wire.endTransmission();
  Wire.requestFrom(adr, 2);
  lsb_z = Wire.read();
  msb_z = Wire.read();
  acc_z = (((((int)msb_z) << 8) | lsb_z));
  /////////////////////////////////////////
  Wire.beginTransmission(adr);
  Wire.write(0x2A);
  Wire.endTransmission();
  Wire.requestFrom(adr, 2);
  lsb_y = Wire.read();
  msb_y = Wire.read();
  acc_y = (((((int)msb_y) << 8) | lsb_y));
  //////////////////////////////////////////
  Wire.beginTransmission(adr);
  Wire.write(0x28);
  Wire.endTransmission();
  Wire.requestFrom(adr, 2);
  lsb_x = Wire.read();
  msb_x = Wire.read();
  acc_x = (((((int)msb_x) << 8) | lsb_x));
  //  Serial.print(acc_x / 100);
  //  Serial.print(',');
  //  Serial.print(acc_y / 100);
  //  Serial.print(',');
  //  Serial.print(acc_z / 100);
  acc_x /= 100;
  acc_y /= 100;
  acc_z /= 100;
  Serial.print(acc_x); Serial.print(" "); Serial.print(acc_y); Serial.print(" "); Serial.print(acc_z); Serial.print(" ");
  acc_x *= acc_x;
  acc_y *= acc_y;
  acc_z *= acc_z;
  result_final = sqrt(acc_z + acc_y + acc_x);
  //    Serial.print(result_final);Serial.print(" ");
}
//
////
void bno_initialize() {
  Wire.beginTransmission(adr);
  Wire.write(0x3D);
  Wire.write(0x0C);
  Wire.endTransmission();
  delay(1);
  ////////////////
  for (int i = 0; i < 50; i++) {
    Wire.beginTransmission(adr);
    Wire.write(0x1A);
    Wire.endTransmission();
    Wire.requestFrom(adr, 6);
    lsb_yaw = Wire.read();
    msb_yaw = Wire.read();
    //
    lsb_roll = Wire.read();
    msb_roll = Wire.read();
    //
    lsb_pitch = Wire.read();
    msb_pitch = Wire.read();
    yaw_offset = yaw_offset + (((((int)msb_yaw) << 8) | lsb_yaw));
    roll_offset = roll_offset + (((((int)msb_roll) << 8) | lsb_roll));
    pitch_offset = pitch_offset + (((((int)msb_pitch) << 8) | lsb_pitch));
  }
  yaw_offset /= 800;
  roll_offset /= 800;
  pitch_offset /= 800;
  //  Serial.println(yaw_offset);
}
//
void bno_angle() {
  Wire.beginTransmission(adr);
  Wire.write(0x1A);
  Wire.endTransmission();
  Wire.requestFrom(adr, 6);
  lsb_yaw = Wire.read();
  msb_yaw = Wire.read();
  //
  lsb_roll = Wire.read();
  msb_roll = Wire.read();
  //
  lsb_pitch = Wire.read();
  msb_pitch = Wire.read();
  yaw = (((((int)msb_yaw) << 8) | lsb_yaw));
  yaw /= 16;
  yaw = yaw - yaw_offset;
  if (yaw < 0)
    yaw = yaw + 360;
  if (yaw > 180 && yaw < 360) {
    yaw = map(yaw, 180, 360, -180, 0);
    //
  }
  //      Serial.print("yaw=");
  //      Serial.println(yaw);
  //
  roll = (((((int)msb_roll) << 8) | lsb_roll));
  roll /= 16;
  roll = roll - roll_offset;
  //
  pitch = (((((int)msb_pitch) << 8) | lsb_pitch));
  pitch /= 16;
  pitch = pitch - pitch_offset;
  Serial.print(yaw); Serial.println(" ");// Serial.print(roll); Serial.print(" "); Serial.println(pitch);

}
