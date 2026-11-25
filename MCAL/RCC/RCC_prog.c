/***************************************************************************************************
 * @file:           RCC_prog.c
 * @brief:			This file contains the implementation of the RCC driver functions
 * @author:         Ibrahim Saber
 * @version:        1.0
 * @date:           17-11-2026
 * Last Update:     4:40 PM, Wednesday, November 25, 2026
 ****************************************************************************************************/
#include <stdint.h>
#include <stddef.h>

#include "BIT_MATH.h"
#include "MCAL_baseAddress.h"

#include "RCC_prv.h"
#include "RCC_cfg.h"
#include "RCC_interface.h"

#include "PWR_interface.h"







/**
 * 	Description:                This Function is used to initialize the RCC peripheral at one pass
 * 	Parameters:                 RCC_Configs_t * Copy_pConfigs
 * 	Returns:                    - RCC_ErrorState_t Local_eErrorState The return state of the function
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The RCC driver is initialized
 * 	Sync/Async:               	Sync.
 */
RCC_ErrorState_t RCC_eInit(RCC_Configs_t * Copy_pConfigs)
{
	RCC_ErrorState_t Local_eErrorState = RCC_Exit_OK;

	if(Copy_pConfigs != NULL)
	{

		/*Config PLL*/

		/*must be off before PLL is configed*/
		RCC_eSetClckState(RCC_PLL, RCC_Clk_OFF);
		/*XTPRE config*/
		if((Copy_pConfigs->PllXTPRE))
		{
			SET_BIT((RCC->CFGR), CFGR_PLL_XTPRE);
		}
		else
		{
			CLR_BIT((RCC->CFGR), CFGR_PLL_XTPRE);
		}
		/*PLL Clk Src config*/
		if((Copy_pConfigs->PllClkSrc))
		{
			SET_BIT((RCC->CFGR), CFGR_PLL_SRC);
		}
		else
		{
			CLR_BIT((RCC->CFGR), CFGR_PLL_SRC);
		}
		/*PLL multiplier*/
		CLR_BITS((RCC->CFGR), CFGR_PLLMUL0, CFGR_PLLMUL_MASK);
		SET_BITS((RCC->CFGR), CFGR_PLLMUL0, (Copy_pConfigs->PllMul));



		/*config the prescalers*/

		/*AHB Presc*/
		CLR_BITS((RCC->CFGR), CFGR_HPRE0, CFGR_HPRE_MASK);
		SET_BITS((RCC->CFGR), CFGR_HPRE0, (Copy_pConfigs->AHBpresc));
		/*APB1 Presc*/
		CLR_BITS((RCC->CFGR), CFGR_PPRE10, CFGR_PPRE1_MASK);
		SET_BITS((RCC->CFGR), CFGR_PPRE10, (Copy_pConfigs->APB1presc));
		/*APB2 Presc*/
		CLR_BITS((RCC->CFGR), CFGR_PPRE20, CFGR_PPRE2_MASK);
		SET_BITS((RCC->CFGR), CFGR_PPRE20, (Copy_pConfigs-> APB2presc));
		/*ADC Presc*/
		CLR_BITS((RCC->CFGR), CFGR_ADC_PRE0, CFGR_ADC_PRE_MASK);
		SET_BITS((RCC->CFGR), CFGR_ADC_PRE0, (Copy_pConfigs-> ADCpresc));
		/*USB Presc*/
		CLR_BIT((RCC->CFGR), CFGR_OTGSPRE);
		SET_BITS((RCC->CFGR), CFGR_OTGSPRE, (Copy_pConfigs-> USBpresc));
		/*RTC Clk src*/
		CLR_BITS((RCC->BDCR), BDCR_RTCSEL0, BDCR_RTCSEL_MASK);
		SET_BITS((RCC->BDCR), BDCR_RTCSEL0, (Copy_pConfigs->RTCclkSrc));

		/*RCC CCS config*/
		CLR_BIT((RCC->CR), CR_CSSON);
		SET_BITS((RCC->CR), CR_CSSON, (Copy_pConfigs->ClkSecurity));

		/*MCO select*/
		CLR_BITS((RCC->CFGR), CFGR_MCO0, CFGR_MCO_MASK);
		SET_BITS((RCC->CFGR), CFGR_MCO0, (Copy_pConfigs->MCOselect));


		/*Setting up clk states*/
		RCC_eSetClckState(RCC_HSI, (Copy_pConfigs->HSIstate));
		RCC_eSetClckState(RCC_HSE, (Copy_pConfigs->HSEstate));
		RCC_eSetClckState(RCC_PLL, (Copy_pConfigs->PLLstate));
		RCC_eSetClckState(RCC_LSI, (Copy_pConfigs->LSIstate));
		RCC_eSetClckState(RCC_LSE, (Copy_pConfigs->LSEstate));
		RCC_eSetClckState(RCC_RTC, (Copy_pConfigs->RTCstate));

		/*Setting up sys clk*/
		RCC_eSetSysClck((Copy_pConfigs->SysClkSrc));

	}

	else
	{
		Local_eErrorState = RCC_NULL_Ptr_Err;
	}


	return Local_eErrorState;

}




