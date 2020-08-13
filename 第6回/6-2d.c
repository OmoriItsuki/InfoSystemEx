#include<xc.h>
#include<string.h>
#pragma config FOSC = HSMP
#pragma config WDTEN=OFF
#pragma config LVP=OFF

int last=0;

void swap(char *a,char *b){
    char tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

void enqueue(char buf[],char new){
    buf[last%6]=new;
    last++;
}

char dequeue(char buf[]){
    for(int i=0;i<6;i++){
        swap(buf[i%6],buf[(i+1)%6]);
    }
    last--;
    return buf[(last+1)%6];
}

void send(char out[]){
    int i=0;
    while(out[i]!='\0'){
        while(TRMT1==0);
        TXREG1=out[i];
        i++;
    }
}

void main(void){
    //char input[],output
    char ans1[6]={'h','i','r','a','k','e'};
    char ans2[4]={'y','a','m','a'};
    char buffer[6];
    char c[6];
    int hirakeCheck=1,yamaCheck=1;
    TRISA=0b001111;
    TRISB=0;
    TRISC=0b10111001;
    ANSELA=0b00000011;
    ANSELB=0;
    ANSELC=0;
    BAUDCON1=0;
    SPBRG1=64;
    TXSTA1=0b00100100;
    RCSTA1=0b10010000;
    RC1IE=1;
    IPEN=1;
    GIEH=1;
    while(1){
        while(RC1IF==0){
            RC1IF=0;
            if(!strcmp(RCREG1,0xA)){
                for(int i=0;i<6;i++){
                    c[i]=dequeue(buffer);
                }
                if(!strcmp(c,ans1)){
                    send("GOMA!");
                }else if(!strcmp(c,ans2)){
                    send("KAWA!");
                }
            }
            enqueue(buffer,RCREG);
            TXREG1=buffer[0];
        }
    }
}


