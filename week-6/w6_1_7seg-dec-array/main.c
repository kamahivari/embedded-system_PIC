#include <main.h>
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG

#use delay(clock=4M)

int sayilar[]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};

void main()
{
   int i = 0 ;
   set_tris_a(0x00);
   set_tris_b(0x00);
   output_b(0x00);
   output_a(0x04);
   
   
   while(TRUE)
   {
      for(i=0;i<10;i++){
      output_b(sayilar[i]);
      delay_ms(500);
      
      }
     i=0;
   }

}
