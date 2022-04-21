//PROGRAMA UTILIZADO NO ROBÔ FEITO POR THIAGO BATISTA ARAÚJO, LUIZ OTÁVIO DE OLIVEIRA, RYAN ALVES E SAMUEL BÁRBARA
//DIA 02/10/2019
//SEGUNDO MECATRÔNICA 
//CEFET-MG, VARGINHA
//=====================================================================================================================================================
//MAPEAMENTO DE HARDWARE//
#define Sensor1    A1      // define que o sensor infravermelho 1 (mais a esquerda)está na entrada analógica 1 do arduino
#define Sensor2    A2      //define que o sensor infravermelho 2 (central)está na entrada analógica 2 do arduino
#define Sensor3    A3      //define que o sensor infravermelho 3 (mais a direita) está na entrada analógica 3 do arduino 

#define PwmA  3            //define que o Enable do motor A está no pino digital 3(controle de velocidade)
#define PwmB  11           //define que o Enable do motor B está no pino digital 11(controle de velocidade)

#define MotorA1   4        //vcc ou gnd(sentido de rotação motor A). Pino provindo (In1) do módulo controlador de motor l298N. DIGITAL
#define MotorA2   5        //vcc ou gnd(sentido de rotação motor A).Pino provindo (In2) do módulo controlador de motor l298N. DIGITAL

#define MotorB1   6        //vcc ou gnd(sentido de rotação motor B).Pino provindo (In3) do módulo controlador de motor l298N. DIGITAL
#define MotorB2   7        //vcc ou gnd(sentido de rotação motor B).Pino provindo (In4) do módulo controlador de motor l298N. DIGITAL

#define Botao_beggin  13   //define que o botão para iniciar movimento está no pino digital 13

#define TRIGGER_PIN   9    //define que o Trigger do sensor ultrassônico está no pino digital 9
#define ECHO_PIN      12   //define que o Eccho do sensor ultrassônico no pino digital 12

//=====================================================================================================================================================
//FUNÇÕES//
//EXPLICADAS DE FORMA MAIS DIDÁTICA NOS SEUS RESPECTIVOS DESENVOLVIMENTOS
int Sensor_calibrar();//função que fará a calibração dos sensores
float Erro_determin();//função que deterimina o erro                                                  
float ControlePID();//função responsável pelo controle PID utilizado no controle do robô sobre a linha, neste caso, apenas o proporcional
void Robo_frente();//função que fará o robô se mover para frente
void Robo_direita();//função que fará o robô se mover para direita
void Robo_esquerda();//função que fará o robô se mover para esquerda
void andar();//função que engloba todos os processos para realização do robo seguir LINHA
//=====================================================================================================================================================
//VARIAVEIS GLOBAIS//
//EXPLICADAS SUAS FUNÇÕES MAIS DETALHADAMENTE EM SUAS RESPECTIVAS FUNÇÕES
int media,erro,ValorPwm = 70;
float ValorSensor1, ValorSensor2, ValorSensor3, Valormax = 0, Valormin = 1023,PID, DistanciaemCM;
//int32_t t,t0;
//byte x;
float kp = 29, ki = 0, kd = 0, proporcional, integral, derivado, erroPrevisto = 0;//utilizadas no calculo do proporcional
float dist, pulso;//utilizadas no calculo da distância do objeto
//=====================================================================================================================================================\\
//DESENVOLVIMENTO DAS FUNÇÕES//
void andar()//função responsável por fazer o rôbo seguir linha
{
    ValorSensor1 = analogRead(Sensor1);//variável global armazena valor lido pelo sensor infravermelho 1 (O mais à esquerda)
    ValorSensor2 = analogRead(Sensor2);//variável global armazena valor lido pelo sensor infravermelho 2 (Sensor central)
    ValorSensor3 = analogRead(Sensor3);//variável global armazena valor lido pelo sensor infravermelho 1 (O mais à direira)
    
    Erro_determin();//chamamos a função que, como já citado anteriormente, determina o erro para que assim seja possível fazer o controle proporcional
    ControlePID();//chama-se a função que, como citado, é responsável por fazer o cálculo do proporcional
  
    if (PID > 0) //caso o return de PID (só o P, nesta etapa), calculado pela função ControlePID() for > 0
    {
      Robo_direita();//função que, como já citado, é responsável por fazer o robô virar para a direita
    }
    if (PID == 0)//caso o return de PID (só o P, nesta etapa), calculado pela função ControlePID() for == 0
    {
      Robo_frente();//chama-se a função responsável por fazer o robô andar para frente
    }
    if (PID < 0)//caso o return de PID (só o P, nesta etapa), calculado pela função ControlePID() for < 0
    {
      Robo_esquerda();//chama-se a função responsável por fazer o robô andar para a esquerda
    }

}

