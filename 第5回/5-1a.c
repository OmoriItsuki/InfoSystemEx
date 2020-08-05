#include<xc.h>
#pragma config FOSC = HSMP
#pragma config WDTEN=OFF
#pragma config LVP=OFF

int counter=0;

void main(){
    ANSELB=0;
    TRISB=0;
    IPEN=1;
    T0CON=0b10010101;
    TMR0IP=1;
    TMR0IF=0;
    TMR0IE=1;
    GIEH=1;
    LATB=counter;
    while(1){
    }
}

void interrupt tmr0(int counter){
    if(TMR0IF == 1){
        TMR0IF = 0;
        counter++;
        LATB=counter;
        TMR0=26473;
    }
}