///////////////////////////////////////////////////////////////////////////////////////////
// Name         : Thirumoorthy p                                                         //                                                                                      //
// FileName     : timer11                                                                //
// Description  : using timer11 blinking led                                             //
///////////////////////////////////////////////////////////////////////////////////////////
#include "baseConfig.h"
void rcc_config()
{
   //clear rcc HSE on bit
   *RCC_CR &= (~1<<16);

   //set rcc HSE on bit
   *RCC_CR |= (1<<16);

   //checking rcc HSE bit set or not
   while((*RCC_CR & (1<<17)) == 0);

   //clear switch for HSE clock set bit
   *RCC_CFGR &= (~0x3<<0);

   //clear switch for HSE clock set bit
   *RCC_CFGR |= (1<<0);

   //checking HSE switch bit set or not
   while(!(*RCC_CFGR & (1<<2) == 4));

   //enable timer 11 
   *RCC_APB2ENR |= (1<<18);

   //a port selection
   *RCC_AHB1ENR |= (1<<0);

}
void gpio_config(void)
{
   //gpio_moder set for a0 pin
   *GPIOA_MODER |= (1<<0); 
}
void timer_11(void)
{
   //disable counter
   *TIM11_CR1 &= (~1<<0);

   //enable update disable
   *TIM11_CR1 |= (1<<1);

   //Update request source set as 0
   *TIM11_CR1 &= (~1<<2);

   //enable auto reload preload value
   *TIM11_CR1 |= (1<<7);

   //set counter start value
   *TIM11_CNT = 0;

   //assign the prescalar value
   *TIM11_PSC = 1000;

   //assign the auto reload value
   *TIM11_ARR = 2500;

   //enble counter
   *TIM11_CR1 |= (1<<0);

   //wait untill status reg 0 bit get 1
   while(!(*TIM11_SR & (1<<0)));

   //clear the status reg  0 th bit 
   *TIM11_SR &= (~1<<0);
}
void led_blinking(void)
{
   //trun on led
  *GPIOA_ODR |= (1<<0); 

  timer_11();

  //trun off led
  *GPIOA_ODR &= (0<<0);

  timer_11();
}
int main()
{
   rcc_config();
   gpio_config();
   timer_11();
   while(1)
   {
      led_blinking();
   }
}
