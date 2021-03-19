#include<pic16f877a.h>
#device ADC=10
#include<stdio.h>
#use delay(clock=10M)
#byte lcd=0x06
#byte TRISB=0x86
#bit rs=0x07.0
#bit TRIS_rs=0x87.0
#bit e=0x07.1
#bit TRIS_e=0x87.1
#bit sw1=0x05.1
#bit TRIS_sw1=0x85.1
#bit sw2=0x05.2
#bit TRIS_sw2=0x85.2
void cmd(char,int);
int i,y,z,a;
//float a;
char x[10];
char d[]="Select";
char f[]="Volt or mVolt";
void main()
{
   TRISB=0x00;
   TRIS_rs=0;
   TRIS_e=0;
   TRIS_sw1=1;
   TRIS_sw2=1;
   cmd(0x0c,0);
   cmd(0x38,0);
   cmd(0x85,0);
   for(i=0;i<6;i++)
   {
      cmd(d[i],1);
   }
   cmd(0xc2,0);
   for(i=0;i<13;i++)
   {
      cmd(f[i],1);
   }
   SETUP_ADC(ADC_CLOCK_INTERNAL);
   SETUP_ADC_PORTS(AN0);
   SET_ADC_CHANNEL(0);
     
   while(TRUE)
   { 
      y=z=0;
      if(sw1==0)     //volt
      {
         cmd(0x01,0);
         while(y<1)
         {
            a=READ_ADC();
            cmd(0x80,0);
            sprintf(x,"%d",a);
            
         
            
            //sprintf(x,"%f",a*.0048);
            for(i=0;i<4;i++)
            {
               cmd(x[i],1);
            }
            //cmd('V',1);
            //if(sw2==0)
            //{
            //   y=2;
            //}*/
         }
      }
      if(sw2==0)    //milli volt
      {
         cmd(0x01,0);
         while(z<1)
         {
            a=READ_ADC();
            cmd(0x80,0);
            sprintf(x,"%f",a*4.88);
            for(i=0;i<7;i++)
            {
               cmd(x[i],1);
            }
            if(sw1==0)
            {
               z=2;
            }
            cmd('m',1);
            cmd('V',1);
         }
      }
   }
}
void cmd(char c,int t)
{
   lcd=c;
   rs=t;
   e=1;
   delay_ms(5);
   e=0;
}
