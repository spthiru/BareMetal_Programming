
////RCC REGISTER ADDRESS      ////////////

#define RCC_CR            (volatile unsigned int *)0x40023800     // RCC clock control register (RCC_CR)
#define PLL_CFRG          (volatile unsigned int *)0x40023804     //RCC PLL configuration register (RCC_PLLCFGR)
#define RCC_CFGR          (volatile unsigned int *)0x40023808     // RCC clock configuration register (RCC_CFGR)
#define RCC_CIR           (volatile unsigned int *)0x4002380C     // RCC clock interrupt register (RCC_CIR)
#define RCC_AHB1RSTR      (volatile unsigned int *)0x40023810     // RCC AHB1 peripheral reset register (RCC_AHB1RSTR) 
#define RCC_AHB2RSTR      (volatile unsigned int *)0x40023814     // RCC AHB2 peripheral reset register (RCC_AHB2RSTR) 
#define RCC_APB1RSTR      (volatile unsigned int *)0x40023820     // RCC APB1 peripheral reset register for (RCC_APB1RSTR) 
#define RCC_APB2RSTR      (volatile unsigned int *)0x40023824     // RCC APB2 peripheral reset register (RCC_APB2RSTR)
#define RCC_AHB1ENR       (volatile unsigned int *)0x40023830     // RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
#define RCC_AHB2ENR       (volatile unsigned int *)0x40023834     // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
#define RCC_APB1ENR       (volatile unsigned int *)0x40023840     // RCC APB1 peripheral clock enable register (RCC_APB1ENR)
#define RCC_APB2ENR       (volatile unsigned int *)0x40023844     // RCC APB2 peripheral clock enable register (RCC_APB2ENR)
#define RCC_RCC_AHB1LPENR (volatile unsigned int *)0x40023850     // RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR)
#define RCC_AHB2LPENR     (volatile unsigned int *)0x40023854     // RCC AHB2 peripheral clock enable in low power mode register (RCC_AHB2LPENR)
#define RCC_APB1LPENR     (volatile unsigned int *)0x40023860     // RCC APB1 peripheral clock enable in low power mode register (RCC_APB1LPENR)
#define RCC_APB2LPENR     (volatile unsigned int *)0x40023864     // RCC APB2 peripheral clock enabled in low power mode register (RCC_APB2LPENR)
#define RCC_BDCR          (volatile unsigned int *)0x40023870     // RCC Backup domain control register (RCC_BDCR)
#define RCC_CSR           (volatile unsigned int *)0x40023874     // RCC clock control & status register (RCC_CSR)
#define RCC_SSCGR         (volatile unsigned int *)0x40023880     // RCC spread spectrum clock generation register (RCC_SSCGR)
#define RCC_PLLI2SCFGR    (volatile unsigned int *)0x40023884     // RCC PLLI2S configuration register (RCC_PLLI2SCFGR)
#define RCC_DCKCFGR       (volatile unsigned int *)0x4002388C     // RCC Dedicated Clocks Configuration Register (RCC_DCKCFGR)

//// END RCC REGISTER ADDRESS /////////////////

////// GPIOA PORT ADDRESS ////////////////////////

#define GPIOA_MODER    	(volatile unsigned int *)0x40020000         // GPIOA port mode register (GPIOx_MODER) (x = A..E and H)
#define GPIOA_OTYPER    (volatile unsigned int *)0x40020004         // GPIOA port output type register (GPIOx_OTYPER)
#define GPIOA_OSPEEDR  	(volatile unsigned int *)0x40020008         // GPIOA port output speed register (GPIOx_OSPEEDR)
#define GPIOA_PUPDR 	(volatile unsigned int *)0x4002000C         // GPIOA port pull-up/pull-down register (GPIOx_PUPDR)
#define GPIOA_IDR    	(volatile unsigned int *)0x40020010         // GPIOA port input data register (GPIOx_IDR) (x = A..E and H)
#define GPIOA_ODR     	(volatile unsigned int *)0x40020014         // GPIOA port output data register (GPIOx_ODR) (x = A..E and H)
#define GPIOA_BSRR     	(volatile unsigned int *)0x40020018         // GPIOA port bit set/reset register (GPIOx_BSRR) (x = A..E and H)
#define GPIOA_LCKR     	(volatile unsigned int *)0x4002001C         // GPIOA port configuration lock register (GPIOx_LCKR)
#define GPIOA_AFRL    	(volatile unsigned int *)0x40020020         // GPIOA alternate function low register (GPIOx_AFRL) (x = A..E and H)
#define GPIOA_AFRH    	(volatile unsigned int *)0x40020024         // GPIOA alternate function high register (GPIOx_AFRH)

