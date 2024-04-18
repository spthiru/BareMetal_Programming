///////////////////////////////////////////////////////////////////////////////////////////
// Name         : Thirumoorthy p                                                         //                                                                                      //
// FileName     : sw_ledBlink	`			     				 //
// Description  : using switch controlled led  blowing                                   //
///////////////////////////////////////////////////////////////////////////////////////////
#include "header.h"
void delay()
{
   int i;
   for(i =0;i<1000000;i++);
}
void rcc_config(void)
{
   *RCC_RC = *RCC_RC & (~0x00010000);
   *RCC_RC = *RCC_RC | (1<<16);
   while(*RCC_RC & (1<<17)==0);
   *RCC_CFGR = *RCC_CFGR & (0x00000003);
   *RCC_CFGR = *RCC_CFGR | (0<<1);
   while(!(*RCC_CFGR & (0x00000004)) == 4);
   *RCC_AHB1ENR = *RCC_AHB1ENR | (1<<0);
}

void gpio(void)
{
   *GPIOA_MODER = *GPIOA_MODER | (1<<2);//set moder output mode in a1 pin
   *GPIOA_MODER = *GPIOA_MODER & (~0x00000003); //set moder input mode in ao pin
   *GPIOA_PUPDR = *GPIOA_PUPDR & (~0x00000003); // set pull down on a0 pin
   *GPIOA_PUPDR = *GPIOA_PUPDR | (1<<1); // set pull down on a0 pin
}
int main()
{
   rcc_config();
   gpio();
   while(1)
   {
      if((*GPIOA_IDR & (0x00000001) == 1)) //if a0 input pin getting 1 means conditon true 
      {
	 *GPIOA_ODR = *GPIOA_ODR | (1<<1); //led blinking in a1 pin output 
	 delay();
	 *GPIOA_ODR = *GPIOA_ODR & (0<<1);
	 delay();
      }
   }
}
