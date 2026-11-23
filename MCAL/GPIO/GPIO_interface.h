/***************************************************************************************************
 * @file:           GPIO_interface.h
 * @brief:			This file contains the interfaces and function prototypes of the GPIO driver
 * @author:         Ibrahim Saber
 * @version:        1.0
 * @date:           22-11-2026
 * Last Update:     4:39 PM, Monday, November 23, 2026
 ****************************************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


								/***********************  Enums  ***********************/
typedef enum
{
	GPIO_Exit_OK,
	GPIO_Invalid_Port,
	GPIO_Invalid_Pin,
	GPIO_Invalid_State,


}GPIO_ErrorState_t;


typedef enum
{
	GPIO_PortA,
	GPIO_PortB,
	GPIO_PortC,
	GPIO_PortD,

}GPIO_Port_t;


typedef enum
{
	GPIO_Pin0,
	GPIO_Pin1,
	GPIO_Pin2,
	GPIO_Pin3,
	GPIO_Pin4,
	GPIO_Pin5,
	GPIO_Pin6,
	GPIO_Pin7,
	GPIO_Pin8,
	GPIO_Pin9,
	GPIO_Pin10,
	GPIO_Pin11,
	GPIO_Pin12,
    GPIO_Pin13,
	GPIO_Pin14,
	GPIO_Pin15,

}GPIO_Pin_t;


typedef enum
{
	GPIO_Input_Analog,
	GPIO_Ouput_10MHz_PushPull,
	GPIO_Ouput_2MHz_PushPull,
	GPIO_Ouput_50MHz_PushPull,
	GPIO_Input_Float,
	GPIO_Ouput_10MHz_OpenDrain,
	GPIO_Ouput_2MHz_OpenDrain,
	GPIO_Ouput_50MHz_OpenDrain,
	GPIO_Input_PullUpDown,
	GPIO_Output_10MHz_AF_PushPull,
	GPIO_Output_2MHz_AF_PushPull,
	GPIO_Output_50MHz_AF_PushPull,
	GPIO_Output_10MHz_AF_OpenDrain = 13,
	GPIO_Output_2MHz_AF_OpenDrain,
	GPIO_Output_50MHz_AF_OpenDrain,

}GPIO_DirectionMode_t;


typedef enum
{
	GPIO_Pin_Low,
	GPIO_Pin_High,

}GPIO_PinState_t;


typedef enum
{
	GPIO_LockKey_Disabled,
	GPIO_LockKey_Enabled,

}GPIO_LockKey_t;


typedef enum
{
	GPIO_Pin_NotLocked,
	GPIO_Pin_Locked,

}GPIO_LockPin_t;

						/*********************** Config struct  ***********************/



							/*********************** Functions  ***********************/


/**
* 	Description:                This Function is used to set the direction of a GPIO pin
* 	Parameters:                 - GPIO_Port_t Copy_ePort
* 								- GPIO_Pin_t Copy_ePin
* 								- GPIO_DirectionMode_t Copy_eDirection
*
* 	Returns:                    - GPIO_ErrorState_t Local_eErrorState The return state of the function
* 	Preconditions:              - The RCC driver is initialized and working
* 								- The clk is enabled of the specific GPIO port
* 	Side effects:               No side effects
* 	Post Conditions:            Pin direction and mode configured
* 	Sync/Async:               	Sync.
*/
GPIO_ErrorState_t GPIO_eSetPinDirection(GPIO_Port_t Copy_ePort, GPIO_Pin_t Copy_ePin, GPIO_DirectionMode_t Copy_eDirection);





/**
* 	Description:                This Function is used to set the pin state of a GPIO port
* 	Parameters:                 - GPIO_Port_t Copy_ePort
* 								- GPIO_Pin_t Copy_ePin
* 								- GPIO_PinState_t Copy_eState
*
* 	Returns:                    - GPIO_ErrorState_t Local_eErrorState The return state of the function
* 	Preconditions:              - The direction of the pin is set
*
* 	Side effects:               No side effects
* 	Post Conditions:            Pin state direction set
* 	Sync/Async:               	Sync.
*/
GPIO_ErrorState_t GPIO_eSetPinState(GPIO_Port_t Copy_ePort, GPIO_Pin_t Copy_ePin, GPIO_PinState_t Copy_eState);



/**
* 	Description:                This Function is used to set the state of a GPIO port
* 	Parameters:                 - GPIO_Port_t Copy_ePort
* 								- GPIO_PinState_t Copy_eState
*
* 	Returns:                    - GPIO_ErrorState_t Local_eErrorState The return state of the function
* 	Preconditions:            	- port direction must be set
* 	Side effects:               No side effects
* 	Post Conditions:            Port state configured
* 	Sync/Async:               	Sync.
*/
GPIO_ErrorState_t GPIO_eSetPortState(GPIO_Port_t Copy_ePort,  GPIO_PinState_t Copy_eState);


/**
* 	Description:                This Function is used to toggle the pin state of a GPIO port
* 	Parameters:                 - GPIO_Port_t Copy_ePort
* 								- GPIO_Pin_t Copy_ePin
*
* 	Returns:                    - GPIO_ErrorState_t Local_eErrorState The return state of the function
* 	Preconditions:              - The direction of the pin is set
*
* 	Side effects:               No side effects
* 	Post Conditions:            pin state toggled
* 	Sync/Async:               	Sync.
*/
GPIO_ErrorState_t GPIO_eTogPinState(GPIO_Port_t Copy_ePort, GPIO_Pin_t Copy_ePin);



/**
* 	Description:                This Function is used to toggle the state of a GPIO port
* 	Parameters:                 - GPIO_Port_t Copy_ePort
*
* 	Returns:                    - GPIO_ErrorState_t Local_eErrorState The return state of the function
* 	Preconditions:            	- port direction must be set
* 	Side effects:               No side effects
* 	Post Conditions:            Port state toggled
* 	Sync/Async:               	Sync.
*/
GPIO_ErrorState_t GPIO_eTogPortState(GPIO_Port_t Copy_ePort);




/**
* 	Description:                This Function is used to read the pin state of a GPIO pin
* 	Parameters:                 - GPIO_Port_t Copy_ePort
* 								- GPIO_Pin_t Copy_ePin
*
* 	Returns:                    - GPIO_PinState_t Local_ePinVal The return state of the function
* 	Preconditions:              - The Pin direction is configured
* 	Side effects:               No side effects
* 	Post Conditions:            Pint state read
* 	Sync/Async:               	Sync.
*/
GPIO_PinState_t GPIO_eGetPinState(GPIO_Port_t Copy_ePort, GPIO_Pin_t Copy_ePin);




/**
* 	Description:                This Function is used to read the port state of a GPIO port
* 	Parameters:                 - GPIO_Port_t Copy_ePort
*
* 	Returns:                    - uint16_t Local_u16PortVal The return state of the function
* 	Preconditions:              - The Port direction is configured
* 	Side effects:               No side effects
* 	Post Conditions:            Port state read
* 	Sync/Async:               	Sync.
*/
uint16_t GPIO_u16GetPortState(GPIO_Port_t Copy_ePort);







#endif
