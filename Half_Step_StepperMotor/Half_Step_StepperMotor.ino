int motorPin1a = 6;
int motorPin1b = 8;
int motorPin2a = 7;
int motorPin2b = 9;
int delayTime = 20;
int increment = 0;
int buttonPin1 = A0;
bool isSpinning = False;


void setup() {
  pinMode(motorPin1a, OUTPUT);
  pinMode(motorPin1b, OUTPUT);
  pinMode(motorPin2a, OUTPUT);
  pinMode(motorPin2b, OUTPUT);
  pinMode(buttonPin1, INPUT);
  //pinMode(13, OUTPUT);
  Serial.begin(9600);
  delay(100);
}


void loop() {
  if (digitalRead(buttonPin1) == HIGH && isSpinning == false){
    isSpinning = true;
  }
  if (isSpinning = true){
    delay(10);
    spin();
  }


void spin(){
  if (digitalRead(buttonPin1) == HIGH){
    isSpinning = false;
    return;
  }
  digitalWrite(13, HIGH);
  Serial.print("Delay time: ");
  Serial.println(delayTime);
  //Step 1 
  digitalWrite(motorPin1a, HIGH);
  digitalWrite(motorPin1b, LOW);
  digitalWrite(motorPin2a, LOW);
  digitalWrite(motorPin2b, HIGH);
 
  delay(delayTime);
  //Step 2
  digitalWrite(motorPin1a, HIGH);
  digitalWrite(motorPin1b, LOW);
  digitalWrite(motorPin2a, LOW);
  digitalWrite(motorPin2b, LOW);
  delay(delayTime);
  //Step 3
  digitalWrite(motorPin1a, HIGH);
  digitalWrite(motorPin1b, LOW);
  digitalWrite(motorPin2a, HIGH);
  digitalWrite(motorPin2b, LOW);
  delay(delayTime);
  //Step 4
  digitalWrite(motorPin1a, LOW);
  digitalWrite(motorPin1b, LOW);
  digitalWrite(motorPin2a, HIGH);
  digitalWrite(motorPin2b, LOW);
  delay(delayTime);
  //digitalWrite(13, LOW);
  //Step 5
  digitalWrite(motorPin1a, LOW);
  digitalWrite(motorPin1b, HIGH);
  digitalWrite(motorPin2a, HIGH);
  digitalWrite(motorPin2b, LOW);
  delay(delayTime);
  //Step 6
  digitalWrite(motorPin1a, LOW);
  digitalWrite(motorPin1b, HIGH);
  digitalWrite(motorPin2a, LOW);
  digitalWrite(motorPin2b, LOW);
  delay(delayTime);
  //Step 7
  digitalWrite(motorPin1a, LOW);
  digitalWrite(motorPin1b, HIGH);
  digitalWrite(motorPin2a, LOW);
  digitalWrite(motorPin2b, HIGH);
  delay(delayTime);
  //Step 8
  digitalWrite(motorPin1a, LOW);
  digitalWrite(motorPin1b, LOW);
  digitalWrite(motorPin2a, LOW);
  digitalWrite(motorPin2b, HIGH);
  delay(delayTime);
  if ((delayTime < 10)||(delayTime > 50)) {
    increment = -increment;
  }
  delayTime += increment;
}

}
