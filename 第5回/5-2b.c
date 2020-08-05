

#include<xc.h>
#pragma config FOSC = HSMP
#pragma config WDTEN=OFF
#pragma config LVP=OFF

int div=2;
int state=0;
unsigned int freq=267;

void rest(int n){
    while(--n);
}


void interrupt buzer(){
    if(INT0IF == 1){
        state=!state;
        if(state){
            div=4;
        }else{
            div=2;
        }
        INT0IF=0;
    }
}

void main(){
    ANSELB=0;
    TRISB=0b00000001;
    ANSELA=0;
    TRISA=0b00010111;

    IPEN=1;
    GIEH=1;
    INT0IF=0;
    INT0IE=1;
    INTEDG0=0;
    LATB=0x00;

    while(1){
        LATBbits.LATB1=1;
        PORTAbits.RA5=1;
        rest(freq/div);
        LATBbits.LATB1=0;
        PORTAbits.RA5=0;
        rest(freq/div);
    }
}