///////////////////////////////////////////////////////////////////////////////////////////
// Name         : Thirumoorthy p                                                         //                                                                                      //
// FileName     : DroneMotor                                                             //
// Description  : controlling drone motor using PWM and ADC                              //
///////////////////////////////////////////////////////////////////////////////////////////
#include "baseConfig.h"
void rcc_config(void)
{
   //internal clock ready
   while((*RCC_CR & 1<<1) == 0);

   //select timer10 on APB2ENR
   *RCC_APB2ENR |= (1<<17);

   //select port b
   *RCC_AHB1ENR |= (1<<1);


   //set usart1 enable pin
   *RCC_APB2ENR |= (1<<4);

   //A port selection
   *RCC_AHB1ENR |= (1<<0);


   //ADC1 clock enable
   *RCC_APB2ENR |= (1<<8);
}
void gpio_config(void)
{
   //select moder to the A port b8 pin
   *GPIOB_MODER |= (1<<17);

   //aternative high register AF3 value set
   *GPIOB_AFRH |= (3<<0);
   

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
void PWM_config(void)
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
   *TIM10_CCR1 = 7;

   //Output compare 1 preload enable
   *TIM10_CCMR1 |= (1<<7);

   //set autoreload value
   *TIM10_ARR = 3200;

   //set prescalar value
   *TIM10_PSC = 100;

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
   adc_config();
   PWM_config();
   gpio_config();
   while(1)
   {
     val = conv_adc();
     val = val+65; 
    
     //until wait SR register interrupt flag set 1
     while(!(*TIM10_SR & (1<<0)));
    
     //clear the intrrupt flags
     *TIM10_SR &= (~3<<0);
    
     //CCR1 value set
     *TIM10_CCR1 = val;

     uart_config((val/1000)+48);

     uart_config(((val/100)%10)+48);

     uart_config(((val/10)%10)+48);
   
     uart_config((val%10)+48);
  
     uart_config('\n');
     
     uart_config('\r');
   }
}
