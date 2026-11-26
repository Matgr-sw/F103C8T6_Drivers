/***************************************************************************************************
 * @file:           RCC_prv.h
 * @brief:			This file contains the private definitions of the RCC driver
 * @author:         Ibrahim Saber
 * @version:        1.0
 * @date:           16-11-2026
 * Last Update:     4:40 PM, Wednesday, November 25, 2026
 ****************************************************************************************************/
#ifndef		RCC_PRV_H
#define 	RCC_PRV_H
								/*********************** prv MACROS  ***********************/
#define RCC_RDY_FLAGS_TIMEOUT		1000u
#define RCC_HSI_FREQ_HZ				8000000u
#define RCC_SYSCLK_MAX_HZ			72000000u
#define RCC_FLASH_0WS_MAX_HZ		24000000u
#define RCC_FLASH_1WS_MAX_HZ		48000000u
#define RCC_PLL_HSI_DIV				2u
#define RCC_PLL_XTPRE_DIV			2u
#define RCC_PLLMUL_OFFSET			2u
#define RCC_PLLMUL_MAX				16u

#define FLASH_LATENCY_0WS			0u
#define FLASH_LATENCY_1WS			1u
#define FLASH_LATENCY_2WS			2u


								/*********************** MASKS  ***********************/
#define CR_HSITRIM_MASK		0b11111
#define CR_HSICAL_MASK		0xFF

#define CFGR_SW_MASK		0b11
#define CFGR_SWS_MASK		0b11
#define CFGR_HPRE_MASK		0b1111
#define CFGR_PPRE1_MASK		0b111
#define CFGR_PPRE2_MASK		0b111
#define CFGR_ADC_PRE_MASK	0b11
#define CFGR_PLLMUL_MASK	0b1111
#define CFGR_MCO_MASK		0b1111


#define BDCR_RTCSEL_MASK	0b11


#define ACR_LATENCY_MASK	0b111
								/*********************** Bits  ***********************/
#define CR_HSION		0u
#define CR_HSIRDY		1u
#define CR_HSITRIM0		3u
#define CR_HSICAL0		7u
#define CR_HSEON		16u
#define CR_HSERDY		17u
#define CR_HSEBYP		18u
#define CR_CSSON		19u
#define CR_PLLON		24u
#define CR_PLLRDY		25u
#define CR_PLL2ON		26u
#define CR_PLL2RDY		27u
#define CR_PLL3ON		28u
#define CR_PLL3RDY		29u


#define CFGR_SW0		0u
#define CFGR_SWS0		2u
#define CFGR_HPRE0		4u
#define CFGR_PPRE10		8u
#define CFGR_PPRE20     11u
#define CFGR_ADC_PRE0	14u
#define CFGR_PLL_SRC	16u
#define CFGR_PLL_XTPRE	17u
#define CFGR_PLLMUL0	18u
#define CFGR_OTGSPRE	22u
#define CFGR_MCO0		24u


#define CIR_LSI_RDYF	0u
#define CIR_LSE_RDYF	1u
#define CIR_HSI_RDYF	2u
#define CIR_HSE_RDYF	3u
#define CIR_PLL_RDYF	4u
#define CIR_PLL2_RDYF	5u
#define CIR_PLL3_RDYF	6u
#define CIR_CSSF		7u
#define CIR_LSI_RDYIE	8u
#define CIR_LSE_RDYIE	9u
#define CIR_HSI_RDYIE	10u
#define CIR_HSE_RDYIE	11u
#define CIR_PLL_RDYIE	12u
#define CIR_PLL2_RDYIE	13u
#define CIR_PLL3_RDYIE	14u
#define CIR_LSI_RDYC	16u
#define CIR_LSE_RDYC	17u
#define CIR_HSI_RDYC	18u
#define CIR_HSE_RDYC	19u
#define CIR_PLL_RDYC	20u
#define CIR_PLL2_RDYC	21u
#define CIR_PLL3_RDYC	22u
#define CIR_CSSC		23u



#define APB2RSTR_AFIO_RST	0u
#define APB2RSTR_IOPA_RST	2u
#define APB2RSTR_IOPB_RST	3u
#define APB2RSTR_IOPC_RST	4u
#define APB2RSTR_IOPD_RST	5u
#define APB2RSTR_IOPE_RST	6u
#define APB2RSTR_ADC1_RST	9u
#define APB2RSTR_ADC2_RST	10u
#define APB2RSTR_TIM1_RST	11u
#define APB2RSTR_SPI1_RST	12u
#define APB2RSTR_USART1_RST	14u