//////// GPIOA ADDRESS END ////////////////////


////// GPIOB PORT ADDRESS ////////////////////////

#define GPIOB_MODER    	(volatile unsigned int *)0x40020400         // GPIOB port mode register (GPIOx_MODER) (x = A..E and H)
#define GPIOB_OTYPER    (volatile unsigned int *)0x40020404         // GPIOB port output type register (GPIOx_OTYPER)
#define GPIOB_OSPEEDR  	(volatile unsigned int *)0x40020408         // GPIOB port output speed register (GPIOx_OSPEEDR)
#define GPIOB_PUPDR 	(volatile unsigned int *)0x4002040C         // GPIOB port pull-up/pull-down register (GPIOx_PUPDR)
#define GPIOB_IDR    	(volatile unsigned int *)0x40020410         // GPIOB port input data register (GPIOx_IDR) (x = A..E and H)
#define GPIOB_ODR     	(volatile unsigned int *)0x40020414         // GPIOB port output data register (GPIOx_ODR) (x = A..E and H)
#define GPIOB_BSRR     	(volatile unsigned int *)0x40020418         // GPIOB port bit set/reset register (GPIOx_BSRR) (x = A..E and H)
#define GPIOB_LCKR     	(volatile unsigned int *)0x4002041C         // GPIOB port configuration lock register (GPIOx_LCKR)
#define GPIOB_AFRL    	(volatile unsigned int *)0x40020420         // GPIOB alternate function low register (GPIOx_AFRL) (x = A..E and H)
#define GPIOB_AFRH    	(volatile unsigned int *)0x40020424         // GPIOB alternate function high register (GPIOx_AFRH)

//////// GPIOA ADDRESS END ////////////////////

////// GPIOC PORT ADDRESS ////////////////////////

#define GPIOC_MODER    	(volatile unsigned int *)0x40020800         // GPIOC port mode register (GPIOx_MODER) (x = A..E and H)
#define GPIOC_OTYPER    (volatile unsigned int *)0x40020804         // GPIOC port output type register (GPIOx_OTYPER)
#define GPIOC_OSPEEDR  	(volatile unsigned int *)0x40020808         // GPIOC port output speed register (GPIOx_OSPEEDR)
#define GPIOC_PUPDR 	(volatile unsigned int *)0x4002080C         // GPIOC port pull-up/pull-down register (GPIOx_PUPDR)
#define GPIOC_IDR    	(volatile unsigned int *)0x40020810         // GPIOC port input data register (GPIOx_IDR) (x = A..E and H)
#define GPIOC_ODR     	(volatile unsigned int *)0x40020814         // GPIOC port output data register (GPIOx_ODR) (x = A..E and H)
#define GPIOC_BSRR     	(volatile unsigned int *)0x40020818         // GPIOC port bit set/reset register (GPIOx_BSRR) (x = A..E and H)
#define GPIOC_LCKR     	(volatile unsigned int *)0x4002081C         // GPIOC port configuration lock register (GPIOx_LCKR)
#define GPIOC_AFRL    	(volatile unsigned int *)0x40020820         // GPIOC alternate function low register (GPIOx_AFRL) (x = A..E and H)
#define GPIOC_AFRH    	(volatile unsigned int *)0x40020824         // GPIOC alternate function high register (GPIOx_AFRH)

////// END GPIOC ADDRESS ///////////////////////

////// GPIOD PORT ADDRESS ////////////////////////

