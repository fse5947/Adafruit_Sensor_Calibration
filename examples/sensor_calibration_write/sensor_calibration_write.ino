#include "Adafruit_Sensor_Calibration.h"

Adafruit_Sensor_Calibration cal;

void setup() {
  while (!Serial) delay(10);
  Serial.begin(115200);

  delay(100);
  Serial.println("Calibration filesys test");
  if (!cal.begin()) {
    Serial.println("Failed to initialize calibration helper");
    while (1) yield();
  }
  Serial.print("Has EEPROM: "); Serial.println(cal.hasEEPROM());
  Serial.print("Has FLASH: "); Serial.println(cal.hasFLASH());

  if (! cal.loadCalibration()) {
    Serial.println("No calibration loaded/found... will start with defaults");
  } else {
    Serial.println("Loaded existing calibration");
  }

  // in uTesla
  cal.mag_hardiron[0] = -3.35;
  cal.mag_hardiron[1] = -0.74;
  cal.mag_hardiron[2] = -40.79;

  // in uTesla
  cal.mag_softiron[0] = 0.965;
  cal.mag_softiron[1] = 0.018;
  cal.mag_softiron[2] = 0.010;  
  cal.mag_softiron[3] = 0.018;
  cal.mag_softiron[4] = 0.960;
  cal.mag_softiron[5] = 0.003;  
  cal.mag_softiron[6] = 0.010;
  cal.mag_softiron[7] = 0.003;
  cal.mag_softiron[8] = 1.080;  

  // in Radians/s
  cal.gyro_zerorate[0] = 0.05;
  cal.gyro_zerorate[1] = -0.01;
  cal.gyro_zerorate[2] = -0.01;

  if (! cal.saveCalibration()) {
    Serial.println("**WARNING** Couldn't save calibration");
  } else {
    Serial.println("Wrote calibration");    
  }

  cal.printSavedCalibration();
}

void loop() {

}
