int ledPin = 5;
long currentTime = 0;
long previousTime = 0;
int delayVal = 500;

void setup() {
 pinMode(ledPin, OUTPUT);
 Serial.begin(9600);
}


void loop(){
  currentTime = millis();

  if(currentTime - previousTime>=delayVal){
       digitalWrite(ledPin, HIGH);
  }
  if(currentTime - previousTime>=delayVal*2){
       digitalWrite(ledPin, LOW);
       previousTime = currentTime;
  }
}
