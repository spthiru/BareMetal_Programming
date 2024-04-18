///////////////////////////////////////////////////////////////////////////////////////////
// Name         : Thirumoorthy p                                                         //                                                                                      //
// FileName     : timer10                                                                //
// Description  : using timer10 blinking led                                             //
///////////////////////////////////////////////////////////////////////////////////////////
#include "baseConfig.h"
void rcc_config(void)
{
  //clear hse on bit
   *RCC_CR &= (~1<<16);

   //set hse on bit 1
   *RCC_CR |= (1<<16);

   //checking of hse bit set or not 
   while((*RCC_CR & (1<<17)) == 0);

   //clear switch hse bit
   *RCC_CFGR &= ~(3<<0);

  //select switch as hse oscillator
   *RCC_CFGR |= (1<<0);

   //checking hse oscillator set or not
   while(!(*RCC_CFGR & (1<<2)) == 4);

   //timer10 enable 
   *RCC_APB2ENR |= (1<<17);

   //select port a
   *RCC_AHB1ENR |= (1<<0); 
}
void gpio_config(void)
{
   //select moder on Aport a0th pin
   *GPIOA_MODER = *GPIOA_MODER | (1<<0);

}
void timer_10(void)
{
   //disable the timer10 counter bit
   *TIM10_CR1 &= (~1<<0);

   //enable the update disable
   *TIM10_CR1 |= (1<<1);

   //disable update request source
   *TIM10_CR1 &= (~1<<2);

   //enble auto reload bit
   *TIM10_CR1 |= (1<<7);

   //set counter value
   *TIM10_CNT = 0;

   //load reload value
   *TIM10_PSC = 999;

   //load auto reload
   *TIM10_ARR = 2499;

   //clear update interrupt
   // *TIM10_SR &= (~1<<0);

   //enable couter
   *TIM10_CR1 |= (1<<0);

   //waiting interrupt set
   while(!(*TIM10_SR & (1<<0))); 

   //clear interrupt
   *TIM10_SR &= (~1<<0);
}
void led_on(void)
{
   //set a0 pin high for led on
   *GPIOA_ODR |= (1<<0);

   timer_10();

   //set a0 pin low for led off
   *GPIOA_ODR &= (0<<0);

   timer_10();

}
int main()
{
   rcc_config();
   gpio_config();
   while(1)
   {
      led_on();
   }
}