/**
 * 	Description:                This Function is used to set the switched state of each clk type
 * 	Parameters:                 - RCC_SysClk_t Copy_eClk
 * 								- RCC_ClkState_t Copy_eClkState
 * 	Returns:                    - RCC_ErrorState_t Local_eErrorState The return state of the function
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The clk state is setted and ensured by waiting on its flag
 * 	Sync/Async:               	Sync.
 */
RCC_ErrorState_t RCC_eSetClckState(RCC_SysClk_t Copy_eClk, RCC_ClkState_t Copy_eClkState)
{

	RCC_ErrorState_t Local_eErrorState = RCC_Exit_OK;
	uint16_t Local_u16TimeOutCounter = 0;

		switch(Copy_eClkState)
		{
			case RCC_Clk_OFF:
			{
				if(((GET_BITS((RCC->CFGR), CFGR_SW0, CFGR_SW_MASK)) != Copy_eClk) && ((GET_BITS((RCC->CFGR), CFGR_SWS0, CFGR_SWS_MASK)) != Copy_eClk))
				{
					switch(Copy_eClk)
					{
						/*making sure you don't shut a selected or running clk*/
						case RCC_HSI:
						{
							CLR_BIT((RCC->CR), CR_HSION);
							break;
						}

						case RCC_HSE:
						{
							CLR_BIT((RCC->CR), CR_HSEON);
							break;
						}

						case RCC_PLL:
						{
							/*USB must be cleared before PLLON is disabled*/
							CLR_BIT((RCC->AHBENR), AHBENR_OTGFS_EN);
							CLR_BIT((RCC->CR), CR_PLLON);
							break;
						}

						case RCC_LSE:
						{
							CLR_BIT((RCC->BDCR), BDCR_LSE_ON);
							break;

						}

						case RCC_LSI:
						{
							CLR_BIT((RCC->CSR), CSR_LSI_ON);
							break;
						}

						case RCC_RTC:
						{
							CLR_BIT((RCC->BDCR), BDCR_RTC_EN);
							break;
						}

						default: Local_eErrorState = RCC_Invalid_ClkType; break;

						}

			}


			else
			{
				Local_eErrorState = RCC_Shut_SelectedClk;
			}

				break;

		}


			case RCC_Clk_ON:
			{
				switch(Copy_eClk)
				{
					case RCC_HSI:
					{
						SET_BIT((RCC->CR), CR_HSION);
						while (!(GET_BIT((RCC->CR), CR_HSIRDY)) && (Local_u16TimeOutCounter < RCC_RDY_FLAGS_TIMEOUT))
						{
							Local_u16TimeOutCounter++;
						}

						break;
					}

					case RCC_HSE:
					{
						SET_BIT((RCC->CR), CR_HSEON);
						while (!(GET_BIT((RCC->CR), CR_HSERDY)) && (Local_u16TimeOutCounter < RCC_RDY_FLAGS_TIMEOUT))
						{
							Local_u16TimeOutCounter++;
						}

						break;
					}

					case RCC_PLL:
					{
						SET_BIT((RCC->CR), CR_PLLON);
						while (!(GET_BIT((RCC->CR), CR_PLLRDY)) && (Local_u16TimeOutCounter < RCC_RDY_FLAGS_TIMEOUT))
						{
							Local_u16TimeOutCounter++;
						}

						break;
					}

					case RCC_LSE:
					{

						SET_BIT((RCC->APB1ENR), APB1ENR_PWR_EN);
						PWR_eBDCRsetAccess(PWR_BDCR_Access_Enabled);

						SET_BIT((RCC->BDCR), BDCR_LSE_ON);
						while (!(GET_BIT((RCC->BDCR), BDCR_LSE_RDY)) && (Local_u16TimeOutCounter < RCC_RDY_FLAGS_TIMEOUT))
						{
							Local_u16TimeOutCounter++;
						}

						PWR_eBDCRsetAccess(PWR_BDCR_Access_Disabled);


						break;
					}

					case RCC_LSI:
					{
						SET_BIT((RCC->CSR), CSR_LSI_ON);
						while (!(GET_BIT((RCC->CSR), CSR_LSI_RDY)) && (Local_u16TimeOutCounter < RCC_RDY_FLAGS_TIMEOUT))
						{
							Local_u16TimeOutCounter++;
						}

						break;
					}

					case RCC_RTC:
					{
						SET_BIT((RCC->APB1ENR), APB1ENR_PWR_EN);
						PWR_eBDCRsetAccess(PWR_BDCR_Access_Enabled);
						SET_BIT((RCC->BDCR), BDCR_RTC_EN);
						PWR_eBDCRsetAccess(PWR_BDCR_Access_Disabled);

						break;

					}

					default: Local_eErrorState = RCC_Invalid_ClkType;break;

				}


				break;

			}

			default: Local_eErrorState = RCC_Invalid_ClkState; break;

		}



	if(Local_u16TimeOutCounter >= RCC_RDY_FLAGS_TIMEOUT)
	{
		Local_eErrorState = RCC_Timeout;
	}


	return Local_eErrorState;
}



