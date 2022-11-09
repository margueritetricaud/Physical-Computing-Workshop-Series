int ledPin = 5;
long currentTime = 0;
long previousTime = 0;
int delayVal = 500;
int ldrPin = A0;
int ldrVal =0;
int state =0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin,INPUT);
  Serial.begin(9600);
}


void loop() {
  currentTime = millis();
  ldrVal = analogRead(ldrPin);
  Serial.println(ldrVal);
 
 //STATE SWITCHING INPUT
  if (ldrVal <= 300) {
    state = 0;
  } else if (ldrVal>300 && ldrVal<=600) {
    state = 1;
  } else if (ldrVal>600) {
    state = 2;
  }

//STATES OUTPUTS
  if (state == 1) {
    animation1();
  } else if (state == 2) {
    animation2();
  } else if (state == 0) {
    off();
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

void off(){
  digitalWrite(ledPin, LOW);
}