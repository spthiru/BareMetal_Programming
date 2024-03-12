//```````````````````````````````````````````````````````````````````````````````//
//Author Name : ThiruMoorthy.p							 //
//File Name   : PWM led blinking						 //
//Date        : 12-03-2024			                		 //
//Description : Using Pluse width modulation blink led 				 //
//-------------------------------------------------------------------------------//

#include "baseConfig.h"
void rcc_config(void)
{

   //internal clock ready
   while((*RCC_CR & 1<<1) == 0);

   //select timer10 on APB2ENR
   *RCC_APB2ENR |= (1<<17);

   //select port b 
   *RCC_AHB1ENR |= (1<<1);
}
void gpio_config(void)
{
   //select moder to the A port b8 pin
   *GPIOB_MODER |= (1<<17);
   
   //aternative high register AF3 value set
   *GPIOB_AFRH |= (3<<0);

}
void timerWithpwm(void)
{
   //clear  capture compare output mode enable bit, OC1 is not active
   *TIM10_CCER &= (~1<<0);

   //clear Output Compare 1 preload enable bit, Preload register on TIMx_CCR1 disabled. TIMx_CCR1 can be written at anytime, the new value is tak    en in account immediately
   *TIM10_CCMR1 &= (~1<<3);

   //enable Capture/Compare 1 selection as a output, CC1 channel is configured as output.
   *TIM10_CCMR1 &= (~3<<0);

   //set PWM mode 1 - Channel 1 is active as long as TIMx_CNT < TIMx_CCR1 else inactive 
   *TIM10_CCMR1 |= (6<<4);

   //Output compare 1 fast enable
   *TIM10_CCMR1 |= (1<<2);

   //set value for cappture compare mode using internal clock
   *TIM10_CCR1 = 1;

   //Output compare 1 preload enable
   *TIM10_CCMR1 |= (1<<7);

   //set autoreload value
   *TIM10_ARR = 320;

   //set prescalar value
   *TIM10_PSC = 999;

   //set count value
   *TIM10_CNT = 0;

   //Capture/Compare 1 output Polarity. set hiigh
   *TIM10_CCER &= (~1<<1);

   //CC1NP: Capture/Compare 1 complementary output Polarity.
   *TIM10_CCER &= (~1<<3);

   //capture compare output mode enable
   *TIM10_CCER |= (1<<0);

   //Output compare 1 preload enable
   *TIM10_CCMR1 |= (1<<3);

   //update event
   *TIM10_EGR |= (3<<0);

   //enable counter
   *TIM10_CR1 |= (1<<0);
}

int main()
{
   rcc_config();
   gpio_config();
   timerWithpwm();
   while(1)
   {
      for( int i = 320; i>0 ; i--)
      {
	 //until wait cc interrupt flag set 1
         while(!(*TIM10_SR & (1<<0))); 
      
         //clear the intrrrupt flags
         *TIM10_SR &= (~3<<0);

	 //CCR1 value set
	 *TIM10_CCR1 = i;
      }
   }
}
