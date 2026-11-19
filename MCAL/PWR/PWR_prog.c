/***************************************************************************************************
 * @file:           PWR_prog.c
 * @brief:			This file contains the implementation of the PWR driver functions
 * @author:         Ibrahim Saber
 * @version:        1.0
 * @date:           19-11-2026
 * Last Update:     02:17 PM, Thursday, November 19, 2026
 ****************************************************************************************************/
#include <stdint.h>
#include <stddef.h>

#include "BIT_MATH.h"
#include "MCAL_baseAddress.h"

#include "PWR_prv.h"
#include "PWR_interface.h"





/**
 * 	Description:                This Function is used to adjust the access type of the backup domain register in the RCC registers
 * 	Parameters:                 PWR_BDCR_Access_t Copy_eState
 * 	Returns:                    - void
 * 	Preconditions:              - None
 * 	Side effects:               No side effects
 * 	Post Conditions:            The RCC driver is initialized
 * 	Sync/Async:               	Sync.
 */
 void PWR_eBDCRsetAccess(PWR_BDCR_Access_t Copy_eState)
 {
	 CLR_BIT((PWR->CR), CR_DBP);
	 SET_BITS((PWR->CR), CR_DBP, Copy_eState);
 }
