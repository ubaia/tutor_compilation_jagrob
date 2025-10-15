int button1 = 2;
int button2 = 3;
int led1 = 4;
int led2 = 5;
int buzzer = 6;

int score1 = 0;
int score2 = 0;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT); 
  //pinMode(button1, INPUT_PULLUP);
  //pinMode(button2, INPUT_PULLUP); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  Serial.println("Game Start! Click your button for 15 seconds!");
}

void loop() {
  unsigned long startTime = millis();

  // Game runs for 15 seconds
  while (millis() - startTime < 15000) {

    // Player 1
    if (digitalRead(button1) == HIGH){
      score1++;
      digitalWrite(led1, HIGH);
      delay(100);
      digitalWrite(led1, LOW);
      // wait until released
      while(digitalRead(button1) == HIGH);
    }

    // Player 2
    if (digitalRead(button2) == HIGH) {
      score2++;
      digitalWrite(led2, HIGH);
      delay(100);
      digitalWrite(led2, LOW);
      while(digitalRead(button2) == HIGH);
    }
  }

  // After 15s → buzzer on and show result
  digitalWrite(buzzer, HIGH);
  Serial.println("Time is up!");
  Serial.print("Player 1: "); Serial.println(score1);
  Serial.print("Player 2: "); Serial.println(score2);

  if (score1 > score2) {
    Serial.println("Player 1 Wins!");
  }
  else if (score2 > score1) {
    Serial.println("Player 2 Wins!");
  }
  else {
    Serial.println("It's a Tie!");
  }


  // Keep buzzer on for 3 seconds, then stop
  delay(3000);
  digitalWrite(buzzer, LOW);

  // Game ends here; to play again, press RESET button
}
