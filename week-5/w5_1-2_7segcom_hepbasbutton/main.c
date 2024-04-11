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
   int sayi=0;
   
   while(TRUE)
   {
   
      if(input(pin_a1)==1){
         sayi++;
         if(sayi==10)sayi=0;
         delay_ms(300);
      }
    output_b(sayilar[sayi]);
   }

}
