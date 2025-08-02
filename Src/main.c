#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>
#include "uart.h"
#include "Keypad.h"



int main(void)
{
	uart2_tx_init();

	KEYPAD();

	while(1)
	{

	}
}












