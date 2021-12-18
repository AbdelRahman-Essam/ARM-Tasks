/*
 * stm32f407xx_rcc_driver.h
 *
 *  Created on: Dec 18, 2021
 *      Author: Abdelrahman Essam
 */

#ifndef INC_STM32F407XX_RCC_H_
#define INC_STM32F407XX_RCC_H_

#include "stm32f407xx.h"


uint32_t RCC_GetPCLK1Value(void);
uint32_t RCC_GetPCLK2Value(void);
uint32_t RCC_GetPLLOutputClock(void);

#endif /* INC_STM32F407XX_RCC_H_ */
