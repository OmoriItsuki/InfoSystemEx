#include<xc.h>
#pragma config FOSC = HSMP
#pragma config WDTEN=OFF
#pragma config LVP=OFF

void rest(){
    unsigned int n=1;
    while(n!=0)n++;
}

void main(){
    /*
    ANSELB=0;
    TRISB=0;
    char cnt=0x01;
    int isUpDown=0;
    while(1){
        if(isUpDown==0){
            cnt = cnt<<1;
            if(cnt==0x80){
                isUpDown=1;
            }
        }else{
            cnt = cnt>>1;
            if(cnt==0x01){
                isUpDown=0;
            }
        }
        LATB=cnt;
        rest();
    }
     */
    ANSELB=0;
    TRISB=0;
    ANSELA=0;
    TRISA=0b00000100;

    LATB=0x00;

    while(1){
        if(PORTAbits.RA2==0){
            LATBbits.LATB0=1;
        }else{
            LATB=0x00;
        }
    }
    
}
