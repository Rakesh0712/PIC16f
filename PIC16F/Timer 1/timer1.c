#include <16f877a.h>
#bit TMR1IF=0x0c.0
#byte TMR1L=0x0e
#byte TMR1H=0x0f
#byte T1CON=0x10
#bit led=0x05.0
#bit TRIS_led=0x85.0
void timer();
void main()
{
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
   unsigned int i;
   T1CON=0x01;
   for(i=0;i<200;i++)
   {
      TMR1H=0x9E;
      TMR1L=0x58;
      while(TMR1IF==0);
      TMR1IF=0;
   }
}
   
