#include <PolynomialRegression.h>

int vet[14], k, m, n, o;
double rele = A1;
double x;
double t;
float somamenor=0;
double mediamenor;
float somamaior=0;
double mediamaior;
float somacentro=0;
double mediacentro;
double dmenor;
double dmaior;
double pmenor;
double pmaior;
double va;

PolynomialRegression pr = PolynomialRegression();

  double doubleMap(double x, double in_min, double in_max, double out_min, double out_max) 
  {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }


void setup() 
{
  Serial.begin(9600);
  pinMode(rele, INPUT);

}
void loop() 
{ 
////////////////////////////////////////////Polimial////////////////////////////////////////////////////

  for(int i = 0; i <15; i++)
  {
   x = analogRead(rele);
   t= x/10.24;
   pr.learn(i,t); 
  }

   for(int j = 0; j<15; j++)
   {
   pr.calculate(j);
   k = pr.calculate(j);
   vet[j]=k;
   }

////////////////////////////////////////////Media dos valores 0 a 6////////////////////////////////////////////////////
  
  for(m=0; m<7; m++)
  {
    somamenor= somamenor+vet[m];
  }
    mediamenor= somamenor/7;
    
///////////////////////////////////////////Media dos valores 10 a 14/////////////////////////////////////////////////////
    
  for(n=10; n<15; n++)
  {
    somamaior= somamaior+vet[n];
  }
    mediamaior= somamaior/5;

///////////////////////////////////////////Media dos valores 7 a 9/////////////////////////////////////////////////////

  for(o=7; o<10; o++)
  { 
    somacentro= somacentro+vet[o];
  }
    mediacentro= somacentro/3;

//////////////////////////////////////////Funcao Map//////////////////////////////////////////////////////

    dmenor= (mediamenor);   // dmenor: o menor limite do intervalo atual do valor
    dmaior= (mediamaior);   // dmaior: o maior limite do intervalo atual do valor
    pmenor= (mediacentro - 1.00);    // pmenor: o menor limite do intervalo alvo
    pmaior= (mediacentro + 1.00);    // pmaior: o maior limite do intervalo alvo

    va= map(mediacentro,dmenor,dmaior,pmenor,pmaior);   // map(talvo, dmenor, dmaior, pmenor, pmaior);

    //Serial.println(va);
    delay(500);

/////////////////////////////////////////Return 0;///////////////////////////////////////////////////////

  Serial.print(vet[0]);
  Serial.print("\t");
  Serial.print(vet[1]);
  Serial.print("\t");
  Serial.print(vet[2]);
  Serial.print("\t");
  Serial.print(vet[3]);
  Serial.print("\t");
  Serial.print(vet[4]);
  Serial.print("\t");
  Serial.print(vet[5]);
  Serial.print("\t");
  Serial.print(vet[6]);
  Serial.print("\t");
  Serial.print(vet[7]);
  Serial.print("\t");
  Serial.print(vet[8]);
  Serial.print("\t");
  Serial.print(vet[9]);
  Serial.print("\t");
  Serial.print(vet[10]);
  Serial.print("\t");
  Serial.print(vet[11]);
  Serial.print("\t");
  Serial.print(vet[12]);
  Serial.print("\t");
  Serial.print(vet[13]);
  Serial.print("\t");
  Serial.print(vet[14]);
  Serial.print("\t");
  Serial.println("novos valores");


  
  somamenor=0;
  somamaior=0;  
  somacentro=0;
  pr.reset();
}
