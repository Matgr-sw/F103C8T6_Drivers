/***************************************************************************************************
 * @file:           AFIO_cfg.h
 * @brief:			This file contains the configuration of the pins re-mapping
 * @author:         Ibrahim Saber
 * @version:        1.0
 * @date:           24-11-2026
 * Last Update:     10:03 PM, Wednesday, November 25, 2026
 ****************************************************************************************************/
#ifndef AFIO_CFG_H
#define AFIO_CFG_H

/**
 *use one of the following configs
 *
 *		- AFIO_DEFAULT
 *		- AFIO_REMAPPED
 *
 */
#define     SPI1_REMAPPING					AFIO_DEFAULT
#define     I2C1_REMAPPING                  AFIO_DEFAULT
#define     USART1_REMAPPING                AFIO_DEFAULT
#define     USART2_REMAPPING                AFIO_DEFAULT
#define     TIM4_REMAPPING                  AFIO_DEFAULT
#define     PD01_REMAPPING                  AFIO_DEFAULT
#define     TIM5CH4_IR_REMAPPING            AFIO_DEFAULT
#define     ADC1_ETRGINJ_REMAPPING          AFIO_DEFAULT
#define     ADC1_ETRGREG_REMAPPING          AFIO_DEFAULT
#define     ADC2_ETRGINJ_REMAPPING          AFIO_DEFAULT
#define     ADC2_ETRGREG_REMAPPING          AFIO_DEFAULT


/**
 *use one of the following configs
 *
 *		- AFIO_DEFAULT
 *		- AFIO_REMAPPED
 *		- AFIO_PARTIAL_REMAP
 *		- AFIO_FULL_REMAP
 *		note: available options for CAN are:
 *		- AFIO_DEFAULT -> RX to PA11, TX to PA12
 *		- AFIO_PARTIAL_REMAP -> RX to PB8, TX to PB9
 *		- AFIO_FULL_REMAP -> RX to PD0, TX to PD1
 *
 */
#define     USART3_REMAPPING                AFIO_DEFAULT
#define     TIM1_REMAPPING                  AFIO_DEFAULT
#define     TIM2_REMAPPING                  AFIO_DEFAULT
#define     TIM3_REMAPPING                  AFIO_DEFAULT
#define     CAN_REMAPPING                   AFIO_DEFAULT




























#endif
