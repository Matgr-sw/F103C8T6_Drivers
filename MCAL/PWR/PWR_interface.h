/***************************************************************************************************
 * @file:           PWR_interface.h
 * @brief:			This file contains the interfaces and function prototypes of the PWR driver
 * @author:         Ibrahim Saber
 * @version:        1.0
 * @date:           19-11-2026
 * Last Update:     03:29 PM, Thursday, November 19, 2026
 ****************************************************************************************************/
#ifndef PWR_INTERFACE_H
#define PWR_INTERFACE_H

								/***********************  Enums  ***********************/
typedef enum
{
	PWR_Exit_OK,
	PWR_NULL_Ptr_Err,

}PWR_ErrorState_t;


typedef enum
{
	PWR_BDCR_Access_Disabled,
	PWR_BDCR_Access_Enabled,

}PWR_BDCR_Access_t;




/*********************** Functions  ***********************/

/**
 * 	Description:                This Function is used to adjust the access type of the backup domain register in the RCC registers
 * 	Parameters:                 PWR_BDCR_Access_t Copy_eState
 * 	Returns:                    - void
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The RCC driver is initialized
 * 	Sync/Async:               	Sync.
 */
void PWR_eBDCRsetAccess(PWR_BDCR_Access_t Copy_eState);






#endif
