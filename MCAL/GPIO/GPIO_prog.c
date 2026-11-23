/***************************************************************************************************
 * @file:           GPIO_prog.c
 * @brief:			This file contains the implementation of the GPIO driver functions
 * @author:         Ibrahim Saber
 * @version:        1.0
 * @date:           23-11-2026
 * Last Update:     4:39 PM, Monday, November 23, 2026
 ****************************************************************************************************/
#include <stdint.h>
#include <stddef.h>

#include "BIT_MATH.h"
#include "MCAL_baseAddress.h"

#include "GPIO_prv.h"
#include "GPIO_interface.h"





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
GPIO_ErrorState_t GPIO_eSetPinDirection(GPIO_Port_t Copy_ePort, GPIO_Pin_t Copy_ePin, GPIO_DirectionMode_t Copy_eDirection)
{
	GPIO_ErrorState_t Local_eErrorState = GPIO_Exit_OK;

	if((Copy_ePin >= GPIO_Pin0) && (Copy_ePin <= GPIO_Pin15))
	{
	    switch(Copy_ePort)
	    {
	    	case GPIO_PortA:
	    	{
	    		(GPIOA->CR[(Copy_ePin/CR_HL_SHIFTING)]) &= ~(GPIO_4BIT_MASK << (CR_4BITS_SHIFTING * (Copy_ePin % CR_HL_SHIFTING)));
	    		(GPIOA->CR[(Copy_ePin/CR_HL_SHIFTING)]) |=  (Copy_eDirection <<(CR_4BITS_SHIFTING * (Copy_ePin % CR_HL_SHIFTING)));
	    		break;
	    	}

	    	case GPIO_PortB:
	    	{

	    		(GPIOB->CR[(Copy_ePin/CR_HL_SHIFTING)]) &= ~(GPIO_4BIT_MASK << (CR_4BITS_SHIFTING * (Copy_ePin % CR_HL_SHIFTING)));
	    	    (GPIOB->CR[(Copy_ePin/CR_HL_SHIFTING)]) |=  (Copy_eDirection <<(CR_4BITS_SHIFTING * (Copy_ePin % CR_HL_SHIFTING)));
	    		break;
	    	}

	    	case GPIO_PortC:
	    	{

	    		(GPIOC->CR[(Copy_ePin/CR_HL_SHIFTING)]) &= ~(GPIO_4BIT_MASK << (CR_4BITS_SHIFTING * (Copy_ePin % CR_HL_SHIFTING)));
	    	    (GPIOC->CR[(Copy_ePin/CR_HL_SHIFTING)]) |=  (Copy_eDirection <<(CR_4BITS_SHIFTING * (Copy_ePin % CR_HL_SHIFTING)));
	    		break;
	    	}

	    	case GPIO_PortD:
	    	{

	    		(GPIOD->CR[(Copy_ePin/CR_HL_SHIFTING)]) &= ~(GPIO_4BIT_MASK << (CR_4BITS_SHIFTING * (Copy_ePin % CR_HL_SHIFTING)));
	    	    (GPIOD->CR[(Copy_ePin/CR_HL_SHIFTING)]) |=  (Copy_eDirection <<(CR_4BITS_SHIFTING * (Copy_ePin % CR_HL_SHIFTING)));
	    		break;
	    	}

	    	default: Local_eErrorState = GPIO_Invalid_Port; break;

		}

	}

	else
	{
		Local_eErrorState = GPIO_Invalid_Pin;
	}

	return Local_eErrorState;
}






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
GPIO_ErrorState_t GPIO_eSetPinState(GPIO_Port_t Copy_ePort, GPIO_Pin_t Copy_ePin, GPIO_PinState_t Copy_eState)
{
	GPIO_ErrorState_t Local_eErrorState = GPIO_Exit_OK;

	if((Copy_ePin >= GPIO_Pin0) && (Copy_ePin <= GPIO_Pin15))
	{
	    switch(Copy_ePort)
	    {
	    	case GPIO_PortA:
	    	{
	    		(GPIOA->ODR) &= ~(GPIO_1BIT_MASK << Copy_ePin);
	    		(GPIOA->ODR) |=  (Copy_eState << Copy_ePin);
	    		break;
	    	}

	    	case GPIO_PortB:
	    	{
	    		(GPIOB->ODR) &= ~(GPIO_1BIT_MASK << Copy_ePin);
	    		(GPIOB->ODR) |=  (Copy_eState << Copy_ePin);
	    		break;
	    	}

	    	case GPIO_PortC:
	    	{
	    		(GPIOC->ODR) &= ~(GPIO_1BIT_MASK << Copy_ePin);
	    		(GPIOC->ODR) |=  (Copy_eState << Copy_ePin);
	    		break;
	    	}

	    	case GPIO_PortD:
	    	{
	    		(GPIOD->ODR) &= ~(GPIO_1BIT_MASK << Copy_ePin);
	    		(GPIOD->ODR) |=  (Copy_eState << Copy_ePin);
	    		break;
	    	}

	    	default: Local_eErrorState = GPIO_Invalid_Port; break;

		}

	}

	else
	{
		Local_eErrorState = GPIO_Invalid_Pin;
	}

	return Local_eErrorState;
}



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
GPIO_ErrorState_t GPIO_eSetPortState(GPIO_Port_t Copy_ePort,  GPIO_PinState_t Copy_eState)
{
	GPIO_ErrorState_t Local_eErrorState = GPIO_Exit_OK;

	switch(Copy_eState)
	{
		case GPIO_Pin_High:
		{
			switch(Copy_ePort)
			{
	    		case GPIO_PortA:
	    		{
	    			(GPIOA->ODR) &= ~(GPIO_16BIT_MASK);
	    			(GPIOA->ODR) |=  (GPIO_16BIT_MASK);
	    			break;
	    		}

	    		case GPIO_PortB:
	    		{
	    			(GPIOB->ODR) &= ~(GPIO_16BIT_MASK);
	    			(GPIOB->ODR) |=  (GPIO_16BIT_MASK);
	    			break;
	    		}

	    		case GPIO_PortC:
	    		{
	    			(GPIOC->ODR) &= ~(GPIO_16BIT_MASK);
	    			(GPIOC->ODR) |=  (GPIO_16BIT_MASK);
	    			break;
	    		}

	    		case GPIO_PortD:
	    		{
	    			(GPIOD->ODR) &= ~(GPIO_16BIT_MASK);
	    			(GPIOD->ODR) |=  (GPIO_16BIT_MASK);
	    			break;
	    		}

	    		default: Local_eErrorState = GPIO_Invalid_Port; break;

			}


			break;

		}

		case GPIO_Pin_Low:
		{
			switch(Copy_ePort)
			{
	    		case GPIO_PortA:
	    		{
	    			(GPIOA->ODR) &= ~(GPIO_16BIT_MASK);
	    			break;
	    		}

	    		case GPIO_PortB:
	    		{
	    			(GPIOB->ODR) &= ~(GPIO_16BIT_MASK);
	    			break;
	    		}

	    		case GPIO_PortC:
	    		{
	    			(GPIOC->ODR) &= ~(GPIO_16BIT_MASK);
	    			break;
	    		}

	    		case GPIO_PortD:
	    		{
	    			(GPIOD->ODR) &= ~(GPIO_16BIT_MASK);
	    			break;
	    		}

	    		default: Local_eErrorState = GPIO_Invalid_Port; break;

			}


			break;

		}

		default: Local_eErrorState = GPIO_Invalid_State;

	}







	return Local_eErrorState;
}


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
GPIO_ErrorState_t GPIO_eTogPinState(GPIO_Port_t Copy_ePort, GPIO_Pin_t Copy_ePin)
{
	GPIO_ErrorState_t Local_eErrorState = GPIO_Exit_OK;

	if((Copy_ePin >= GPIO_Pin0) && (Copy_ePin <= GPIO_Pin15))
	{
	    switch(Copy_ePort)
	    {
	    	case GPIO_PortA:
	    	{
	    		TOG_BIT((GPIOA->ODR), Copy_ePin);
	    		break;
	    	}

	    	case GPIO_PortB:
	    	{
	    		TOG_BIT((GPIOB->ODR), Copy_ePin);
	    		break;
	    	}

	    	case GPIO_PortC:
	    	{
	    		TOG_BIT((GPIOC->ODR), Copy_ePin);
	    		break;
	    	}

	    	case GPIO_PortD:
	    	{
	    		TOG_BIT((GPIOD->ODR), Copy_ePin);
	    		break;
	    	}

	    	default: Local_eErrorState = GPIO_Invalid_Port; break;

		}

	}

	else
	{
		Local_eErrorState = GPIO_Invalid_Pin;
	}

	return Local_eErrorState;
}



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
GPIO_ErrorState_t GPIO_eTogPortState(GPIO_Port_t Copy_ePort)
{
	GPIO_ErrorState_t Local_eErrorState = GPIO_Exit_OK;

	switch(Copy_ePort)
	{
		case GPIO_PortA:
		{
			(GPIOA->ODR) ^= (GPIO_16BIT_MASK);
			break;
		}

		case GPIO_PortB:
		{
			(GPIOB->ODR) ^= (GPIO_16BIT_MASK);
			break;
		}

		case GPIO_PortC:
		{
			(GPIOC->ODR) ^= (GPIO_16BIT_MASK);
			break;
		}

		case GPIO_PortD:
		{
			(GPIOD->ODR) ^= (GPIO_16BIT_MASK);
			break;
		}

		default: Local_eErrorState = GPIO_Invalid_Port; break;

	}

	return Local_eErrorState;
}




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
GPIO_PinState_t GPIO_eGetPinState(GPIO_Port_t Copy_ePort, GPIO_Pin_t Copy_ePin)
{
	GPIO_PinState_t Local_ePinVal = GPIO_Pin_Low;

	switch(Copy_ePort)
	{
		case GPIO_PortA:
		{
			Local_ePinVal = GET_BIT((GPIOA->IDR), Copy_ePin);
			break;
		}

		case GPIO_PortB:
		{
			Local_ePinVal = GET_BIT((GPIOB->IDR), Copy_ePin);
			break;
		}

		case GPIO_PortC:
		{
			Local_ePinVal = GET_BIT((GPIOC->IDR), Copy_ePin);
			break;
		}

		case GPIO_PortD:
		{
			Local_ePinVal = GET_BIT((GPIOD->IDR), Copy_ePin);
			break;
		}

		default: break;
	}




	return Local_ePinVal;

}




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
uint16_t GPIO_u16GetPortState(GPIO_Port_t Copy_ePort)
{
	uint16_t Local_u16PortVal = 0;

	switch(Copy_ePort)
	{
		case GPIO_PortA:
		{
			Local_u16PortVal = GET_BITS((GPIOA->IDR), 0, GPIO_16BIT_MASK);
			break;
		}

		case GPIO_PortB:
		{
			Local_u16PortVal = GET_BITS((GPIOB->IDR), 0, GPIO_16BIT_MASK);
			break;
		}

		case GPIO_PortC:
		{
			Local_u16PortVal = GET_BITS((GPIOC->IDR), 0, GPIO_16BIT_MASK);
			break;
		}

		case GPIO_PortD:
		{
			Local_u16PortVal = GET_BITS((GPIOD->IDR), 0, GPIO_16BIT_MASK);
			break;
		}

		default: break;
	}


	return Local_u16PortVal;

}




