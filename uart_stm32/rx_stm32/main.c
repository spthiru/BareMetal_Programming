#include "baseConfig.h"
void rcc_config(void)
{
   //clear the usart enable in rcc
   *RCC_APB2ENR &= (~1<<4);

   //enable usart in rcc
   *RCC_APB2ENR |= (1<<4);

   //select usart port
   *RCC_AHB1ENR |= (1<<0);
}
void port_config(void)
{
   *GPIOA_MODER |= (1<<0);
   // moder on usart rx pin set as a input
   *GPIOA_MODER &= (~0x3<<20);

   //set usart rx pin as a alternative function mode
   *GPIOA_MODER |= (1<<21);

   //set alternative value for usart rx AF7
   *GPIOA_AFRH |= (0x7<<8);

   //clear speed select bits on ospeedr reg
   *GPIOA_OSPEEDR &= (~0x3<<20);

   //set speed as a10 pin fast speed mode
   *GPIOA_OSPEEDR |= (1<<21); 
}
void uart_config(void)
{
   //select word length
   *USART_CR1 &= (~1<<12);

  //enable usart
  *USART_CR1 |= (1<<13);

 //clear stop bit 
 *USART_CR2 &= (~0x3<<12);

 //set stop bit 2
 *USART_CR2 |= (1<<13);

 //set baud rate fraction
 *USART_BRR |= 4;

 //set baud rate mantissa
 *USART_BRR |= (103<<4);

 //enable rcevier
 *USART_CR1 |= (1<<2); 
}
void rx_data()
{
  char m;
   m = *USART_DR;

  while(!(*USART_SR & (1<<5)));

 *USART_SR &= (~1<<5);

 if(m == 'a')
 {
    *GPIOA_ODR |= (1<<0);
 } 
}
int main()
{
   rcc_config();
   port_config();
   uart_config();
   rx_data();
}
