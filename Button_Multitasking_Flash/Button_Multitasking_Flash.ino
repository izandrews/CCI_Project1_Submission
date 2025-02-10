void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}



void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval && !buttonState) {
    previousMillis = currentMillis;
    if (ledState == HIGH) {
      ledState = LOW;
    } else {
      ledState = HIGH;
    }
  }

  if ((digitalRead(buttonPin) = LOW) && !buttonState) {
    buttonState = true;
    ledState = HIGH;
    Serial.println("Button Pressed");
  }



  if ((digitalRead(buttonPin) = LOW) && buttonState) {
    Serial.println("Button Pressed Again!");
    buttonState = false;
  }

  digitalWrite(ledPin, ledState);
}
