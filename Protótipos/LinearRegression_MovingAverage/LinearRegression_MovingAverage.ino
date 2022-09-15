 //Fonte : https://github.com/cubiwan/LinearRegressino

#include <LinearRegression.h>

double rele = A1;
double x;
double t;
double tnova;
double media;
double somat;
double h;

  #define     num    50

  long moving_average(int sig);

  int values[num];
  int adc_noise1,               
      adc_noise2;


LinearRegression lr = LinearRegression();

void setup()
{
    Serial.begin(9600);
    pinMode(rele, INPUT);
}

void loop()
{
    for(int m = 0; m<=10; m++)
    {
       x = analogRead(rele);
       t= x/10.24;
       lr.learn(m,t);
    }

    for(int n = 0; n<=10; n++)
    {
     //Serial.println(lr.calculate(j));
     tnova = lr.calculate(n);
     delay(500);
    }
    lr.reset();
    
  adc_noise1 = tnova;
  adc_noise2 = moving_average(adc_noise1);

  Serial.println(tnova);
  delay(500);
} 


  // FUNCAO DA MEDIA MOVEL RETIRADA DO LINK DO YOUTUBE

  long moving_average(int sig)
{
  int i;               //variável auxiliar para iterações
  long acc = 0;        //acumulador
  
  //Desloca o vetor completamente eliminando o valor mais antigo
  for(i = num; i > 0; i--) values[i] = values[i-1];    
  
  values[0] = sig;           //carrega o sinal no primeiro elemento do vetor
  
 // long sum = 0;            //Variável para somatório
  
  for(i = 0; i < num; i++) acc += values[i];
   
  return acc / num;         //Retorna a média móvel

} 
