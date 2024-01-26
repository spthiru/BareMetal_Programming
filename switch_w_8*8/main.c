#include "header.h"
void delay(void)
{
   int i;
   for(i = 0; i < 1000000; i++);//for loop using delay purpose
}
void rcc_config(void)
{
   *RCC_RC = *RCC_RC & (~0x00010000);//clear the 16 bit in RCC_RC  for extrenal clock select
   *RCC_RC = *RCC_RC | (1<<16); // set external clock control bit
   while(*RCC_RC & (1<<17) == 0); 
   *RCC_CFGR = *RCC_CFGR & (0x00000003);//clear the 0 bit in RCC_CFGR reg for switch set as external 
   *RCC_CFGR = *RCC_CFGR | (1<<0); //set the switch as external clock configure
   while(!(*RCC_CFGR & (0x00000004)) == 4); 
   *RCC_AHB1ENR = *RCC_AHB1ENR | (0x00000007); // select ports a,b,c
}
void gpio_config(void )
{
   *GPIOA_MODER = *GPIOA_MODER | (0x00055555); //select a0 to a7 eigth pin in a port
   *GPIOB_MODER = *GPIOB_MODER | (0x00055555); //select b0 to b2 and b5 to b9 eight pin in b port
   *GPIOA_MODER = *GPIOA_MODER & (~0x00000003); //selct  pin input mode
   *GPIOA_PUPDR = *GPIOA_PUPDR & (~0x00000003); //clear the pin for pull down config
   *GPIOA_PUPDR = *GPIOA_PUPDR | (1<<1); //set  pin for pull down
}
int count_switch()
{
   int k = 0, i, j;
   while(1)
   {
      while(1)
      {
	 if((*GPIOA_IDR & (0x00000001)) == 1)
	 {
	    k++;
	    break;
	 }
      }
      if(k == 1)
      {
	    *GPIOA_ODR = *GPIOA_ODR | (1<<1);
	    *GPIOB_ODR = *GPIOB_ODR | (1<<0);
	    delay();
	    *GPIOA_ODR = *GPIOA_ODR & (0<<1);
	    *GPIOB_ODR = *GPIOB_ODR & (0<<0);
      }
      else if(k == 3)
      {
	 *GPIOA_ODR = *GPIOA_ODR | (0x0000ffff);
	 *GPIOB_ODR = *GPIOB_ODR | (0x0000ffff);
	 delay();
	 *GPIOA_ODR = *GPIOA_ODR & (0x00000000);
	 *GPIOB_ODR = *GPIOB_ODR & (0x00000000);
      }
      else if(k == 3)
      {
	 *GPIOA_ODR = *GPIOA_ODR | (0x0000000f);
	 *GPIOB_ODR = *GPIOB_ODR | (0x0000000f);
	 delay();
	 *GPIOA_ODR = *GPIOA_ODR & (0x00000000);
	 *GPIOB_ODR = *GPIOB_ODR & (0x00000000);
      }
      else if(k == 4)
      {
	 for(i = 1; i < 16 ; i++)
	 {
	       *GPIOA_ODR = *GPIOA_ODR | (1<<i);
	       *GPIOB_ODR = *GPIOB_ODR | (0x0000ffff);
	       delay();
	 }
	 delay();
	 *GPIOA_ODR = *GPIOA_ODR & (0x00000000);
	 *GPIOB_ODR = *GPIOB_ODR & (0x00000000);
      }
      else if(k == 5)
      {
	 for(i = 16; i >=1 ; i--)
	 {
	       *GPIOA_ODR = *GPIOA_ODR | (1<<i);
	       *GPIOB_ODR = *GPIOB_ODR | (0x0000ffff);
	       delay();
	 }
	 *GPIOA_ODR = *GPIOA_ODR & (0x00000000);
	 *GPIOB_ODR = *GPIOB_ODR & (0x00000000);
      }
   }
}
int main()
{
   rcc_config();
   gpio_config();
   count_switch();
}
