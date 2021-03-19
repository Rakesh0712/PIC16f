#include <main.h>
#USE SPI (MASTER, SPI1, MODE=0, BITS=8)
#bit ss1=0x05.5
#bit TRIS_ss1=0x85.5
#bit ss2=0x05.0
#bit TRIS_ss2=0x85.0
void main()
{
   TRIS_ss1=0;
   TRIS_ss2=0;
   delay_ms(100);
   ss1=0;
   spi_write(0x00);
   ss1=1;
   delay_ms(100);
   ss2=0;
   spi_write(0x00);
   ss2=1;
   delay_ms(100);
   while(TRUE)
   {
      ss1=0;
      spi_write('A');
      ss1=1;
      delay_ms(100);
      ss2=0;
      spi_write('B');
      ss2=1;
      delay_ms(100);
      //TODO: User Code
   }

}
