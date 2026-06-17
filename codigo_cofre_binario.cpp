#include<Servo.h>
Servo porta;
int A = 10;
int B = 11;
int C = 12;
int D = 7;
int E = 6;
int DP = 0;
int G = 9;
int F = 8;                // Display

 int bt=5;
 int pot=0;
 int certo=4; 
 int buzzer=3;
 int errado=2;

int contador=0;
int leitor=0;

int dig1=0;
int dig2=0;
int dig3=0;

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(certo, OUTPUT);
  pinMode(errado, OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(bt, INPUT);
  pinMode(pot, INPUT);
  porta.attach(13);
  Serial.begin(9600);
  porta.write(0);
}

void loop()
{
  
  leitor=digitalRead(bt);
  pot=digitalRead(A0);

  senha();
  if(pot==0){
      digitalWrite(A, 0);
      digitalWrite(B, 0);
      digitalWrite(C, 0);
      digitalWrite(D, 0);
      digitalWrite(E, 0);
      digitalWrite(F, 0);
      digitalWrite(G, 1);


  } 
    if(pot==1){
      digitalWrite(A, 1);
      digitalWrite(B, 0);
      digitalWrite(C, 0);
      digitalWrite(D, 1);
      digitalWrite(E, 1);
      digitalWrite(F, 1);
      digitalWrite(G, 1);
    }
  
    
  
}

void senha(){
  if(leitor==1){
    contador++;
    delay(500);
    if(contador==1 && dig1==0){
      dig1=pot;
       Serial.println("dig 1:");
       Serial.println(dig1);
      delay(500);
    }
     if(contador==2 &&dig2==0){
      dig2=pot;
       Serial.println("dig 2:");
       Serial.println(dig2);
         delay(500);
    }
   if(contador==3 &&dig3==0){
      dig3=pot;
       Serial.println("dig 3:");
       Serial.println(dig3);
         delay(500);
     result();
    }
   }
   
}

void result(){
  if(dig1==0 && dig2==1 && dig3==0) {
    digitalWrite(certo,1);
    tone(buzzer,700,100);
    delay(500);
    tone(buzzer,330,100);
    digitalWrite(certo,0);
    porta.write(90);
    delay(500);
    
}
else{
   digitalWrite(errado,1);
   digitalWrite(buzzer,1);
    delay(1500);
    digitalWrite(errado,0);
    digitalWrite(buzzer,0);
    porta.write(0);
    delay(1500);
  
    
}
}