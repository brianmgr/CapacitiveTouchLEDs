#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>

CapacitiveSensor capSensor = CapacitiveSensor(4,2);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(4, 13, NEO_GRBW + NEO_KHZ800);

int state = 0;

void setup() {
  capSensor.set_CS_AutocaL_Millis(0xFFFFFFFF);
  pixels.begin();
  pixels.show();
  Serial.begin(9600);
}

void loop() {
  long capReading =  capSensor.capacitiveSensor(30);
  
  if (capReading > 125){
    if (state == 0){
      Serial.println(capReading);
      pixels.setPixelColor(0,255,30,0,255);
      pixels.setPixelColor(1,255,30,0,0);
      pixels.setPixelColor(2,255,30,0,0);
      pixels.setPixelColor(3,255,30,0,255);
      pixels.show();
      state = 1;
      delay(500);
    } else if (state == 1){
      Serial.println(capReading);
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
