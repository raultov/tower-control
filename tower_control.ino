int turnLeftPin = 12;
int turnRightPin = 11;
int changeDirectionPin = 2;
volatile boolean turnDirection = true;
volatile unsigned long lastTurnTime;

void setup() {
  pinMode(turnLeftPin, OUTPUT);
  pinMode(turnRightPin, OUTPUT);
  pinMode(changeDirectionPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(changeDirectionPin), changeDirection, RISING);
  /*Serial.begin(9600);
  initialTime = millis();*/
  lastTurnTime = millis();
  delay(500);
}

void loop() {
/*
  if (millis() - initialTime > 25000) {
    turnDirection = !turnDirection;
    initialTime = millis();
    Serial.println(initialTime);
  }

  if (digitalRead(10) == HIGH) {
    turnBoolean(turnDirection);
    delay(3);
    stop();
    delay(50);
  }
  */
 
  delay(5);
  stop();
  delay(50);
  turn();
}

void changeDirection() {
  if (millis() - lastTurnTime > 1000L) {
    turnDirection = !turnDirection;
    lastTurnTime = millis();
  }
}

void turn() {
  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if (turnDirection == true) {
    inPin1 = HIGH;
    inPin2 = LOW;
  }
    
  digitalWrite(turnLeftPin, inPin1);
  digitalWrite(turnRightPin, inPin2);
}
/*
void turnBoolean(boolean turnDirection) {
  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if (turnDirection == true) {
    inPin1 = HIGH;
    inPin2 = LOW;
  }
    
  digitalWrite(turnLeftPin, inPin1);
  digitalWrite(turnRightPin, inPin2);
}
*/
void stop() {
    digitalWrite(turnLeftPin, LOW);
    digitalWrite(turnRightPin, LOW);
}
