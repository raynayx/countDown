/*
My Library for using 4 digit 7 segment displays
// 7-segment uses negative logic
*/

#include "Arduino.h"

enum digit{c1,c2,c3,c4,all,none};
struct common
{
    bool c1;
    bool c2;
    bool c3;
    bool c4;
};

struct number
{
    bool segA;
    bool segB;
    bool segC;
    bool segD;
    bool segE;
    bool segF;
    bool segG;
};

number n0();
number n1();
number n2();
number n3();
number n4();
number n5();
number n6();
number n7();
number n8();
number n9();

//binary for writing the various digits on the 7 segment display
static byte f0 = 0b00000001;
static byte f1 = 0b01001111;
static byte f2 = 0b00010010;
static byte f3 = 0b00000110;
static byte f4 = 0b01001100;
static byte f5 = 0b00100100;
static byte f6 = 0b00100000;
static byte f7 = 0b00001111;
static byte f8 = 0b00000000;
static byte f9 = 0b00000100;



void dispNumber(int val,digit c,int pinA, int pinB, int pinC, int pinD, int pinE, int pinF, int pinG, int C1,int C2, int C3, int C4);
