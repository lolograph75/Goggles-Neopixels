#include <Adafruit_NeoPixel.h>

#define DATAPIN 6
#define NUMLEDS 32
#define BRIGHTNESS 40
#define DURATION 35
#define DURATION1 80
#define DELAY_ANIM 5000

Adafruit_NeoPixel leds = Adafruit_NeoPixel(NUMLEDS, DATAPIN, NEO_GRB + NEO_KHZ800);

char color;

void setup() {
  Serial.begin(9600);
  leds.begin();
  leds.setBrightness(BRIGHTNESS);
  leds.show();
}

void loop() {

    startAnimation();
}

void startAnimation() {
  
  //theaterChase(255,0,0);
  if (Serial.available() > 0) {
    //color = (char)Serial.read();
    switch(Serial.read()){

  case 'r':
  color = 'r'; 
  break;

  case 'g':
  color = 'g'; 
  break;

  case 'b':
  color = 'b'; 
  break;

  case 'y':
  color = 'y'; 
  break;

  case 'p':
  color = 'p'; 
  break;

  case 'a':
  color = 'a'; 
  break;

  case 'o':
  color = 'o'; 
  break;

  case 'c':
  color = 'c'; 
  break;

  case 'v':
  color = 'v'; 
  break;
      
    }
  }
  
  Serial.println((byte)color);
  if (color == 'r') {
    colorWipe(255, 0, 0);
    //Serial.println("color wipe red");
  }
  if (color == 'g') {
    colorWipe(0, 255, 0);
    //Serial.println(" color wipe green");
  }
  if (color == 'b') {
    colorWipe(0, 0, 255);
    //Serial.println("color wipe blue");
  }
  if (color == 'y') {
    colorWipe(255, 204, 0);
    //Serial.println("color wipe yellow");
  }
  if (color == 'p') {
    colorWipe(255, 0, 180);
    //Serial.println("color wipe pink");
  }
  if (color == 'a') {
    theaterChase(172, 230, 0);
    //Serial.println("theater chase anis");
  }
  if (color == 'o') {
    theaterChase(255, 51, 0);
    //Serial.println("theater chase orange");
  }
  if (color == 'c') {
    theaterChase(0, 255, 255);
    //Serial.println("theater chase cyan");
  }
  if (color == 'v') {
    theaterChase(153, 0, 255);
    //Serial.println("theater chase violet");
  }
}

void colorWipe(byte red, byte green, byte blue) {


    for (int i = 0; i < NUMLEDS; i++) {
      leds.setPixelColor(i, red, green, blue);
      leds.setPixelColor(NUMLEDS - 1 - i, red, green, blue);
      leds.show();
      delay(DURATION);
    }

    for (int i = NUMLEDS - 1; i >= 0; i--) {
      leds.setPixelColor(NUMLEDS - 1 - i, 0, 0, 0);
      leds.setPixelColor(i, 0, 0, 0);
      leds.show();
      delay(DURATION);
    }
  

}

void theaterChase(byte red, byte green, byte blue) {
  
    for (byte q = 0; q < 3; q++) {
      for (byte i = 0; i < NUMLEDS; i = i + 3) {
        leds.setPixelColor(i + q, red, green, blue); //turn every third pixel on
      }
      leds.show();

      delay(DURATION);

      for (byte i = 0; i < NUMLEDS; i = i + 3) {
        leds.setPixelColor(i + q, 0, 0, 0);    //turn every third pixel off
      }
      leds.show();
      delay(DURATION1);
    }  
}



