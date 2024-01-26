//RCC CONFIGURE
volatile unsigned int *RCC_RC      = (volatile unsigned int *)(0x40023800);//CLOCK CONTROL SELECT AS EXTERNAL
volatile unsigned int *RCC_CFGR    = (volatile unsigned int *)(0x40023808);//CONFIGURE EXTERNAL CLOCK 
volatile unsigned int *RCC_AHB1ENR = (volatile unsigned int *)(0x40023830);//GPIO PORT SELECTION

//A_PORT,B_PORT, C_PORT PIN CONFIGURE
volatile unsigned int *GPIOA_MODER = (volatile unsigned int *)(0x40020000);//A PORT MODER SELECTION
volatile unsigned int *GPIOA_ODR   = (volatile unsigned int *)(0x40020014);//A PORT SET AS OUTPUT MODE

volatile unsigned int *GPIOB_MODER = (volatile unsigned int *)(0x40020400);//B PORT MODER SELECTION
volatile unsigned int *GPIOB_ODR   = (volatile unsigned int *)(0x40020414);//B PORT SET AS OUTPUT MODE

volatile unsigned int *GPIOA_IDR   = (volatile unsigned int *)(0x40020010);//C PORT SET AS INPUT MODE
volatile unsigned int *GPIOA_PUPDR = (volatile unsigned int *)(0x4002000c);//C PORT SET AS PULL UP/DOWN MODE
