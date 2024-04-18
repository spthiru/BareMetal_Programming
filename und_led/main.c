///////////////////////////////////////////////////////////////////////////////////////////
// Name         : Thirumoorthy p                                                         //                                                                                      //
// FileName     : und_led                                                                //
// Description  : understanding example program write by own                             //
///////////////////////////////////////////////////////////////////////////////////////////
volatile unsigned int *RCC_CR      = (volatile unsigned int *)0x40023800;//clock control
volatile unsigned int *RCC_CFGR    = (volatile unsigned int *)0x40023808;//clock control configuration
volatile unsigned int *RCC_AHB1ENR = (volatile unsigned int *)0x40023830;//peripheral clock enable

//A port
volatile unsigned int *GPIOA_MODER = (volatile unsigned int *)0x40020000; 
volatile unsigned int *GPIOA_ODR   = (volatile unsigned int *)0x40020014; 


void rcc_config()
{
   *RCC_CR = *RCC_CR & (~0x00010000);//clear the RCC_CR 
   *RCC_CR = *RCC_CR | (1<<16);//set 16 bit for HSE clock bit

   while((*RCC_CR & 1<<17) == 0);

   *RCC_CFGR = *RCC_CFGR & (~0x00000003);//clear the RCC_CFGR
   *RCC_CFGR = *RCC_CFGR | (1<<0); //set RCCC_CFGR bit
   while(!(*RCC_CFGR & 0x00000004) == 4); 

   *RCC_AHB1ENR = *RCC_AHB1ENR | (1<<0);
}
void gpio()
{
   *GPIOA_MODER = *GPIOA_MODER | (1<<12);
   *GPIOA_ODR = *GPIOA_ODR | (1<<6);
}
void led_blink()
{
      *GPIOA_ODR = *GPIOA_ODR |(1<<6);
}
int main()
{
   rcc_config();
   gpio();
   while(1)
   {
      led_blink();
   }
}
