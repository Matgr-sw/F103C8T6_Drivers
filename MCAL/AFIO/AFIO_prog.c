/***************************************************************************************************
 * @file:           AFIO_prog.c
 * @brief:			This file contains the implementation of the AFIO driver functions
 * @author:         Ibrahim Saber
 * @version:        1.0
 * @date:           24-11-2026
 * Last Update:     10:00 AM, Thursday, November 26, 2026
 ****************************************************************************************************/
#include <stdint.h>
#include <stddef.h>

#include "BIT_MATH.h"
#include "MCAL_baseAddress.h"

#include "AFIO_prv.h"
#include "AFIO_cfg.h"
#include "AFIO_interface.h"


							/*********************** prv vars  ***********************/
/*SWJ_CFG is write-only (reads undefined): last mode set, reset = full SWJ*/
static AFIO_SWJ_t AFIO_eSWJModeShadow = AFIO_Full_SWJ;



							/*********************** Functions  ***********************/


/**
* 	Description:                This Function is used to set the mapping state of the peripherals
* 	Parameters:                 - void
* 	Returns:                    - void
* 	Preconditions:              - The RCC driver is initialized and working
* 								- The clk is enabled of the AFIO peripheral
* 	Side effects:               No side effects
* 	Post Conditions:            Mapping configs from AFIO_cfg.h are applied
* 	Sync/Async:               	Sync.
*/
void AFIO_vInit(void)
{
	/*work on a copy of MAPR, written once at the end*/
	uint32_t Local_u32Mapr = AFIO->MAPR;

	/*put back the last SWJ mode, not the undefined read*/
	CLR_BITS((Local_u32Mapr), MAPR_SWJ_CFG0, AFIO_3BIT_MASK);
	SET_BITS((Local_u32Mapr), MAPR_SWJ_CFG0, AFIO_eSWJModeShadow);

	#if(SPI1_REMAPPING == AFIO_REMAPPED)
		SET_BIT((Local_u32Mapr), MAPR_SPI1_REMAP);
	#elif(SPI1_REMAPPING == AFIO_DEFAULT)
		CLR_BIT((Local_u32Mapr), MAPR_SPI1_REMAP);
	#else
		#error "Invalid AFIO MAP config"
	#endif

	#if(I2C1_REMAPPING == AFIO_REMAPPED)
		SET_BIT((Local_u32Mapr), MAPR_I2C1_REMAP);
	#elif(I2C1_REMAPPING == AFIO_DEFAULT)
		CLR_BIT((Local_u32Mapr), MAPR_I2C1_REMAP);
	#else
		#error "Invalid AFIO MAP config"
	#endif

	#if(USART1_REMAPPING == AFIO_REMAPPED)
		SET_BIT((Local_u32Mapr), MAPR_USART1_REMAP);
	#elif(USART1_REMAPPING == AFIO_DEFAULT)
		CLR_BIT((Local_u32Mapr), MAPR_USART1_REMAP);
	#else
		#error "Invalid AFIO MAP config"
	#endif

	#if(USART2_REMAPPING == AFIO_REMAPPED)
		SET_BIT((Local_u32Mapr), MAPR_USART2_REMAP);
	#elif(USART2_REMAPPING == AFIO_DEFAULT)
		CLR_BIT((Local_u32Mapr), MAPR_USART2_REMAP);
	#else
		#error "Invalid AFIO MAP config"
	#endif


	#if(USART3_REMAPPING == AFIO_DEFAULT)
		CLR_BITS((Local_u32Mapr), MAPR_USART3_REMAP0, AFIO_2BIT_MASK);
	#elif(USART3_REMAPPING == AFIO_PARTIAL_REMAP)
		CLR_BITS((Local_u32Mapr), MAPR_USART3_REMAP0, AFIO_2BIT_MASK);
		SET_BITS((Local_u32Mapr), MAPR_USART3_REMAP0, AFIO_USART3_PARTIAL_VAL);
	#elif(USART3_REMAPPING == AFIO_FULL_REMAP)
		CLR_BITS((Local_u32Mapr), MAPR_USART3_REMAP0, AFIO_2BIT_MASK);
		SET_BITS((Local_u32Mapr), MAPR_USART3_REMAP0, AFIO_USART3_FULL_VAL);
	#else
		#error "Invalid AFIO MAP config"
	#endif


	#if(TIM1_REMAPPING == AFIO_DEFAULT)
		CLR_BITS((Local_u32Mapr), MAPR_TIM1_REMAP0, AFIO_2BIT_MASK);
	#elif(TIM1_REMAPPING == AFIO_PARTIAL_REMAP)
		CLR_BITS((Local_u32Mapr), MAPR_TIM1_REMAP0, AFIO_2BIT_MASK);
		SET_BITS((Local_u32Mapr), MAPR_TIM1_REMAP0, AFIO_TIM1_PARTIAL_VAL);
	#elif(TIM1_REMAPPING == AFIO_FULL_REMAP)
		CLR_BITS((Local_u32Mapr), MAPR_TIM1_REMAP0, AFIO_2BIT_MASK);
		SET_BITS((Local_u32Mapr), MAPR_TIM1_REMAP0, AFIO_TIM1_FULL_VAL);
	#else
		#error "Invalid AFIO MAP config"
	#endif


	#if(TIM2_REMAPPING == AFIO_DEFAULT)
		CLR_BITS((Local_u32Mapr), MAPR_TIM2_REMAP0, AFIO_2BIT_MASK);
	#elif(TIM2_REMAPPING == AFIO_PARTIAL_REMAP)
		CLR_BITS((Local_u32Mapr), MAPR_TIM2_REMAP0, AFIO_2BIT_MASK);
		SET_BITS((Local_u32Mapr), MAPR_TIM2_REMAP0, AFIO_TIM2_PARTIAL_VAL);
	#elif(TIM2_REMAPPING == AFIO_FULL_REMAP)
		CLR_BITS((Local_u32Mapr), MAPR_TIM2_REMAP0, AFIO_2BIT_MASK);
		SET_BITS((Local_u32Mapr), MAPR_TIM2_REMAP0, AFIO_TIM2_FULL_VAL);
	#else
		#error "Invalid AFIO MAP config"
	#endif


	#if(TIM3_REMAPPING == AFIO_DEFAULT)
		CLR_BITS((Local_u32Mapr), MAPR_TIM3_REMAP0, AFIO_2BIT_MASK);
	#elif(TIM3_REMAPPING == AFIO_PARTIAL_REMAP)
		CLR_BITS((Local_u32Mapr), MAPR_TIM3_REMAP0, AFIO_2BIT_MASK);
		SET_BITS((Local_u32Mapr), MAPR_TIM3_REMAP0, AFIO_TIM3_PARTIAL_VAL);
	#elif(TIM3_REMAPPING == AFIO_FULL_REMAP)
		CLR_BITS((Local_u32Mapr), MAPR_TIM3_REMAP0, AFIO_2BIT_MASK);
		SET_BITS((Local_u32Mapr), MAPR_TIM3_REMAP0, AFIO_TIM3_FULL_VAL);
	#else
		#error "Invalid AFIO MAP config"
	#endif



	#if(TIM4_REMAPPING == AFIO_REMAPPED)
		SET_BIT((Local_u32Mapr), MAPR_TIM4_REMAP);
	#elif(TIM4_REMAPPING == AFIO_DEFAULT)
		CLR_BIT((Local_u32Mapr), MAPR_TIM4_REMAP);
	#else
		#error "Invalid AFIO MAP config"
	#endif


	#if(CAN_REMAPPING == AFIO_DEFAULT)
		CLR_BITS((Local_u32Mapr), MAPR_CAN_REMAP0, AFIO_2BIT_MASK);
	#elif(CAN_REMAPPING == AFIO_PARTIAL_REMAP)
		CLR_BITS((Local_u32Mapr), MAPR_CAN_REMAP0, AFIO_2BIT_MASK);
		SET_BITS((Local_u32Mapr), MAPR_CAN_REMAP0, AFIO_CAN_PARTIAL_VAL);
	#elif(CAN_REMAPPING == AFIO_FULL_REMAP)
		CLR_BITS((Local_u32Mapr), MAPR_CAN_REMAP0, AFIO_2BIT_MASK);
		SET_BITS((Local_u32Mapr), MAPR_CAN_REMAP0, AFIO_CAN_FULL_VAL);
	#else
		#error "Invalid AFIO MAP config"
	#endif


	#if(PD01_REMAPPING == AFIO_REMAPPED)
		SET_BIT((Local_u32Mapr), MAPR_PD01_REMAP);
	#elif(PD01_REMAPPING == AFIO_DEFAULT)
		CLR_BIT((Local_u32Mapr), MAPR_PD01_REMAP);
	#else
		#error "Invalid AFIO MAP config"
	#endif


	#if(TIM5CH4_IR_REMAPPING == AFIO_REMAPPED)
		SET_BIT((Local_u32Mapr), MAPR_TIM5CH4_IR_REMAP);
	#elif(TIM5CH4_IR_REMAPPING == AFIO_DEFAULT)
		CLR_BIT((Local_u32Mapr), MAPR_TIM5CH4_IR_REMAP);
	#else
		#error "Invalid AFIO MAP config"
	#endif


	#if(ADC1_ETRGINJ_REMAPPING == AFIO_REMAPPED)
		SET_BIT((Local_u32Mapr), MAPR_ADC1_ETRGINJ_REMAP);
	#elif(ADC1_ETRGINJ_REMAPPING == AFIO_DEFAULT)
		CLR_BIT((Local_u32Mapr), MAPR_ADC1_ETRGINJ_REMAP);
	#else
		#error "Invalid AFIO MAP config"
	#endif


	#if(ADC1_ETRGREG_REMAPPING == AFIO_REMAPPED)
		SET_BIT((Local_u32Mapr), MAPR_ADC1_ETRGREG_REMAP);
	#elif(ADC1_ETRGREG_REMAPPING == AFIO_DEFAULT)
		CLR_BIT((Local_u32Mapr), MAPR_ADC1_ETRGREG_REMAP);
	#else
		#error "Invalid AFIO MAP config"
	#endif


	#if(ADC2_ETRGINJ_REMAPPING == AFIO_REMAPPED)
		SET_BIT((Local_u32Mapr), MAPR_ADC2_ETRGINJ_REMAP);
	#elif(ADC2_ETRGINJ_REMAPPING == AFIO_DEFAULT)
		CLR_BIT((Local_u32Mapr), MAPR_ADC2_ETRGINJ_REMAP);
	#else
		#error "Invalid AFIO MAP config"
	#endif


	#if(ADC2_ETRGREG_REMAPPING == AFIO_REMAPPED)
		SET_BIT((Local_u32Mapr), MAPR_ADC2_ETRGREG_REMAP);
	#elif(ADC2_ETRGREG_REMAPPING == AFIO_DEFAULT)
		CLR_BIT((Local_u32Mapr), MAPR_ADC2_ETRGREG_REMAP);
	#else
		#error "Invalid AFIO MAP config"
	#endif

	AFIO->MAPR = Local_u32Mapr;

}




