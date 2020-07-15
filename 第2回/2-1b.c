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
    TRISA=0b00000100;

    int state=0,n=0;

    LATB=0x00;

    while(1){
        while(PORTAbits.RA2!=0);
        rest(1000);
        state = !state;
        LATBbits.LATB0=state;
        while(PORTAbits.RA2==0);
        rest(1000);
    }
}
