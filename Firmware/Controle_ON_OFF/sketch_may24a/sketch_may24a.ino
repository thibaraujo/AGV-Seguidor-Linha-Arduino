//teste para programação do robô

#define Sensor1 A0//sensor 1 na entrada digital 0
#define Sensor2 A1//sensor 2 na entrada digital 1 
#define Sensor3 A2//sensor 3 na entrada digital 2
#define Sensor4 A3//sensor 3 na entrada digital 2

#define PwmA 3//Enable do motor A no pino 11(controle de velocidade)
#define PwmB 5//Enable do motor B no pino 3 (controle de velocidade)

#define MotorA1 4 //vcc ou gnd(sentido de rotação motor A)
#define MotorA2 6//vcc ou gnd(sentido de rotação motor A)

#define MotorB1 7//vcc ou gnd(sentido de rotação motor B)
#define MotorB2 8//vcc ou gnd(sentido de rotação motor B)

#define Botao 13//botão para iniciar movimento no pino digital 13

#define TRIGGER_PIN 9
#define ECHO_PIN 12


                    //Determinado a velocidade inicial dos motores//
                    
int ValorPwmA = 200;//2,94V chegando no motor
int ValorPwmB = 200;//2,94V chegando no motor


void setup() {
  Serial.begin(9600);
  pinMode(MotorA1, OUTPUT);//saída
  pinMode(MotorA2, OUTPUT);//saída
  pinMode(MotorB1, OUTPUT);//saída
  pinMode(MotorB2, OUTPUT);//saída
  pinMode(Sensor1, INPUT);//entrada
  pinMode(Sensor2, INPUT);//entrada
  pinMode(Sensor3, INPUT);//entrada
  pinMode(Sensor4, INPUT);//entrada
  pinMode(Botao, INPUT_PULLUP);//entrada
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(MotorA1, HIGH);
  digitalWrite(MotorA2, LOW);
  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, HIGH);

 

}
void loop() {

     // Serial.println(".");
      
      bool ValorSensor1 = digitalRead(Sensor1);
      bool ValorSensor2 = digitalRead(Sensor2);
      bool ValorSensor3 = digitalRead(Sensor3);
      bool ValorSensor4 = digitalRead(Sensor4);
      //*/

    //preto == 1;
      
    //}
      
      if(!ValorSensor1&&!ValorSensor2&&!ValorSensor3&&!ValorSensor4){ // 0000
        analogWrite(PwmA, 80);
        analogWrite(PwmB, 80);
      }
        if(!ValorSensor1&&ValorSensor2&&!ValorSensor3&&!ValorSensor4){//0100
        analogWrite(PwmA, 30);
        analogWrite(PwmB, 100);
      }
        if(!ValorSensor1&&!ValorSensor2&&ValorSensor3&&!ValorSensor4){//0010
        analogWrite(PwmA, 100);
        analogWrite(PwmB, 30);
      }
        if(ValorSensor1&&!ValorSensor2&&!ValorSensor3&&!ValorSensor4){//1000
        analogWrite(PwmA, 0);
        analogWrite(PwmB, 160);
      }
        if(!ValorSensor1&&!ValorSensor2&&!ValorSensor3&&ValorSensor4){//0001
        analogWrite(PwmA, 160);
        analogWrite(PwmB, 0);
      }
        if(ValorSensor1&&ValorSensor2&&!ValorSensor3&&!ValorSensor4){//1100
        analogWrite(PwmA, 0);
        analogWrite(PwmB, 120);
      }
        if(!ValorSensor1&&!ValorSensor2&&ValorSensor3&&ValorSensor4){//0011
        analogWrite(PwmA, 120);
        analogWrite(PwmB, 0);
      }


}

 
    
  
  
