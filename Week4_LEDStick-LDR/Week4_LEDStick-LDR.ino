#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 6  // On Trinket or Gemma, suggest changing this to 1
int ldrPin = A0;
int ldrVal;
int pixelShown;

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 8  // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500  // Time (in milliseconds) to pause between pixels

void setup() {

  pixels.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
}

void loop() {
  ldrVal = analogRead(ldrPin);
  Serial.println(ldrVal);
  pixelShown = map(ldrVal, 180, 840, 0, 8);
  Serial.println(pixelShown);

  pixels.clear();  // Set all pixel colors to 'off'

  for (int i = 0; i < pixelShown; i++) {  // For each pixel...
    pixels.setPixelColor(i, 10, 250 - i * 20, 10 + i * 20);
    //delay(DELAYVAL); // Pause before next pass through loop
  }
  pixels.show();  // Send the updated pixel colors to the hardware.

}