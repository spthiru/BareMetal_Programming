#include "baseConfig.h"
void rcc_config(void)
{

 //set usart1 enable pin
 *RCC_APB2ENR |= (1<<4);

 //A port selection
 *RCC_AHB1ENR |= (1<<0);

 //ADC1 clock enable
 *RCC_APB2ENR |= (1<<8);
}
void gpio_config(void)
{
   //clear select moder a9 pin 
   *GPIOA_MODER &= (~3<<18);

   //set alternative function a9 pin
   *GPIOA_MODER |= (1<<19);

   //clear high speed bit for pin a9
   *GPIOA_OSPEEDR &= (~3<<18);

   //set fast speed bit for pin a9
   *GPIOA_OSPEEDR |= (1<<19);

   //set aternativ function bit af7
   *GPIOA_AFRH |= (0x7<<4);

   //set aport moder in analog mode for a0 pin
   *GPIOA_MODER |=3;
}
void adc_config(void)
{
   //clear ADC_CR1 regster
   *ADC_CR1 = 0;

   //A/D Converter ON / OFF
   *ADC_CR2 |= (1<<0);

   //RES[1:0]: Resolution
   *ADC_CR1 &= ~(0x03<<24);
   *ADC_CR1 |= (1<<25); // 8-bit (11 ADCCLK cycles)

   // clear Continuous conversion
   *ADC_CR2 &= ~(0x2);

   //SWSTART: Start conversion of regular channel
   *ADC_CR2 |= (1<<30);

   //Data alignment
   *ADC_CR2 &= ~(1<<11);

   //Channel x sampling time selection :15 cycles
   *ADC_SMPR2 &= ~(1<<7);
   *ADC_SMPR2 |= 1;

   /*
    // clear reagister
    *ADC_SR  &= ~(0x3f);

     //A/D Converter ON / OFF
     *ADC_CR2 |= (1<<0);

     //Start conversion of regular channels
     *ADC_CR2 |= (1<<30);

     //Channel x sampling time selection :15 cycles
     *ADC_SMPR2 &= ~(0x7<<0);
     *ADC_SMPR2 |=(0x1<<0);

     //Resolution : 8-bit (11 ADCCLK cycles)
     *ADC_CR1 &= (~3<<24);
     *ADC_CR1 |= (1<<25);

 //    *ADC_CR2 &= (0<<11);

     //Regular channel sequence length
      *ADC_SQR3 &= (~0xf<<20);

      *ADC_CCR  &= (~3<<16);*/
}
unsigned int conv_adc(void)
{
   unsigned int adc_data = 0; 

   *ADC_CR2 |= (1<<30);

     //untill wait Regular channel end of conversion
     while(!(*ADC_SR & 0x2));

     adc_data = *ADC_DR;

     return(adc_data);
}
void uart_config(unsigned char data)
{

   //clear select word length for uart
   *USART_CR1 &= (~1<<12);

   //enable usart
   *USART_CR1 |= (1<<13);

   //stop bit set
   *USART_CR2 &= (~3<<12);

   *USART_CR2 |= (1<<13);

   //set baud rate value fraction
   *USART_BRR |= 4;

   //set baud rate mantisa value
   *USART_BRR |= (103<<4);

  // TE interupt enble
  *USART_CR1 |= (1<<3);

 //untill wait TXE data transfer to the shift register
 while(!(*USART_SR & (1<<7)));

 //data transmission
  *USART_DR = data;

   //transmission complete 
   while(!(*USART_SR & (1<<6)));

   *USART_SR &= (~1<<6);
}
int main()
{
   unsigned int val;
   rcc_config();
   gpio_config();
   adc_config();
   while(1)
   {
     val = conv_adc(); 
     for(int i=0; i<7;i++)
     {
	if(val & 1<<i)
	{
	   uart_config('1');
	}
	else
	{
	   uart_config('0');
	}
     }

    /* uart_config((val/1000)+48);

     uart_config(((val/100)%10)+48);

     uart_config(((val/10)%10)+48);

     uart_config((val%10)+48);*/
  
     uart_config('\n');
     
     uart_config('\r');
    // for(int i=0; i<10000; i++);
   }
}