/**
 * 	Description:                This Function is used to calc the sysclk freq of the selected clk src
 * 	Parameters:                 - RCC_SysClk_t Copy_eSysClk
 * 	Returns:                    - uint32_t Local_u32Freq The sysclk freq in Hz
 * 	Preconditions:              - PLL cfg is already written in CFGR
 * 	Side effects:               No side effects
 * 	Post Conditions:            None
 * 	Sync/Async:               	Sync.
 */
static uint32_t RCC_u32GetSysClkFreq(RCC_SysClk_t Copy_eSysClk)
{
	uint32_t Local_u32Freq = RCC_HSI_FREQ_HZ;
	uint32_t Local_u32PllMul;

	if(Copy_eSysClk == RCC_HSE)
	{
		Local_u32Freq = RCC_HSE_FREQ_HZ;
	}

	else if(Copy_eSysClk == RCC_PLL)
	{
		/*PLL input*/
		if(GET_BIT((RCC->CFGR), CFGR_PLL_SRC) == RCC_HSE_PllXTPRE)
		{
			Local_u32Freq = RCC_HSE_FREQ_HZ;
			if(GET_BIT((RCC->CFGR), CFGR_PLL_XTPRE) == RCC_PlLXTPRE_HSE_DIV_2)
			{
				Local_u32Freq /= RCC_PLL_XTPRE_DIV;
			}
		}

		else
		{
			Local_u32Freq = (RCC_HSI_FREQ_HZ / RCC_PLL_HSI_DIV);
		}

		/*PLL multiplier = field + 2, field 1111 is x16 clampped by HW from x17*/
		Local_u32PllMul = (GET_BITS((RCC->CFGR), CFGR_PLLMUL0, CFGR_PLLMUL_MASK) + RCC_PLLMUL_OFFSET);
		if(Local_u32PllMul > RCC_PLLMUL_MAX)
		{
			Local_u32PllMul = RCC_PLLMUL_MAX;
		}
		Local_u32Freq *= Local_u32PllMul;
	}

	return Local_u32Freq;
}



