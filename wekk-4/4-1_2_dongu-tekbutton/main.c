#include <main.h>
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG

#use delay(clock=4M)

void main()
{

   set_tris_b(0x00);
   set_tris_d(0x01); //1 buton kullandigimiz icin 0x01 ama 2 buton olsa 0x03 verilmeli
   int x=1;
   output_b(0); //baslangicta tum LED ler sonuk olsun
   
   while(TRUE)
   {
      //TODO: User Code
      
      if(input(pin_d0)==1){
      //problem1 : 100ms ile simulator ve LED tepki veremiyor B0-33.pin LED yanmiyor gibi
      // O sebeple 100 ms => 200 ms olarak degistirelim
    
    /*
    
    // Problem 1 
    
     for(k=1;k<128;k++)
     {
     output_b(k);
     delay_ms(200);
     k=k*2;
     }
    */
    
    //Problem 2 -> devre butona 1 kere basinca calisiyor sadece , bir daha calismiyor
    // B0-B7 tum ledleri yakabiliyoruz ama bir kez.
    // k degerinin sifirlanmamasiyla alakali sanirim
    
    /*
     for(k=1;k<256;k=k*2)
     {
     output_b(k);
     delay_ms(200);
     }
     */
     for(int k=0;k<8;k++)
     {
     output_b(x);
     delay_ms(200);
     x=x*2;
     }
      k=0;
      x=1;
      output_b(x);
      delay_ms(500);
     
     
   }

}
}


