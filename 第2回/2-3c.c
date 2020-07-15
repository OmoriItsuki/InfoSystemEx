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

    int tmp=0;
    int cnt=200;
    int i;
    unsigned int freq[8]={267,237,212,200,178,159,141,133};

    while(1){
        while(PORTAbits.RA2!=0);
        rest(1000);
        for(i=0;i<8;i++){
            tmp=0;
            while(tmp < cnt){
                LATBbits.LATB1=1;
                LATBbits.LATB0=1;
                PORTAbits.RA5=1;
                rest(freq[i]);
                LATBbits.LATB0=0;
                PORTAbits.RA5=0;
                LATBbits.LATB1=0;
                tmp++;
            }
            if(i!=7){
                cnt*=freq[i]/freq[i+1];
             }else{
                cnt=400;
            }
        }
        while(PORTAbits.RA2==0);
        rest(1000);
    }
}


