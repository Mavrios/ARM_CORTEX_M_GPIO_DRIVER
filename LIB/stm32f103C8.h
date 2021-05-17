#ifndef _STM32F103C8_H
#define _STM32F103C8_H


	/*********************************************************************
	**********************     	RCC REGISTERS	     *********************
	*********************************************************************/
#define RCC_u32_BASE_ADDRESS         0x40021000

typedef struct
{
    volatile u32 CR         ;
    volatile u32 CFGR       ;
    volatile u32 CIR        ;
    volatile u32 APB2RSTR   ;
    volatile u32 APB1RSTR   ;
    volatile u32 AHBENR     ;
    volatile u32 APB2ENR   	;
    volatile u32 APB1ENR   	;
    volatile u32 BDCR       ;
    volatile u32 CSR        ;
    }RCC_RegDef_t;

#define RCC         ((RCC_RegDef_t * ) RCC_u32_BASE_ADDRESS)

	/*********************************************************************
	**********************     	GPIO REGISTERS	     *********************
	*********************************************************************/
#define GPIO_u32_GPIOA_BASE_ADDRESS         0x40010800
#define GPIO_u32_GPIOB_BASE_ADDRESS         0x40010C00
#define GPIO_u32_GPIOC_BASE_ADDRESS         0x40011000


typedef struct
{
	volatile u64 CR			;
	volatile u32 IDR		;
	volatile u32 ODR		;
	volatile u32 BSRR		;
	volatile u32 BRR		;
	volatile u32 LCKR		;
}GPIO_RegDef_t;

#define GPIOA	((GPIO_RegDef_t *) GPIO_u32_GPIOA_BASE_ADDRESS)
#define GPIOB	((GPIO_RegDef_t *) GPIO_u32_GPIOB_BASE_ADDRESS)
#define GPIOC	((GPIO_RegDef_t *) GPIO_u32_GPIOC_BASE_ADDRESS)

	/*********************************************************************
	**************     	ALTERNATIVE I/O REGISTERS	     *****************
	*********************************************************************/

#define AFIO_u32_BASE_ADDRESS         0x40010000

typedef struct
{
	volatile u32 EVCR		;
	volatile u32 MAPR		;
	volatile u32 EXTICR1	;
	volatile u32 EXTICR2	;
	volatile u32 EXTICR3	;
	volatile u32 EXTICR4	;
	volatile u32 MAPR2		;
}AFIO_RegDef_t;

#define AFIO	((GPIO_RegDef_t *) AFIO_u32_BASE_ADDRESS)


#endif
