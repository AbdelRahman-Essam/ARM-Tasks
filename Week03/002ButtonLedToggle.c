/*
 * 002ButtonLedToggle.c
 *
 *  Created on: Nov 26, 2021
 *      Author: Abdelrahman Essam
 */


#include "stm32f407xx.h"

void delay (void)
{
	for(uint32_t i=0 ;i<500000;i++);
}

int main(void)
{
	GPIO_Handle_t Gpioled;
	Gpioled.pGPIOx = GPIOD;
	Gpioled.GPIO_PinConfig.GPIO_PinNumber =  GPIO_PIN_14;
	Gpioled.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Gpioled.GPIO_PinConfig.GPIO_PinOPType = GPIO_OPTYPE_PP;
	Gpioled.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	Gpioled.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_Handle_t Gpioled2;
	Gpioled2.pGPIOx = GPIOD;
	Gpioled2.GPIO_PinConfig.GPIO_PinNumber =  GPIO_PIN_12;
	Gpioled2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	Gpioled2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OPTYPE_PP;
	Gpioled2.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PU;
	Gpioled2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_Handle_t GpioButton;
	GpioButton.pGPIOx = GPIOA;
	GpioButton.GPIO_PinConfig.GPIO_PinNumber =  GPIO_PIN_0;
	GpioButton.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GpioButton.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&Gpioled);
	GPIO_Init(&Gpioled2);
	GPIO_Init(&GpioButton);

		while(1)
		{
			if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_0))
			{
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_14);
			delay();
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_12);
			}
		}




	return 0;
}

