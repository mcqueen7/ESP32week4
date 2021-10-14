#include <Stepper.h> //引入步進馬達函示庫

const int stepsPerRevolution = 100;  //此馬達轉一圈為2048步
const int RPM = 40; //馬達旋轉速度

//宣告Stepper物件，的步數和引腳
//引角依序對應驅動版的1N1、1N3、1N2、1N4
Stepper myStepper(stepsPerRevolution, 13, 14, 12, 27);  

void setup() {  
  Serial.begin(115200);
  myStepper.setSpeed(RPM);  //設定馬達轉速
  pinMode(26,INPUT_PULLUP);
  pinMode(25,INPUT_PULLUP);
}

void loop() {
int a=digitalRead(26);
int b=digitalRead(25);

Serial.print(a);
Serial.print(" ");
Serial.println(b);
myStepper.step(1-a);
myStepper.step(-1+b);
 
}