/**
* 	Description:                This Function is used to set the SWJ mode
* 	Parameters:                 - AFIO_SWJ_t Copy_eSWJmode
* 	Returns:                    - void
* 	Preconditions:              - The RCC driver is initialized and working
* 								- The clk is enabled of the AFIO peripheral
* 	Side effects:               The mode is kept and put back on every AFIO_vInit
* 	Post Conditions:            SWJ mode is configed
* 	Sync/Async:               	Sync.
*/
void AFIO_vSetSWJMode(AFIO_SWJ_t Copy_eSWJmode)
{
	uint32_t Local_u32Mapr = AFIO->MAPR;

	AFIO_eSWJModeShadow = Copy_eSWJmode;

	CLR_BITS((Local_u32Mapr), MAPR_SWJ_CFG0, AFIO_3BIT_MASK);
	SET_BITS((Local_u32Mapr), MAPR_SWJ_CFG0, AFIO_eSWJModeShadow);
	/*one write: no 000 (full JTAG) step in between*/
	AFIO->MAPR = Local_u32Mapr;
}




/**
* 	Description:                This Function is used to set the EXTI pin and port
* 	Parameters:                 - AFIO_Pin_t Copy_eEXTInum
* 								- AFIO_Port_t Copy_ePort
* 	Returns:                    - AFIO_ErrorStates_t Local_eErrorState
* 	Preconditions:              - The RCC driver is initialized and working
* 								- The clk is enabled of the AFIO peripheral
* 	Side effects:               No side effects
* 	Post Conditions:            EXTI port and pin configs applied
* 	Sync/Async:               	Sync.
*/
AFIO_ErrorStates_t AFIO_eSetEXTIPort(AFIO_Pin_t Copy_eEXTInum, AFIO_Port_t Copy_ePort)
{
	AFIO_ErrorStates_t Local_eErrorState = AFIO_Exit_Ok;

	if((Copy_eEXTInum >= AFIO_Pin0) && (Copy_eEXTInum <= AFIO_Pin15))
	{
		if((Copy_ePort >= AFIO_PortA) && (Copy_ePort <= AFIO_PortD))
		{

			(AFIO->EXTI[Copy_eEXTInum/AFIO_EXTI_REGS_SHIFTING]) &= ~(AFIO_4BIT_MASK << (AFIO_EXTI_REGS_SHIFTING * (Copy_eEXTInum % AFIO_EXTI_REGS_SHIFTING)));
			(AFIO->EXTI[Copy_eEXTInum/AFIO_EXTI_REGS_SHIFTING]) |=  (Copy_ePort << (AFIO_EXTI_REGS_SHIFTING * (Copy_eEXTInum % AFIO_EXTI_REGS_SHIFTING)));

		}

		else
		{
			Local_eErrorState = AFIO_Invalid_Port;
		}

	}

	else
	{
		Local_eErrorState = AFIO_Invalid_EXTI;
	}

	return Local_eErrorState;
}




