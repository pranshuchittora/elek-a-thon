void servo_run() {
  if (yaw > 0) {
    myservo.write(val);
    val++;
  }
  if (yaw < 0) {
    myservo.write(val);
    val--;
  }
  if (pitch > 0) {
    myservo1.write(val2);
    val2++;
  }
  if (pitch < 0) {
    myservo1.write(val2);
    val2 --;
  }
  if (result_final < 2)
    myservo2.write(1500);
  if (result_final > 2)
    myservo2.write(1000);
}
