#include<xc.h>
#pragma config FOSC = HSMP
#pragma config WDTEN=OFF
#pragma config LVP=OFF

unsigned int n,ADBUF;

void main(){
    TRISA=0b001111;
    TRISB=0;
    ANSELA=0b00000011;
    ANSELB=0;
    ANSELC=0;
    ADCON0=0b00000001;
    ADCON1=0b00000000;
    ADCON2=0b10000011;


    while(1){
        ADCON0bits.GO=1;
        while(ADCON0bits.GO == 1);

        ADBUF=(ADRESH << 8) + ADRESL;
        
        PORTB=ADBUF>>2;

        for(n=0;n<1000;n++);
    }
}
