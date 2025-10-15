#include <Servo.h>

#define TRIG 2
#define ECHO 3
#define RED_LED 4
#define GREEN_LED 5
#define SERVO_PIN 6

Servo gate;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  gate.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  // Measure distance
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duration = pulseIn(ECHO, HIGH);
  float distance = duration * 0.034 / 2; // cm

  Serial.print("Distance: ");
  Serial.println(distance);

  // Gate control logic
  if (distance > 0 && distance < 20) {
    gate.write(90);               // open gate
    digitalWrite(RED_LED, LOW);  // red LED on
    digitalWrite(GREEN_LED, HIGH);
  } else {
    gate.write(0);                // close gate
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW); // green LED on
  }

  delay(300);
}