#define APB1RSTR_TIM2_RST	0u
#define APB1RSTR_TIM3_RST	1u
#define APB1RSTR_TIM4_RST	2u
#define APB1RSTR_TIM5_RST	3u
#define APB1RSTR_TIM6_RST	4u
#define APB1RSTR_TIM7_RST	5u
#define APB1RSTR_WWDG_RST	11u
#define APB1RSTR_SPI2_RST	14u
#define APB1RSTR_SPI3_RST	15u
#define APB1RSTR_USART2_RST	17u
#define APB1RSTR_USART3_RST	18u
#define APB1RSTR_USART4_RST	19u
#define APB1RSTR_USART5_RST	20u
#define APB1RSTR_I2C1_RST	21u
#define APB1RSTR_I2C2_RST	22u
#define APB1RSTR_CAN1_RST	25u
#define APB1RSTR_CAN2_RST	26u
#define APB1RSTR_BKP_RST	27u
#define APB1RSTR_PWR_RST	28u
#define APB1RSTR_DAC_RST	29u


#define AHBENR_DMA1_EN		0u
#define AHBENR_DMA2_EN		1u
#define AHBENR_SRAM_EN		2u
#define AHBENR_FLITF_EN		4u
#define AHBENR_CRC_EN		6u
#define AHBENR_OTGFS_EN		12u
#define AHBENR_ETHMAC_EN	14u
#define AHBENR_ETHMAC_TX_EN	15u
#define AHBENR_ETHMAC_RX_EN	16u


#define APB2ENR_AFIO_EN		0u
#define APB2ENR_IOPA_EN		2u
#define APB2ENR_IOPB_EN		3u
#define APB2ENR_IOPC_EN		4u
#define APB2ENR_IOPD_EN		5u
#define APB2ENR_IOPE_EN		6u
#define APB2ENR_ADC1_EN		9u
#define APB2ENR_ADC2_EN		10u
#define APB2ENR_TIM1_EN		11u
#define APB2ENR_SPI1_EN		12u
#define APB2ENR_USART1_EN	14u



#define APB1ENR_TIM2_EN		0u
#define APB1ENR_TIM3_EN		1u
#define APB1ENR_TIM4_EN		2u
#define APB1ENR_TIM5_EN		3u
#define APB1ENR_TIM6_EN		4u
#define APB1ENR_TIM7_EN		5u
#define APB1ENR_WWDG_EN		11u
#define APB1ENR_SPI2_EN		12u
#define APB1ENR_SPI3_EN		13u
#define APB1ENR_USART2_EN	17u
#define APB1ENR_USART3_EN	18u
#define APB1ENR_USART4_EN	19u
#define APB1ENR_USART5_EN	20u
#define APB1ENR_I2C1_EN		21u
#define APB1ENR_I2C2_EN		22u
#define APB1ENR_CAN1_EN		25u
#define APB1ENR_CAN2_EN		26u
#define APB1ENR_BKP_EN		27u
#define APB1ENR_PWR_EN		28u
#define APB1ENR_DAC_EN		29u



#define BDCR_LSE_ON			0u
#define BDCR_LSE_RDY		1u
#define BDCR_LSE_BYP		2u
#define BDCR_RTCSEL0		8u
#define BDCR_RTC_EN			15u
#define BDCR_BRST			16u

#define CSR_LSI_ON			0u
#define CSR_LSI_RDY			1u
#define CSR_RMVF			24u
#define CSR_PIN_RSTF		26u
#define CSR_POR_RSTF		27u
#define CSR_SFT_RSTF		28u
#define CSR_IWDG_RSTF		29u
#define CSR_WWDG_RSTF		30u
#define CSR_LPWR_RSTF		31u


#define AHBRSTR_OTGFS_RST	12u
#define AHBRSTR_ETHMAC_RST	14u




#define CFGR2_PREDIV10		0u
#define CFGR2_PREDIV20		4u
#define CFGR2_PLL2MUL0		8u
#define CFGR2_PLL3MUL0		12u
#define CFGR2_PREDIV1SRC	16u
#define CFGR2_I2S2SRC		17u
#define CFGR2_I2S3SRC		18u



#define ACR_LATENCY0		0u
















#endif
