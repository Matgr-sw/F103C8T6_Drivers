/***************************************************************************************************
 * @file:           AFIO_prv.h
 * @brief:			This file contains the private definitions of the AFIO driver
 * @author:         Ibrahim Saber
 * @version:        1.0
 * @date:           24-11-2026
 * Last Update:     10:03 PM, Wednesday, November 25, 2026
 ****************************************************************************************************/
#ifndef AFIO_PRV_H
#define AFIO_PRV_H


								/*********************** prv MACROS  ***********************/
#define 	AFIO_DEFAULT		       0u
#define		AFIO_REMAPPED		       1u
#define     AFIO_PARTIAL_REMAP	       2u
#define     AFIO_FULL_REMAP   	       3u

#define 	AFIO_EXTI_REGS_SHIFTING	   4u

								/*********************** MASKS  ***********************/
#define		AFIO_2BIT_MASK			0b11u
#define 	AFIO_3BIT_MASK			0b111u
#define 	AFIO_4BIT_MASK			0b1111u



								/*********************** Bits  ***********************/
#define 	EVCR_PIN0				0u
#define 	EVCR_PORT0				4u
#define 	EVCR_EVOE				7u

#define     MAPR_SPI1_REMAP				0u
#define     MAPR_I2C1_REMAP             1u
#define     MAPR_USART1_REMAP           2u
#define     MAPR_USART2_REMAP           3u
#define     MAPR_USART3_REMAP0          4u
#define     MAPR_TIM1_REMAP0            6u
#define     MAPR_TIM2_REMAP0            8u
#define     MAPR_TIM3_REMAP0            10u
#define     MAPR_TIM4_REMAP             12u
#define     MAPR_CAN_REMAP0             13u
#define     MAPR_PD01_REMAP             15u
#define     MAPR_TIM5CH4_IR_REMAP       16u
#define     MAPR_ADC1_ETRGINJ_REMAP     17u
#define     MAPR_ADC1_ETRGREG_REMAP     18u
#define     MAPR_ADC2_ETRGINJ_REMAP     19u
#define     MAPR_ADC2_ETRGREG_REMAP     20u
#define     MAPR_SWJ_CFG0               24u





#endif
