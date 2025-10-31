const int trigPin = 2;
const int echoPin = 3;
const int buttonPin = 4;
const int ledPin = 5;
const int threshold = 20; // Distance in cm

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Check if button is pressed
  if (digitalRead(buttonPin) == HIGH) {
    
    // Keep sensing while button stays pressed
    while (digitalRead(buttonPin) == HIGH) {
      
      // Send ultrasonic pulse
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      //Serial.println("ultrasonic");
      
      // Read the echo
      long duration = pulseIn(echoPin, HIGH);
      
      // Calculate distance in cm
      int distance = duration * 0.034 / 2;
      //Serial.println(distance);
      // Check if object is close
      if (distance < threshold && distance > 0) {
        //Serial.println("LEDON");
        digitalWrite(ledPin, HIGH); // Turn LED on
      } else {
        //Serial.println("LEDOFF");
        digitalWrite(ledPin, LOW); // Turn LED off
      }
      
      delay(100); // Small delay between measurements
    }
    
    // Turn LED off when button is released
    digitalWrite(ledPin, LOW);
  }
}