/***************************************************************************************************
 * @file:           RCC_interface.h
 * @brief:			This file contains the interfaces and function prototypes of the RCC driver
 * @author:         Ibrahim Saber
 * @version:        1.0
 * @date:           16-11-2026
 * Last Update:     01:39 PM, Monday, November 16, 2026
 ****************************************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*The configuration of each PLL (selection of clock source, predivision factor and
multiplication factor) must be done before enabling the PLL*/

/*When changing the entry clock source of the main PLL, the original clock source must be
switched off only after the selection of the new clock source (done through bit PLLSRC in
the Clock configuration register (RCC_CFGR)).*/



								/*********************** Enums  ***********************/
typedef enum
{
	RCC_Exit_OK,
	RCC_NULL_Ptr_Err,
	RCC_Invalid_Config,

}RCC_ErrorState_t;



								/*********************** Config struct  ***********************/
typedef struct
{

}RCC_Configs_t;


								/*********************** Functions  ***********************/

/**
 * 	Description:                This Function is used to initialize the RCC peripheral
 * 	Parameters:                 RCC_Configs_t * Copy_pConfigs
 * 	Returns:                    - RCC_ErrorState_t Local_eErrorState The return state of the function
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The RCC driver is initialized
 * 	Sync/Async:               	Sync.
 */
RCC_ErrorState_t RCC_eInit(RCC_Configs_t * Copy_pConfigs);












#endif
