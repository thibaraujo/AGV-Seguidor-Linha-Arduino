#define Sensor1    A1 //sensor 1 na entrada anaógica 1
#define Sensor2    A2 //sensor 2 na entrada anaógica 2
#define Sensor3    A3 //sensor 3 na entrada anaógica 3

void setup() {
  Serial.begin(9600);
  
  pinMode(Sensor1, INPUT);//entrada
  pinMode(Sensor2, INPUT);//entrada
  pinMode(Sensor3, INPUT);//entrada

  
 
void loop() {
  int media;
  float ValorSensor1,ValorSensor2,ValorSensor3,Valormax = 0,Valormin = 1023;
   
    for(int t=0;t<=5;t++){
         ValorSensor1 = analogRead(Sensor1); 
         ValorSensor2 = analogRead(Sensor2); 
         ValorSensor3 = analogRead(Sensor3); 
      
          if(ValorSensor1< Valormin)
      Valormin = ValorSensor1;
          if(ValorSensor2< Valormin)
      Valormin = ValorSensor2;
          if(ValorSensor3< Valormin)
      Valormin = ValorSensor3;

      Serial.println(Valormin);
      delay(2000);
      
        if(ValorSensor1 > Valormax)
      Valormax = ValorSensor1; 
        if(ValorSensor2 > Valormax)
      Valormax = ValorSensor2;
        if(ValorSensor3 > Valormax)
      Valormax = ValorSensor3;

      
      Serial.println(Valormax);
      delay(2000);
 }
  
  media = (Valormax + Valormin)/2;
  Serial.println(media);
  delay(2000);
}
