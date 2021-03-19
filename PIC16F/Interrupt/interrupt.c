#include <16F877A.h>
#use delay(CLOCK=20M)
#bit led=0x07.0
#bit TRIS_led=0x87.0
void main()
{
   TRIS_led=0;
   ENABLE_INTERRUPTS(GLOBAL );
   ENABLE_INTERRUPTS(INT_EXT);
   EXT_INT_EDGE(L_TO_H);
   while(TRUE)
   {
   }
}
   #INT_EXT
   void fun()
   {
      led=~led;
      delay_ms(10);
   }
