int turnLeftPin = 12;
int turnRightPin = 11;
int changeDirectionPin = 10;
unsigned long initialTime;
boolean turnDirection = true;

void setup() {
  pinMode(turnLeftPin, OUTPUT);
  pinMode(turnRightPin, OUTPUT);
  pinMode(changeDirectionPin, INPUT);
  Serial.begin(9600);
  delay(500);
  initialTime = millis();
}

void loop() {
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
}


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

void stop() {
    digitalWrite(turnLeftPin, LOW);
    digitalWrite(turnRightPin, LOW);
}
