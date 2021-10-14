#include <Servo.h>  //匯入函式庫
Servo myservo;  // 建立伺服馬達控制

const int servoPin = 14;  //用常態變數設定pin腳位，與之前define方式差不多
int pos = 0;
int mappos=0;

void setup() {
  myservo.attach(servoPin);  // 將伺服馬達連接的GPIO pin連接伺服物件
  Serial.begin(115200);//序列阜連線速率(鮑率)
  pinMode(13,INPUT);
} 

void loop() {
      pos=analogRead(13);
      mappos=map(pos,0,4095,0,180);
        myservo.write(mappos); //Servo設定角度
        Serial.print(pos);
        Serial.print(" ");
        Serial.println(mappos);
        delay(50);
 
}