#define GPIOD_MODER    	(volatile unsigned int *)0x40020C00         // GPIOD port mode register (GPIOx_MODER) (x = A..E and H)
#define GPIOD_OTYPER    (volatile unsigned int *)0x40020C04         // GPIOD port output type register (GPIOx_OTYPER)
#define GPIOD_OSPEEDR  	(volatile unsigned int *)0x40020C08         // GPIOD port output speed register (GPIOx_OSPEEDR)
#define GPIOD_PUPDR 	(volatile unsigned int *)0x40020C0C         // GPIOD port pull-up/pull-down register (GPIOx_PUPDR)
#define GPIOD_IDR    	(volatile unsigned int *)0x40020C10         // GPIOD port input data register (GPIOx_IDR) (x = A..E and H)
#define GPIOD_ODR     	(volatile unsigned int *)0x40020C14         // GPIOD port output data register (GPIOx_ODR) (x = A..E and H)
#define GPIOD_BSRR     	(volatile unsigned int *)0x40020C18         // GPIOD port bit set/reset register (GPIOx_BSRR) (x = A..E and H)
#define GPIOD_LCKR     	(volatile unsigned int *)0x40020C1C         // GPIOD port configuration lock register (GPIOx_LCKR)
#define GPIOD_AFRL    	(volatile unsigned int *)0x40020C20         // GPIOD alternate function low register (GPIOx_AFRL) (x = A..E and H)
#define GPIOD_AFRH    	(volatile unsigned int *)0x40020C24         // GPIOD alternate function high register (GPIOx_AFRH)

//////// GPIOA ADDRESS END ////////////////////


////// GPIOE PORT ADDRESS ////////////////////////

#define GPIOE_MODER    	(volatile unsigned int *)0x40021000         // GPIOE port mode register (GPIOx_MODER) (x = A..E and H)
#define GPIOE_OTYPER    (volatile unsigned int *)0x40021004         // GPIOE port output type register (GPIOx_OTYPER)
#define GPIOE_OSPEEDR  	(volatile unsigned int *)0x40021008         // GPIOE port output speed register (GPIOx_OSPEEDR)
#define GPIOE_PUPDR 	(volatile unsigned int *)0x4002100C         // GPIOE port pull-up/pull-down register (GPIOx_PUPDR)
#define GPIOE_IDR    	(volatile unsigned int *)0x40021010         // GPIOE port input data register (GPIOx_IDR) (x = A..E and H)
#define GPIOE_ODR     	(volatile unsigned int *)0x40021014         // GPIOE port output data register (GPIOx_ODR) (x = A..E and H)
#define GPIOE_BSRR     	(volatile unsigned int *)0x40021018         // GPIOE port bit set/reset register (GPIOx_BSRR) (x = A..E and H)
#define GPIOE_LCKR     	(volatile unsigned int *)0x4002101C         // GPIOE port configuration lock register (GPIOx_LCKR)
#define GPIOE_AFRL    	(volatile unsigned int *)0x40021020         // GPIOE alternate function low register (GPIOx_AFRL) (x = A..E and H)
#define GPIOE_AFRH    	(volatile unsigned int *)0x40021024         // GPIOE alternate function high register (GPIOx_AFRH)

//////// GPIOE ADDRESS END ////////////////////


////// GPIOH PORT ADDRESS ////////////////////////

#define GPIOH_MODER    	(volatile unsigned int *)0x40021C00         // GPIOA port mode register (GPIOx_MODER) (x = A..E and H)
#define GPIOH_OTYPER    (volatile unsigned int *)0x40021C04         // GPIOA port output type register (GPIOx_OTYPER)
#define GPIOH_OSPEEDR  	(volatile unsigned int *)0x40021C08         // GPIOA port output speed register (GPIOx_OSPEEDR)
#define GPIOH_PUPDR 	(volatile unsigned int *)0x40021C0C         // GPIOA port pull-up/pull-down register (GPIOx_PUPDR)
#define GPIOH_IDR    	(volatile unsigned int *)0x40021C10         // GPIOA port input data register (GPIOx_IDR) (x = A..E and H)
#define GPIOH_ODR     	(volatile unsigned int *)0x40021C14         // GPIOA port output data register (GPIOx_ODR) (x = A..E and H)
#define GPIOH_BSRR     	(volatile unsigned int *)0x40021C18         // GPIOA port bit set/reset register (GPIOx_BSRR) (x = A..E and H)
#define GPIOH_LCKR     	(volatile unsigned int *)0x40021C1C         // GPIOA port configuration lock register (GPIOx_LCKR)
#define GPIOH_AFRL    	(volatile unsigned int *)0x40021C20         // GPIOA alternate function low register (GPIOx_AFRL) (x = A..E and H)
#define GPIOH_AFRH    	(volatile unsigned int *)0x40021C24         // GPIOA alternate function high register (GPIOx_AFRH)

