#include "4digit7seg.h"
#define INTERVAL 86400000            // for a day 86400000 and 1000 for a second

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;

int C1 = 9;
int C2 = 10;
int C3 = 11;
int C4 = 12;

int countDownDays = 5;
unsigned long lastUpdate = 0;
struct digits{int first; int sec; int third; int fourth;};
digits intToSingleDigit(int startDay)
{
  String numArr = String(startDay);
  digits vals;
  if(numArr.length() == 3)
  {
    for(int i = 0; i < 4; i++)
  {
    switch (i)
    {
    case 0:
      vals.third = String(numArr[i]).toInt();
      break;
    case 1:
      vals.sec = String(numArr[i]).toInt();
      break;
    case 2:
      vals.first = String(numArr[i]).toInt();
      break;
    case 3:
      vals.fourth = 0;
//      String(numArr[i]).toInt();
      break;   
    default:
      break;
    }
  }
  }
  else if(numArr.length() == 2)
  {
     for(int i = 0; i < 4; i++)
  {
    switch (i)
    {
    case 0:
      vals.sec = String(numArr[i]).toInt();
      break;
    case 1:
      vals.first = String(numArr[i]).toInt();
      break;
    case 2:
      vals.third = 0;
//      String(numArr[i]).toInt();
      break;
    case 3:
      vals.fourth = 0;
//      String(numArr[i]).toInt();
      break;   
    default:
      break;
    }
  }
  }
  else if(numArr.length() == 1)
  {
     for(int i = 0; i < 4; i++)
  {
    switch (i)
    {
    case 0:
      vals.first = String(numArr[i]).toInt();
      break;
    case 1:
      vals.sec = 0;
      break;
    case 2:
      vals.third = 0;
//      String(numArr[i]).toInt();
      break;
    case 3:
      vals.fourth = 0;
//      String(numArr[i]).toInt();
      break;   
    default:
      break;
    }
  }
  }
  else
  {
    for(int i = 0; i < 4; i++)
  {
    switch (i)
    {
    case 0:
      vals.fourth = String(numArr[i]).toInt();
      break;
    case 1:
      vals.third = String(numArr[i]).toInt();
      break;
    case 2:
      vals.sec = String(numArr[i]).toInt();
      break;
    case 3:
      vals.first = String(numArr[i]).toInt();
      break;   
    default:
      break;
    }
  }
  }
  
  
  
  return vals;
}

void setup() {
  Serial.begin(115200);
  pinMode(pinA,OUTPUT);
  pinMode(pinB,OUTPUT);
  pinMode(pinC,OUTPUT);
  pinMode(pinD,OUTPUT);
  pinMode(pinE,OUTPUT);
  pinMode(pinF,OUTPUT);
  pinMode(pinG,OUTPUT);
  // pinMode(dot,OUTPUT);

  pinMode(C1,OUTPUT);
  pinMode(C2,OUTPUT);
  pinMode(C3,OUTPUT);
  pinMode(C4,OUTPUT);
}

void loop() {

   digits  a = intToSingleDigit(countDownDays);
  for(int i = 0; i < 4; i++)
  {
    switch (i)
    {
    case 0:
      dispNumber(a.fourth,c1,pinA,pinB,pinC,pinD,pinE,pinF,pinG,C1,C2,C3,C4);
      delay(1);
      Serial.println(a.first);
      break;
    case 1:
      dispNumber(a.third,c2,pinA,pinB,pinC,pinD,pinE,pinF,pinG,C1,C2,C3,C4);
      delay(1);
      Serial.println(a.sec);
      break;
    case 2:
      dispNumber(a.sec,c3,pinA,pinB,pinC,pinD,pinE,pinF,pinG,C1,C2,C3,C4);
      delay(1);
      Serial.println(a.third);
      break;
    case 3:
      dispNumber(a.first,c4,pinA,pinB,pinC,pinD,pinE,pinF,pinG,C1,C2,C3,C4);
      delay(1);
      Serial.println(a.fourth);
      break;   
    default:
      break;
    }
  }

  if((millis() - lastUpdate) > INTERVAL)   
  {
    lastUpdate = millis();
    if(countDownDays <= 0)
    {
      // call buzzing function here
//      Serial.print(" millis \t");
//      Serial.println(f0);
      // get stuck here
    }
    else
    {
      countDownDays--;
    }
    
  }
 
  
}
