#define PwmA 3
#define PwmB 11

#define MotorA1 4
#define MotorA2 5

#define MotorB1 6
#define MotorB2 7

int ValorPwmA = 150;
int ValorPwmB = 150;

void setup(){
pinMode(MotorA1, OUTPUT);
pinMode(MotorA2, OUTPUT);
pinMode(MotorB1, OUTPUT);
pinMode(MotorB2, OUTPUT);
pinMode(PwmA, OUTPUT);
pinMode(PwmB, OUTPUT);

}

void loop(){
digitalWrite(MotorA1, HIGH);
digitalWrite(MotorA2, LOW);
digitalWrite(MotorB1, LOW);
digitalWrite(MotorB2, HIGH); 
analogWrite(PwmA, ValorPwmA);
analogWrite(PwmB, ValorPwmB);

}
