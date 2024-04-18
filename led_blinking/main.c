///////////////////////////////////////////////////////////////////////////////////////////
// Name         : Thirumoorthy p                                                         //                                                                                      //
// FileName     : led_blinking                                                           //
// Description  : using any port blowing the led                                         //
///////////////////////////////////////////////////////////////////////////////////////////

volatile unsigned int *RCC_CR       = (volatile unsigned int *)0x40023800;
volatile unsigned int *RCC_CFGR     = (volatile unsigned int *)0x40023808;
volatile unsigned int *RCC_AHB1ENR  = (volatile unsigned int *)0x40023830;

//portc
volatile unsigned int *GPIOA_MODER  = (volatile unsigned int *)0x40020000;
volatile unsigned int *GPIOA_ODR    = (volatile unsigned int *)0x40020014;

void rcc_config(void);
void gpioc_moder(void);
void led_blinking(void);

int main()
{
        rcc_config();
        gpioc_moder();
        while(1)
        {
                led_blinking();
        }
}

void rcc_config()
{

        *RCC_CR   = *RCC_CR & (~0x00010000);
        *RCC_CR   = *RCC_CR | (1<<16);
        while((*RCC_CR & 1<<17)==0);
        *RCC_CFGR = *RCC_CFGR & (~0X00000003);
        *RCC_CFGR = *RCC_CFGR | (1<<0);
        while(!(*RCC_CFGR & 0X00000004)==4);
        *RCC_AHB1ENR = *RCC_AHB1ENR | (1<<0);     
}

void gpioc_moder()
{
        *GPIOA_MODER  = *GPIOA_MODER | (1<<12);
        *GPIOA_ODR    = *GPIOA_ODR | (1<<6);
}

void led_blinking()
{
  // if(*GPIOA_ODR & (1<<6))
  // {
  
               // *GPIOA_ODR = *GPIOA_ODR & ~(1<<6);
  // }
  /* else
   {
                *GPIOA_ODR = *GPIOA_ODR | (1<<6);
 }*/
                *GPIOA_ODR = *GPIOA_ODR | (1<<6);
}
