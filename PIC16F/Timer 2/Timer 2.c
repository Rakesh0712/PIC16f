#include <16f877a.h>
#byte T2CON=0x12
#byte TMR2=0x11
#bit TMR2IF=0x0C.1
/*#byte lcd=0x06
#bit rs=0x07.2
#bit e=0x07.3
#byte TRISB=0x86
#bit TRIS_rs=0x87.2
#bit TRIS_e=0x87.3*/
#bit led=0x05.0
#bit TRIS_led=0x85.0
void timer();
void main()
{
   /*TRISB=0x00;
   TRIS_rs=0;
   TRIS_e=0;
   cmd(0x0F,0);
   cmd(0x38,0);*/
   TRIS_led=0;
   while(TRUE)
   {
      led=1;
      timer();
      led=0;
      timer();
   }
}
void timer()
{
   unsigned  int16 i;
   T2CON=0x04;
   for(i=0;i<20000;i++)
   {
      TMR2=0x04;
      while(TMR2IF==0);
      TMR2IF=0;
   }
}      
