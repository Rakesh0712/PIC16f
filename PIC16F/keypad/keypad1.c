#include<16f877a.h>
#bit r1=0x08.0
#bit r2=0x08.1
#bit r3=0x08.2
#bit r4=0x08.3
#bit c1=0x08.4
#bit c2=0x08.5
#bit c3=0x08.6
#byte TRISD=0x88     //TRIS address
#byte lcd=0x06
#byte TRISB=0x86     //TRIS address
#bit rs=0x07.0
#bit e=0x07.1
#byte TRISC=0x87   //TRIS address
void cmd(char,int);
void delay();
char keypad();
int i,t;
char p;
void main()
{
   TRISD=0xf0;   //11110000
   TRISB=0x00;    
   TRISC=0xfc;   //11111100
   cmd(0x0f,0);
   cmd(0x38,0);
   while(TRUE)
   {
          p=keypad();     // input 
          cmd(p,1);
   }
}
void cmd(char c,int t)   //lcd function
{
   lcd=c;
   rs=t;
   e=1;
   delay();
   e=0;
}
void delay()   // delay loop
{
   for(i=0;i<100;i++);
}
char keypad()  //keypad function
{
   t=0;
   while(t==0)
   {
      r1=1;
      r2=r3=r4=0;
      if(c1==1){while(c1==1);t=1;return '1';}
      if(c2==1){while(c2==1);t=1;return '2';}
      if(c3==1){while(c3==1);t=1;return '3';}
      r2=1;
      r1=r3=r4=0;
      if(c1==1){while(c1==1);t=1;return '4';}
      if(c2==1){while(c2==1);t=1;return '5';}
      if(c3==1){while(c3==1);t=1;return '6';}
      r3=1;
      r1=r2=r4=0;
      if(c1==1){while(c1==1);t=1;return '7';}
      if(c2==1){while(c2==1);t=1;return '8';}
      if(c3==1){while(c3==1);t=1;return '9';}
      r4=1;
      r1=r2=r3=0;
      if(c1==1){while(c1==1);t=1;return '*';}
      if(c2==1){while(c2==1);t=1;return '0';}
      if(c3==1){while(c3==1);t=1;return '#';}
   }
}
  
