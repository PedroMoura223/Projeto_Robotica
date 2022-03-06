int ledfrente = 12;
int ledtras = 13;
int ledsinal = 11;
int ledporta = 9;
int bpararandar = 7;
int babrirporta = 6;
int bsinal = 5;
int buzz = 4;
int estado_sinal = 1;
int estado_onibus = 1;
int estado_porta = 1;
int p = 2;
int q = 2;

#include <Servo.h>
#define servo 8
int pos = 0;

Servo s;

void setup()
{
  pinMode(ledfrente, OUTPUT);
  pinMode(ledtras, OUTPUT);
  pinMode(ledsinal, OUTPUT);
  pinMode(ledporta, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(bpararandar, INPUT);
  pinMode(babrirporta, INPUT);
  pinMode(bsinal, INPUT);
   s.attach(servo);
  Serial.begin(9600);
  s.write(0);
}

void loop()
{  
   //LED FRENTE PERMANECER ACESO 
  if(p%2 != 0){
    digitalWrite(ledfrente,LOW);
  }
  
if(p%2 == 0){
  digitalWrite(ledfrente,HIGH);}
  
  //PARAR ÔNIBUS
   if(digitalRead(bpararandar) == HIGH){
   delay(1);
    if(digitalRead(bpararandar) == LOW){
     
   p++;
      digitalWrite(ledtras,estado_onibus);
     estado_onibus = !estado_onibus;
    
  }
  }
  
  if(digitalRead(bsinal) == HIGH){
   delay(1);
    if(digitalRead(bsinal) == LOW){
       tone(buzz, 3000 , 2000);
   
      digitalWrite(ledsinal,HIGH);
     estado_sinal = !estado_sinal;
   
    
  }}
   if(digitalRead(babrirporta) == HIGH){
   delay(1);
    if(digitalRead(babrirporta) == LOW){
        digitalWrite(ledsinal,LOW);
      digitalWrite(ledporta,estado_porta);
     estado_porta = !estado_porta;
      if(q%2 == 0){
        for(pos = 0; pos < 90; pos++){
    s.write(pos);
    delay(10);
  
  }
      }
      if(q%2 != 0){
        for(pos = 90;pos > 0; pos--){
          s.write(pos);
          delay(10);
      }
      }
 
      q++;
    }
  
