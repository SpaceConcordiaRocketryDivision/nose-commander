#include <SoftwareSerial.h>

#include <Adafruit_GPS. h>


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
  //Get and transmit GPS data
  gpsSensor.GetData(array);
  Serial.write('0xFF');
  Serial.print(":N:0:GG");
  for(int i=0; i<9; i++)
  {
    Serial.print(":");
    Serial.print(array[i]);
  }
  Serial.print(":");
  Serial.write('0XFF');
  Serial.write('/r');
  Serial.println();
  
  //Get and retransmit data from XBEE
  while(Serial.available()>0)
    Serial.print(Serial.read());
}
