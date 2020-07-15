#include<xc.h>
#pragma config FOSC = HSMP
#pragma config WDTEN=OFF
#pragma config LVP=OFF

void rest(int n){
    while(--n);
}

void main(){
    ANSELB=0;
    TRISB=0;
    ANSELA=0;
    TRISA=0b00010100;

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
            rest(freq);
            LATBbits.LATB0=0;
            PORTAbits.RA5=0;
            n++;
        }
        while(PORTAbits.RA2==0);
        rest(1000);
    }
}