/**
 * 	Description:                This Function is used to get the flash latency needed for a sysclk freq
 * 	Parameters:                 - uint32_t Copy_u32Freq
 * 	Returns:                    - uint32_t Local_u32Latency The flash latency
 * 	Preconditions:              - Copy_u32Freq is not above RCC_SYSCLK_MAX_HZ
 * 	Side effects:               No side effects
 * 	Post Conditions:            None
 * 	Sync/Async:               	Sync.
 */
static uint32_t RCC_u32GetFlashLatency(uint32_t Copy_u32Freq)
{
	uint32_t Local_u32Latency = FLASH_LATENCY_0WS;

	if(Copy_u32Freq > RCC_FLASH_1WS_MAX_HZ)
	{
		Local_u32Latency = FLASH_LATENCY_2WS;
	}

	else if(Copy_u32Freq > RCC_FLASH_0WS_MAX_HZ)
	{
		Local_u32Latency = FLASH_LATENCY_1WS;
	}

	return Local_u32Latency;
}



/**
 * 	Description:                This Function is used to select which clk type is the sysclk
 * 	Parameters:                 RCC_SysClk_t Copy_eSysClk
 * 	Returns:                    - RCC_ErrorState_t Local_eErrorState The return state of the function
 * 								  (RCC_Invalid_Config if the sysclk is above 72 MHz, RCC_Timeout if SWS is not set)
 * 	Preconditions:              - The selected clk must be on and stable
 * 	Side effects:               Flash latency is changed to match the sysclk
 * 	Post Conditions:            The sysclk is switched, ensured by waiting on SWS, and the flash latency matches it
 * 	Sync/Async:               	Sync.
 */
RCC_ErrorState_t RCC_eSetSysClck(RCC_SysClk_t Copy_eSysClk)
{
	RCC_ErrorState_t Local_eErrorState = RCC_Exit_OK;
	uint32_t Local_u32Freq;
	uint32_t Local_u32NewLatency;
	uint32_t Local_u32OldLatency;
	uint16_t Local_u16TimeOutCounter = 0;


	if((Copy_eSysClk >=  RCC_HSI) && (Copy_eSysClk <= RCC_PLL))
	{
		Local_u32Freq = RCC_u32GetSysClkFreq(Copy_eSysClk);

		/*max sysclk 72 MHz*/
		if(Local_u32Freq <= RCC_SYSCLK_MAX_HZ)
		{
			Local_u32NewLatency = RCC_u32GetFlashLatency(Local_u32Freq);
			Local_u32OldLatency = GET_BITS((FLASH->ACR), ACR_LATENCY0, ACR_LATENCY_MASK);

			/*must be raised before switching to a faster clk*/
			if(Local_u32NewLatency > Local_u32OldLatency)
			{
				CLR_BITS((FLASH->ACR), ACR_LATENCY0, ACR_LATENCY_MASK);
				SET_BITS((FLASH->ACR), ACR_LATENCY0, Local_u32NewLatency);
			}

			/*Setting up sys clk*/
			CLR_BITS((RCC -> CFGR), CFGR_SW0, CFGR_SW_MASK);
			SET_BITS((RCC -> CFGR), CFGR_SW0, (Copy_eSysClk));

			/*waiting on SWS*/
			while((GET_BITS((RCC -> CFGR), CFGR_SWS0, CFGR_SWS_MASK) != (uint32_t)Copy_eSysClk) &&
				  (Local_u16TimeOutCounter < RCC_RDY_FLAGS_TIMEOUT))
			{
				Local_u16TimeOutCounter++;
			}

			if(Local_u16TimeOutCounter >= RCC_RDY_FLAGS_TIMEOUT)
			{
				/*switch not done, higher latency kept*/
				Local_eErrorState = RCC_Timeout;
			}

			/*must be lowered only after the switch is done*/
			else if(Local_u32NewLatency < Local_u32OldLatency)
			{
				CLR_BITS((FLASH->ACR), ACR_LATENCY0, ACR_LATENCY_MASK);
				SET_BITS((FLASH->ACR), ACR_LATENCY0, Local_u32NewLatency);
			}
		}

		else
		{
			Local_eErrorState = RCC_Invalid_Config;
		}
	}

	else
	{
		Local_eErrorState = RCC_Invalid_ClkType;
	}

	return Local_eErrorState;
}



