#include "keypad.h"
#include "stm32f4xx.h"
#include "uart.h"
#include <stdio.h>


#define RCC_EN			(3U << 0)

void delay(void){
	for(uint32_t i = 0 ; i < 400000 ; i++);
}

void KEYPAD(void)
{



    //Enable clock
    RCC->AHB1ENR |= RCC_EN;

	//Configure Rows (PA10 PB10 PB4 PB5)as output
	GPIOA->MODER &= ~(3U << 20);
	GPIOA->MODER |= (1U << 20);
	GPIOB->MODER &= ~(3U << 8);
	GPIOB->MODER |= (1U << 8);
	GPIOB->MODER &= ~(3U << 10);
	GPIOB->MODER |= (1U << 10);
	GPIOB->MODER &= ~(3U << 20);
	GPIOB->MODER |= (1U << 20);

	//Configure columns(PA6 PA7 PA8 PA9) as input
	GPIOA->MODER &= ~(0xFF << 12);

	//Setup Input pull up for PA6 PA7 PA8 PA9
	GPIOA->PUPDR &= ~( 0xFF << 12 );//clearing bits
	GPIOA->PUPDR |= ( 0x55 << 12 );//Setting bits


	while(1){

		char detected_key = 0;
		//Making all rows high
		GPIOA->ODR |=(1<<10);
		GPIOB->ODR |= (1 << 10) | (1 << 5) | (1 << 4);

		//Make R1 Low PA10
		GPIOA->ODR &= ~( 1 << 10 );

		//scan the columns
		//Check C1(PA8) low or high
		if(!(GPIOA->IDR & ( 1 << 8 ))){ detected_key= '3'; }
		//Check C2(PA9) low or high
		else if(!(GPIOA->IDR & ( 1 << 9 ))){ detected_key= 'A'; }
		//Check C3(PA7) low or high
		else if(!(GPIOA->IDR & ( 1 << 7 ))){ detected_key= '2'; }
		//Check C4(PA6) low or high
		else if(!(GPIOA->IDR & ( 1 << 6 ))){ detected_key= '1'; }

		//Making all rows high
		GPIOA->ODR |=(1<<10);
		GPIOB->ODR |= (1 << 10) | (1 << 5) | (1 << 4);

		//Make R2 Low PB10
		GPIOB->ODR &= ~( 1 << 10 );


		//scan the columns
		//Check C1(PA8) low or high
		if(!(GPIOA->IDR & ( 1 << 8 ))){ detected_key= '6'; }
		//Check C2(PA9) low or high
		else if(!(GPIOA->IDR & ( 1 << 9 ))){ detected_key= 'B'; }
		//Check C3(PA7) low or high
		else if(!(GPIOA->IDR & ( 1 << 7 ))){ detected_key= '5'; }
		//Check C4(PA6) low or high
		else if(!(GPIOA->IDR & ( 1 << 6 ))){ detected_key= '4'; }

		//Making all rows high
		GPIOA->ODR |=(1<<10);
		GPIOB->ODR |= (1 << 10) | (1 << 5) | (1 << 4);

		//Make R3 Low PB5
		GPIOB->ODR &= ~( 1 << 5 );


		//scan the columns
		//Check C1(PA8) low or high
		if(!(GPIOA->IDR & ( 1 << 8 ))){ detected_key= '9'; }
		//Check C2(PA9) low or high
		else if(!(GPIOA->IDR & ( 1 << 9 ))){ detected_key= 'C'; }
		//Check C3(PA7) low or high
		else if(!(GPIOA->IDR & ( 1 << 7 ))){ detected_key= '8'; }
		//Check C4(PA6) low or high
		else if(!(GPIOA->IDR & ( 1 << 6 ))){ detected_key= '7'; }


		//Making all rows high
		GPIOA->ODR |=(1<<10);
		GPIOB->ODR |= (1 << 10) | (1 << 5) | (1 << 4);
		//Make R4 Low PB4
		GPIOB->ODR &= ~( 1 << 4 );


		//scan the columns
		//Check C1(PA8) low or high
		if(!(GPIOA->IDR & ( 1 << 8 ))){ detected_key= '#'; }
		//Check C2(PA9) low or high
		else if(!(GPIOA->IDR & ( 1 << 9 ))){ detected_key= 'D'; }
		//Check C3(PA7) low or high
		else if(!(GPIOA->IDR & ( 1 << 7 ))){ detected_key= '0'; }
		//Check C4(PA6) low or high
		else if(!(GPIOA->IDR & ( 1 << 6 ))){ detected_key= '*'; }

		// If key is detected:
		if(detected_key){
			delay();
			printf("%c\r\n",detected_key);
			while (!(GPIOA->IDR & (1 << 8)) ||
				   !(GPIOA->IDR & (1 << 9)) ||
				   !(GPIOA->IDR & (1 << 7)) ||
				   !(GPIOA->IDR & (1 << 6)) );
		}
	}


}
