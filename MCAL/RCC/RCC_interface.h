/***************************************************************************************************
 * @file:           RCC_interface.h
 * @brief:			This file contains the interfaces and function prototypes of the RCC driver
 * @author:         Ibrahim Saber
 * @version:        1.0
 * @date:           16-11-2026
 * Last Update:     4:55 PM, Wednesday, November 25, 2026
 ****************************************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


								/***********************  Enums  ***********************/
typedef enum
{
	RCC_Exit_OK,
	RCC_NULL_Ptr_Err,
	RCC_Invalid_Config,
	RCC_Invalid_ClkState,
	RCC_Invalid_ClkType,
	RCC_Shut_SelectedClk,
	RCC_Timeout,

}RCC_ErrorState_t;


typedef enum
{
	RCC_HSI,
	RCC_HSE,
	RCC_PLL,
	RCC_LSE,
	RCC_LSI,
	RCC_RTC,

}RCC_SysClk_t;


typedef enum
{
	RCC_Clk_OFF,
	RCC_Clk_ON,

}RCC_ClkState_t;


typedef enum
{
	RCC_SysClk_DIV_1,
	RCC_SysClk_DIV_2 = 8,
    RCC_SysClk_DIV_4,
    RCC_SysClk_DIV_8,
    RCC_SysClk_DIV_16,
    RCC_SysClk_DIV_64,
    RCC_SysClk_DIV_128,
    RCC_SysClk_DIV_256,
    RCC_SysClk_DIV_512,

}RCC_AHBpresc_t;


typedef enum
{

	RCC_Hclk_DIV_1,
	RCC_Hclk_DIV_2 = 4,
	RCC_Hclk_DIV_4,
	RCC_Hclk_DIV_8,
	RCC_Hclk_DIV_16,

}RCC_APBpresc_t;


typedef enum
{
	RCC_Pclk_DIV_2,
	RCC_Pclk_DIV_4,
	RCC_Pclk_DIV_6,
	RCC_Pclk_DIV_8,



}RCC_ADCpresc_t;


typedef enum
{
	RCC_HSI_DIV_2,
	RCC_HSE_PllXTPRE,

}RCC_PllClkSrc_t;


typedef enum
{
	RCC_PllXTPRE_HSE_DIV_1,
	RCC_PlLXTPRE_HSE_DIV_2,

}RCC_PllXTPRE_t;


typedef enum
{
	RCC_PllSrc_MUL_2 = 0,
	RCC_PllSrc_MUL_3,
	RCC_PllSrc_MUL_4,
	RCC_PllSrc_MUL_5,
	RCC_PllSrc_MUL_6,
	RCC_PllSrc_MUL_7,
	RCC_PllSrc_MUL_8,
	RCC_PllSrc_MUL_9,
	RCC_PllSrc_MUL_10,
	RCC_PllSrc_MUL_11,
	RCC_PllSrc_MUL_12,
	RCC_PllSrc_MUL_13,
	RCC_PllSrc_MUL_14,
	RCC_PllSrc_MUL_15,
	RCC_PllSrc_MUL_16,

}RCC_PllMul_t;



typedef enum
{
	RCC_PllVCO_DIV_3,
	RCC_PllVCO_DIV_2,

}RCC_OTGFSpresc_t;


typedef enum
{
	RCC_MCO_NO_Clk,
	RCC_MCO_SysClk = 4,
	RCC_MCO_HSI,
	RCC_MCO_HSE,
	RCC_MCO_PLL_DIV_2,
	RCC_MCO_PLL2,
	RCC_MCO_PLL3_DIV_2,
	RCC_MCO_XT1,
	RCC_MCO_PLL3,

}RCC_MCOselect_t;


typedef enum
{
	RCC_CSS_OFF,
	RCC_CSS_ON,

}RCC_ClkSecurSys_t;


typedef enum
{
	RCC_AHB_DMA1,
	RCC_AHB_DMA2,
	RCC_AHB_SRAM,
	RCC_AHB_FLITF = 4,
	RCC_AHB_CRC = 6,
	RCC_AHB_OTGFS = 12,
	RCC_AHB_ETHMAC = 14,
	RCC_AHB_ETHMAC_TX,
	RCC_AHB_ETHMAC_RX,

}RCC_AHBperiphs_t;



typedef enum
{
	RCC_APB2_AFIO,
	RCC_APB2_IOA = 2,
	RCC_APB2_IOB,
	RCC_APB2_IOC,
	RCC_APB2_IOD,
	RCC_APB2_IOE,
	RCC_APB2_ADC1 = 9,
	RCC_APB2_ADC2,
	RCC_APB2_TIM1,
	RCC_APB2_SPI1,
	RCC_APB2_USART1 = 14,

}RCC_APB2periphs_t;


typedef enum
{
	RCC_APB1_TIM2,
    RCC_APB1_TIM3,
    RCC_APB1_TIM4,
    RCC_APB1_TIM5,
    RCC_APB1_TIM6,
    RCC_APB1_TIM7,
    RCC_APB1_WWDG = 11,
    RCC_APB1_SPI2 = 14,
    RCC_APB1_SPI3,
    RCC_APB1_USART2 = 17,
    RCC_APB1_USART3,
    RCC_APB1_USART4,
	RCC_APB1_USART5,
	RCC_APB1_I2C1,
	RCC_APB1_I2C2,
	RCC_APB1_CAN1 = 25,
	RCC_APB1_CAN2,
	RCC_APB1_BKP,
	RCC_APB1_PWR,
	RCC_APB1_DAC,

}RCC_APB1periphs_t;


