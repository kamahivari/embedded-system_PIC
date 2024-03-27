#include <main1.h>
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG

#use delay(clock=4M)

void main()
{
   set_tris_b(0);
   
   while(TRUE)
   {
      //TODO: User Code
      
      output_b(0x01);
      delay_ms(500);
      output_b(0x00);
      delay_ms(500);
   }

}
