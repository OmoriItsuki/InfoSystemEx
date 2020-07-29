#include<xc.h>
#pragma config FOSC = HSMP
#pragma config WDTEN=OFF
#pragma config LVP=OFF

void rest(unsigned int n){
    while(n!=0)n--;
}

void main(){
    int dutyRatio=64;
    ANSELB=0;
    TRISB=0;
    ANSELA=0;
    TRISA=0b00001100;
    PORTB=0;
    LATBbits.LATB0=0;
    while(1){
        LATBbits.LATB0=1;
        rest(dutyRatio);
        LATBbits.LATB0=0;
        rest(128-dutyRatio);
        if(PORTAbits.RA3==0){
            rest(1000);
            if(dutyRatio-1<0){
                dutyRatio=0;
            }else{
                dutyRatio-=1;
            }
            rest(1000);
        }
        if(PORTAbits.RA2==0){
            rest(1000);
            if(dutyRatio+1>127){
                dutyRatio=127;
            }else{
                dutyRatio+=1;
            }
            rest(1000);
        }
        PORTB=dutyRatio<<1;
    }
}

