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
#define Buzzer        10

//Criando objeto ultrasonic e definindo as portas digitais
//do Trigger - 9 - e Echo - 10
Ultrasonic SensorUltrassonico1(TRIGGER_PIN, ECHO_PIN  );


//=====================================================================================================================================================
//=====================================================================================================================================================
//VARIAVEIS GLOBAIS//
long Microsegundos = 0;   // Variável para armazenar o valor do tempo da reflexão do som refletido pelo objeto fornecido pela biblioteca do sensor
float DistanciaemCM = 0;  // Variável para armazenar o valor da distância a ser convertido por uma função da própria bilbioteca do sensor

//=====================================================================================================================================================
//SETUP E LOOP//
void setup() {
  Serial.begin(9600);
  pinMode(MotorA1, OUTPUT);//saída
  pinMode(MotorA2, OUTPUT);//saída
  pinMode(MotorB1, OUTPUT);//saída
  pinMode(MotorB2, OUTPUT);//saída

  pinMode(Sensor1, INPUT);//entrada
  pinMode(Sensor2, INPUT);//entrada
  pinMode(Sensor3, INPUT);//entrada

  digitalWrite(MotorA1, HIGH);
  digitalWrite(MotorA2, LOW);
  digitalWrite(MotorB1, LOW);
  digitalWrite(MotorB2, HIGH);

   pinMode(ECHO_PIN, INPUT);
   pinMode(TRIGGER_PIN, OUTPUT);

  

}

void loop() {
  DistanciaemCM = SensorUltrassonico1.convert(SensorUltrassonico1.timing(), Ultrasonic::CM);
  Serial.println(DistanciaemCM);
  while(DistanciaemCM < 10){

  analogWrite(PwmA, 0);
  analogWrite(PwmB, 0);
  DistanciaemCM = SensorUltrassonico1.convert(SensorUltrassonico1.timing(), Ultrasonic::CM);
  Serial.println(DistanciaemCM);
  }
  analogWrite(PwmA, 255);
  analogWrite(PwmB, 255);
 }
