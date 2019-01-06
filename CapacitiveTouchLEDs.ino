#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>

//Pins 0 and 4 for sensor
CapacitiveSensor capSensor = CapacitiveSensor(0,4);

//Pin 2 for data to LEDs
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(4, 2, NEO_GRBW + NEO_KHZ800);

int state = 0;

void setup() {
  capSensor.set_CS_AutocaL_Millis(0xFFFFFFFF);
  pixels.begin();
  pixels.show();
}

void loop() {
  long capReading =  capSensor.capacitiveSensor(30);
  
  if (capReading > 125){
    if (state == 0){
      pixels.setPixelColor(0,255,0,0,0);
      pixels.setPixelColor(1,0,0,0,255);
      pixels.setPixelColor(2,255,30,0,0);
      pixels.setPixelColor(3,255,30,0,255);
      pixels.show();
      state = 1;
      delay(500);
    } else if (state == 1){
      for(int i=0;i<4;i++){
        pixels.setPixelColor(i, pixels.Color(0,0,0,0));
        pixels.show();
      }
      state = 0;
      delay(500);
    }
  } else {
    delay(15);
  }
}
