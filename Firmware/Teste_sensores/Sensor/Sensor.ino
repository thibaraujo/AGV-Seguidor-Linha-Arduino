#define Sensor1    A0     //sensor 1 na entrada analógica 1
#define Sensor2    A1      //sensor 2 na entrada analógica 2
#define Sensor3    A2      //sensor 3 na entrada analógica 3
#define Sensor4    A3      //sensor 3 na entrada analógica 4
  

void setup() {
  Serial.begin(9600);
  pinMode(Sensor1, INPUT);//entrada
  pinMode(Sensor2, INPUT);//entrada
  pinMode(Sensor3, INPUT);//entrada
 // pinMode(Sensor4, INPUT);//entrada
 
}

void loop() {
   int ValorSensor1 = digitalRead(Sensor1);
   Serial.print("1\t");
   Serial.println (ValorSensor1);
   delay(2000);
  int ValorSensor2 = digitalRead(Sensor2);
   Serial.print("2\t");
   Serial.println (ValorSensor2);
   delay(2000);
   int ValorSensor3 = digitalRead(Sensor3);
   Serial.print("3\t");
   Serial.println (ValorSensor3);
   delay(2000);
   int ValorSensor4 = digitalRead(Sensor4);
   Serial.print("4\t");
   Serial.println (ValorSensor4);
   delay(2000);
}
