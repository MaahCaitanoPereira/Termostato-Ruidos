

double rele = A1;   //saída para relé de maior potência


  double doubleMap(double x, double in_min, double in_max, double out_min, double out_max) 
  {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }

void setup() 
{

  Serial.begin(9600);      //inicia a comunicação Serial
  
} 

void loop() 
{
  double x, t; 
  
  x = analogRead(rele); 
  
  //x = map(x,0,1023,0,255);
  
  t = (x /(10.24));   // valor entre 1023 menos 255 = 7.69

  x = doubleMap( x, 20.00, 30.00, 22.00, 23.00);
  
  Serial.println(t);

  delay(1500);
  
 
} 


 
  
