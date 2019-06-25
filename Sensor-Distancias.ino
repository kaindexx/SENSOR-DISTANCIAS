//Sensor de distancias
long distancia;
long pulso;
int pinTrig=13; //Salida Trigger 
int pinEcho=12; //Entrada Echo
int pinLed=11;  //Led pulso


void setup() 
{
  Serial.begin(9600);//Iniciando la comunicacion serial
  //sensor ultrasonido
  pinMode(pinTrig,OUTPUT);
  pinMode(pinEcho,INPUT);
  //led
  pinMode(pinLed,OUTPUT);
  digitalWrite(pinLed,LOW);
  //Mensaje de conexion
  Serial.println("MODULO CONECTADO");
  Serial.print("#");
  
}

void loop() 
{
  digitalWrite(pinTrig,LOW);
  delayMicroseconds(5);
  digitalWrite(pinTrig,HIGH);
  delayMicroseconds(10);
  pulso=pulseIn(pinEcho,HIGH);
  Serial.print("Tiempo = ");
  Serial.print(float(pulso/1000.0));
  Serial.print("MiliSegundos, Distancia = ");
  distancia = ((float(pulso/1000.0))*34.32)/2;
  Serial.print(distancia);
  Serial.println("cm");
  delay(1000);
  if(Serial.available())  
  {
    char VarRead;
    VarRead=Serial.read();

    if(VarRead=='1')
    {
      Serial.print(distancia);
      Serial.println("cm");
      Serial.println("#");
    }
    if(VarRead=='0')
    {
       Serial.println(" ");
       Serial.println("#");
      
    }
    
  }
   
}
