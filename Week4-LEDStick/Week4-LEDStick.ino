#include <Adafruit_NeoPixel.h>
#define PIN 6  // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 8  // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);
}

void loop() {

  for (int i = 0; i < 8; i++) {  // For each pixel...
    pixels.setPixelColor(i, 200 - 20 * i, 20 * i, 100);
    pixels.show();  // Send the updated pixel colors to the hardware.
    delay(100);     // Pause before next pass through loop
  }

  for (int i = 7; i >= 0; i--) {       // For each pixel...
    pixels.setPixelColor(i, 0, 0, 0);  // Send the updated pixel colors to the hardware.
    pixels.show();                     // Send the updated pixel colors to the hardware.
    delay(100);                        // Pause before next pass through loop
  }
}