#include <Wire.h>
#include <BH1745NUC.h>

BH1745NUC senseColor(0x39);

void setup() {
  byte senseValue;

  Serial.begin(9600);
  while (!Serial);
  Serial.println("14CORE | COLOR SENSOR ");
  Serial.println("Initializing .........");
  delay(4000);
  Wire.begin();
  senseValue = senseColor.init();
}

void loop() {
  byte senseValue;
  unsigned short rgbc[4];
  
  senseValue = senseColor.get_val(rgbc);
  if (senseValue == 0) {
    Serial.print("BH1745NUC (RED)   > ");
    Serial.println(rgbc[0]);
    Serial.print("BH1745NUC (GREEN) > ");
    Serial.println(rgbc[1]);
    Serial.print"BH1745NUC (BLUE)  > ");
    Serial.println(rgbc[2]);
    Serial.print("BH1745NUC (CLEAR) > ");
    Serial.println(rgbc[3]);    
    Serial.println();
  }
 
  delay(500);

}
