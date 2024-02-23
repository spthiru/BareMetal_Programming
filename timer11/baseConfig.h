//rcc config
volatile unsigned int *RCC_CR      = (volatile unsigned int *)(0x40023800);
volatile unsigned int *RCC_CFGR    = (volatile unsigned int *)(0x40023808);
volatile unsigned int *RCC_AHB1ENR = (volatile unsigned int *)(0x40023830);
volatile unsigned int *RCC_APB2ENR = (volatile unsigned int *)(0x40023844);

//gpio configuration
volatile unsigned int *GPIOA_MODER = (volatile unsigned int *)(0x40020000);
volatile unsigned int *GPIOA_ODR   = (volatile unsigned int *)(0x40020014);

//timer11 config
volatile unsigned int *TIM11_CR1 = (volatile unsigned int *)(0x40014800);
volatile unsigned int *TIM11_SR  = (volatile unsigned int *)(0x40014810);
volatile unsigned int *TIM11_CNT = (volatile unsigned int *)(0x40014824);
volatile unsigned int *TIM11_PSC = (volatile unsigned int *)(0x40014828);
volatile unsigned int *TIM11_ARR = (volatile unsigned int *)(0x4001482c);
