int ledPin = 5;
long currentTime = 0;
long previousTime = 0;
int delayVal = 500;
int buttonState = 0;
int buttonPin = 2;
int state =0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}


void loop() {
  currentTime = millis();
  buttonState = digitalRead(buttonPin);
 
 //STATE SWITCHING INPUT
  if (buttonState == 0) {
    state = 0;
  } else if (buttonState == 1) {
    state = 1;
  }

//STATES OUTPUTS
  if (state == 0) {
    animation1();
  } else if (state == 1) {
    animation2();
  }
}

void animation1(){
  if (currentTime - previousTime >= delayVal) {
    digitalWrite(ledPin, HIGH);
  }
  if (currentTime - previousTime >= delayVal * 2) {
    digitalWrite(ledPin, LOW);
    previousTime = currentTime;
  }
}

void animation2(){
  digitalWrite(ledPin, HIGH);
}