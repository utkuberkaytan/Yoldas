//Utku Berkay TAN, UBT, Yoldaş Project (Hardware: v2.0  Software: v1.5) 
char data;                                     //bluetooth veri tanımlaması
long sure;
long uzaklik;
int kirmiziPin = 9;                 //RGB Ledin kırmızı bacağının takılacağı pin
int yesilPin = 8;                  //RGB Ledin yeşil bacağının takılacağı pin       
                   
#define trig 11                                 // tanımlamalar
#define echo 10
#define sol_motor_1 5
#define sol_motor_2 6
#define sag_motor_1 3
#define sag_motor_2 4
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
  digitalWrite(sol_motor_2, LOW);
  digitalWrite(sag_motor_1, HIGH);
  digitalWrite(sag_motor_2, LOW);
  
}

void sag(){
  
  digitalWrite(sol_motor_1, HIGH);
  digitalWrite(sol_motor_2, LOW);
  digitalWrite(sag_motor_1, LOW);
  digitalWrite(sag_motor_2, LOW);
  
}

void dur(){

  digitalWrite(sol_motor_1, LOW);
  digitalWrite(sol_motor_2, LOW);
  digitalWrite(sag_motor_1, LOW);
  digitalWrite(sag_motor_2, LOW);
  
}

void setup() {
pinMode(5,OUTPUT);   //Sol Motor 2
pinMode(6,OUTPUT);   //Sol Motor 1
pinMode(4,OUTPUT);   //Sağ Motor 1
pinMode(3,OUTPUT);   //Sağ Motor 2
pinMode(2,OUTPUT);   //Sağ Motor EN
pinMode(7,OUTPUT);   //Sol Motor EN
pinMode(11,OUTPUT);   //TrigPin
pinMode(10,INPUT);   //EchoPin
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
Serial.begin(9600);

}


 
void loop() {

   

  digitalWrite(trig, LOW); 
  delayMicroseconds(5); 
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trig, LOW);   
  sure = pulseIn(echo, HIGH); 
  uzaklik = sure /29.1/2; 
  if(uzaklik > 200){
  uzaklik = 200;
  }
  
  

if(Serial.available()>0){         //Seri haberleşmeden veri gelmesini bekliyoruz.
    data = Serial.read();           //Seri haberleşmeden gelen veriyi okuyoruz. 
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
if(uzaklik <= 25){                        //duvara çarpmama
  geri();
  delay(100);
}
else if(uzaklik == 0){
  dur();
  delay(100);
  digitalWrite(9, HIGH);
}
else{
  if(Serial.available()>0){         //Seri haberleşmeden veri gelmesini bekliyoruz.
    data = Serial.read();           //Seri haberleşmeden gelen veriyi okuyoruz. 
  }
}
}
