int ledPin = 5;
long currentTime = 0;
long previousTime = 0;
int delayVal = 500;
int buttonState = 0;
int buttonPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}


void loop() {
  currentTime = millis();
  buttonState = digitalRead(buttonPin);

  if (buttonState == 0) {
    if (currentTime - previousTime >= delayVal) {
      digitalWrite(ledPin, HIGH);
    }
    if (currentTime - previousTime >= delayVal * 2) {
      digitalWrite(ledPin, LOW);
      previousTime = currentTime;
    }
  } else if (buttonState == 1) {
    digitalWrite(ledPin, HIGH);
  }
}