#include <main.h>
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG

#use delay(clock=4M)

#define BUTON1 pin_b0
#define BUTON2 pin_b1
#define LED pin_b7

void main()
{
   set_tris_b(0x03);
   output_b(0);
   
   while(TRUE)
   {
      //TODO: User Code
       if(input(BUTON1)==1)  
       {
         output_high(LED);
       }
       if(input(BUTON2)==1)
       {
         output_low(LED);
       }
         
   }

}
