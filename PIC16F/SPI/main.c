#include <main.h>
#USE SPI (MASTER, SPI1, MODE=0, BITS=8)
#bit ss1=0x05.5
#bit TRIS_ss1=0x85.5
void main()
{
   TRIS_ss1=0;
   delay_ms(100);
   while(TRUE)
   {
      ss1=0;
      spi_write('A');
      ss1=1;
      delay_ms(100);
      //TODO: User Code
   }

}
