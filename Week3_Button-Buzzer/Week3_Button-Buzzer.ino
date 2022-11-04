/*  sketch playing notes depending on which of three buttons is pressed */

//INPUT PINS
int switchPin1 = 3;
int switchPin2 = 4;
int switchPin3 = 5;

//OUTPUT PINS
int buzzerPin = 10;

//VARIABLES
int state1 = 0;
int state2 = 0;
int state3 = 0;

//OUTPUT NOTES FREQUENCIES
int note1 = 262;
int note2 = 294;
int note3 = 330;
int note4 = 349;
int note5 = 392;
int note6 = 440;
int note7 = 494;

void setup() {
  Serial.begin(9600);

  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(switchPin3, INPUT);
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  
//get input data from buttons
 state1 = digitalRead(switchPin1);
 state2 = digitalRead(switchPin2);
 state3 = digitalRead(switchPin3);

//print input data to serial monitor
 Serial.print(state1);
 Serial.print(",");
 Serial.print(state2);
 Serial.print(",");
 Serial.println(state3);

//output logic
 if(state1 == 1 && state2 == 0 || state3 == 0){
  tone(buzzerPin, note1);
 }else if(state1 == 0 && state2 == 1 && state3 == 0){
  tone(buzzerPin, note2);
 }else if(state1 == 0 && state2 == 0 && state3 == 1){
  tone(buzzerPin, note3);
 }else if(state1 == 1 && state2 == 1 && state3 == 0){
  tone(buzzerPin, note4);
 }else if(state1 == 0 && state2 == 1 && state3 == 1){
  tone(buzzerPin, note5);
 }else if(state1 == 1 && state2 == 0 && state3 == 1){
  tone(buzzerPin, note6);
 }else if(state1 == 1 && state2 == 1 && state3 == 1){
  tone(buzzerPin, note7);
 }else{
  noTone(buzzerPin);
 }
 


}
