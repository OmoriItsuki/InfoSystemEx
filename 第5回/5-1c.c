
#include<xc.h>
#pragma config FOSC = HSMP
#pragma config WDTEN=OFF
#pragma config LVP=OFF

int counter=0;
int second=0;

void rest(unsigned int n){
    while(n!=0){
        n--;
    }
}

void main(){
    ANSELB=0;
    TRISB=0;
    IPEN=1;
    T0CON=0b10010111;
    TMR0IP=1;
    TMR0IF=0;
    TMR0IE=1;
    GIEH=1;
    ANSELA=0;
    TRISA=0b00001100;
    LATB=counter;
    while(1){
        while(PORTAbits.RA2!=0);
        rest(1000);
        counter++;
        while(PORTAbits.RA2==0);
        rest(1000);
        if(counter>=10){
            LATB=second;
            second=0;
            counter=0;
        }
    }
}

void interrupt tmr0(){
    if(TMR0IF == 1){
        TMR0IF = 0;
        second++;
        TMR0=55769;
    }
}

