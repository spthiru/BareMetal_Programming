///////////////////////////////////////////////////////////////////////////////////////////
// Name         : Thirumoorthy p                                                         //                                                                                      //
// FileName     : 8x8_matirx                                                             //
// Description  : using 8x8 led matrix blinking diffrent pattern                         //
///////////////////////////////////////////////////////////////////////////////////////////
//clock config
volatile unsigned int *RCC_RC      = (volatile unsigned int*)0x40023800;
volatile unsigned int *RCC_CFGR    = (volatile unsigned int *)0x40023808;
volatile unsigned int *RCC_AHB1ENR = (volatile unsigned int *)0x40023830;

//A port
volatile unsigned int *GPIOA_MODER = (volatile unsigned int *)0x40020000;
volatile unsigned int *GPIOA_ODR   = (volatile unsigned int *)0x40020014;
//B port
volatile unsigned int *GPIOB_MODER = (volatile unsigned int *)0x40020400;
volatile unsigned int *GPIOB_ODR   = (volatile unsigned int *)0x40020414;

void delay()
{
   for(int i = 0; i < 100000;i++);
}

void rcc_config()
{
   *RCC_RC = *RCC_RC &(0x00010000);
   *RCC_RC = *RCC_RC |(1<<16);
   while(*RCC_RC &(1<<17) == 0);

   *RCC_CFGR = *RCC_CFGR & (0x00000003);
   *RCC_CFGR = *RCC_CFGR | (1<<0);
   while(!(*RCC_CFGR & (1<<2)) == 4);

   *RCC_AHB1ENR = *RCC_AHB1ENR | (1<<0);
   *RCC_AHB1ENR = *RCC_AHB1ENR | (1<<1);
}

void gpio()
{
   int i;
   for(i = 0; i < 20; i++)
   {
      *GPIOA_MODER = *GPIOA_MODER | (1<<i);
      *GPIOB_MODER = *GPIOB_MODER | (1<<i);
      delay();
      i++;
   }
}

void ledblinking()
{
   int i, j;
   for(i = 0; i < 10; i++)
   {
      *GPIOA_ODR = *GPIOA_ODR | (1<<i);
      for(j = 0; j <= i ; j++)
      {
	 *GPIOB_ODR = *GPIOB_ODR | (1<<j);
      }
      delay();
      delay();
   }
   for(i = 0; i < 10; i++)
   {
      *GPIOA_ODR = *GPIOA_ODR & (0<<i);
      for(j = 0; j <= i ; j++)
      {
	 *GPIOB_ODR = *GPIOB_ODR & (0<<j);
      }
      delay();
      delay();
   }
}

int main()
{
   rcc_config();
   gpio();
   while(1)
   {
      ledblinking();
      delay();
   }
}
