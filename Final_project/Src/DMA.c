/********* DMA Driver ****************
 *
 *  Created on: Jan 1, 2022
 *      Author: Farouk
 *
 *************************************
 *	Driver Capabilities
 *
 *	- Select between the 2 available DMAs (DMA1-DMA2)
 *
 *	- Availability to choose any channels to work on
 *
 *	- Availability to configure more than one channel (extend the array)
 *
 *	- Supported interrupts for all the streams (Transfer complete interrupt)
 *
 *	- APIs to check transmission status (completed or not"error")
 *
 *	- Only transfer complete interrupt is enabled
 *
 */



#include "DMA_Interface.h"
#include "DMA_Private.h"
#include "DMA_Config.h"

#include "GPIO_Interface.h"






void DMA_SetConfigurations(DmaConfig_t* ptr)
{
	// clear all interrupt flags
	DMA->LIFCR = 0xFF;
	DMA->HIFCR = 0xFF;


	DMA = (DMA_REG*)ptr->peripheral_Id;
	// set peripheral address
	DMA->S[ptr->streamId][SxPAR] = ptr->scr_address;
	// set memory address
	DMA->S[ptr->streamId][SxM0AR] = ptr->dest_address;
	// config total number of items to be sent
	DMA->S[ptr->streamId][SxNDTR] = ptr->numberOfTransfers;

	DMA->S[ptr->streamId][SxCR] = (ptr->channel_Id<<25)|(ptr->stream_priority<<16)
				|(ptr->transferMode<<6)|((ptr->transferItemSize>>4)<<13)
				|((ptr->transferItemSize>>4)<<11)|(BURST_INC4<<21)|(BURST_INC4<<23)
				|(ptr->flow_control<<5);


	if(ptr->interruptID != NO_INT)
	{
		DMA->S[ptr->streamId][SxCR] |= (ptr->interruptID<<2); // enable interrupt
	}


		/* use FIFO - Burst mode */
	if(ptr->numberOfTransfers > 1) {
		DMA->S[ptr->streamId][SxCR] |= (PERIPHERAL_MEM_INC<<9);
		DMA->S[ptr->streamId][SxFCR] = (1<<2)|((ptr->transferItemSize&0x0f)<<0);
	}
}


/*
 * General init of DMA (DMA clock, DMA NVIC interrupt)
 */
void DMA_Init(unsigned char peripheral_id)
{
	if(peripheral_id == RCC_DMA1)
	{
			/* Enable interrupts from NVIC */
		DMA_EnableNVICInterrupt(DMA1_Stream0,0);
		DMA_EnableNVICInterrupt(DMA1_Stream1,0);
		DMA_EnableNVICInterrupt(DMA1_Stream2,0);
		DMA_EnableNVICInterrupt(DMA1_Stream3,0);
		DMA_EnableNVICInterrupt(DMA1_Stream4,0);
		DMA_EnableNVICInterrupt(DMA1_Stream5,0);
		DMA_EnableNVICInterrupt(DMA1_Stream6,0);
		DMA_EnableNVICInterrupt(DMA1_Stream7,1);

	}
	else
	{
		/* Enable interrupts from NVIC */
		DMA_EnableNVICInterrupt(DMA2_Stream0,1);
		DMA_EnableNVICInterrupt(DMA2_Stream1,1);
		DMA_EnableNVICInterrupt(DMA2_Stream2,1);
		DMA_EnableNVICInterrupt(DMA2_Stream3,1);
		DMA_EnableNVICInterrupt(DMA2_Stream4,1);
		DMA_EnableNVICInterrupt(DMA2_Stream5,2);
		DMA_EnableNVICInterrupt(DMA2_Stream6,2);
		DMA_EnableNVICInterrupt(DMA2_Stream7,2);
	}


	/* Enable RCC clk selected DMA */
	DMA_EnableClk(peripheral_id);
}


void DMA_StartTransfer(unsigned char stream_id)
{
	// enable the dma to operate according to the predefined configurations
	DMA->S[stream_id][SxCR] |= 1;
}


void DMA_EnterCriticalSection(void)
{
	DMA->S[0][SxCR] &= ~(1<<4);
	DMA->S[1][SxCR] &= ~(1<<4);
	DMA->S[2][SxCR] &= ~(1<<4);
	DMA->S[3][SxCR] &= ~(1<<4);
	DMA->S[4][SxCR] &= ~(1<<4);
	DMA->S[5][SxCR] &= ~(1<<4);
	DMA->S[6][SxCR] &= ~(1<<4);
	DMA->S[7][SxCR] &= ~(1<<4);
}


void DMA_ExitCriticalSection(void)
{
	DMA->S[0][SxCR] |= (1<<4);
	DMA->S[1][SxCR] |= (1<<4);
	DMA->S[2][SxCR] |= (1<<4);
	DMA->S[3][SxCR] |= (1<<4);
	DMA->S[4][SxCR] |= (1<<4);
	DMA->S[5][SxCR] |= (1<<4);
	DMA->S[6][SxCR] |= (1<<4);
	DMA->S[7][SxCR] |= (1<<4);
}


