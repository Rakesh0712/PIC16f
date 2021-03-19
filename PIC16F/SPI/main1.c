#include <main1.h>
#USE SPI (SLAVE, SPI1, BITS=8, STREAM=SPI_1)
char a;
void main()
{
   while(TRUE)
   {
      a=spi_read();
      spi_write(a);
      delay_ms(100);
      //TODO: User Code
   }
}
