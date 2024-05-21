#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"


int y = 0 ; 
int k ; 


void main(void)
{
	//initaialize rcc ,configure port A

	MRCC_voidInit();
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOA);

	//initialize pina0 output high

	MGPIO_voidSetPinMode(GPIO_PORTA,0,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTA,1,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTA,2,GPIO_OUTPUT);

	MGPIO_voidSetPinOutputMode(GPIO_PORTA,0,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,1,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,2,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	
	




	while(1)
	{
		MGPIO_voidSetPinValue(GPIO_PORTA,0,GPIO_PIN_HIGH);
		for(u16 i=0;i<1000;i++)
		{
			asm("NOP");
		}
		MGPIO_voidSetPinValue(GPIO_PORTA,1,GPIO_PIN_HIGH);
		for(u16 i=0;i<10000;i++)
		{
			asm("NOP");
		}
		MGPIO_voidSetPinValue(GPIO_PORTA,2,GPIO_PIN_HIGH);
		for(u16 i=0;i<16000;i++)
		{
			asm("NOP");
		}


	}
}
