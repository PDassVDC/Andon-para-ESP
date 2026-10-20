/*################################ RC522 #######################################*/
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIXEL_PIN    15  // D8 Pino de endereçamento dos LEDS
#define PIXEL_COUNT 12    // Numero de LEDS na FITA
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setupLed(){
  strip.begin();
  strip.show();
  }

void setColor(int G, int R, int B, int delays){
  for(int i = 0; i < PIXEL_COUNT; i++){
    strip.setPixelColor(i, G, R, B);
    strip.show();
    delay(delays);
    }
  }

void ledOff(){
  //strip.clear();
  setColor(0, 0, 0, 0);
  }
void onLedRed(){
  setColor(0, 255, 0, 0);
  }
void onLedBlue(){
  setColor(0, 0, 255, 0);
  }
void onLedGreen(){
  setColor(255, 0, 0, 0);
  }
 
  void onLedWhite(){
  setColor(160, 255, 100, 0);
  }
  void onLedYellon(){
  setColor(70, 200, 0, 0);
  //strip.setBrightness(255);
  }
  