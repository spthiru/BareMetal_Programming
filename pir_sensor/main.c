#include "header.h"
void sys_tick_tmr(void)
{
   int i;
   for(i = 0; i < 1000000; i++);
}

void rcc_config(void)
{
   *RCC_RC = *RCC_RC & (~0x00010000);//CLEAR THE PARTICULAR BIT IN RCC_RC
   *RCC_RC = *RCC_RC | (1<<16); //SET EXTRENAL CLOCK BIT 
   while((*RCC_RC & (1<<17)) == 0);
   *RCC_CFGR = *RCC_CFGR & (~0x00000003);//CLEAR THE PARTICULAR BIT IN RCC_CFGR 
   *RCC_CFGR = *RCC_CFGR | (1<<0); //SET EXTERNAL CLOCK CONFIGURATION
   while(!(*RCC_CFGR & (0x00000004)) == 4);
   *RCC_AHB1ENR = *RCC_AHB1ENR | (1<<0); //SELECTION OF A PORT
}
void gpio_config(void)
{
   *GPIOA_MODER = *GPIOA_MODER | (1<<0);//SET MODER FOR A P0RT OUPUT MODE(PP)
   *GPIOA_MODER = *GPIOA_MODER & (~0x0000000c); //SET MODER A PORT INPUT MODE(PP)
   *GPIOA_PUPDR = *GPIOA_PUPDR & (~0X0000000c); //SET PULL DOWN A1 PIN
   *GPIOA_PUPDR = *GPIOA_PUPDR | (1<<3);//
}
void obj_detect(void)
{
   while(1)
   {
      if((*GPIOA_IDR & (1<<1)))//WAIT UNTILL A1 INPUT SET 1 
      {
	 *GPIOA_ODR = *GPIOA_ODR & (0<<0); //SET AS A0 OUTPUT 0 FOR LED OFF
      }
      else
      {
	 *GPIOA_ODR = *GPIOA_ODR | (1<<0); //SET AS A0 OUTPUT 1 FOR LED ON

      }
   }
}
int main()
{
   rcc_config();
   gpio_config();
   obj_detect();
}
