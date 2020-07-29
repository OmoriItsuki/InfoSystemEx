#include<xc.h>
#pragma config FOSC = HSMP
#pragma config WDTEN=OFF
#pragma config LVP=OFF

void rest(int n){
    while(n!=0)n--;
}

void main(){
    int dutyRatio=64;
    ANSELB=0;
    TRISB=0;
    PORTB=0;
    LATBbits.LATB0=0;
    while(1){
        LATBbits.LATB0=1;
        rest(dutyRatio);
        LATBbits.LATB0=0;
        rest(128-dutyRatio);
    }

}
