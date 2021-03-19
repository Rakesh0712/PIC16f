#include <i2c.h>
#use I2C(master, sda=PIN_B0, scl=PIN_B1)
void main()
{

   while(TRUE)
   {
      i2c_start();    // Start condition

     i2c_write(0xa0);// Device address

     i2c_write('A');// Low byte of command
     
     i2c_stop();     // Stop condition



    // i2c_write('A'>>8);// High byte of command

 
   }

}
