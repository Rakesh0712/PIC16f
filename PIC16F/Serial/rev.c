#include <16f877a.h>
#include<stdio.h>
#use delay(CLOCK=20M)
#byte TXSTA=0x98
#byte RCSTA=0x18
#byte SPBRG=0x99
#bit RCIF=0x0C.5
#byte RCREG=0x1A
#byte lcd=0x06
#byte TRISB=0x86
#bit rs=0x07.2
#bit TRIS_rs=0x87.2
#bit e=0x07.3
#bit TRIS_e=0x87.3
void cmd(char,int);
char a[2],b;
int i=0,j;
void main()
{
   
      TRISB=0x00;
      TRIS_rs=0;
      TRIS_e=0;
      TXSTA=0x20;    //00100010
      RCSTA=0x90;    //10010000
      SPBRG=31; //Baud Rate
      cmd(0x0c,0);
      cmd(0x38,0);
      RCIF=0;
   while(TRUE)
   {
   
      while(RCIF==0)
      {
         cmd(0xc0,0);
         cmd(i+48,1);
         delay_ms(1000);
         i++;
      }
      
     delay_ms(200);
      cmd(0x80,0);
         RCIF=0;
         delay_ms(200);
         b=RCREG;
         cmd(b,1);
      
   }
}
void cmd(char c,int t)
{
   lcd=c;
   rs=t;
   e=1;
   delay_ms(100);
   e=0;
}
