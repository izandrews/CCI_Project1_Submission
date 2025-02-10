int motorPin1a = 8;
int motorPin1b = 10;
int motorPin2a = 9;
int motorPin2b = 11;
int delayTime = 40;


void setup() {
  pinMode(motorPin1a, OUTPUT);
  pinMode(motorPin1b, OUTPUT);
  pinMode(motorPin2a, OUTPUT);
  pinMode(motorPin2b, OUTPUT);
  pinMode(13, OUTPUT);
  delay(100);
}


void loop() {
  digitalWrite(13, HIGH);
  digitalWrite(motorPin1a, HIGH);
  digitalWrite(motorPin1b, LOW);
  digitalWrite(motorPin2a, LOW);
  digitalWrite(motorPin2b, LOW);
  delay(delayTime);
  digitalWrite(motorPin1a, LOW);
  digitalWrite(motorPin1b, LOW);
  digitalWrite(motorPin2a, HIGH);
  digitalWrite(motorPin2b, LOW);
  delay(delayTime);
  digitalWrite(13, LOW);
  digitalWrite(motorPin1a, LOW);
  digitalWrite(motorPin1b, HIGH);
  digitalWrite(motorPin2a, LOW);
  digitalWrite(motorPin2b, LOW);
  delay(delayTime);
  digitalWrite(motorPin1a, LOW);
  digitalWrite(motorPin1b, LOW);
  digitalWrite(motorPin2a, LOW);
  digitalWrite(motorPin2b, HIGH);
  delay(delayTime);
}
