///////////////////////////////////////////////////////////////////////////////////////////
// Name         : Thirumoorthy p                                                         //                                                                                      //
// FileName     : led_blinking                                                           //
// Description  : without using timer blowing led                                        //
///////////////////////////////////////////////////////////////////////////////////////////
volatile unsigned int *RCC_CR      = (volatile unsigned int *)0x40023800;
volatile unsigned int *RCC_CFGR    = (volatile unsigned int *)0x40023808;
volatile unsigned int *RCC_AHB1ENR = (volatile unsigned int *)0x40023830;

volatile unsigned int *GPIOA_MODER = (volatile unsigned int *)0x40020000;
volatile unsigned int *GPIOA_ODR   = (volatile unsigned int *)0x40020014;

void delay()
{
   int i; 
   for(i = 0; i < 1000000; i++);
}

void rcc_config()
{
   *RCC_CR = *RCC_CR & (~0x00010000); //CLEAR THE PARTICULAR BIT IN RCC_CR
   *RCC_CR = *RCC_CR |(1<<16); //SET THE 16 BIT
   while((*RCC_CR & (1<<17))==0);

   *RCC_CFGR = *RCC_CFGR & (~0x00000003);//CLEAR THE PARTICULAR BITS IN RCC_CFGR
   *RCC_CFGR = *RCC_CFGR | (1<<0);
   while(!(*RCC_CFGR &(1<<3))==4);

   *RCC_AHB1ENR  = *RCC_AHB1ENR | (1<<0);
}
void gpio()
{
   int k = 0;
   for( k = 0; k < 16; k++)
   {
      *GPIOA_MODER = *GPIOA_MODER | (1<<k);
      k++;
   }
}
void led_blinking()
{
   int i;
   for(i = 7 ; i >= 0; i--)
   {
      *GPIOA_ODR = *GPIOA_ODR |(1<<i);
       delay();
      *GPIOA_ODR = *GPIOA_ODR &(0<<i);
       delay();
   }
}
int main()
{
   rcc_config();
   gpio();

   while(1)
   {
      led_blinking();
      delay();
   }
}
