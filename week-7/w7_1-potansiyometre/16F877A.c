#include <16F877A.h>
//#device adc=16
#device adc=8
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG


#use delay(clock=4M)
#use fast_io(a)

#include <lcd.c>

unsigned long int deger=0;

void main()
{
   set_tris_a(0x20);
   lcd_init();
   setup_adc(adc_clock_div_32);
   setup_adc_ports(ALL_ANALOG);
   
   set_adc_channel(4);
   
   while(TRUE)
   {
      //set_adc_channel(4);
      delay_us(20);
      deger=read_adc();
      printf(lcd_putc,"\fdeger=%lu",deger);
      delay_ms(100);
   }

}