typedef enum
{
	RCC_RTC_NoClk,
	RCC_RTC_LSE,
	RCC_RTC_LSI,
	RCC_RTC_HSE_DIV_128,

}RCC_RTCclkSrc_t;




								/*********************** Config struct  ***********************/
typedef struct
{
	RCC_ClkState_t		HSIstate;
	RCC_ClkState_t		HSEstate;
	RCC_ClkState_t		PLLstate;
	RCC_ClkState_t		LSIstate;
	RCC_ClkState_t		LSEstate;
	RCC_ClkState_t		RTCstate;

	RCC_SysClk_t 		SysClkSrc;

	RCC_PllXTPRE_t		PllXTPRE;
	RCC_PllClkSrc_t		PllClkSrc;
	RCC_PllMul_t		PllMul;

	RCC_AHBpresc_t 		AHBpresc;
	RCC_APBpresc_t 		APB1presc;
	RCC_APBpresc_t 		APB2presc;
	RCC_ADCpresc_t 		ADCpresc;
	RCC_OTGFSpresc_t	USBpresc;

	RCC_RTCclkSrc_t		RTCclkSrc;

	RCC_ClkSecurSys_t	ClkSecurity;
	RCC_MCOselect_t		MCOselect;



}RCC_Configs_t;


								/*********************** Functions  ***********************/

/**
 * 	Description:                This Function is used to initialize the RCC peripheral at one pass
 * 	Parameters:                 RCC_Configs_t * Copy_pConfigs
 * 	Returns:                    - RCC_ErrorState_t Local_eErrorState The return state of the function
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The RCC driver is initialized
 * 	Sync/Async:               	Sync.
 */
RCC_ErrorState_t RCC_eInit(RCC_Configs_t * Copy_pConfigs);




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
RCC_ErrorState_t RCC_eSetClckState(RCC_SysClk_t Copy_eClk, RCC_ClkState_t Copy_eClkState);



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
RCC_ErrorState_t RCC_eSetSysClck(RCC_SysClk_t Copy_eSysClk);



/**
 * 	Description:                This Function is used to read the existing sysclk
 * 	Parameters:                 RCC_SysClk_t* Copy_eSysClk
 * 	Returns:                    - RCC_ErrorState_t Local_eErrorState The return state of the function
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The current sysclk is stored in the param
 * 	Sync/Async:               	Sync.
 */
RCC_ErrorState_t RCC_eGetSysClck(RCC_SysClk_t* Copy_eSysClk);


/**
 * 	Description:                This Function is used to enable the clk of an AHB periph
 * 	Parameters:                 RCC_AHBperiphs_t Copy_eAHBperiph
 * 	Returns:                    - void
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The selected perihp clk is enabled
 * 	Sync/Async:               	Sync.
 */
void RCC_eAHBperiphEnable(RCC_AHBperiphs_t Copy_eAHBperiph);




/**
 * 	Description:                This Function is used to disable the clk of an AHB periph
 * 	Parameters:                 RCC_AHBperiphs_t Copy_eAHBperiph
 * 	Returns:                    - void
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The selected perihp clk is disabled
 * 	Sync/Async:               	Sync.
 */
void RCC_eAHBperiphDisable(RCC_AHBperiphs_t Copy_eAHBperiph);


/**
 * 	Description:                This Function is used to enable the clk of an APB1 periph
 * 	Parameters:                 RCC_APB1periphs_t Copy_eAPB1periph
 * 	Returns:                    - void
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The selected perihp clk is enabled
 * 	Sync/Async:               	Sync.
 */
void RCC_eAPB1periphEnable(RCC_APB1periphs_t Copy_eAPB1periph);




/**
 * 	Description:                This Function is used to disable the clk of an APB1 periph
 * 	Parameters:                 RCC_APB1periphs_t Copy_eAHBperiph
 * 	Returns:                    - void
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The selected perihp clk is disabled
 * 	Sync/Async:               	Sync.
 */
void RCC_eAPB1periphDisable(RCC_APB1periphs_t Copy_eAPB1periph);







/**
 * 	Description:                This Function is used to enable the clk of an APB2 periph
 * 	Parameters:                 RCC_APB2periphs_t Copy_eAPB2periph
 * 	Returns:                    - void
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The selected perihp clk is enabled
 * 	Sync/Async:               	Sync.
 */
void RCC_eAPB2periphEnable(RCC_APB2periphs_t Copy_eAPB2periph);





/**
 * 	Description:                This Function is used to disable the clk of an APB2 periph
 * 	Parameters:                 RCC_APB2periphs_t Copy_eAPB2periph
 * 	Returns:                    - void
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The selected periph clk is disabled
 * 	Sync/Async:               	Sync.
 */
void RCC_eAPB2periphDisable(RCC_APB2periphs_t Copy_eAPB2periph);




#endif
