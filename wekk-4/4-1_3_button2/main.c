#include <main.h>
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG

#use delay(clock=4M)

void main()
{

   set_tris_b(0x00);
   set_tris_d(0x03); //2 buton var artik o yüzden 0x03 verildi
   int k=0,x=1;
   output_b(0); //baslangicta tum LED ler sonuk olsun
   
   
   while(TRUE)
   {
      //TODO: User Code
      
      if(input(pin_d0)==1)
      {
         x=1;
         for(k=0;k<8;k++){
         output_b(x);
         x=x*2;
         delay_ms(200);
         
         }
         
        
      }
      
      if(input(pin_d1)==1)
      {
         x=128;
         for(k=0;k<8;k++){
         output_b(x);
         x=x/2;
         delay_ms(200);
         
         }
        
      }
   }
   
}