int Sensor_calibrar()//função responsável por fazer a calibração dos sensores infravermelhos
{
  for (int t = 0; t <= 5; t++)
  {
    ValorSensor1 = analogRead(Sensor1);//atribuindo o valor analógico lido pelo sensor 1 (mais a esquerda) na variável global
    ValorSensor2 = analogRead(Sensor2);//atribuindo o valor analógico lido pelo sensor 2 (mais a esquerda) na variável global
    ValorSensor3 = analogRead(Sensor3);//atribuindo o valor analógico lido pelo sensor 3 (mais a esquerda) na variável global

    //como visto nas variáveis globais, foi atribuído às variáveis Valormin e valormax os valores de 1023 e 0, respectivamente
    if (ValorSensor1 < Valormin) 
      Valormin = ValorSensor1;
    if (ValorSensor2 < Valormin) 
      Valormin = ValorSensor2;
    if (ValorSensor3 < Valormin)
      Valormin = ValorSensor3;
    //nessa parte da função, pega-se o maior valor lido entre os 3 sensores infravermelhos e atribui à variável que iniciou com o valor 1023(Valormin)
    if (ValorSensor1 > Valormax)
      Valormax = ValorSensor1;
    if (ValorSensor2 > Valormax)
      Valormax = ValorSensor2;
    if (ValorSensor3 > Valormax)
      Valormax = ValorSensor3;
  
   //nessa parte da função, pega-se o maior valor lido entre os 3 sensores infravermelhos e atribui à variável que iniciou com o valor 0 (Valormax)
  }
  //com os valores obtidos (o maior e o menor lido entre os 3 sensores infravermelhos), acha-se um valor Limiar
  media = (Valormax + Valormin) / 2; //cálculo do valor limiar atribuido à variável global media
  //o processo seguinte apenas gira os dois motores com velocidade max para sinalizar que a calibração foi terminada
    analogWrite(PwmA, 255);//motor da esquedarda gira em sua maior velocidade
    analogWrite(PwmB, 255);//motor da direita gira em sua maior velocidade
    delay(2000);//gira-se os motores por 2 segundos
    analogWrite(PwmA, 0);//resseta o motor A (o da esquerda)
    analogWrite(PwmB, 0);//resseta o motor B (o da esquerda)
  return media;//retorna o valor limiar(media)
}

float Erro_determin()//função responsável por calcular um erro que posteriormente será utilizado para calcular o proporcional
{

  float v[3] = {ValorSensor1, ValorSensor2, ValorSensor3};//adicionando um vetor do tipo float que armazenará os valores lidos pelos sensores infravermelhos e fará uma lógica básica que retornará o erro de acordo com "qual" leitor está lendo
  

  if((v[0] < media)&&(v[1] < media)&&(v[2] >= media))     erro = 2;//caso v[0] (ValorSensor1), for menor que o valor limiar(media)e v[1] (ValorSensor2), for menor que o valor limiar(media) e caso v[2] (ValorSensor3), for maior que o valor limiar(media), erro = 2 
  if((v[0] < media)&&(v[1] >= media)&&(v[2] >= media))    erro = 1;//mesma princípio, apenas retornando valores de "erro" menor
  if((v[0] < media)&&(v[1] >= media)&&(v[2] < media))     erro = 0;//mesma princípio, apenas retornando valores de "erro" menor
  if((v[0] >= media)&&(v[1] >= media)&&(v[2] < media))    erro = -1;//mesma princípio, apenas retornando valores de "erro" menor
  if((v[0] >= media)&&(v[1] < media)&&(v[2] < media))     erro = -2;//mesma princípio, apenas retornando valores de "erro" menor
  
  return erro;//retorna-se o erro calculado
}

void Robo_frente()//função responsável por fazer o robô andar para frente
{
  analogWrite(PwmA, constrain(200 + PID, 10, 255));//velocidade do motor da esquerda quando o erro for 0, ou seja, quando o sensor central, exclusivamente, estiver em cima da linha. A função constrain serve para manter o valor resultante da soma de pid + 200(testado empiricamente) em uma faixa de valor desejado, para que assim a soma não seja saturada
  analogWrite(PwmB, constrain(200 + PID, 10, 255));//velocidade do motor da direita quando o erro for 0, ou seja, quando o sensor central, exclusivamente, estiver em cima da linha. A função constrain serve para manter o valor resultante da soma de pid + 200(testado empiricamente) em uma faixa de valor desejado, para que assim a soma não seja saturada 
}

