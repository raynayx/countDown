#pragma once
#include "4digit7seg.h"

//write 0
number n0()
{
    number val;
    val.segA = 0;
    val.segB = 0;
    val.segC = 0;
    val.segD = 0;
    val.segE = 0;
    val.segF = 0;
    val.segG = 1;
    return val;
}

//write 1
number n1()
{
    number val;
    val.segA = 1;
    val.segB = 0;
    val.segC = 0;
    val.segD = 1;
    val.segE = 1;
    val.segF = 1;
    val.segG = 1;
    return val;
}

//write 2
number n2()
{
    number val;
    val.segA = 0;
    val.segB = 0;
    val.segC = 1;
    val.segD = 0;
    val.segE = 0;
    val.segF = 1;
    val.segG = 0;
    return val;
}

// write 3
number n3()
{
    number val;
    val.segA = 0;
    val.segB = 0;
    val.segC = 0;
    val.segD = 0;
    val.segE = 1;
    val.segF = 1;
    val.segG = 0;
    return val;
}

// write 4
number n4()
{
    number val;
    val.segA = 1;
    val.segB = 0;
    val.segC = 0;
    val.segD = 1;
    val.segE = 1;
    val.segF = 0;
    val.segG = 0;
    return val;
}


//write 5
number n5()
{
    number val;
    val.segA = 0;
    val.segB = 1;
    val.segC = 0;
    val.segD = 0;
    val.segE = 1;
    val.segF = 0;
    val.segG = 0;
    return val;
}

//write 6
number n6()
{
    number val;
    val.segA = 0;
    val.segB = 1;
    val.segC = 0;
    val.segD = 0;
    val.segE = 0;
    val.segF = 0;
    val.segG = 0;
    return val;
}


//write 7
number n7()
{
    number val;
    val.segA = 0;
    val.segB = 0;
    val.segC = 0;
    val.segD = 1;
    val.segE = 1;
    val.segF = 1;
    val.segG = 1;
    return val;
}

//write 8
number n8()
{
    number val;
    val.segA = 0;
    val.segB = 0;
    val.segC = 0;
    val.segD = 0;
    val.segE = 0;
    val.segF = 0;
    val.segG = 0;
    return val;
}

//write 9
number n9()
{
    number val;
    val.segA = 0;
    val.segB = 0;
    val.segC = 0;
    val.segD = 0;
    val.segE = 1;
    val.segF = 0;
    val.segG = 0;
    return val;
}

// display number on the 4Digit: NUMBER to display,DIGIT to display on, pinNumbers
void dispNumber(int val,digit c,int pinA, int pinB, int pinC, int pinD, int pinE, int pinF, int pinG, int C1,int C2, int C3, int C4)
{
    common  pins;
    number d;
    switch (val)
    {
    case 0:
        d = n0();
        break;
    case 1:
        d = n1();
        break;
    case 2:
        d = n2();
        break;
    case 3:
        d = n3();
        break;
    case 4:
        d = n4();
        break;
    case 5:
        d = n5();
        break;
    case 6:
        d = n6();
        break;
    case 7:
        d = n7();
        break;
    case 8:
        d = n8();
        break;
    case 9:
        d = n9();
        break;            
    default:
        break;
    }
    switch (c)
    {
    case c1:
       pins={1,0,0,0};
        break;
    case c2:
        pins={0,1,0,0};
        break;
    case c3:
        pins={0,0,1,0};
        break;
    case c4:
        pins={0,0,0,1};
        break;        
    case all:
        pins={1,1,1,1};
        break;
    case none:
        pins={0,0,0,0};
        break;    
    default:
        break;
    }

    digitalWrite(pinA,d.segA);
    digitalWrite(pinB,d.segB);
    digitalWrite(pinC,d.segC);
    digitalWrite(pinD,d.segD);
    digitalWrite(pinE,d.segE);
    digitalWrite(pinF,d.segF);
    digitalWrite(pinG,d.segG);

    digitalWrite(C1,pins.c1);
    digitalWrite(C2,pins.c2);
    digitalWrite(C3,pins.c3);
    digitalWrite(C4,pins.c4);
}
