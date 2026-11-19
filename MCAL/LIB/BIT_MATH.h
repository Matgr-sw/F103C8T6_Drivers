/***************************************************************************************************
 * @file:           BIT_MATH.h
 * @brief:			This file contains the function-like macros encapsulating the BIT math
 * @author:         Ibrahim Saber
 * @version:        1.0
 * @date:           16-11-2026
 * Last Update:     11:05 AM, Thursday, November 19, 2026
 ****************************************************************************************************/
#ifndef RCC_BIT_MATH_H
#define RCC_BIT_MATH_H


#define		SET_BIT(REG, BIT)	((REG) |= (1U << BIT))
#define 	CLR_BIT(REG, BIT)	((REG) &= ~(1U << BIT))
#define		TOG_BIT(REG, BIT)	((REG) ^= (1U << BIT))
#define 	GET_BIT(REG, BIT)	((1U) & (REG >> BIT))

#define 	GET_BITS(REG, BIT, MASK)		((MASK) &  ((REG) >> (BIT)))
#define 	SET_BITS(REG, BIT, MASK)		((REG) |=  ((MASK) << (BIT)))
#define 	CLR_BITS(REG, BIT, MASK)		((REG) &= ~((MASK) << (BIT)))
#define 	TOG_BITS(REG, BIT, MASK)		((REG) ^=  ((MASK) << (BIT))











#endif
