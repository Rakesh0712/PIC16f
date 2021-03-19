#include <main1.h>
#USE SPI (SLAVE, SPI1, BITS=8, STREAM=SPI_1)

void main()
{

   while(TRUE)
   {
      spi_read();
      delay_ms(100);
      //TODO: User Code
   }

}
