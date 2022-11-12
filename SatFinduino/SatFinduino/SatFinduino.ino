/* SatFinduino
 * SHARP BS2F7HZ0194 STV0299/IX2410 based DVB-S Full NIM (SHARP 0194A)
 * 
 */

#define TUNER_194A 0x68               // 7-bit i2c address (0x68) B1101000
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin();

  Wire.beginTransmission(TUNER_194A); // main device address
  Wire.write(0);                      // write data 0
  Wire.endTransmission();

  Wire.requestFrom(TUNER_194A, 1);    // request 1 byte data
  int test = Wire.read();             // read test data
  if (test == 0xA1)                   // tuner test address
  {
    Serial.println("Tuner Communication OK");
  }
  else
  {
    Serial.println("ERROR");
  }
    delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:

}
