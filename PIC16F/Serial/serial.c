#include<16f877a.h>
#use delay(CLOCK=20M)
#byte TXSTA=0x98
#byte RCSTA=0x18
#byte SPBRG=0x99
#bit TXIF=0x0C.4
#byte TXREG=0x19
char a[]="Raja";
int i;
void main()
{
 //  TXSTA=0x20;    //00100010
 //  RCSTA=0x90;    //10010000
 //  SPBRG=31;    //Baud Rate
   //while(TRUE)
   {
      for(i=0;i<4;i++)
      {
      delay_ms(100);
         TXREG=a[i];
         while(TXIF==0);
         TXIF=0;
      }
   }
}
