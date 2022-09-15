// Fonte: https://github.com/cubiwan/Regressino

#include <PolynomialRegression.h>

double rele = A1;
double x;
double t;
double tnova;
double media;
double somat;
double h;

PolynomialRegression pr = PolynomialRegression();

void setup() 
{
  Serial.begin(9600);   
  pinMode(rele, INPUT);
}

void loop() 
{
  for(int i = 0; i < 50; i++)
  {
   x = analogRead(rele);
   t= x/10.24;
   pr.learn(i,t);    
  }
  
  for(int j = 0; j<=50; j++)
   {
   //Serial.println(pr.calculate(j));
   delay(50);
   tnova= pr.calculate(j);
   }
   pr.reset();

    if (h = 14)
    {
     somat= somat + tnova;
     media= somat/h;
     Serial.println(media);
     h=0;
    } 
}
