#ifndef DMA_INTERFAVE_H_
#define DMA_INTERFAVE_H_


typedef struct {
	unsigned int peripheral_Id;
	unsigned char streamId;
	unsigned char channel_Id;
	unsigned int scr_address;
	unsigned int dest_address;
	unsigned char stream_priority;
	unsigned char numberOfTransfers;
	unsigned char transferItemSize;
	unsigned char flow_control;
	unsigned char transferMode; // mem to mem, p to mem, mem to p
	unsigned char interruptID;
}DmaConfig_t;


	/* peripheral Id */
#define DMA1	0x40026000
#define DMA2	0x40026400
	/*stream Id*/
#define STREAM0		0
#define STREAM1		1
#define STREAM2		2
#define STREAM3		3
#define STREAM4		4
#define STREAM5		5
#define STREAM6		6
#define STREAM7		7
	/*channel id*/
#define CHANNEL0	0
#define CHANNEL1	1
#define CHANNEL2	2
#define CHANNEL3	3
#define CHANNEL4	4
#define CHANNEL5	5
#define CHANNEL6	6
#define CHANNEL7	7
/* item size - fifo threshold */
#define _1BYTE__1_4FIFO		0x00
#define _2BYTE__1_2FIFO		0x11
#define _4BYTE__4_4FIFO		0x23

#define PERIPHERAL_MEM_INC	3

/*transfer type*/
#define SINGLE_TRANSFER		0
#define BURST_INC4		1 		/* Always use this*/
#define BURST_INC8		2
#define BURST_INC16		3

	/* tranfer type */
#define MEM_TO_MEM				2
#define PERIPHERAL_TO_MEM		0

	/*stream_priority*/
#define LOW			0U
#define MEDIUM		1U
#define HIGH		2U
#define VERY_HIGH	3U

		/* Flow controller */
#define DMA_FLOW_CONTROL			0
#define PERIPHERAL_FLOW_CONTROL		1

/* Interrupts IDs*/
#define TRANSFER_ERROR			0x01
#define HALF_TRANS_COMPLETE		0x02
#define TRANSFER_COMPLETE		0x04
#define ALL						0x07
#define NO_INT					255

	/* DMA IDs for RCC */
#define RCC_DMA1	  21
#define RCC_DMA2	  22

/* DMA interrupt sources */

				/* COMPLETE TRANSFER INTERRUPT */
#define TRANSFER_COMPLETE_S0		5
#define TRANSFER_COMPLETE_S1		11
#define TRANSFER_COMPLETE_S2		21
#define TRANSFER_COMPLETE_S3		27
#define TRANSFER_COMPLETE_S4		0x85 // 5 with MSB equals 1
#define TRANSFER_COMPLETE_S5		0x8B // 11 with MSB equals 1
#define TRANSFER_COMPLETE_S6		0x95 // 21 with MSB equals 1
#define TRANSFER_COMPLETE_S7		0x9B // 27 with MSB equals 1
				/* TRANSFER ERROR INTERRUPTS */
#define TRANSFER_ERROR_S0			3
#define TRANSFER_ERROR_S1			9
#define TRANSFER_ERROR_S2			19
#define TRANSFER_ERROR_S3			25
#define TRANSFER_ERROR_S4		0x83 // 3 with MSB equals 1
#define TRANSFER_ERROR_S5		0x89 // 9 with MSB equals 1
#define TRANSFER_ERROR_S6		0x93 // 19 with MSB equals 1
#define TRANSFER_ERROR_S7		0x99 // 25 with MSB equals 1
				/* HALF TRANSFER INTERRUPTS */
#define HALF_TRANSFER_S0		4
#define HALF_TRANSFER_S1		10
#define HALF_TRANSFER_S2		20
#define HALF_TRANSFER_S3		26
#define HALF_TRANSFER_S4		0x84 // 4 with MSB equals 1
#define HALF_TRANSFER_S5		0x8A // 10 with MSB equals 1
#define HALF_TRANSFER_S6		0x94 // 20 with MSB equals 1
#define HALF_TRANSFER_S7		0x9A // 26 with MSB equals 1

/****************************************************************/


typedef struct StatusReport{
	unsigned char fifo_error;
	unsigned char transfer_error;
	unsigned char transfer_complete;
	unsigned char half_transfer;
}StatusReport_t;



/****************************************************************/

/******************	APIs Declarations ***************************/

/******************************************************************/
void DMA_Init(unsigned char peripheral_id);
void DMA_StartTransfer(unsigned char stream_id);
StatusReport_t DMA_GetTransferState(unsigned char interrupt_id);
void DMA_SetConfigurations(DmaConfig_t* ptr);

void DMA_EnterCriticalSection(void);
void DMA_ExitCriticalSection(void);



#endif
