#include <Servo.h>

// サーボピン設定
int joint1 = 6;
int joint2 = 5;
int joint3 = 9;
Servo j1_servo, j2_servo, j3_servo;

// 初期角度
int angle1 = 30, angle2 = 30, angle3 = 30;

void setup() {
  Serial.begin(115200); // シリアル通信初期化
  j1_servo.attach(joint1);
  j2_servo.attach(joint2);
  j3_servo.attach(joint3);
  j1_servo.write(angle1);
  j2_servo.write(angle2);
  j3_servo.write(angle3);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readString(); // Pythonから受信
    if (data.startsWith("SET")) {
      sscanf(data.c_str(), "SET %d %d %d", &angle1, &angle2, &angle3);
      j1_servo.write(angle1);
      j2_servo.write(angle2);
      j3_servo.write(angle3);
      Serial.println("OK");
    } else if (data == "GET") {
      Serial.printf("ANGLES %d %d %d\n", angle1, angle2, angle3);
    }
  }
}
