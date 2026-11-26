/***************************************************************************************************
 * @file:           AFIO_prv.h
 * @brief:			This file contains the private definitions of the AFIO driver
 * @author:         Ibrahim Saber
 * @version:        1.0
 * @date:           24-11-2026
 * Last Update:     5:30 PM, Wednesday, November 25, 2026
 ****************************************************************************************************/
#ifndef AFIO_PRV_H
#define AFIO_PRV_H


								/*********************** prv MACROS  ***********************/
/*cfg tokens: #if labels only, never written to a reg*/
#define 	AFIO_DEFAULT		       1u
#define		AFIO_REMAPPED		       2u
#define     AFIO_PARTIAL_REMAP	       3u
#define     AFIO_FULL_REMAP   	       4u

								/*********************** 2-bit remap field values, RM0008 9.4.2  ***********************/
#define     AFIO_USART3_PARTIAL_VAL    0b01u
#define     AFIO_USART3_FULL_VAL       0b11u

#define     AFIO_TIM1_PARTIAL_VAL      0b01u
#define     AFIO_TIM1_FULL_VAL         0b11u

/*partial 1: CH1/ETR to PA15, CH2 to PB3*/
#define     AFIO_TIM2_PARTIAL_VAL      0b01u
#define     AFIO_TIM2_FULL_VAL         0b11u

#define     AFIO_TIM3_PARTIAL_VAL      0b10u
#define     AFIO_TIM3_FULL_VAL         0b11u

/*RX to PB8, TX to PB9*/
#define     AFIO_CAN_PARTIAL_VAL       0b10u
/*RX to PD0, TX to PD1*/
#define     AFIO_CAN_FULL_VAL          0b11u

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
