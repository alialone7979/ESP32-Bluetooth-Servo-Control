#include "BluetoothSerial.h"
#include <ESP32Servo.h>

BluetoothSerial bt;
Servo myServo;

int led = 12;
int servoPin = 13;
char x;

void setup() {
  bt.begin("User-Bluetooth");
  Serial.begin(115200);

  pinMode(led, OUTPUT);

  myServo.attach(servoPin);
  myServo.write(0);

  Serial.println("Bluetooth START");
}

void loop() {

  if (bt.available()) {

    x = bt.read();

    if (x == '1') {
      digitalWrite(led, HIGH);
      bt.println("LED ON");
    }

    else if (x == '2') {
      digitalWrite(led, LOW);
      bt.println("LED OFF");
    }

    else if (x == 'a') {
      myServo.write(90);
      bt.println("SERVO 90 DEG");
    }

    else if (x == 'b') {
      myServo.write(0);
      bt.println("SERVO 0 DEG");
    }
  }

  delay(20);
}
