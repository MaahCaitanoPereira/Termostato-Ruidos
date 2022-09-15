#include <MegunoLink.h>
#include <Filter.h>

#define termostato 9
double rele = A1;

long FilterWeight = 50;
ExponentialFilter<long> ADCFilter(FilterWeight, 0);


void setup() 
{
  Serial.begin(9600);
  //pinMode(rele, INPUT);   //saída para relé
}

void loop() 
{
 double x,va,z;
 
 double RawValue = analogRead(rele);

 ADCFilter.Filter(RawValue);
 
 //x= (RawValue/(10.24));
 
 ADCFilter.Filter(x);
 
 z = ADCFilter.Current(x);
 va=(x/10.24);
 
 Serial.println(x);
 delay(2000);
}
