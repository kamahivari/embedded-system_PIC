#include <main.h>
#fuses XT, NOWDT, NOPROTECT,NOBROWNOUT, NOLVP, NOPUT,NOWRT, NODEBUG

#use delay(clock=4M)


int sayilar []={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0xFF,0xEF};

void main()
{
   
   set_tris_a(0x06);
   set_tris_b(0x00);
   output_b(0x00);
   output_a(0x04);
   //int say=0;
   
   while(TRUE)
   {
      //TODO: User Code
      for(int i =0;i<10;i++)
      {
         output_b(sayilar[i]);
         delay_ms(500);
      }
   }

}