/**
* 	Description:                This Function is used to set the EVO pin, port and state
* 	Parameters:                 - AFIO_Pin_t Copy_eEXTInum
* 								- AFIO_Port_t Copy_ePort
* 	Returns:                    - AFIO_ErrorStates_t Local_eErrorState
* 	Preconditions:              - The RCC driver is initialized and working
* 								- The clk is enabled of the AFIO peripheral
* 	Side effects:               No side effects
* 	Post Conditions:            EXTI port and pin configs applied
* 	Sync/Async:               	Sync.
*/
AFIO_ErrorStates_t AFIO_eConfigEventOutput(AFIO_Port_t Copy_ePort, AFIO_Pin_t Copy_ePin, AFIO_EventOutput_t Copy_eState)
{
	AFIO_ErrorStates_t Local_eErrorState = AFIO_Exit_Ok;

	if((Copy_ePort >= AFIO_PortA) && (Copy_ePort <= AFIO_PortD))
	{
		if((Copy_ePin >= AFIO_Pin0) && (Copy_ePin <= AFIO_Pin15))
		{
			switch(Copy_eState)
			{
				case AFIO_EventOutput_Disable:
				{
					CLR_BIT((AFIO->EVCR), EVCR_EVOE);
					break;
				}

				case AFIO_EventOutput_Enable:
				{
					CLR_BITS((AFIO->EVCR), EVCR_PIN0, AFIO_4BIT_MASK);
					SET_BITS((AFIO->EVCR), EVCR_PIN0, Copy_ePin);

					CLR_BITS((AFIO->EVCR), EVCR_PORT0, AFIO_4BIT_MASK);
					SET_BITS((AFIO->EVCR), EVCR_PORT0, Copy_ePort);

					SET_BIT((AFIO->EVCR), EVCR_EVOE);

					break;
				}
			}

		}

		else
		{
			Local_eErrorState = AFIO_Invalid_Pin;
		}

	}

	else
	{
		Local_eErrorState = AFIO_Invalid_Port;
	}

	return Local_eErrorState;
}



