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

char showA(){
    return 0x77;
}

char showB(){
    return 0x7C;
}

char showC(){
    return 0x39;
}

char showD(){
    return 0x5E;
}

char showE(){
    return 0x79;
}

char showF(){
    return 0x71;
}

char cnvseg(char cnt){
    char seg;
    switch(cnt){
        case '0':
            seg = showZero();
            break;
        case '1':
            seg = showOne();
            break;
        case '2':
            seg = showTwo();
            break;
        case '3':
            seg = showThree();
            break;
        case '4':
            seg = showFour();
            break;
        case '5':
            seg = showFive();
            break;
        case '6':
            seg = showSix();
            break;
        case '7':
            seg = showSeven();
            break;
        case '8':
            seg = showEight();
            break;
        case '9':
            seg = showNine();
            break;
        case 'a':
            seg = showA();
            break;
        case 'b':
            seg = showB();
            break;
        case 'c':
            seg = showC();
            break;
        case 'd':
            seg = showD();
            break;
        case 'e':
            seg = showE();
            break;
        case 'f':
            seg = showF();
            break;

    }
    return seg;
}

void main(void){
    char chr;
    TRISA=0b001111;
    TRISB=0;
    TRISC=0b10111001;
    ANSELA=0b00000011;
    ANSELB=0;
    ANSELC=0;
    BAUDCON1=0;
    SPBRG1=64;
    TXSTA1=0b00100100;
    RCSTA1=0b10010000;
    RC1IE=1;
    IPEN=1;
    GIEH=1;
    chr=0x41;
    while(1){
        while(RC1IF==0){
            RC1IF=0;
            PORTB=cnvseg(RCREG1);
            while(TRMT1==0);
            TXREG1=RCREG1;
        }
    }
}


void interrupt showSegment(){
    if(RC1IF==1){
        RC1IF=0;
        PORTB=cnvseg(RCREG1);
    }
}