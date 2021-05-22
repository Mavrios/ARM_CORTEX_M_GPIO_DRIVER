/*****************************************************************/
/****************** Name    : Ahmed Kishk 	**********************/
/****************** Date    : 12/5/2021  	**********************/
/****************** Version : 1.0V       	**********************/
/****************** SWC     : GPIO          **********************/
/*****************************************************************/

#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H


typedef struct{
    u8 u8PortId;
    u8 u8PinId;
    u8 u8PinMode;
}GPIO_PIN_CONFIG_t;


/*********************************************************************
**************************     PIN MODES     *************************
**********************************************************************/
/************************     INPUT MODES     ************************/
#define GPIO_u8_INPUT_ANALOG                0b0000
#define GPIO_u8_INPUT_FLOATING              0b0100
#define GPIO_u8_INPUT_PULL_DOWN             0b1000
#define GPIO_u8_INPUT_PULL_UP               0b11000
/************************     OUTPUT MODES     ***********************/
/************************     10 MHZ SPEED     ***********************/
#define GPIO_u8_OUTPUT_GP_PP_SPEED_10MHZ    0b0001
#define GPIO_u8_OUTPUT_GP_OD_SPEED_10MHZ    0b0101
#define GPIO_u8_OUTPUT_AF_PP_SPEED_10MHZ    0b1001
#define GPIO_u8_OUTPUT_AF_OD_SPEED_10MHZ    0b1101
/************************     2 MHZ SPEED     ***********************/
#define GPIO_u8_OUTPUT_GP_PP_SPEED_2MHZ     0b0010
#define GPIO_u8_OUTPUT_GP_OD_SPEED_2MHZ     0b0110
#define GPIO_u8_OUTPUT_AF_PP_SPEED_2MHZ     0b1010
#define GPIO_u8_OUTPUT_AF_OD_SPEED_2MHZ     0b1110
/************************     50 MHZ SPEED     ***********************/
#define GPIO_u8_OUTPUT_GP_PP_SPEED_50MHZ    0b0011
#define GPIO_u8_OUTPUT_GP_OD_SPEED_50MHZ    0b0111
#define GPIO_u8_OUTPUT_AF_PP_SPEED_50MHZ    0b1011
#define GPIO_u8_OUTPUT_AF_OD_SPEED_50MHZ    0b1111


/*********************************************************************
**************************     PORT MODES     *************************
**********************************************************************/
/************************     INPUT MODES     ************************/
#define GPIO_u32_PORT_INPUT_ANALOG                0x00000000
#define GPIO_u32_PORT_INPUT_FLOATING              0x44444444
#define GPIO_u32_PORT_INPUT_PULL_DOWN             0x88888888
#define GPIO_u32_PORT_INPUT_PULL_UP               0x88888889
/************************     OUTPUT MODES     ***********************/
/************************     10 MHZ SPEED     ***********************/
#define GPIO_u32_PORT_OUTPUT_GP_PP_SPEED_10MHZ    0x11111111
#define GPIO_u32_PORT_OUTPUT_GP_OD_SPEED_10MHZ    0x55555555
#define GPIO_u32_PORT_OUTPUT_AF_PP_SPEED_10MHZ    0x99999999
#define GPIO_u32_PORT_OUTPUT_AF_OD_SPEED_10MHZ    0xDDDDDDDD
/************************     2 MHZ SPEED     ***********************/
#define GPIO_u32_PORT_OUTPUT_GP_PP_SPEED_2MHZ     0x22222222
#define GPIO_u32_PORT_OUTPUT_GP_OD_SPEED_2MHZ     0x66666666
#define GPIO_u32_PORT_OUTPUT_AF_PP_SPEED_2MHZ     0xAAAAAAAA
#define GPIO_u32_PORT_OUTPUT_AF_OD_SPEED_2MHZ     0xEEEEEEEE
/************************     50 MHZ SPEED     ***********************/
#define GPIO_u32_PORT_OUTPUT_GP_PP_SPEED_50MHZ    0x33333333
#define GPIO_u32_PORT_OUTPUT_GP_OD_SPEED_50MHZ    0x77777777
#define GPIO_u32_PORT_OUTPUT_AF_PP_SPEED_50MHZ    0xBBBBBBBB
#define GPIO_u32_PORT_OUTPUT_AF_OD_SPEED_50MHZ    0xFFFFFFFF
/*********************************************************************
*************************     GPIO PORTS     *************************
**********************************************************************/
#define GPIO_u8_PORT_A						0
#define GPIO_u8_PORT_B						1
#define GPIO_u8_PORT_C						2

/********************************************************************
*************************     GPIO PINS     *************************
*********************************************************************/
#define GPIO_u8_PIN_00                      0
#define GPIO_u8_PIN_01                      1
#define GPIO_u8_PIN_02                      2
#define GPIO_u8_PIN_03                      3
#define GPIO_u8_PIN_04                      4
#define GPIO_u8_PIN_05                      5
#define GPIO_u8_PIN_06                      6
#define GPIO_u8_PIN_07                      7
#define GPIO_u8_PIN_08                      8
#define GPIO_u8_PIN_09                      9
#define GPIO_u8_PIN_10                      10
#define GPIO_u8_PIN_11                      11
#define GPIO_u8_PIN_12                      12
#define GPIO_u8_PIN_13                      13
#define GPIO_u8_PIN_14                      14
#define GPIO_u8_PIN_15                      15


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
u8 GPIO_u8PinMode(const GPIO_PIN_CONFIG_t * Copy_strPtrConfig);
u8 GPIO_u8ReadPinValue(const GPIO_PIN_CONFIG_t * Copy_strPtrConfig , u8 * Copy_PtrResult);
u8 GPIO_u8SetPinValue(const GPIO_PIN_CONFIG_t * Copy_strPtrConfig , u8 Copy_u8Operation);
u8 GPIO_u8TogPin(const GPIO_PIN_CONFIG_t * Copy_strPtrConfig);
u8 GPIO_u8PortMode(u8 Copy_u8Port , u32 Copy_u32PortMode);
u8 GPIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Operation);
u8 GPIO_u8ReadPortValue(u8 Copy_u8Port , u32 * Copy_ptrResult);

#endif
