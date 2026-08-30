#include <util/delay.h>
#include "DIO_interface.h"
#include "LED.h"
#include "BUZZER.h"
#include "_7SEGMENT.h"
#include "STD_TYPES.h"
#define F_CPU	8000000UL
u8 port_val= 0 ;
led_type LED[8] = {
     { .port = PORTA, .pin = DIO_PIN0 },
     { .port = PORTA, .pin = DIO_PIN1 },
     { .port = PORTA, .pin = DIO_PIN2 },
     { .port = PORTA, .pin = DIO_PIN3 },
     { .port = PORTA, .pin = DIO_PIN4 },
     { .port = PORTA, .pin = DIO_PIN5 },
     { .port = PORTA, .pin = DIO_PIN6 },
     { .port = PORTA, .pin = DIO_PIN7 }
 };
u8 main()
{
	DIO_SetPortDirection(PORTC ,0xFF) ;
	DIO_SetPortValue(PORTC,0x00) ;
	DIO_SetPortDirection(PORTD,0x00) ;
	DIO_SetPortValue(PORTD,0xff) ;
	for (u8 i = 0; i < 8; i++)
	  {
		 LED_Init(LED[i]);
	  }
	while(1)
	{
		 DIO_GetPortValue(PORTD,&port_val) ;
		DIO_SetPortValue(PORTA,255-port_val) ;
	}
	return 0;
}