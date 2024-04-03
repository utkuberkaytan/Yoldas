//Utku Berkay TAN, UBT, Yoldaş Project (Hardware: v3.0  Software: v2.0) 
char data;                                     //bluetooth veri tanımlaması
long sure;
long uzaklik;
#include "DHT.h"
#define DHTPIN 11
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);               
#define trig 8                                 // tanımlamalar
#define echo 9
#define sol_motor_1 2
#define sol_motor_2 3
#define sag_motor_1 4
#define sag_motor_2 5
#define korna 10
//Fonksiyon Tanımlamaları
void ileri(){

  digitalWrite(sol_motor_1, HIGH);
  digitalWrite(sol_motor_2, LOW);
  digitalWrite(sag_motor_1, HIGH);
  digitalWrite(sag_motor_2, LOW);
  
}

void geri(){


  digitalWrite(sol_motor_1, LOW);
  digitalWrite(sol_motor_2, HIGH);
  digitalWrite(sag_motor_1, LOW);
  digitalWrite(sag_motor_2, HIGH);

  
}

void sol(){

  

  digitalWrite(sol_motor_1, LOW);
  digitalWrite(sol_motor_2, HIGH);
  digitalWrite(sag_motor_1, HIGH);
  digitalWrite(sag_motor_2, LOW);
  
}

void sag(){
  
  digitalWrite(sol_motor_1, HIGH);
  digitalWrite(sol_motor_2, LOW);
  digitalWrite(sag_motor_1, LOW);
  digitalWrite(sag_motor_2, HIGH);
  
}

void dur(){

  digitalWrite(sol_motor_1, LOW);
  digitalWrite(sol_motor_2, LOW);
  digitalWrite(sag_motor_1, LOW);
  digitalWrite(sag_motor_2, LOW);
  
}

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(sol_motor_1, OUTPUT);
  pinMode(sol_motor_2, OUTPUT);
  pinMode(sag_motor_1, OUTPUT);
  pinMode(sag_motor_2, OUTPUT);
  Serial.begin(9600);
  dht.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(korna, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);

}
int mesafeOlcumu(){
  digitalWrite(trig, LOW); 
  delayMicroseconds(5); 
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trig, LOW);   
  sure = pulseIn(echo, HIGH); 
  uzaklik = sure /29.1/2;
  
  return uzaklik;
} 
void loop() {
  if(mesafeOlcumu() <= 25){
    geri();
    delay(300);
    dur();
  }
  Serial.print("D");
  Serial.println(mesafeOlcumu());
  float t = dht.readTemperature();
  Serial.print("T");
  Serial.println(t);
  delay(10);
  if(Serial.available()>0){         
    data = Serial.read();           
  }
  
  
  if(data == 'F'){            
    ileri();
  }
  
  else if(data == 'B'){      
    geri();
  }
  
  else if(data == 'L'){      
    sol();
  }
  
  else if(data == 'R'){     
    sag();
  }
  
  else if(data == 'S'){      
    dur();
  }
  else if(data == 'X'){
    digitalWrite(korna,HIGH);
    delay(400);
    digitalWrite(korna,LOW);
  }

}
