#include <16F877A.h>

#device adc=10 // 0 -1023 
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG


#use delay(clock=4M)
#use fast_io(a)

#include <lcd.c>

unsigned long int deger=0;
float gerilim=0,sicaklik=0;

void main()
{
   
   
   set_tris_a(0x20);
   set_tris_d(0x00);
   lcd_init();
   setup_adc(adc_clock_div_32);
   setup_adc_ports(ALL_ANALOG);
   
   set_adc_channel(4);
   
   while(TRUE)
   {
      deger=read_adc();
      gerilim=deger*4.88759;
      //sicaklik=gerilim/10+2;
      sicaklik=gerilim/10;
      printf(lcd_putc,"\fdeger=%f",sicaklik);
      delay_ms(100);
   }

}
