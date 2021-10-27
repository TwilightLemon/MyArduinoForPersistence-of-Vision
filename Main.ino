#include <Wire.h>
#include "SCoop.h"
#include "LiquidCrystal_I2C.h"

#define LED0 9
#define LED1 10
#define LED2 11
#define PW A0
#define Senor A2

LiquidCrystal_I2C lcd(0x27,16,2);
int delaytime=200;

defineTask(Task1);
void Task1::setup(){
    pinMode(PW,INPUT);
    pinMode(Senor,INPUT);
  }
void Task1::loop(){
  int value=analogRead(PW)/2+1;
  int level=analogRead(Senor)+1;
  if(delaytime!=value){
      delaytime=value;
      lcd.setCursor(6,0);
      lcd.print(delaytime);
      lcd.setCursor(6,1);
      lcd.print(level);
     // Serial.println(delaytime);
     // Serial.println(level);
      //lcd.setCursor(4,1);
     // lcd.print(value);
    }
    sleep(1000);
  }
void setup() {
  mySCoop.start();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("delay:");
  lcd.setCursor(0,1);
  lcd.print("level:");
 // Serial.begin(9600);

   pinMode(LED0,OUTPUT);
   pinMode(LED1,OUTPUT);
   pinMode(LED2,OUTPUT);
   digitalWrite(LED0,LOW);
   digitalWrite(LED1,LOW);
   digitalWrite(LED2,LOW);
}

void loop() {
 yield();//necessary
 Light(LED0);
  Light(LED1);
   Light(LED2);
}
void Light(int led){
  digitalWrite(led,LOW);
  sleep(delaytime);
  digitalWrite(led,150);
  sleep(delaytime);
  }
