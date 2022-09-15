
int vet[10], k, m, n, o, result;
double rele = A1;
double x;
double t;

void setup() 
{
  Serial.begin(9600);
  pinMode(rele, INPUT);
}

void loop() 
{
  for(k=0; k<=10; k++)
  {
   x = analogRead(rele);
   t= x/10.24;
   result = t;
   vet[k]= result;

   Serial.println(vet[k]);
   delay(500);
  }
  
  Serial.println("Nova contagem");
  return k=0;
}
