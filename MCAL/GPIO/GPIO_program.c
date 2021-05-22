/*****************************************************************/
/****************** Name    : Ahmed Kishk 	**********************/
/****************** Date    : 12/5/2021  	**********************/
/****************** Version : 1.0V       	**********************/
/****************** SWC     : GPIO          **********************/
/*****************************************************************/

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATHS.h"
#include "../include/LIB/stm32f103C8.h"

#include "../include/MCAL/02-GPIO/GPIO_interface.h"
#include "../include/MCAL/02-GPIO/GPIO_config.h"
#include "../include/MCAL/02-GPIO/GPIO_private.h"
GPIO_RegDef_t * GPIO_arrPtr [3] = {GPIOA , GPIOB , GPIOC};

u8 GPIO_u8PinMode(const GPIO_PIN_CONFIG_t * Copy_strPtrConfig){
	u8 LOC_u8ErrorState = STD_TYPES_OK;
	u8 LOC_u8PinMode = 0;
	u8 LOC_u8PinNumber = 0;
	if (Copy_strPtrConfig != NULL){
		if((Copy_strPtrConfig ->u8PortId <= GPIO_u8_PORT_C) && (Copy_strPtrConfig->u8PinId <= GPIO_u8_PIN_15)){
			LOC_u8PinMode = Copy_strPtrConfig->u8PinMode;
			LOC_u8PinNumber = Copy_strPtrConfig->u8PinId;
			if(Copy_strPtrConfig->u8PinMode == GPIO_u8_INPUT_PULL_UP){
				SET_BIT((GPIO_arrPtr[Copy_strPtrConfig->u8PortId]->ODR) , (Copy_strPtrConfig->u8PinId));
				LOC_u8PinMode = GPIO_u8_INPUT_PULL_UP_DOWN ;
			}

			if(Copy_strPtrConfig->u8PinId <= GPIO_u8_PIN_07){
				GPIO_arrPtr[Copy_strPtrConfig->u8PortId]->CRL &= ~((0b1111 << (4 * LOC_u8PinNumber)));
				GPIO_arrPtr[Copy_strPtrConfig->u8PortId]->CRL |=  ((LOC_u8PinMode << (4 * LOC_u8PinNumber)));
			}
			else{
				LOC_u8PinNumber -= GPIO_u8_PIN_08;
				GPIO_arrPtr[Copy_strPtrConfig->u8PortId]->CRH &= ~((0b1111 << (4 * LOC_u8PinNumber)));
				GPIO_arrPtr[Copy_strPtrConfig->u8PortId]->CRH |=  ((LOC_u8PinMode << (4 * LOC_u8PinNumber)));
			}
		}
		else{
			LOC_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else{
		LOC_u8ErrorState = STD_TYPES_NOK;
	}
	return LOC_u8ErrorState;
}



u8 GPIO_u8ReadPinValue(const GPIO_PIN_CONFIG_t * Copy_strPtrConfig , u8 * Copy_PtrResult){
	u8 LOC_u8ErrorState = STD_TYPES_OK;
	if (Copy_strPtrConfig != NULL){
			if((Copy_strPtrConfig ->u8PortId <= GPIO_u8_PORT_C) && (Copy_strPtrConfig->u8PinId <= GPIO_u8_PIN_15)){
				*Copy_PtrResult = GET_BIT(GPIO_arrPtr[Copy_strPtrConfig ->u8PortId]->IDR , Copy_strPtrConfig->u8PinId);
			}
			else{
				LOC_u8ErrorState = STD_TYPES_NOK;
			}
	}
	else{
		LOC_u8ErrorState = STD_TYPES_NOK;
	}

	return LOC_u8ErrorState;
}


u8 GPIO_u8SetPinValue(const GPIO_PIN_CONFIG_t * Copy_strPtrConfig , u8 Copy_u8Operation){
	u8 LOC_u8ErrorState = STD_TYPES_OK;
	if (Copy_strPtrConfig != NULL){
			if((Copy_strPtrConfig ->u8PortId <= GPIO_u8_PORT_C) && (Copy_strPtrConfig->u8PinId <= GPIO_u8_PIN_15)){
				switch (Copy_u8Operation){
				case GPIO_u8_HIGH:
					GPIO_arrPtr[Copy_strPtrConfig->u8PortId]->BSRR = (1<<Copy_strPtrConfig->u8PinId);
					break;

				case GPIO_u8_LOW:
					GPIO_arrPtr[Copy_strPtrConfig->u8PortId]->BRR = (1<<Copy_strPtrConfig->u8PinId);
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
	else{
		LOC_u8ErrorState = STD_TYPES_NOK;
	}

	return LOC_u8ErrorState;
}

u8 GPIO_u8TogPin(const GPIO_PIN_CONFIG_t * Copy_strPtrConfig){
	u8 LOC_u8ErrorState = STD_TYPES_OK;
	if (Copy_strPtrConfig != NULL){
			if((Copy_strPtrConfig ->u8PortId <= GPIO_u8_PORT_C) && (Copy_strPtrConfig->u8PinId <= GPIO_u8_PIN_15)){
				TOGGEL_BIT(GPIO_arrPtr[Copy_strPtrConfig->u8PortId]->ODR , Copy_strPtrConfig->u8PinId);
			}
			else{
				LOC_u8ErrorState = STD_TYPES_NOK;
			}
	}
	else{
		LOC_u8ErrorState = STD_TYPES_NOK;
	}
	return LOC_u8ErrorState;
}


u8 GPIO_u8PortMode(u8 Copy_u8Port , u32 Copy_u32PortMode){
	u8 LOC_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8Port <= GPIO_u8_PORT_C){
		GPIO_arrPtr[Copy_u8Port]->CRL = Copy_u32PortMode;
		GPIO_arrPtr[Copy_u8Port]->CRH = Copy_u32PortMode;
	}
	else{
		LOC_u8ErrorState = STD_TYPES_NOK;
	}
	return LOC_u8ErrorState;
}
u8 GPIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Operation){
	u8 LOC_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8Port <= GPIO_u8_PORT_C){
		switch (Copy_u8Operation){
		case GPIO_u8_HIGH:
			GPIO_arrPtr[Copy_u8Port]->BSRR = 0xFFFF;
			break;

		case GPIO_u8_LOW:
			GPIO_arrPtr[Copy_u8Port]->BRR = 0xFFFF;
			break;

		default:
			LOC_u8ErrorState = STD_TYPES_NOK;
			break;
		}
	}
	else{
		LOC_u8ErrorState = STD_TYPES_NOK;
	}
	return LOC_u8ErrorState;
}


u8 GPIO_u8ReadPortValue(u8 Copy_u8Port , u32 * Copy_ptrResult){
	u8 LOC_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8Port <= GPIO_u8_PORT_C){
		* Copy_ptrResult = GPIO_arrPtr[Copy_u8Port]->IDR;
	}
	else{
		LOC_u8ErrorState = STD_TYPES_NOK;
	}
	return LOC_u8ErrorState;
}




