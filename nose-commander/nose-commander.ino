#include <SoftwareSerial.h>

#include <Adafruit_GPS.h>


#include "GpsSensor.h"


#include <Wire.h>
GpsSensor gpsSensor;
float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
void setup()
{
  gpsSensor.Init();
}

void loop()
{
  //Serial.println("Test");
  //Get and transmit GPS data
  gpsSensor.GetData(array);
  Serial.write('0xFF');
  Serial.print(" N");
  for(int i=0; i<9; i++)
  {
    Serial.print(" ");
    Serial.print(array[i]);
  }
  Serial.write('0XFF');
  Serial.write('/r');
  
  //Get and retransmit data from XBEE
  Serial.println(Serial.read());
}
