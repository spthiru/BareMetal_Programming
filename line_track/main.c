///////////////////////////////////////////////////////////////////////////////////////////
// Name         : Thirumoorthy p                                                         //                                                                                      //
// FileName     : line track                                                             //
// Description  : using ir line tracking module led blowing                              //
///////////////////////////////////////////////////////////////////////////////////////////
#include "baseconfig.h"
void rcc_config(void)
{
   //external clock on clear bit
   *RCC_RC &= ~(1<<16);

   //external clock on set bit
   *RCC_RC |= (1<<16);

   //checking external clock on bit or not
   while((*RCC_RC & (1<<17)) == 0);

   //switch selection clear bit
	   *RCC_CFGR &= ~(0x3<<0);

   //swtich selection set bit
   *RCC_CFGR |= (1<<0);

   //checking of switch selection set or not
   while(!(*RCC_CFGR & 1<<2) == 4);

   //pin selection
   *RCC_AHB1ENR |= (1<<0);
}
void gpio_config(void)
{
   //gpio moder selection a0 pin set as output
   *GPIOA_MODER |= (1<<0);

   //gpio moder selection a1 pin set as input
   *GPIOA_MODER &= ~(0xc<<0);

   //give a pull down for a1 input pin
   *GPIOA_PUPDR |= (1<<3);   
}
void line_detect(void)
{
/*   //keep on checking the sensor detecting white or not
   while(1)
   {
      //white line detected 
      if(!(*GPIOA_IDR & 1<<1))
      {
	 //a0 output  pin set as 0
	 *GPIOA_ODR &= (0<<0);
      }
      else//white line not detect and black detected
      {
	 //ao output pin set as 1
	 *GPIOA_ODR |= (1<<0);
      }
   }*/
   while(1)
   {
      if(*GPIOA_IDR & (1<<1))
      {
	 *GPIOA_ODR |= (1<<0);
      }
      else
      {
	 *GPIOA_ODR &= (0<<0);
      }
   }
}
int main()
{  
   rcc_config();
   gpio_config();
   line_detect();
}
