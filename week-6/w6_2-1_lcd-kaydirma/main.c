#include <main.h>
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG

#use delay(clock=4M)

//#define use_portb_lcd TRUE
//port d kullandigimiz icin bu ifadeye gerek yok , DEFAUL deger PORT D

#include <lcd.c>

//char z;
int i = 5;


void main()
{
   lcd_init();
   printf(lcd_putc,"\f");
   printf(lcd_putc,"DENEME");
   printf(lcd_putc,"\nTEST");
   delay_ms(1000);
   printf(lcd_putc,"\f");
   delay_ms(1000);
  
   
   while(TRUE)
   
   {  //i<42 denendi harf kaybetmeden geldi , 64 vs denenebilir
      for(i=1;i<24;i++){
      lcd_gotoxy(i,1);
      printf(lcd_putc,"Hosgeldiniz");
      delay_ms(200);
      //bu satiri unutursan ileri giderken surekli 'H' yazdirir
      printf(lcd_putc,"\f");
      }
      //i=42 denendi harf kaybetmeden geldi , 64 vs denenebilir
      for(i=24;i>0;i--)
      {
      lcd_gotoxy(i,1);
      printf(lcd_putc,"Hosgeldiniz");
      delay_ms(200);
      //bu satiri unutursan geriye donerken surekli 'z' yazdirir
      printf(lcd_putc,"\f");
      }
   }

}
