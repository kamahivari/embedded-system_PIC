#include <main.h>
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG

#use delay(clock=4M)

void main()
{

   set_tris_b(0x00);
   set_tris_d(0x03); //2 buton var artik o y�zden 0x03 verildi
   int x=1;
   output_b(0); //baslangicta tum LED ler sonuk olsun
   
   
   while(TRUE)
   {
      //TODO: User Code
   
      if(input(pin_d0)==1){
            x=x*2;
            output_b(x);
            //200 ms ile butona seri seri basmam 200ms den daha hizli o yuzden
            //LEDler 2-3 l� atlayarak yaniyor bu gecikmeyi artiralim
            //delay_ms(200);
            delay_ms(500);
            if(x==256){x=128;}
      }
      
      if(input(pin_d1)==1){
         x=x/2;
         output_b(x);
         //delay_ms(200);
         delay_ms(500);
         if(x<1){x=1;}
      }
   }
}
   




