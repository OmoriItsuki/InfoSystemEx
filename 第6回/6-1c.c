#include<xc.h>
#pragma config FOSC = HSMP
#pragma config WDTEN=OFF
#pragma config LVP=OFF

void outch(char chr){
    while(TRMT1==0);
    TXREG1=chr;
}

void outstr(char str[]){
    int i=0;
    do{
        outch(str[i]);
        i++;
    }while(str[i]!='\0');
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
    chr=0x41;
    while(1){
        if(PORTAbits.RA2==0){
            outstr("Hello!");
            while(PORTAbits.RA2==0);
        }
        if(PORTAbits.RA3==0){
            outstr("World!");
            while(PORTAbits.RA3==0);
        }
    }
}
