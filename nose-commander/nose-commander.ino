#include <SoftwareSerial.h>
#include "TransceiverModule.h"
#include <Adafruit_GPS. h>


#include "GpsSensor.h"


#include <Wire.h>
GpsSensor gpsSensor;
TransceiverModule transceiver;
float array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int arraySize = 9;
char input;

long gps_output_count = 0;
void setup()
{
  gpsSensor.Init();
  transceiver.Init('N');
}

void loop()
{
  //Get and transmit GPS data
  if ( millis() > 500 * gps_output_count)
  {
    gpsSensor.GetData(array);
    transceiver.SendData(array, arraySize, 'GG', '8');
    gps_output_count++;
  }
  
  //Get and retransmit data from XBEE
  while(Serial.available()>0)
  {
    input=Serial.read();
    if(input=='A')
      input='N';
    Serial.write(input);
  }
}
