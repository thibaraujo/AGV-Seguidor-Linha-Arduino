//=====================================================================================================================================================
//MAPEAMENTO DE HARDWARE//
#define Sensor1    A1      //sensor 1 na entrada analógica 1
#define Sensor2    A2      //sensor 2 na entrada analógica 2
#define Sensor3    A3      //sensor 3 na entrada analógica 3

#define PwmA  3            //Enable do motor A no pino 11(controle de velocidade)
#define PwmB  11           //Enable do motor B no pino 3 (controle de velocidade)

#define MotorA1   4        //vcc ou gnd(sentido de rotação motor A)
#define MotorA2   5        //vcc ou gnd(sentido de rotação motor A)

#define MotorB1   6        //vcc ou gnd(sentido de rotação motor B)
#define MotorB2   7        //vcc ou gnd(sentido de rotação motor B)

#define Botao_beggin  13   //botão para iniciar movimento no pino digital 13

#include "Ultrasonic.h"    //Incluindo biblioteca Ultrasonic.h
#define TRIGGER_PIN   9    // Arduino pin tied to trigger pin on ping sensor.
#define ECHO_PIN      12




Ultrasonic SensorUltrassonico1(TRIGGER_PIN, ECHO_PIN  );

//=====================================================================================================================================================
//FUNÇÕES//

int Sensor_calibrar();    //função que fará a calibração dos sensores
float Erro_determin();    //função que deterimina o erro                                                  
float ControlePID();      //função responsável pelo controle PID utilizado no controle do robô sobre a linha
void Robo_frente();       //função que fará o robô se mover para frente
void Robo_direita();      //função que fará o robô se mover para direita
void Robo_esquerda();     //função que fará o robô se mover para esquerda
void andar();

//=====================================================================================================================================================
//VARIAVEIS GLOBAIS//
int media,erro,ValorPwm = 60;
float ValorSensor1, ValorSensor2, ValorSensor3, Valormax = 0, Valormin = 1023,PID;
float kp = 30, ki = 1.4, kd = 3.5, proporcional, integral, derivado, erroPrevisto = 0;
float distCM;

//====================================================================================================================================================\\
//DESENVOLVIMENTO DAS FUNÇÕES//
void andar()
{
    ValorSensor1 = analogRead(Sensor1);
    ValorSensor2 = analogRead(Sensor2);
    ValorSensor3 = analogRead(Sensor3);
    
    Erro_determin();
    ControlePID();
  
    if (PID > 0)
    {
      Robo_direita();
    }
    if (PID == 0)
    {
      Robo_frente();
    }
    if (PID < 0)
    {
      Robo_esquerda();
    }

}

int Sensor_calibrar()
{
  for (int t = 0; t <= 5; t++)
  {
    ValorSensor1 = analogRead(Sensor1);
    ValorSensor2 = analogRead(Sensor2);
    ValorSensor3 = analogRead(Sensor3);


    if (ValorSensor1 < Valormin)
      Valormin = ValorSensor1;
    if (ValorSensor2 < Valormin)
      Valormin = ValorSensor2;
    if (ValorSensor3 < Valormin)
      Valormin = ValorSensor3;

    if (ValorSensor1 > Valormax)
      Valormax = ValorSensor1;
    if (ValorSensor2 > Valormax)
      Valormax = ValorSensor2;
    if (ValorSensor3 > Valormax)
      Valormax = ValorSensor3;
    delay(2000);
  }

  media = (Valormax + Valormin) / 2;
    analogWrite(PwmA, 255);
    analogWrite(PwmB, 255);
  delay(2000);
    analogWrite(PwmA, 0);
    analogWrite(PwmB, 0);
  delay(2000);
  return media;
}

float Erro_determin()
{

  float v[3] = {ValorSensor1, ValorSensor2, ValorSensor3};
  

  if((v[0] < media)&&(v[1] < media)&&(v[2] >= media))     erro = 2;
  if((v[0] < media)&&(v[1] >= media)&&(v[2] >= media))    erro = 1;
  if((v[0] < media)&&(v[1] >= media)&&(v[2] < media))     erro = 0;
  if((v[0] >= media)&&(v[1] >= media)&&(v[2] < media))    erro = -1;
  if((v[0] >= media)&&(v[1] < media)&&(v[2] < media))     erro = -2;
  
  Serial.println("Erro: ");
  Serial.println(erro);
  return erro;
}

void Robo_frente()
{

  analogWrite(PwmA, 100 + PID);
  analogWrite(PwmB, 100 + PID);
    Serial.println("Frente");
}

void Robo_direita()
{
  
  analogWrite(PwmA, ValorPwm + PID);
  analogWrite(PwmB, ValorPwm - PID);
  Serial.println("Direita");
}
void Robo_esquerda()
{

  analogWrite(PwmA, ValorPwm + PID);
  analogWrite(PwmB, ValorPwm - PID);
  Serial.println("Esquerda");
}

float ControlePID()
{
  proporcional = erro * kp;
  integral += erro * ki;
  derivado = ((erro - erroPrevisto) * kd);
  erroPrevisto = erro;
  PID = proporcional + integral + derivado;
  return PID;
}

//=====================================================================================================================================================
//SETUP E LOOP//
void setup() {
  Serial.begin(9600);
  pinMode(MotorA1, OUTPUT);//saída
  pinMode(MotorA2, OUTPUT);//saída
  pinMode(MotorB1, OUTPUT);//saída
  pinMode(MotorB2, OUTPUT);//saída
  pinMode(9, OUTPUT);
  pinMode(12, INPUT); 

  pinMode(Sensor1, INPUT);//entrada
  pinMode(Sensor2, INPUT);//entrada
  pinMode(Sensor3, INPUT);//entrada
  pinMode(Botao_beggin, INPUT_PULLUP);//entrada


  digitalWrite(MotorA1, HIGH);
  digitalWrite(MotorA2, LOW);
  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, HIGH);

 Sensor_calibrar();
 while(1){
  if(!digitalRead(Botao_beggin))
  break;
 }
}


void loop()
{
  andar(); 
}



    
    
      
  
