


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


#define RCC_APB2ENR		*((unsigned int*)(0x40023800+0x44))
#define NVIC_ISER0		*((unsigned int*)(0xe000e100))

#define EXTI_BASE_ADDRESS 0x40013C00
#define EXTI_REG(BASE,OFFSET) *((unsigned int*)(BASE+OFFSET))



#define EXTI_IMR 	EXTI_REG(EXTI_BASE_ADDRESS,0x00)
#define EXTI_RTSR	EXTI_REG(EXTI_BASE_ADDRESS,0x08)
#define EXTI_FTSR	EXTI_REG(EXTI_BASE_ADDRESS,0x0C)
#define EXTI_PR		EXTI_REG(EXTI_BASE_ADDRESS,0x14)


	/* pointer to function */
#define NULL 	(void*)(0x00)

void(*function_callback0)(void) = NULL;
void(*function_callback1)(void) = NULL;

#endif
