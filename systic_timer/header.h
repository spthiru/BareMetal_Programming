//RCC COONFIG
volatile unsigned int *RCC_RC       = (volatile unsigned int *)(0x40023800);
volatile unsigned int *RCC_CFGR     = (volatile unsigned int *)(0x40023808);
volatile unsigned int *RCC_AHB1ENR  = (volatile unsigned int *)(0x40023830);

//PORT SELECTION
volatile unsigned int *GPIOA_MODER  = (volatile unsigned int *)(0x40020000);
volatile unsigned int *GPIOA_IDR    = (volatile unsigned int *)(0x40020010);
volatile unsigned int *GPIOA_ODR    = (volatile unsigned int *)(0x40020014);
volatile unsigned int *GPIOA_PUPDR  = (volatile unsigned int *)(0x4002000c);

//SYS TICK CONFIGURATION
volatile unsigned int *STK_CTRL = (volatile unsigned int *) (0xe000e010);
volatile unsigned int *STK_LOAD = (volatile unsigned int *) (0xe000e014);
