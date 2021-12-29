/***************************************
 * 				GPIO_Private.h
 * contains private functions for this module
 *
 * Author: Farouk
 *
 * Date: 3-18-2021
 *
 */


#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H



#define RCC_AHB1ENR   *((unsigned int*)(0x40023800+0x30))


#define NUMBER_OF_PORTS		2
#define NUMBER_OF_GPIO_REG	10

/**********
 * PORT_ID: Base address
 
 * REG_ID: offset of registers
 
 * Return the definition of the register
*/
#define GPIO_REG(PORT_ID,REG_ID) 	((unsigned int*)(PORT_ID+REG_ID))




/* Register Definition of PortA */
#define GPIOA_BASE_ADDRESS 0x40020000

#define GPIOA_MODER 	GPIO_REG(GPIOA_BASE_ADDRESS,0x00))
#define GPIOA_OTYPER 	GPIO_REG(GPIOA_BASE_ADDRESS,0x04))
#define GPIOA_OSPEEDR 	GPIO_REG(GPIOA_BASE_ADDRESS,0x08))
#define GPIOA_PUPDR		GPIO_REG(GPIOA_BASE_ADDRESS,0x0C))
#define GPIOA_IDR		GPIO_REG(GPIOA_BASE_ADDRESS,0x10))
#define GPIOA_ODR		GPIO_REG(GPIOA_BASE_ADDRESS,0x14))
#define GPIOA_BSRR		GPIO_REG(GPIOA_BASE_ADDRESS,0x18))
#define GPIOA_LCKR		GPIO_REG(GPIOA_BASE_ADDRESS,0x1C))
#define GPIOA_AFRL		GPIO_REG(GPIOA_BASE_ADDRESS,0x20))
#define GPIOA_AFRR		GPIO_REG(GPIOA_BASE_ADDRESS,0x24))


/* Register Definition of PortB */
#define GPIOB_BASE_ADDRESS 0x40020400 

#define GPIOB_MODER 	GPIO_REG(GPIOB_BASE_ADDRESS,0x00))
#define GPIOB_OTYPER 	GPIO_REG(GPIOB_BASE_ADDRESS,0x04))
#define GPIOB_OSPEEDR 	GPIO_REG(GPIOB_BASE_ADDRESS,0x08))
#define GPIOB_PUPDR		GPIO_REG(GPIOB_BASE_ADDRESS,0x0C))
#define GPIOB_IDR		GPIO_REG(GPIOB_BASE_ADDRESS,0x10))
#define GPIOB_ODR		GPIO_REG(GPIOB_BASE_ADDRESS,0x14))
#define GPIOB_BSRR		GPIO_REG(GPIOB_BASE_ADDRESS,0x18))
#define GPIOB_LCKR		GPIO_REG(GPIOB_BASE_ADDRESS,0x1C))
#define GPIOB_AFRL		GPIO_REG(GPIOB_BASE_ADDRESS,0x20))
#define GPIOB_AFRR		GPIO_REG(GPIOB_BASE_ADDRESS,0x24))







#endif
