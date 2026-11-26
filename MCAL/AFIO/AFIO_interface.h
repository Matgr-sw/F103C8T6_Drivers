/***************************************************************************************************
 * @file:           AFIO_interface.h
 * @brief:			This file contains the interfaces and function prototypes of the AFIO driver
 * @author:         Ibrahim Saber
 * @version:        1.0
 * @date:           24-11-2026
 * Last Update:     10:00 AM, Thursday, November 26, 2026
 ****************************************************************************************************/
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

								/***********************  Enums  ***********************/
typedef enum
{
	AFIO_Exit_Ok,
	AFIO_Invalid_EventOutput_Config,
	AFIO_Invalid_Port,
	AFIO_Invalid_Pin,
	AFIO_Invalid_EXTI,

}AFIO_ErrorStates_t;;


typedef enum
{
	AFIO_EventOutput_Disable,
	AFIO_EventOutput_Enable,
}AFIO_EventOutput_t;


typedef enum
{
	AFIO_PortA,
	AFIO_PortB,
	AFIO_PortC,
	AFIO_PortD,

}AFIO_Port_t;


typedef enum
{
	AFIO_Pin0,
	AFIO_Pin1,
	AFIO_Pin2,
	AFIO_Pin3,
	AFIO_Pin4,
	AFIO_Pin5,
	AFIO_Pin6,
	AFIO_Pin7,
	AFIO_Pin8,
	AFIO_Pin9,
	AFIO_Pin10,
	AFIO_Pin11,
	AFIO_Pin12,
	AFIO_Pin13,
	AFIO_Pin14,
	AFIO_Pin15,

}AFIO_Pin_t;


typedef enum
{
	AFIO_Full_SWJ,
	AFIO_Full_SWJ_No_NJTRST,
	AFIO_JTAG_Disabled_SWDP_Enabled,
	AFIO_JTAG_Disabled_SWDP_Disabled = 4,
}AFIO_SWJ_t;



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
void AFIO_vInit(void);




/**
* 	Description:                This Function is used to set the SWJ mode
* 	Parameters:                 - AFIO_SWJ_t Copy_eSWJmode
* 	Returns:                    - void
* 	Preconditions:              - The RCC driver is initialized and working
* 								- The clk is enabled of the AFIO peripheral
* 	Side effects:               No side effects
* 	Post Conditions:            SWJ mode is configed
* 	Sync/Async:               	Sync.
*/
void AFIO_vSetSWJMode(AFIO_SWJ_t Copy_eSWJmode);




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
AFIO_ErrorStates_t AFIO_eSetEXTIPort(AFIO_Pin_t Copy_eEXTInum, AFIO_Port_t Copy_ePort);




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
AFIO_ErrorStates_t AFIO_eConfigEventOutput(AFIO_Port_t Copy_ePort, AFIO_Pin_t Copy_ePin, AFIO_EventOutput_t Copy_eState);







#endif
