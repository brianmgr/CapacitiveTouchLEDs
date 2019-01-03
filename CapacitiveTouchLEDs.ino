#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>

CapacitiveSensor capSensor = CapacitiveSensor(4,2);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1, 13, NEO_GRB + NEO_KHZ800);

int state = 0;

void setup() {
  capSensor.set_CS_AutocaL_Millis(0xFFFFFFFF);
  pixels.begin();
}

void loop() {
  long capReading =  capSensor.capacitiveSensor(30);

  if (capReading > 120){
    if (state == 0){
      pixels.setPixelColor(0, pixels.Color(255,40,0));
      state = 1;
      pixels.show();
      delay(500);
    } else if (state == 1){
      pixels.setPixelColor(0, pixels.Color(0,0,0));
      state = 0;
      pixels.show();
      delay(500);
    }
  }
}
