#include <16F877A.h>

#device adc=10 // 0 -1023 
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG


#use delay(clock=4M)
#use fast_io(a)

#include <lcd.c>

unsigned long int deger=0;
float gerilim=0,sicaklik=0;

#int_ad

void sicaklik_kesmesi()
{
   if(sicaklik>30.0){
   output_b(0x01);
   }else{
   output_b(0x00);
   }

}

void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   
   set_tris_a(0x20);
   set_tris_d(0x00);
   lcd_init();
   setup_adc(adc_clock_div_32);
   setup_adc_ports(ALL_ANALOG);
   
   set_adc_channel(4);
   delay_us(20);
   
   
   enable_interrupts(INT_AD);
   enable_interrupts(GLOBAL);
   
   
   while(TRUE)
   {
      deger=read_adc();
      gerilim=deger*4.88759;
      sicaklik=gerilim/10+2;
      //sicaklik=gerilim/10;
      printf(lcd_putc,"\fdeger=%f",sicaklik);
      delay_ms(100);
   }

}
