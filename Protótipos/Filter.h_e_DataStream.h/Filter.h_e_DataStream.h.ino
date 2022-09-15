#include <Filter.h>
#include <DataStream.h>

double rele = A1;

Filter filteredData(10); 

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{

  double x,t;
  
  x= analogRead(rele);
  
  filteredData.write(x);
  double analogMean = filteredData.mean();
  
  t = (x /(10,24)); 
  
  Serial.println(t);  
  delay(1500);
}