//////// GPIOH ADDRESS END ////////////////////

////TIMER 10 REGISRERS ///////////////////////

#define TIM10_CR1   ((volatile unsigned int *)0x40014400)    // TIM10 control register 1 (TIM10_CR1)
#define TIM10_DIER  ((volatile unsigned int *)0x4001440C)    // TIM10 Interrupt enable register (TIM10_DIER)
#define TIM10_SR    ((volatile unsigned int *)0x40014410)    // TIM10 status register
#define TIM10_EGR   ((volatile unsigned int *)0x40014414)    // TIM10 event generation register (TIM10_EGR)
#define TIM10_CCMR1 ((volatile unsigned int *)0x40014418)    // TIM10 capture/compare mode register 1 (TIM10_CCMR1)
#define TIM10_CCER  ((volatile unsigned int *)0x40014420)    // TIM10 capture/compare enable register (TIM10_CCER)
#define TIM10_CNT   ((volatile unsigned int *)0x40014424)    // TIM10 counter (TIM10_CNT)
#define TIM10_PSC   ((volatile unsigned int *)0x40014428)    // TIM10 prescaler (TIM10_PSC)
#define TIM10_ARR   ((volatile unsigned int *)0x4001442C)    // TIM10 auto-reload register (TIM10_ARR)
#define TIM10_CCR1  ((volatile unsigned int *)0x40014434)    // TIM10 capture/compare register 1 (TIM10_CCR1)
#define TIM10_OR    ((volatile unsigned int *)0x40014450)    // TIM11 option register 1 (TIM11_OR)

//// END TIMER 10 REGISTERS ADDRESS  ////////
////TIMER 11 REGISRERS ///////////////////////

#define TIM11_CR1   ((volatile unsigned int *)0x40014400)    // TIM10 control register 1 (TIM10_CR1)
#define TIM11_DIER  ((volatile unsigned int *)0x4001440C)    // TIM10 Interrupt enable register (TIM10_DIER)
#define TIM11_SR    ((volatile unsigned int *)0x40014410)    // TIM10 status register
#define TIM11_EGR   ((volatile unsigned int *)0x40014414)    // TIM10 event generation register (TIM10_EGR)
#define TIM11_CCMR1 ((volatile unsigned int *)0x40014418)    // TIM10 capture/compare mode register 1 (TIM10_CCMR1)
#define TIM11_CCER  ((volatile unsigned int *)0x40014420)    // TIM10 capture/compare enable register (TIM10_CCER)
#define TIM11_CNT   ((volatile unsigned int *)0x40014424)    // TIM10 counter (TIM10_CNT)
#define TIM11_PSC   ((volatile unsigned int *)0x40014428)    // TIM10 prescaler (TIM10_PSC)
#define TIM11_ARR   ((volatile unsigned int *)0x4001442C)    // TIM10 auto-reload register (TIM10_ARR)
#define TIM11_CCR1  ((volatile unsigned int *)0x40014434)    // TIM10 capture/compare register 1 (TIM10_CCR1)
#define TIM11_OR    ((volatile unsigned int *)0x40014450)    // TIM11 option register 1 (TIM11_OR)

//// END TIMER 11 REGISTERS ADDRESS  ////////

