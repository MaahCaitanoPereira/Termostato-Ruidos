
// ESTA FUNCIONANDO PARA TEMPERATURA AMBIENTE

#include <MegunoLink.h>
#include <Filter.h>

#define termostato 9
double rele = A1;

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
 double x,va;
 
 double RawValue = analogRead(rele);

 ADCFilter.Filter(RawValue);

// dmenor = inserir o menor valor da escala, outliers
// dmaior = inserir o maior valor da escala, outliers
// pmenor = inserir o menor valor alvo 
// pmaior = inserir o maior valor alvo 

// x = doublemap(variavel,dmenor,dmaior,pmenor,pmaior);
     
     x = (RawValue/(10.24));
     
     x = doubleMap( x, 18.00, 40.00, 23.50, 25.00);
 
 ADCFilter.Filter(x);
 
 Serial.println(x);
 delay(1500);
}