/**
 * 	Description:                This Function is used to read the existing sysclk
 * 	Parameters:                 RCC_SysClk_t* Copy_eSysClk
 * 	Returns:                    - RCC_ErrorState_t Local_eErrorState The return state of the function
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The current sysclk is stored in the param
 * 	Sync/Async:               	Sync.
 */
RCC_ErrorState_t RCC_eGetSysClck(RCC_SysClk_t* Copy_eSysClk)
{
	RCC_ErrorState_t Local_eErrorState = RCC_Exit_OK;

	if(Copy_eSysClk != NULL)
	{
		*Copy_eSysClk = (RCC_SysClk_t) (GET_BITS((RCC -> CFGR), CFGR_SWS0, CFGR_SWS_MASK));
	}

	else
	{
		Local_eErrorState = RCC_NULL_Ptr_Err;
	}

	return Local_eErrorState;
}


/**
 * 	Description:                This Function is used to enable the clk of an AHB periph
 * 	Parameters:                 RCC_AHBperiphs_t Copy_eAHBperiph
 * 	Returns:                    - void
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The selected perihp clk is enabled
 * 	Sync/Async:               	Sync.
 */
void RCC_eAHBperiphEnable(RCC_AHBperiphs_t Copy_eAHBperiph)
{
	SET_BIT((RCC->AHBENR), Copy_eAHBperiph);
}





/**
 * 	Description:                This Function is used to disable the clk of an AHB periph
 * 	Parameters:                 RCC_AHBperiphs_t Copy_eAHBperiph
 * 	Returns:                    - void
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The selected perihp clk is disabled
 * 	Sync/Async:               	Sync.
 */
void RCC_eAHBperiphDisable(RCC_AHBperiphs_t Copy_eAHBperiph)
{
	CLR_BIT((RCC->AHBENR), Copy_eAHBperiph);
}


/**
 * 	Description:                This Function is used to enable the clk of an APB1 periph
 * 	Parameters:                 RCC_APB1periphs_t Copy_eAPB1periph
 * 	Returns:                    - void
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The selected perihp clk is enabled
 * 	Sync/Async:               	Sync.
 */
void RCC_eAPB1periphEnable(RCC_APB1periphs_t Copy_eAPB1periph)
{
	SET_BIT((RCC->APB1ENR), Copy_eAPB1periph);

}




/**
 * 	Description:                This Function is used to disable the clk of an APB1 periph
 * 	Parameters:                 RCC_APB1periphs_t Copy_eAHBperiph
 * 	Returns:                    - void
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The selected perihp clk is disabled
 * 	Sync/Async:               	Sync.
 */
void RCC_eAPB1periphDisable(RCC_APB1periphs_t Copy_eAPB1periph)
{
	CLR_BIT((RCC->APB1ENR), Copy_eAPB1periph);
}







/**
 * 	Description:                This Function is used to enable the clk of an APB2 periph
 * 	Parameters:                 RCC_APB2periphs_t Copy_eAPB2periph
 * 	Returns:                    - void
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The selected perihp clk is enabled
 * 	Sync/Async:               	Sync.
 */
void RCC_eAPB2periphEnable(RCC_APB2periphs_t Copy_eAPB2periph)
{
	SET_BIT((RCC->APB2ENR), Copy_eAPB2periph);
}




/**
 * 	Description:                This Function is used to disable the clk of an APB2 periph
 * 	Parameters:                 RCC_APB2periphs_t Copy_eAPB2periph
 * 	Returns:                    - void
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The selected periph clk is disabled
 * 	Sync/Async:               	Sync.
 */
void RCC_eAPB2periphDisable(RCC_APB2periphs_t Copy_eAPB2periph)
{
	CLR_BIT((RCC->APB2ENR), Copy_eAPB2periph);
}




