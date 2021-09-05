#include "Board_LED.h"
#include <stdint.h>
#include "Board_Buttons.h"




int main(void)
{
	LED_Initialize();
	Buttons_Initialize();
	while(1)
	{
		if(Buttons_GetState() == 1)
		{
			LED_On(0);
			LED_On(1);
			LED_On(2);
			LED_On(3);
		}
		else
		{
			LED_Off(0);
			LED_Off(1);
			LED_Off(2);
			LED_Off(3);
		}
	

		
	}
}