/***** Get the status of transmission (completed - not completed(Error))
 *
 * args: void
 *
 * return: status(unsigned char)
 * 		1 --> transmission completed
 * 		0 --> still running or Error
 *
 * EX: DMA_GetTransferState(TRANSFER_COMPLETE_S0);
 */
StatusReport_t DMA_GetTransferState(unsigned char interrupt_id)
{
	StatusReport_t report;
	report.half_transfer = DMA_ReadIntFlag(HALF_TRANSFER_S5);
	report.transfer_complete = DMA_ReadIntFlag(TRANSFER_COMPLETE_S5);
	report.transfer_error = DMA_ReadIntFlag(TRANSFER_ERROR_S5);

	return report;

}

/********************************************************************/

/******************   PRIVATE FUNCTIONS   ***************************/

/********************************************************************/









unsigned char DMA_ReadIntFlag(unsigned char interrupt_id){

	if((interrupt_id &0x80) == 0)
	{
		// transfer complete interrupt
		return (DMA->LISR & (1<<interrupt_id))>> interrupt_id;
	}
	else
	{
		interrupt_id = interrupt_id & (0x7f);
		return (DMA->HISR & (1<<interrupt_id))>> interrupt_id;
	}
}



void DMA_ClearIntFlag(unsigned char interrupt_id){

	if((interrupt_id & 0x80) == 0)
		DMA->LIFCR |= (1<<interrupt_id); // transfer complete interrupt
	else
		DMA->HIFCR |= (1<<(interrupt_id & 0x7F));
}


void DMA_EnableClk(unsigned char peripheral_id)
{
	RCC_AHB1ENR |= 1<<peripheral_id;
}




/*
***		NVIC APIs (set/clear interrupt - set/clear pending flag - generate SW interrupt)
 */


/******* Enable global interrupt key from NVIC with interrupt ID
 * args:
 * 		interrupt_id(uint8): interrupt id in datasheet
 *
 * 		set_id(uint8): index of register contains this interrupt (NVIC_ISER0 -> 0)
 *
 * return: void
 */
void DMA_EnableNVICInterrupt(unsigned char interrupt_id, unsigned char set_id)
{
	switch(set_id)
	{
		case 0:
			NVIC_ISER0 |= (1<< (interrupt_id-32*set_id));
			break;
		case 1:
			NVIC_ISER1 |= (1<< (interrupt_id-32*set_id));
			break;
		case 2:
			NVIC_ISER2 |= (1<< (interrupt_id-32*set_id));
			break;
	}

}

void DMA_DisableNVICInterrupt(unsigned char interrupt_id, unsigned char set_id)
{
	switch(set_id)
	{
		case 0:
			NVIC_ICER0 |= (1<< (interrupt_id-32*set_id));
			break;
		case 1:
			NVIC_ICER1 |= (1<< (interrupt_id-32*set_id));
			break;
		case 2:
			NVIC_ICER2 |= (1<< (interrupt_id-32*set_id));
			break;
	}
}

void DMA_SetNVICPendingFlag(unsigned char interrupt_id, unsigned char set_id)
{
	switch(set_id)
	{
		case 0:
			NVIC_ISPR0 |= (1<< (interrupt_id-32*set_id));
			break;
		case 1:
			NVIC_ISPR1 |= (1<< (interrupt_id-32*set_id));
			break;
		case 2:
			NVIC_ISPR2 |= (1<< (interrupt_id-32*set_id));
			break;
	}
}


void DMA_ClearNVICPendingFlag(unsigned char interrupt_id, unsigned char set_id)
{

	switch(set_id)
	{
		case 0:
			NVIC_ICPR0 |= (1<< (interrupt_id-32*set_id));
			break;
		case 1:
			NVIC_ICPR1 |= (1<< (interrupt_id-32*set_id));
			break;
		case 2:
			NVIC_ICPR2 |= (1<< (interrupt_id-32*set_id));
			break;
	}
}


void NVIC_GenerateInterrupt(unsigned char interrupt_id)
{
	NVIC_STIR = interrupt_id;
}





extern void App_TransferNotification(void);

void DMA2_Stream5_IRQHandler(void) {

	if (DMA_ReadIntFlag(TRANSFER_COMPLETE_S5))
	{
		App_TransferNotification();
		GPIO_Init(PORTA,PIN0,OUTPUT_PUSHPULL);
		GPIO_WritePin(PORTA, PIN0, 1);
		DMA_ClearIntFlag(TRANSFER_COMPLETE_S5);

	}
	else if (DMA_ReadIntFlag(TRANSFER_ERROR_S5))
	{


		DMA_ClearIntFlag(TRANSFER_ERROR_S5);
	}
	else if (DMA_ReadIntFlag(HALF_TRANSFER_S5))
	{
		GPIO_Init(PORTA, PIN1, OUTPUT_PUSHPULL);
		GPIO_WritePin(PORTA, PIN1, 1);

		DMA_ClearIntFlag(HALF_TRANSFER_S5);
	}
	else
	{
		// do nothing
	}



}


