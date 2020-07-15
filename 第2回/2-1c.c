#include<xc.h>
#pragma config FOSC = HSMP
#pragma config WDTEN=OFF
#pragma config LVP=OFF


char reset(){
    return 0x00;
}

char showZero(){
    return 0x3F;
}

char showOne(){
    return 0x06;
}

char showTwo(){
    return 0x5B;
}

char showThree(){
    return 0x4F;
}

char showFour(){
    return 0x66;
}

char showFive(){
    return 0x6D;
}

char showSix(){
    return 0x7D;
}

char showSeven(){
    return 0x07;
}

char showEight(){
    return 0x7F;
}

char showNine(){
    return 0x6F;
}

char cnvseg(int cnt){
    char seg;
    switch(cnt){
        case 0:
            seg = showZero();
            break;
        case 1:
            seg = showOne();
            break;
        case 2:
            seg = showTwo();
            break;
        case 3:
            seg = showThree();
            break;
        case 4:
            seg = showFour();
            break;
        case 5:
            seg = showFive();
            break;
        case 6:
            seg = showSix();
            break;
        case 7:
            seg = showSeven();
            break;
        case 8:
            seg = showEight();
            break;
        case 9:
            seg = showNine();
            break;
    }
    return seg;
}

void rest(int n){
    while(--n);
}

void main(){
    ANSELB=0;
    TRISB=0;
    ANSELA=0;
    TRISA=0b00001100;

    int n=0,num=0;

    LATB=0x00;

    while(1){
        num%=10;
        LATB=cnvseg(num);
        while(PORTAbits.RA2==1 && PORTAbits.RA3==1);
        rest(1000);
        if(PORTAbits.RA2==0){
            num+=2;
        }else if(PORTAbits.RA3==0){
            num+=3;
        }
        while(PORTAbits.RA2==0 || PORTAbits.RA3==0);
        rest(1000);
        /*
        while(PORTAbits.RA3!=0);
        rest(1000);
        num+=3;
        while(PORTAbits.RA3==0);
        rest(1000);
        */
    }
}

