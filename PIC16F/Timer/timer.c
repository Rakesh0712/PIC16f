#include <16f877a.h>
#bit led=0x08.0
#bit TRIS_led=0x88.0
#byte OPTION_REG=0x81
#byte TMR0=0x01
#bit TMR0IF=0x0b.2
void timer();
void main()
{  
   TRIS_led=0;
   while(TRUE)
   {
      
      led=0;
      timer();
      led=1;
      timer();
   }
}
void timer()
{
   unsigned long int i;
   OPTION_REG=0x00;  //xx000000
   for(i=0;i<50000;i++)
   {
      TMR0=6;  // starting number
   
      while(TMR0IF==0);
      TMR0IF=0;
   }
}
