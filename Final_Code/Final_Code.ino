int motorPin1a = 2;
int motorPin1b = 4;
int motorPin2a = 3;
int motorPin2b = 5;
int motorPin3a = 6;
int motorPin3b = 8;
int motorPin4a = 7;
int motorPin4b = 9;
int motorPin5a = 10;
int motorPin5b = 12;
int motorPin6a = 11;
int motorPin6b = 13;
int delayTime = 15;
int increment = 0;
int buttonPin1 = 23;
int ledPin = 22;
int spinlength = 0;
int spincount = 0;
bool isSpinning = false;
int ledState = HIGH;
unsigned long previousMillis = 0;
bool blinkState = false;
const long interval = 50;



void setup() {
  pinMode(motorPin1a, OUTPUT);
  pinMode(motorPin1b, OUTPUT);
  pinMode(motorPin2a, OUTPUT);
  pinMode(motorPin2b, OUTPUT);
  pinMode(motorPin3a, OUTPUT);
  pinMode(motorPin3b, OUTPUT);
  pinMode(motorPin4a, OUTPUT);
  pinMode(motorPin4b, OUTPUT);
  pinMode(motorPin5a, OUTPUT);
  pinMode(motorPin5b, OUTPUT);
  pinMode(motorPin6a, OUTPUT);
  pinMode(motorPin6b, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  //pinMode(13, OUTPUT);
  Serial.begin(9600);
  delay(100);
}

void spin(){
  while(spincount <= spinlength){
  Serial.println("count:");
  Serial.println(spincount);
  Serial.println("length:");
  Serial.println(spinlength);
 //Step 1 Reel 1
  digitalWrite(motorPin1a, HIGH);
  digitalWrite(motorPin1b, LOW);
  digitalWrite(motorPin2a, LOW);
  digitalWrite(motorPin2b, HIGH);
  //Step 1 Reel 2
  digitalWrite(motorPin3a, HIGH);
  digitalWrite(motorPin3b, LOW);
  digitalWrite(motorPin4a, LOW);
  digitalWrite(motorPin4b, HIGH);
  //Step 1 Reel 3
  digitalWrite(motorPin5a, HIGH);
  digitalWrite(motorPin5b, LOW);
  digitalWrite(motorPin6a, LOW);
  digitalWrite(motorPin6b, HIGH);
  //digitalWrite(ledPin, ledState);
  delay(delayTime);

 

  //Step 2
  digitalWrite(motorPin1a, HIGH);
  digitalWrite(motorPin1b, LOW);
  digitalWrite(motorPin2a, LOW);
  digitalWrite(motorPin2b, LOW);
  //delay(delayTime);
  //Step 1 Reel 2
  digitalWrite(motorPin3a, HIGH);
  digitalWrite(motorPin3b, LOW);
  digitalWrite(motorPin4a, LOW);
  digitalWrite(motorPin4b, LOW);
  //Step 1 Reel 3
  digitalWrite(motorPin5a, HIGH);
  digitalWrite(motorPin5b, LOW);
  digitalWrite(motorPin6a, LOW);
  digitalWrite(motorPin6b, LOW);
  delay(delayTime);

  //Step 3
  digitalWrite(motorPin1a, HIGH);
  digitalWrite(motorPin1b, LOW);
  digitalWrite(motorPin2a, HIGH);
  digitalWrite(motorPin2b, LOW);
  //delay(delayTime);
  //Step 3 Reel 2
  digitalWrite(motorPin3a, HIGH);
  digitalWrite(motorPin3b, LOW);
  digitalWrite(motorPin4a, HIGH);
  digitalWrite(motorPin4b, LOW);
  //Step 3 Reel 3
  digitalWrite(motorPin5a, HIGH);
  digitalWrite(motorPin5b, LOW);
  digitalWrite(motorPin6a, HIGH);
  digitalWrite(motorPin6b, LOW);
  delay(delayTime);

  //Step 4
  digitalWrite(motorPin1a, LOW);
  digitalWrite(motorPin1b, LOW);
  digitalWrite(motorPin2a, HIGH);
  digitalWrite(motorPin2b, LOW);
  //delay(delayTime);
  //digitalWrite(13, LOW);
  //Step 4 Reel 2
  digitalWrite(motorPin3a, LOW);
  digitalWrite(motorPin3b, LOW);
  digitalWrite(motorPin4a, HIGH);
  digitalWrite(motorPin4b, LOW);
  //Step 4 Reel 3
  digitalWrite(motorPin5a, LOW);
  digitalWrite(motorPin5b, LOW);
  digitalWrite(motorPin6a, HIGH);
  digitalWrite(motorPin6b, LOW);
  delay(delayTime);
  digitalWrite(ledPin, !ledState);

  //Step 5
  digitalWrite(motorPin1a, LOW);
  digitalWrite(motorPin1b, HIGH);
  digitalWrite(motorPin2a, HIGH);
  digitalWrite(motorPin2b, LOW);
  //delay(delayTime);
  //Step 5 Reel 2
  digitalWrite(motorPin3a, LOW);
  digitalWrite(motorPin3b, HIGH);
  digitalWrite(motorPin4a, HIGH);
  digitalWrite(motorPin4b, LOW);
  //Step 5 Reel 3
  digitalWrite(motorPin5a, LOW);
  digitalWrite(motorPin5b, HIGH);
  digitalWrite(motorPin6a, HIGH);
  digitalWrite(motorPin6b, LOW);
  delay(delayTime);

  //Step 6
  digitalWrite(motorPin1a, LOW);
  digitalWrite(motorPin1b, HIGH);
  digitalWrite(motorPin2a, LOW);
  digitalWrite(motorPin2b, LOW);
  //delay(delayTime);
  //Step 6 Reel 2
  digitalWrite(motorPin3a, LOW);
  digitalWrite(motorPin3b, HIGH);
  digitalWrite(motorPin4a, LOW);
  digitalWrite(motorPin4b, LOW);
  //Step 6 Reel 3
  digitalWrite(motorPin5a, LOW);
  digitalWrite(motorPin5b, HIGH);
  digitalWrite(motorPin6a, LOW);
  digitalWrite(motorPin6b, LOW);
  delay(delayTime);
  //digitalWrite(ledPin, ledState);

  //Step 7
  digitalWrite(motorPin1a, LOW);
  digitalWrite(motorPin1b, HIGH);
  digitalWrite(motorPin2a, LOW);
  digitalWrite(motorPin2b, HIGH);
  //delay(delayTime);
  //Step 7 Reel 2
  digitalWrite(motorPin3a, LOW);
  digitalWrite(motorPin3b, HIGH);
  digitalWrite(motorPin4a, LOW);
  digitalWrite(motorPin4b, HIGH);
  //Step 7 Reel 3
  digitalWrite(motorPin5a, LOW);
  digitalWrite(motorPin5b, HIGH);
  digitalWrite(motorPin6a, LOW);
  digitalWrite(motorPin6b, HIGH);
  delay(delayTime);

  //Step 8
  digitalWrite(motorPin1a, LOW);
  digitalWrite(motorPin1b, LOW);
  digitalWrite(motorPin2a, LOW);
  digitalWrite(motorPin2b, HIGH);
  //Step 8 Reel 2
  digitalWrite(motorPin3a, LOW);
  digitalWrite(motorPin3b, LOW);
  digitalWrite(motorPin4a, LOW);
  digitalWrite(motorPin4b, HIGH);
  //Step 8 Reel 3
  digitalWrite(motorPin5a, LOW);
  digitalWrite(motorPin5b, LOW);
  digitalWrite(motorPin6a, LOW);
  digitalWrite(motorPin6b, HIGH);
  digitalWrite(ledPin, ledState);
  delay(delayTime);
  spincount = spincount += 1;

  }
  return;


}





void loop() {
  unsigned long currentMillis = millis();
  if(blinkState == false){
    ledState = HIGH;
  }
  if(currentMillis - previousMillis >= interval && blinkState){
    previousMillis = currentMillis;
    ledState = !ledState;
  }
  if (digitalRead(buttonPin1) == LOW && isSpinning == false){
    delay(50);
    blinkState = true;
    isSpinning = true;
    Serial.println("Button Pressed!");

  }
  digitalWrite(ledPin, ledState);
  if (isSpinning == true){
    delay(10);
    spincount = 0;
    //spinlength = random(2,12);
    spinlength = random(2,12);
    spin();
    isSpinning = false;
    blinkState = false;
  }

}
