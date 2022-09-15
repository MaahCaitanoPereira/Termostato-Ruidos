#include <MegunoLink.h>
#include <Filter.h>

#define termostato 9

const int rele = A0;
float x = 0;


long FilterWeight = 100;
ExponentialFilter<long> ADCFilter(FilterWeight, 0);


  double doubleMap(double x, double in_min, double in_max, double out_min, double out_max) 
  {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
 
 double RawValue = analogRead(rele);

 ADCFilter.Filter(RawValue);

     //RawValue = map(RawValue,0,1023,0,255);
     
    // x = doubleMap( x, 20.00, 30.00, 22.00, 23.00);
     
     x = (RawValue/(10.24));
 
 ADCFilter.Filter(x);
 

 Serial.println(x);
 delay(1500);
}
