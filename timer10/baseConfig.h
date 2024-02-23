//rcc configuration 
volatile unsigned int *RCC_CR      = (volatile unsigned int *)(0x40023800);
volatile unsigned int *RCC_CFGR    = (volatile unsigned int *)(0x40023808);
volatile unsigned int *RCC_AHB1ENR = (volatile unsigned int *)(0x40023830);
volatile unsigned int *RCC_APB2ENR = (volatile unsigned int *)(0x40023844);

//general purpose input output configuration
volatile unsigned int *GPIOA_MODER = (volatile unsigned int *)(0x40020000);
volatile unsigned int *GPIOA_ODR   = (volatile unsigned int *)(0x40020014);

//timer10 configuration
volatile unsigned int *TIM10_CR1   = (volatile unsigned int *)(0x40014400);
volatile unsigned int *TIM10_CNT   = (volatile unsigned int *)(0x40014424);
volatile unsigned int *TIM10_PSC   = (volatile unsigned int *)(0x40014428);
volatile unsigned int *TIM10_ARR   = (volatile unsigned int *)(0x4001442c);
volatile unsigned int *TIM10_SR    = (volatile unsigned int *)(0x40014410);