//// USART  REGISGER ////////////////////////
#define USART_SR   ((volatile unsigned int *)0x40011000)      // USART 1 Status register (USART_SR) 
#define USART_DR   ((volatile unsigned int *)0x40011004)      // USART 1 Data register (USART_DR) 
#define USART_BRR  ((volatile unsigned int *)0x40011008)      // USART 1 Baud rate register (USART_BRR) 
#define USART_CR1  ((volatile unsigned int *)0x4001100C)      // USART 1 Control register 1 (USART_CR1) 
#define USART_CR2  ((volatile unsigned int *)0x40011010)      // USART 2 Control register 2 (USART_CR2) 
#define USART_CR3  ((volatile unsigned int *)0x40011014)      // USART 3 Control register 3 (USART_CR3) 
#define USART_GTPR ((volatile unsigned int *)0x40011018)      // USART  Guard time and prescaler register (USART_GTPR) 

////////// USART REGISTER END ////////////

////////////////SYSTICK TIMER /////////////////////////////////////////////////

#define STK_CTRL   ((volatile unsigned int *)0xE000E010)  //SysTick control and status register(STK_CTRL)
#define STK_LOAD   ((volatile unsigned int *)0xE000E014)  //SysTick reload value register (STK_LOAD)
#define STK_VAL    ((volatile unsigned int *)0xE000E018)  //SysTick current value register (STK_VAL)
#define STK_CALIB  ((volatile unsigned int *)0xE000E01C)  //SysTick calibration value register (STK_CALIB)

///////////////SYSTICK TIMER END///////////////////////////////////////////////

//////////// ADC REGISTER ADDRESS ////////////////////////////////////////////////

#define ADC_SR     ((volatile unsigned int *)0x40012000)           // ADC status register (ADC_SR)
#define ADC_CR1    ((volatile unsigned int *)0x40012004)           // ADC control register 1 (ADC_C1)
#define ADC_CR2    ((volatile unsigned int *)0x40012008)           // ADC control register 2 (ADC_CR2)
#define ADC_SMPR1  ((volatile unsigned int *)0x4001200C)           // ADC sample time register 1 (ADC_SMPR1)
#define ADC_SMPR2  ((volatile unsigned int *)0x40012010)           // ADC sample time register 2 (ADC_SMPR2)
#define ADC_JOFR1  ((volatile unsigned int *)0x40012014)           // ADC status register (ADC_SR)
#define ADC_JOFR2  ((volatile unsigned int *)0x40012018)           // ADC status register (ADC_SR)
#define ADC_JOFR3  ((volatile unsigned int *)0x4001201C)           // ADC status register (ADC_SR)
#define ADC_JOFR4  ((volatile unsigned int *)0x40012020)           // ADC status register (ADC_SR)
#define ADC_HTR    ((volatile unsigned int *)0x40012024)           // ADC watchdog higher threshold register (ADC_HTR)
#define ADC_LTR    ((volatile unsigned int *)0x40012028)           // ADC watchdog lower threshold register (ADC_LTR)
#define ADC_SQR1   ((volatile unsigned int *)0x4001202C)           // ADC regular sequence register 1 (ADC_SQR1)
#define ADC_SQR2   ((volatile unsigned int *)0x40012030)           // ADC regular sequence register 2 (ADC_SQR2)
#define ADC_SQR3   ((volatile unsigned int *)0x40012034)           // ADC regular sequence register 3 (ADC_SQR3)
#define ADC_JSQR   ((volatile unsigned int *)0x40012038)           // ADC injected sequence register (ADC_JSQR)
#define ADC_JDR1   ((volatile unsigned int *)0x4001203C)           // ADC injected data register x (ADC_JDR1) 
#define ADC_JDR2   ((volatile unsigned int *)0x40012040)           // ADC injected data register x (ADC_JDR2) 
#define ADC_JDR3   ((volatile unsigned int *)0x40012044)           // ADC injected data register x (ADC_JDR3) 
#define ADC_JDR4   ((volatile unsigned int *)0x40012048)           // ADC injected data register x (ADC_JDR4) 
#define ADC_DR     ((volatile unsigned int *)0x4001204C)           // ADC regular data register (ADC_DR)
#define ADC_CCR    ((volatile unsigned int *)0x40012304)           // ADC common control register (ADC_CCR)

////////////// ADC REGISTER ADDRESS END //////////////////////////////////////////
