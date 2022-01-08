#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

		/* NVIC registers */
#define NVIC_ISER0 *((unsigned int*)(0xE000E100+0x00))
#define NVIC_ISER1 *((unsigned int*)(0xE000E100+0x04))
#define NVIC_ISER2 *((unsigned int*)(0xE000E100+0x08))

#define NVIC_ICER0 *((unsigned int*)(0XE000E180+0x00))
#define NVIC_ICER1 *((unsigned int*)(0XE000E180+0x04))
#define NVIC_ICER2 *((unsigned int*)(0XE000E180+0x08))

#define NVIC_ISPR0 *((unsigned int*)(0XE000E200+0x00))
#define NVIC_ISPR1 *((unsigned int*)(0XE000E200+0x04))
#define NVIC_ISPR2 *((unsigned int*)(0XE000E200+0x08))

#define NVIC_ICPR0 *((unsigned int*)(0XE000E280+0x00))
#define NVIC_ICPR1 *((unsigned int*)(0XE000E280+0x04))
#define NVIC_ICPR2 *((unsigned int*)(0XE000E280+0x08))

#define NVIC_STIR  *((unsigned int*)(0xE000EF00))

		/* RCC registers */
#define RCC_AHB1ENR		*((unsigned int*)(0x40023800+0x30))


/* DMA registers */
//#define DMA_REG(BASE,OFFSET)	*((unsigned int*)(BASE+OFFSET))
//
//#define DMA_BASE_ADDRESS  0x40026400 /* DMA2 */
//#define DMA_BASE_ADDRESS  0x40026000 /* DMA1 */
//
//#define DMA_LISR	DMA_REG(DMA_BASE_ADDRESS,0x00)
//#define DMA_HISR	DMA_REG(DMA_BASE_ADDRESS,0x04)
//#define DMA_LIFCR	DMA_REG(DMA_BASE_ADDRESS,0x08)
//#define DMA_HIFCR	DMA_REG(DMA_BASE_ADDRESS,0x0C)
//#define DMA_S0CR	DMA_REG(DMA_BASE_ADDRESS,0x10)
//#define DMA_S0NDTR	DMA_REG(DMA_BASE_ADDRESS,0x14)
//#define DMA_S0PAR	DMA_REG(DMA_BASE_ADDRESS,0x18)
//#define DMA_S0M0AR	DMA_REG(DMA_BASE_ADDRESS,0x1C)
//#define DMA_S0M1AR	DMA_REG(DMA_BASE_ADDRESS,0x20)
//#define DMA_S0FCR	DMA_REG(DMA_BASE_ADDRESS,0x24)



typedef struct {
	unsigned int LISR;
	unsigned int HISR;
	unsigned int LIFCR;
	unsigned int HIFCR;
	unsigned int S[8][6];


}DMA_REG;

DMA_REG* DMA;


/********
 * Register nicknames to be used to access streams
 *
 * EX: DMA->S0[SxCR]
 */
#define SxCR		0
#define SxNDTR		1
#define SxPAR		2
#define SxM0AR		3
#define SxM1AR		4
#define SxFCR		5


	/* NVIC global interrupts keys */
#define DMA1_Stream0	11
#define DMA1_Stream1	12
#define DMA1_Stream2	13
#define DMA1_Stream3	14
#define DMA1_Stream4	15
#define DMA1_Stream5	16
#define DMA1_Stream6	17
#define DMA1_Stream7	47

#define DMA2_Stream0	56
#define DMA2_Stream1	57
#define DMA2_Stream2	58
#define DMA2_Stream3	59
#define DMA2_Stream4	60
#define DMA2_Stream5	68
#define DMA2_Stream6	69
#define DMA2_Stream7	70



	/* Private functions protoptypes */
/*********************************************/

void DMA_EnableClk(unsigned char peripheral_id);

	/* DMA interrupt control */
void DMA_ClearIntFlag(unsigned char interrupt_id);
unsigned char DMA_ReadIntFlag(unsigned char interrupt_id);

	/* NVIC interrupt control */
void DMA_EnableNVICInterrupt(unsigned char interrupt_id, unsigned char set_id);
void DMA_DisableNVICInterrupt(unsigned char interrupt_id, unsigned char set_id);
void DMA_SetNVICPendingFlag(unsigned char interrupt_id, unsigned char set_id);
void DMA_ClearNVICPendingFlag(unsigned char interrupt_id, unsigned char set_id);
void NVIC_GenerateInterrupt(unsigned char interrupt_id);





#endif
