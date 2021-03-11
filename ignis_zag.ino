#include <FastLED.h>
#define NUM_LEDS 48
#define ws2812b_SendRGB FastLED.show

CRGB leds_1[NUM_LEDS];
CRGB leds_2[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, PB6>(leds_1, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, PB7>(leds_2, NUM_LEDS);
}

void colors_split(int R, int G, int B, int first_led, int wait) {
  for (int i = 0; i < NUM_LEDS; i++){
    if (i >= first_led) {
      leds_1[i].setRGB(R, G, B);
      leds_2[i].setRGB(R, G, B);
    } else {
      leds_1[i].setRGB(0, 0, 0);
      leds_2[i].setRGB(0, 0, 0);
    }
  }
  FastLED.show();
  delay(wait);
}

void dualcolors(int R_1, int G_1, int B_1, int R_2, int G_2, int B_2, int first_led_1, int first_led_2, int wait){
  for (int i = 0; i < NUM_LEDS; i++){
    if (i >= first_led_1) {
      leds_1[i].setRGB(R_1, G_1, B_1);
    } else {
      leds_1[i].setRGB(0, 0, 0);
    }
    if (i >= first_led_2) {
      leds_2[i].setRGB(R_2, G_2, B_2);
    } else {
      leds_2[i].setRGB(0, 0, 0);
    }
  }
  FastLED.show();
  delay(wait);  
}

void colors(int R, int G, int B, int wait){
  for(int i = 0; i < NUM_LEDS; i++)
  {
    leds_1[i].setRGB(R, G, B);
    leds_2[i].setRGB(R, G, B);
  }
  FastLED.show();
  delay(wait);
}
void loop() {
