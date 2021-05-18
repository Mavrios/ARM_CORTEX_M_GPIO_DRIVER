/*****************************************************************/
/****************** Name    : Ahmed Kishk 	**********************/
/****************** Date    : 12/5/2021  	**********************/
/****************** Version : 1.0V       	**********************/
/****************** SWC     : GPIO          **********************/
/*****************************************************************/

#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H


/*********************************************************************
**************************     PIN MODES     *************************
**********************************************************************/
#define GPIO_u8_ANALOG_MODE					0
#define GPIO_u8_FLOATING_MODE				1
#define GPIO_u8_PULLUP_PULLDOWN_MODE		2
#define GPIO_u8_PUSH_PULL					3
#define GPIO_u8_OPEN_DRIAN					4
#define GPIO_u8_ALTERNATE_PUSH_PULL			5
#define GPIO_u8_ALTERNATE_OPEN_DRIAN		6

/*********************************************************************
*************************     GPIO PORTS     *************************
**********************************************************************/
#define GPIO_u8_PORT_A						0
#define GPIO_u8_PORT_B						1
#define GPIO_u8_PORT_C						2


/*********************************************************************
*******************     PIN OUTPUT OPERATIONS      *******************
**********************************************************************/
#define GPIO_u8_HIGH						1
#define GPIO_u8_LOW							0
#define GPIO_u8_SET							1
#define GPIO_u8_RESET						0



/*********************************************************************
*********************     FUNCTIONS PROTOTYPE     ********************
**********************************************************************/
u8 GPIO_u8PinMode(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode);
u8 GPIO_u8PinModeWithSpeed(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode , u8 Copy_u8Speed);
u8 GPIO_u8ReadPinValue(u8 Copy_u8Port , u8 Copy_u8Pin);
u8 GPIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Operation);

#endif
