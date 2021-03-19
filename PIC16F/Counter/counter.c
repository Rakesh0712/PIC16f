#include <16f877a.h>
#include <stdio.h>
#use delay(clock=20M)
#byte T1CON=0x10
#byte TMR1L=0x0E
//it TMR1IF=0x0c.0
#byte lcd=0x06
#byte TRISB=0x86
//#bit sw=0x07.0
//#bit TRIS_sw=0x87
#bit rs=0x07.2
#bit e=0x07.3
#bit TRIS_rs=0x87.2
#bit TRIS_e=0x87.3
//#bit sw=0x07.0
//#bit TRIS_sw=0x87.0
void cmd(char,int);
unsigned int a,i;
char x[4];
void main()
{
   TRISB=0x00;
   TRIS_rs=0;
   TRIS_e=0;
   cmd(0x0C,0);
   cmd(0x38,0);
   //TRIS_sw=0;
   
  
   T1CON=0x0B;
   TMR1L=0;
   //cmd('0',1);
 while(TRUE)
 {
   cmd(0x80,0);
   a=TMR1L;
   sprintf(x,"%u",a);
   for(i=0;i<4;i++)
   {
      cmd(x[i],1);
   }
}
}
void cmd(char c,int t)
{
   lcd=c;
   rs=t;
   e=1;
   delay_ms(10);
   e=0;
}
