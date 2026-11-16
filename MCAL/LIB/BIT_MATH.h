/***************************************************************************************************
 * @file:           BIT_MATH.h
 * @brief:			This file contains the function-like macros encapsulating the BIT math
 * @author:         Ibrahim Saber
 * @version:        1.0
 * @date:           16-11-2026
 * Last Update:     01:57 PM, Monday, November 16, 2026
 ****************************************************************************************************/
#ifndef RCC_BIT_MATH_H
#define RCC_BIT_MATH_H


#define		SET_BIT(REG, BIT)	((REG) |= (1U << BIT))
#define 	CLR_BIT(REG, BIT)	((REG) &= ~(1U << BIT))
#define		TOG_BIT(REG, BIT)	((REG) ^= (1U << BIT))
#define 	GET_BIT(REG, BIT)	((1U) & (REG >> BIT))











#endif
