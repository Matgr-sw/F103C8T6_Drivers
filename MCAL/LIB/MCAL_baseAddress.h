/*
 * 	MCAL_baseAddress.h
 *
 *  Created on: Nov, 2026
 *      Author: SaadanyOmar
 *      Last Update:     01:41 PM, Thursday, November 19, 2026
 */

#ifndef		MCAL_baseAddress_H
#define		MCAL_baseAddress_H

#define		FLASH_BASE_ADDRESS		(0x40022000)
#define		RCC_BASE_ADDRESS		  (0x40021000)
#define		DMA1_BASE_ADDRESS	  	(0x40020000)
#define		TIM11_BASE_ADDRESS		(0x40015400)
#define		TIM10_BASE_ADDRESS		(0x40015000)
#define		TIM9_BASE_ADDRESS		  (0x40014C00)
#define		ADC3_BASE_ADDRESS		  (0x40013C00)
#define		USART1_BASE_ADDRESS		(0x40013800)
#define		TIM8_BASE_ADDRESS		  (0x40013400)
#define		SPI1_BASE_ADDRESS		  (0x40013000)
#define		TIM1_BASE_ADDRESS		  (0x40012C00)
#define		ADC2_BASE_ADDRESS		  (0x40012800)
#define		ADC1_BASE_ADDRESS		  (0x40012400)
#define		GPIOD_BASE_ADDRESS		(0x40011400)
#define		GPIOC_BASE_ADDRESS		(0x40011000)
#define		GPIOB_BASE_ADDRESS		(0x40010C00)
#define		GPIOA_BASE_ADDRESS		(0x40010800)
#define		EXTI_BASE_ADDRESS		  (0x40010400)
#define		AFIO_BASE_ADDRESS	  	(0x40010000)
#define		DAC_BASE_ADDRESS		  (0x40007400)
#define		PWR_BASE_ADDRESS		  (0x40007000)
#define		CAN1_BASE_ADDRESS		  (0x40006400)
#define		CAN2_BASE_ADDRESS		  (0x40006800)
#define		I2C2_BASE_ADDRESS		  (0x40005800)
#define		I2C1_BASE_ADDRESS		  (0x40005400)
#define		USART3_BASE_ADDRESS		(0x40004800)
#define		USART2_BASE_ADDRESS		(0x40004400)
#define		RTC_BASE_ADDRESS	  	(0x40002800)
#define		TIM14_BASE_ADDRESS		(0x40002000)
#define		TIM13_BASE_ADDRESS		(0x40001C00)
#define		TIM12_BASE_ADDRESS		(0x40001800)
#define		TIM7_BASE_ADDRESS		  (0x40001400)
#define		TIM6_BASE_ADDRESS  		(0x40001000)
#define		TIM5_BASE_ADDRESS		  (0x40000C00)
#define		TIM4_BASE_ADDRESS		  (0x40000800)
#define		TIM3_BASE_ADDRESS		  (0x40000400)
#define		TIM2_BASE_ADDRESS		  (0x40000000)


typedef struct
{
	volatile uint32_t   CR;
	volatile uint32_t   CFGR;
	volatile uint32_t   CIR;
	volatile uint32_t   APB2RSTR;
	volatile uint32_t   APB1RSTR;
	volatile uint32_t   AHBENR;
	volatile uint32_t   APB2ENR;
	volatile uint32_t   APB1ENR;
	volatile uint32_t   BDCR;
	volatile uint32_t   CSR;

}  RCC_Register_t;


typedef struct
{
	volatile uint32_t 	CR;
	volatile uint32_t 	CSR;

}PWR_Registers_t;


typedef struct
{
	volatile uint32_t 	CR[2];
	volatile uint32_t 	IDR;
    volatile uint32_t	ODR;
    volatile uint32_t	BSRR;
    volatile uint32_t	BRR;
    volatile uint32_t	LCKR;

}GPIO_Registers_t;





#define RCC 	((volatile RCC_Register_t*)(RCC_BASE_ADDRESS))

#define GPIOA	((volatile GPIO_Registers_t*) (GPIOA_BASE_ADDRESS))
#define GPIOB	((volatile GPIO_Registers_t*) (GPIOB_BASE_ADDRESS))
#define GPIOC	((volatile GPIO_Registers_t*) (GPIOC_BASE_ADDRESS))
#define GPIOD	((volatile GPIO_Registers_t*) (GPIOD_BASE_ADDRESS))



#define PWR		((volatile PWR_Registers_t*) (PWR_BASE_ADDRESS))


#endif
