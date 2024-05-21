/*
 * MGPIO_Program.c
 *
 *  Created on: Apr 22, 2024
 *      Author: Ibrahim Refaey
 */


/************************************************************************/
/*							FILES INCLUSIONS							*/
/************************************************************************/
/*******************************LIB**************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"



/*******************************MCAL*************************************/
#include "MGPIO_Interface.h"
#include "MGPIO_Config.h"

#include "MGPIO_Private.h"



/**************************Functions Definitions***********************/

void MGPIO_voidSetPinMode(u8 copyu8Port, u8 copyu8Pin, u8 copyu8Mode)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Do Nothing*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Do Nothing*/
	}

	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			GPIOA->MODER &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOA->MODER |= (copyu8Mode<<(copyu8Pin *2));
			break;

		case GPIO_PORTB:
			GPIOB->MODER &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOB->MODER |= (copyu8Mode<<(copyu8Pin *2));
			break;

		case GPIO_PORTC:
			GPIOC->MODER &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOC->MODER |= (copyu8Mode<<(copyu8Pin *2));
			break;

		default:
			break;
		}
	}
}

void MGPIO_voidSetPinOutputMode(u8 copyu8Port, u8 copyu8Pin, u8 copyu8OutputMode , u8 copyu8Speed)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Do Nothing*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Do Nothing*/
	}

	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			/*Set speed*/
			GPIOA->OSPEEDR &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOA->OSPEEDR |= (copyu8Speed<<(copyu8Pin *2));

			/*Set pin output mode*/
			GPIOA->OTYPER &= ~(ONE_BIT_MASK <<(copyu8Pin));
			GPIOA->OTYPER |= (copyu8OutputMode<<(copyu8Pin));
			break;

		case GPIO_PORTB:
			GPIOB->OSPEEDR &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOB->OSPEEDR |= (copyu8Speed<<(copyu8Pin *2));

			GPIOB->OTYPER &= ~(ONE_BIT_MASK <<(copyu8Pin));
			GPIOB->OTYPER |= (copyu8OutputMode<<(copyu8Pin));
			break;

		case GPIO_PORTC:
			GPIOC->OSPEEDR &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOC->OSPEEDR |= (copyu8Speed<<(copyu8Pin *2));

			GPIOC->OTYPER &= ~(ONE_BIT_MASK <<(copyu8Pin));
			GPIOC->OTYPER |= (copyu8OutputMode<<(copyu8Pin));
			break;

		default:
			break;
		}
	}

}

void MGPIO_voidSetPinInputMode(u8 copyu8Port, u8 copyu8Pin, u8 copyu8InputMode)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Do Nothing*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Do Nothing*/
	}

	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			GPIOA->PUPDR &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOA->PUPDR |= (copyu8InputMode<<(copyu8Pin *2));
			break;

		case GPIO_PORTB:
			GPIOB->PUPDR &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOB->PUPDR |= (copyu8InputMode<<(copyu8Pin *2));
			break;

		case GPIO_PORTC:
			GPIOC->PUPDR &= ~(TWO_BIT_MASK <<(copyu8Pin *2));
			GPIOC->PUPDR |= (copyu8InputMode<<(copyu8Pin *2));
			break;

		default:
			break;
		}
	}
}

void MGPIO_voidSetPinValue(u8 copyu8Port, u8 copyu8Pin, u8 copyu8Output)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Do Nothing*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Do Nothing*/
	}

	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			switch(copyu8Output)
			{
			case GPIO_PIN_HIGH:
				SET_BIT(GPIOA->ODR , copyu8Pin);
				break;

			case GPIO_PIN_LOW:
				CLR_BIT(GPIOA->ODR , copyu8Pin);
				break;

			default:
				break;
			}
			break;

			case GPIO_PORTB:
				switch(copyu8Output)
				{
				case GPIO_PIN_HIGH:
					SET_BIT(GPIOB->ODR , copyu8Pin);
					break;

				case GPIO_PIN_LOW:
					CLR_BIT(GPIOB->ODR , copyu8Pin);
					break;

				default:
					break;
				}
				break;

				case GPIO_PORTC:
					switch(copyu8Output)
					{
					case GPIO_PIN_HIGH:
						SET_BIT(GPIOC->ODR , copyu8Pin);
						break;

					case GPIO_PIN_LOW:
						CLR_BIT(GPIOC->ODR , copyu8Pin);
						break;

					default:
						break;
					}
					break;

					default:
						break;
		}
	}
}

void MGPIO_voidGetPinValue(u8 copyu8Port, u8 copyu8Pin, u8 *pu8Return)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Do Nothing*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Do Nothing*/
	}

	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			*pu8Return = GET_BIT(GPIOA->IDR ,copyu8Pin);
			break;

		case GPIO_PORTB:
			*pu8Return = GET_BIT(GPIOB->IDR ,copyu8Pin);
			break;

		case GPIO_PORTC:
			*pu8Return = GET_BIT(GPIOC->IDR ,copyu8Pin);
			break;

		default:
			break;
		}
	}
}

void MGPIO_voidSetResetPin(u8 copyu8Port, u8 copyu8Pin, u8 copyu8SetResetValue)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Do Nothing*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Do Nothing*/
	}

	else
	{
		switch(copyu8Port)
		{
		case GPIO_PORTA:
			switch(copyu8SetResetValue)
			{
			case GPIO_SET:
				GPIOA->BSRR = (1 <<copyu8Pin);
				break;

			case GPIO_RESET:
				GPIOA->BSRR = (1 <<(copyu8Pin +16));
				break;

			default:
				break;
			}
			break;

			case GPIO_PORTB:
				switch(copyu8SetResetValue)
				{
				case GPIO_SET:
					GPIOB->BSRR = (1 <<copyu8Pin);
					break;

				case GPIO_RESET:
					GPIOB->BSRR = (1 <<(copyu8Pin +16));
					break;

				default:
					break;
				}
				break;

				case GPIO_PORTC:
					switch(copyu8SetResetValue)
					{
					case GPIO_SET:
						GPIOC->BSRR = (1 <<copyu8Pin);
						break;

					case GPIO_RESET:
						GPIOC->BSRR = (1 <<(copyu8Pin +16));
						break;

					default:
						break;
					}
					break;

					default:
						break;
		}
	}
}





