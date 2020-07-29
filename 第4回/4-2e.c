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
    ANSELC=0;
    TRISC=0b00000000;
    PORTB=0;
    unsigned int freq=500;
    LATBbits.LATB0=0;
    LATCbits.LATC1=1;
    while(1){
        LATCbits.LATC1=1;
        rest(dutyRatio);
        LATCbits.LATC1=0;
        rest(freq-dutyRatio);
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
            if(dutyRatio+1>freq){
                dutyRatio=freq;
            }else{
                dutyRatio+=1;
            }
            rest(1000);
        }
        PORTB=dutyRatio<<1;
    }
}



