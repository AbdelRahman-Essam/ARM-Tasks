/*
 * stm32f407xx_spi_driver.h
 *
 *  Created on: Dec 18, 2021
 *      Author: Abdelrahman Essam
 */

#ifndef INC_STM32F407XX_SPI_H_
#define INC_STM32F407XX_SPI_H_

#include "stm32f407xx.h"

/*
 * Configuration structure for SPIx peripheral
 */
typedef struct {
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
}SPI_Config_t;

/*
 * Handle structure for SPIx peripheral
 */
typedef struct {
	SPI_RegDef_t*	pSPIx; /*!<	This holds the base address of SPIx(x:0,1,2) peripheral	>*/
	SPI_Config_t	SPIConfig;
	uint8_t			*pTxBuffer;	/* !< To store the app. Tx buffer address > */
	uint8_t			*pRxBuffer;	/* !< To store the app. Rx buffer address > */
	uint32_t		TxLen;		/* !< To store the Tx len > */
	uint32_t		RxLen;		/* !< To store the Rx len > */
	uint8_t			TxState;	/* !< To store the Tx state > */
	uint8_t			RxState;	/* !< To store the Rx len > */
}SPI_Handle_t;

/*
 * SPI Application States
 */
#define SPI_READY			0
#define SPI_BUSY_IN_RX		1
#define SPI_BUSY_IN_TX		2

/*
 * SPI Application events
 */
#define SPI_EVENT_TX_CMPLT	0
#define SPI_EVENT_RX_CMPLT	1
#define SPI_EVENT_MODF_ERR	2
#define SPI_EVENT_OVR_ERR	3
#define SPI_EVENT_CRC_ERR	4
#define SPI_EVENT_FRE_ERR	5

/*
 * @SPI_DeviceMode
 */
#define SPI_DEVICE_MODE_MASTER		1
#define SPI_DEVICE_MODE_SLAVE		0

/*
 * @SPI_BusConfig
 */
#define SPI_BUS_CONFIG_FD					1
#define SPI_BUS_CONFIG_HD					2
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY		3

/*
 * @SPI_SclkSpeed
 */
#define SPI_SCLK_SPEED_DIV2			0
#define SPI_SCLK_SPEED_DIV4			1
#define SPI_SCLK_SPEED_DIV8			2
#define SPI_SCLK_SPEED_DIV16		3
#define SPI_SCLK_SPEED_DIV32		4
#define SPI_SCLK_SPEED_DIV64		5
#define SPI_SCLK_SPEED_DIV128		6
#define SPI_SCLK_SPEED_DIV256		7

/*
 * @SPI_DFF
 */
#define SPI_DFF_8BITS		0
#define SPI_DFF_16BITS		1

/*
 * @SPI_CPOL
 */
#define SPI_CPOL_HIGH	1
#define SPI_CPOL_LOW	0

/*
 * @SPI_CPHA
 */
#define SPI_CPHA_HIGH	1
#define SPI_CPHA_LOW	0

/*
 * @SPI_SSM
 */
#define SPI_SSM_EN		1
#define SPI_SSM_DI		0

/*
 * SPI related status flag definitions
 */
#define SPI_FLAG_RXNE		(1 << SPI_SR_RXNE)
#define SPI_FLAG_TXE		(1 << SPI_SR_TXE)
#define SPI_FLAG_CHSIDE		(1 << SPI_SR_CHSIDE)
#define SPI_FLAG_UDR		(1 << SPI_SR_UDR)
#define SPI_FLAG_CRCERR		(1 << SPI_SR_CRCERR)
#define SPI_FLAG_MODF		(1 << SPI_SR_MODF)
#define SPI_FLAG_OVR		(1 << SPI_SR_OVR)
#define SPI_FLAG_BSY		(1 << SPI_SR_BSY)
#define SPI_FLAG_SRE		(1 << SPI_SR_FRE)



/**************************************************************************
 * 					APIs supported by this driver
 * For more information about these APIs check the function description
 **************************************************************************/
/*
 * Peripheral clock setup
 */
void SPI_PeriClockControl(SPI_RegDef_t* pSPIx, uint8_t enOrDi);

/*
 * Init and De-init
 */
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t* pSPIx);


/*
 * Data send and receive
 */
void SPI_SendData(SPI_RegDef_t* pSPIx, uint8_t *pTxBuffer, uint32_t len);
void SPI_ReceiveData(SPI_RegDef_t* pSPIx, uint8_t *pRxBuffer, uint32_t len);

uint8_t SPI_SendDataIT(SPI_Handle_t* pSPIHandle, uint8_t *pTxBuffer, uint32_t len);
uint8_t SPI_ReceiveDataIT(SPI_Handle_t* pSPIHandle, uint8_t *pRxBuffer, uint32_t len);

/*
 * IRQ configuration and handling
 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t enOrDi);
void SPI_IRQPriorityConfig(uint8_t IRQPriority, uint8_t IRQNumber);
void SPI_IRQHandling(SPI_Handle_t *pHandle);

/*
 * Other peripheral control APIs
 */
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t enOrDi);
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t enOrDi);
void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t enOrDi);
uint8_t SPI_GetFlagStatus(SPI_RegDef_t* pSPIx, uint32_t flag);
void SPI_ClearOVRFlag(SPI_RegDef_t* pSPIx);
void SPI_CloseTransmission(SPI_Handle_t *pSPIHandle);
void SPI_CloseReception(SPI_Handle_t *pSPIHandle);

/*
 * Application callback
 */
void SPI_ApplicationEventCallback(SPI_Handle_t *pSPIHandle, uint8_t appEvent);


#endif /* INC_STM32F407XX_SPI_H_ */