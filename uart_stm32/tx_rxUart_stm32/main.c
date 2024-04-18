///////////////////////////////////////////////////////////////////////////////////////////
// Name         : Thirumoorthy p                                                         //                                                                                      //
// FileName     : tx_rxUart_stm32                                                        //
// Description  : transfer data and recevie the data                                     //
///////////////////////////////////////////////////////////////////////////////////////////
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

   // moder on usart rx pin set as a input
   *GPIOA_MODER &= (~3<<20);

   //set usart rx pin as a alternative function mode
   *GPIOA_MODER |= (1<<21);

   //clear speed select bits on ospeedr reg
   *GPIOA_OSPEEDR &= (~0x3<<20);

   //set speed as a10 pin fast speed mode
   *GPIOA_OSPEEDR |= (1<<21);

   //set alternative value for usart rx AF7
    *GPIOA_AFRH |= (0x7<<8);

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

  //enable rcevier
  *USART_CR1 |= (1<<2);

}
void data_transfer(char data)
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

   uart1_config();

   //untill wait TXE data transfer to the shift register
   while(!(*USART_SR & (1<<7)));

   *USART_DR = data;

   //transmission complete 
   while(!(*USART_SR & (1<<6)));

   *USART_SR &= ~(1<<6);
   
   //*USART_DR &= (~) ;

}
int main()
{
   char m;
   rcc_config();
   gpio_config();
   uart1_config();
   while(1)
   {
      while(!(*USART_SR & (1<<5)));

      *USART_SR &= (~1<<5);

       m = *USART_DR;

       data_transfer(m);
   }
}
