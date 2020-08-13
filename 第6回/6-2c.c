#include<xc.h>
#pragma config FOSC = HSMP
#pragma config WDTEN=OFF
#pragma config LVP=OFF

void sound(int length,int wait){
    for(int i=0;i<length;i++){
        LATAbits.LATA5=1;
        for(int n=0;n<wait;n++);
        LATAbits.LATA5=0;
        for(int n=0;n<wait;n++);
    }
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
            while(TRMT1==0);
            TXREG1=RCREG1;
        }
    }
}

void switchSound(char chr){
    switch(chr){
         case 'a':
             sound(104,132);
            break;
        case 'b':
            sound(117,117);
            break;
        case 'c':
            sound(132,104);
            break;
        case 'd':
            sound(140,98);
            break;
        case 'e':
            sound(157,88);
            break;
        case 'f':
            sound(176,79);
            break;
        case 'g':
            sound(197,70);
            break;
        case 'h':
            sound(209,66);
            break;

    }
}

void interrupt showSegment(){
    if(RC1IF==1){
        RC1IF=0;
        switchSound(RCREG1);
    }
}
