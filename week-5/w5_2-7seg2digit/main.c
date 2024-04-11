#include <main.h>
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG

#use delay(clock=4M)

#define display_2 pin_a0
#define display_1 pin_a1

int birler=0,onlar=0,sayi=0;
int sayilar []={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0xFF,0xEF};

void main()
{
   set_tris_a(0x00);
   set_tris_b(0x00);
   output_a(0x03);
   output_b(0x00);
   output_low(display_1);
   output_low(display_2);

   while(TRUE)
   {
      //TODO: User Code
      
      birler=sayi%10;
      onlar=sayi/10;
      output_low(display_2);
      output_b(sayilar[birler]);
      //delay_ms(5);
      //biraz hizli sayiyor bunu yavaslatalim.
      //display 1 ve 2 nin aslinda ayni anda yanmadigini bu sayede gorebilirsin
      
      delay_ms(50);
      output_high(display_2);
      
      output_low(display_1);
      output_b(sayilar[onlar]);
      //delay_ms(5);
      delay_ms(50);
      output_high(display_1);
      
      
      sayi++;
      if(sayi==100)sayi=0;
      
   }

}
