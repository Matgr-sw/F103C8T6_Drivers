/***************************************************************************************************
 * @file:           PWR_prv.h
 * @brief:			This file contains the private definitions of the PWR driver
 * @author:         Ibrahim Saber
 * @version:        1.0
 * @date:           19-11-2026
 * Last Update:     01:59 PM, Thursday, November 19, 2026
 ****************************************************************************************************/
#ifndef PWR_PRV_H
#define PWR_PRV_H


								/*********************** prv MACROS  ***********************/




								/*********************** MASKS  ***********************/
#define CR_PLS_MASK		0b111u



								/*********************** Bits  ***********************/
#define CR_LPDS		0u
#define CR_PDDS		1u
#define CR_CWUF		2u
#define CR_CSBF		3u
#define CR_PVDE		4u
#define CR_PLS0		5u
#define CR_DBP		8u


#define CSR_WUF		0u
#define CSR_SBF		1u
#define CSR_PVDO	2u
#define CSR_EWUP	8u


















#endif