void Robo_direita()//função responsável por fazer o robô andar para a direita
{
  
  analogWrite(PwmA, constrain(ValorPwm + PID, 10, 255));//velocidade do motor quando o erro for maior que 0
  analogWrite(PwmB, constrain(ValorPwm - PID, 10, 255));//velocidade do motor da direita quando o erro for maior que 0
 
}
void Robo_esquerda()//função responsável por fazer o robô andar para a esquerda
{
  
  analogWrite(PwmA,constrain(ValorPwm + PID, 10, 255));//velocidade do motor quando o erro for menor que 0
  analogWrite(PwmB,constrain(ValorPwm - PID, 10, 255));//velocidade do motor quando o erro for menor que 0
  //A variavel "ValorPwm" já foi determinado antes e é constante, ou seja,o unico que varia é o valor atribuido à variável pid, que é = erro *kp
  //Neste caso, "PID" possui um valor negativo, portando, a velocidade do motor da esquerda diminui proporcionalmente ao aumento da velocidade do motor da direita 
}

float ControlePID()//função responsável por realizar o calcúlo do proporcional
{
  proporcional = erro * kp;//na variavel erro, foi etribuido um valor anteriormente, por meio de lógica. Kp é uma constante que é multiplicada ao "erro" e é testada empiricamente
  integral += erro * ki;//não utilizada por enquanto, o resultado da 0
  derivado = ((erro - erroPrevisto) * kd);//não utilizada por enquanto, o resultado da 0
  erroPrevisto = erro;//não utilizada por enquanto, o resultado da 0
  PID = proporcional + integral + derivado;//integral e derivada = 0, ou seja, a soma atribuída à variável global "PID", é igual à "proporcional"
  return PID; //retorna o valor calculado na função
}
//=====================================================================================================================================================
//SETUP E LOOP//
void setup() {
  Serial.begin(9600);
  pinMode(MotorA1, OUTPUT);//determina o pino In1, que vem do shield l298N como saída
  pinMode(MotorA2, OUTPUT);//determina o pino In2, que vem do shield l298N como saída
  pinMode(MotorB1, OUTPUT);//determina o pino In3, que vem do shield l298N como saída
  pinMode(MotorB2, OUTPUT);//determina o pino In4, que vem do shield l298N como saída
  pinMode(TRIGGER_PIN, OUTPUT);//determina o trigger do ultrassônico como saída
  pinMode(ECHO_PIN, INPUT);//determina o eccho do ultrassônico como entrada
  digitalWrite(TRIGGER_PIN, LOW);//inicia o trigger com nível lógico baixo

  pinMode(Sensor1, INPUT);//determina o sensor infravermelho 1 como entrada
  pinMode(Sensor2, INPUT);//determina o sensor infravermelho 2 como entrada
  pinMode(Sensor3, INPUT);//determina o sensor infravermelho 3 como entrada
  pinMode(Botao_beggin, INPUT_PULLUP);//determina o botão que inicia o movimento como entrada, informando que este neste será ultilizado pull-up interno

  //como apenas um sentido de rotação será utilizado no robô, determinei este no setup (realiza apenas uma vez)
  digitalWrite(MotorA1, HIGH);//sentido de rotação motor da esquerda. 
  digitalWrite(MotorA2, LOW);//sentido de rotação motor da esquerda
  digitalWrite(MotorB1, LOW);//sentido de rotação motor da direita
  digitalWrite(MotorB2, HIGH);//sentido de rotação motor da direita

  Sensor_calibrar();//chama-se a função já explicada para relizar a calibração dos sensores infravermelhos (apenas 1 vez também)
  while(1)
 {
   if(!digitalRead(Botao_beggin)) //se o botão que inicia o movimento for apertado..
   break;//sai do setup
 }
   
}


void loop()
{

  digitalWrite(TRIGGER_PIN, HIGH);//o trigger do robô é iniciado (começa e emitir ultrasons) por...
  delayMicroseconds(10);//10 microsegundos
  digitalWrite(TRIGGER_PIN,  LOW);//o trigger é colocado em nível lógico baixo (para de emitir ultrasons)
  delayMicroseconds(3);//delay só para "melhorar o processamento"

  float sensor = pulseIn(ECHO_PIN, HIGH, 500000)/58.0;//a variável local "sensor" recebe o que pelo eccho do ultrassônico é recebido, por 500000 microsegundos dividido por 58.0
  //o valor resulrante acima equivale à uma distância x em centimetros
  if(sensor < 15.0)//caso essa distância for menor que 15
  {
      digitalWrite(PwmA,0);//motor da esquerda é zerado, ou seja, para de rodar
      digitalWrite(PwmB,0);//motor da direita é zerado, ou seja, para de rodar
  }
   else//caso contrário,
     andar();//chama-se a função responsável por fazer o robô seguir linha
} 
