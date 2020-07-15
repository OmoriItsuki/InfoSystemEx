#include<xc.h>
#pragma config FOSC = HSMP
#pragma config WDTEN=OFF
#pragma config LVP=OFF

void rest(int n){
    while(--n);
}

void main(){
    ANSELB=0;
    TRISB=0b00000001;
    ANSELA=0;
    TRISA=0b00000101;

    LATB=0x00;

    while(1){
        if(PORTBbits.RB0==1){
            LATBbits.LATB1=1;
        }else{
            LATBbits.LATB1=0;
        }
    }
}
