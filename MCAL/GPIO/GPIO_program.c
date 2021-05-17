/*****************************************************************/
/****************** Name    : Ahmed Kishk 	**********************/
/****************** Date    : 12/5/2021  	**********************/
/****************** Version : 1.0V       	**********************/
/****************** SWC     : GPIO          **********************/
/*****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "stm32f103C8.h"

#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

u8 GPIO_u8PinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode) {
	u8 LOC_u8ErrorState = STD_TYPES_OK;

	if (Copy_u8Pin < 16) {
		if (Copy_u8Mode >= GPIO_u8_PUSH_PULL) {
#if GPIO_u8_MAX_OUTPUT_SPEED	==	GPIO_u8_10MHZ
			SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 0);
			CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 1);
#elif GPIO_u8_MAX_OUTPUT_SPEED	==	GPIO_u8_2MHZ
			CLR_BIT(GPIOA->CR , (Copy_u8Pin * 4) + 0 );
			SET_BIT(GPIOA->CR , (Copy_u8Pin * 4) + 1 );
#elif GPIO_u8_MAX_OUTPUT_SPEED	==	GPIO_u8_50MHZ
			SET_BIT(GPIOA->CR , (Copy_u8Pin * 4) + 0 );
			SET_BIT(GPIOA->CR , (Copy_u8Pin * 4) + 1 );
#endif
		}
		switch (Copy_u8Mode) {

		case GPIO_u8_ANALOG_MODE:
			switch (Copy_u8Port) {
			case GPIO_u8_PORT_A:
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 1);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_B:
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 1);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_C:
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 1);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 3);
				break;
			default:
				LOC_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			break;

		case GPIO_u8_FLOATING_MODE:
			switch (Copy_u8Port) {
			case GPIO_u8_PORT_A:
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 1);
				SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_B:
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 1);
				SET_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_C:
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 1);
				SET_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 3);
				break;
			default:
				LOC_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			break;

		case GPIO_u8_PULLUP_PULLDOWN_MODE:
			switch (Copy_u8Port) {
			case GPIO_u8_PORT_A:
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 1);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_B:
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 1);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_C:
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 1);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 3);
				break;
			default:
				LOC_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			break;

		case GPIO_u8_PUSH_PULL:
			switch (Copy_u8Port) {
			case GPIO_u8_PORT_A:
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_B:
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_C:
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 3);
				break;
			default:
				LOC_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			break;

		case GPIO_u8_OPEN_DRIAN:
			switch (Copy_u8Port) {
			case GPIO_u8_PORT_A:
				SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_B:
				SET_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_C:
				SET_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 3);
				break;
			default:
				LOC_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			break;

		case GPIO_u8_ALTERNATE_PUSH_PULL:
			switch (Copy_u8Port) {
			case GPIO_u8_PORT_A:
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_B:
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_C:
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 3);
				break;
			default:
				LOC_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			break;

		case GPIO_u8_ALTERNATE_OPEN_DRIAN:
			switch (Copy_u8Port) {
			case GPIO_u8_PORT_A:
				SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_B:
				SET_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_C:
				SET_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 3);
				break;
			default:
				LOC_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			break;

		}
	}
	return LOC_u8ErrorState;

}

u8 GPIO_u8PinModeWithSpeed(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode,
		u8 Copy_u8Speed) {
	u8 LOC_u8ErrorState = STD_TYPES_OK;

	if (Copy_u8Pin < 16) {
		if (Copy_u8Mode >= GPIO_u8_PUSH_PULL) {
			switch (Copy_u8Speed) {
			case GPIO_u8_10MHZ:
				SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 1);
				break;
			case GPIO_u8_2MHZ:
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 0);
				SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 1);
				break;
			case GPIO_u8_50MHZ:
				SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 0);
				SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 1);
				break;
			default:
				LOC_u8ErrorState = STD_TYPES_NOK;
				break;
			}
		}

		switch (Copy_u8Mode) {
		case GPIO_u8_ANALOG_MODE:
			switch (Copy_u8Port) {
			case GPIO_u8_PORT_A:
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 1);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 3);

				break;
			case GPIO_u8_PORT_B:
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 1);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 3);

				break;
			case GPIO_u8_PORT_C:
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 1);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 3);

				break;
			default:
				LOC_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			break;

		case GPIO_u8_FLOATING_MODE:
			switch (Copy_u8Port) {
			case GPIO_u8_PORT_A:
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 1);
				SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_B:
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 1);
				SET_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 3);

				break;
			case GPIO_u8_PORT_C:
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 1);
				SET_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 3);
				break;
			default:
				LOC_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			break;

		case GPIO_u8_PULLUP_PULLDOWN_MODE:
			switch (Copy_u8Port) {
			case GPIO_u8_PORT_A:
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 1);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_B:
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 1);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_C:
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 0);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 1);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 3);
				break;
			default:
				LOC_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			break;

		case GPIO_u8_PUSH_PULL:
			switch (Copy_u8Port) {
			case GPIO_u8_PORT_A:
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_B:
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_C:
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 3);
				break;
			default:
				LOC_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			break;

		case GPIO_u8_OPEN_DRIAN:
			switch (Copy_u8Port) {
			case GPIO_u8_PORT_A:
				SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_B:
				SET_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_C:
				SET_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 2);
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 3);
				break;
			default:
				LOC_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			break;

		case GPIO_u8_ALTERNATE_PUSH_PULL:
			switch (Copy_u8Port) {
			case GPIO_u8_PORT_A:
				CLR_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_B:
				CLR_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_C:
				CLR_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 3);
				break;
			default:
				LOC_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			break;

		case GPIO_u8_ALTERNATE_OPEN_DRIAN:
			switch (Copy_u8Port) {
			case GPIO_u8_PORT_A:
				SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOA->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_B:
				SET_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOB->CR, (Copy_u8Pin * 4) + 3);
				break;
			case GPIO_u8_PORT_C:
				SET_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 2);
				SET_BIT(GPIOC->CR, (Copy_u8Pin * 4) + 3);
				break;
			default:
				LOC_u8ErrorState = STD_TYPES_NOK;
				break;
			}
			break;

		}
	} else {
		LOC_u8ErrorState = STD_TYPES_NOK;
	}

	return LOC_u8ErrorState;
}


u8 GPIO_u8ReadPinValue(u8 Copy_u8Port , u8 Copy_u8Pin){
	u8 LOC_u8ErrorState = STD_TYPES_OK;
	u8 LOC_u8Result	=	0;
	if(Copy_u8Pin < 16){
		switch(Copy_u8Port){
		case GPIO_u8_PORT_A:
			LOC_u8Result = GET_BIT(GPIOA->IDR , Copy_u8Pin);
			break;
		case GPIO_u8_PORT_B:
			LOC_u8Result = GET_BIT(GPIOB->IDR , Copy_u8Pin);
			break;
		case GPIO_u8_PORT_C:
			LOC_u8Result = GET_BIT(GPIOC->IDR , Copy_u8Pin);
			break;
		default:
			LOC_u8ErrorState = STD_TYPES_NOK;
			break;
		}
	}
	else{
		LOC_u8ErrorState = STD_TYPES_NOK;
	}
	return LOC_u8Result;
}


u8 GPIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Operation){
	u8 LOC_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8Pin < 16){
		if(Copy_u8Operation == GPIO_u8_SET){
			switch(Copy_u8Port){
				case GPIO_u8_PORT_A:
					GPIOA->BSRR = (1 << Copy_u8Pin);
					break;
				case GPIO_u8_PORT_B:
					GPIOB->BSRR = (1 << Copy_u8Pin);
					break;
				case GPIO_u8_PORT_C:
					GPIOC->BSRR = (1 << Copy_u8Pin);
					break;
				default:
					LOC_u8ErrorState = STD_TYPES_NOK;
					break;
			}
		}
		else if (Copy_u8Operation == GPIO_u8_RESET){
			switch(Copy_u8Port){
							case GPIO_u8_PORT_A:
								GPIOA->BRR = (1 << Copy_u8Pin);
								break;
							case GPIO_u8_PORT_B:
								GPIOB->BRR = (1 << Copy_u8Pin);
								break;
							case GPIO_u8_PORT_C:
								GPIOC->BRR = (1 << Copy_u8Pin);
								break;
							default:
								LOC_u8ErrorState = STD_TYPES_NOK;
								break;
						}
		}
		else{
			LOC_u8ErrorState = STD_TYPES_NOK;
		}
	}
	return LOC_u8ErrorState;
}
