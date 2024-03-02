#include "baseConfig.h"
void rcc_config(void)
{
   //set usart1 enable pin
   *RCC_APB2ENR |= (1<<4);

   //aport selection
   *RCC_AHB1ENR |= (1<<0);

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
}
void uart1_config()
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
}
void data_transfer(void)
{
   *USART_DR ='a';

   //transmission complete 
   while(!(*USART_SR & (1<<6)));

   *USART_SR &= ~(1<<6);

}
int main()
{
   rcc_config();
   gpio_config();
   uart1_config();
   data_transfer();
}
