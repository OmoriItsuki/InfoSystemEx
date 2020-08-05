
#include<xc.h>
#pragma config FOSC = HSMP
#pragma config WDTEN=OFF
#pragma config LVP=OFF

int counter=0;

void rest(int n){
    while(--n);
}

void main(){
    ANSELB=0;
    TRISB=0;
    ANSELA=0;
    TRISA=0b00010100;

    IPEN=1;
    T0CON=0b10010111;
    TMR0IP=1;
    TMR0IF=0;
    TMR0IE=1;
    GIEH=1;
    LATB=0x00;

    unsigned int n;
    unsigned int freq=267;

    while(1){
        while(PORTAbits.RA2!=0);
        rest(1000);
        n=1;
        while(1){
            LATBbits.LATB0=1;
            PORTAbits.RA5=1;
            rest(freq/2);
            LATBbits.LATB0=0;
            PORTAbits.RA5=0;
            rest(freq/2);
            n++;
        }
        while(PORTAbits.RA2==0);
        rest(1000);
    }
}

void interrupt tmr0(){
    if(TMR0IF == 1){
        TMR0IF = 0;
        counter++;
        LATB=counter<<1;
        TMR0=55769;
        rest(1000);
        rest(1000);
        rest(1000);
    }
}