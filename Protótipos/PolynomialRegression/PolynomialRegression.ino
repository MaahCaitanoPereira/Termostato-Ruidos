// Fonte: https://github.com/cubiwan/Regressino

#include <PolynomialRegression.h>

double rele = A1;
double x;
double t;

PolynomialRegression pr = PolynomialRegression();

void setup() 
{
  Serial.begin(9600);   
  pinMode(rele, INPUT);
}

void loop() 
{
  for(int i = 0; i<15; i++)
  {
   x = analogRead(rele);
   t= x/10.24;
   pr.learn(i,t);    
  }
  
  for(int j = 0; j<15; j++)
   {
   Serial.println(pr.calculate(j));
   delay(500);
   }
   Serial.println("novos valores");
   pr.reset();
}
