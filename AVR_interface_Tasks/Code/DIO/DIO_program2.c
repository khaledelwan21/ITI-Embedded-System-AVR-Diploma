#include <util/delay.h>
#include "DIO_interface.h"
#include "LED.h"
#include "BUZZER.h"
#include "_7SEGMENT.h"
#include "STD_TYPES.h"
#define F_CPU	8000000UL
u8 button1_status,button2_status ;
u8 i =0 ;
static u8 button1_prev = 1, button2_prev = 1;
seg_type seg1={
	 .port = PORTC,
	 .type=COMMON_CATHOUDE } ;
int main()
{
	DIO_SetPortDirection(PORTA ,0xFF) ;
	DIO_SetPinDirection(PORTD,DIO_PIN7, DIO_INPUT) ;
	DIO_SetPin_PullUp(PORTD,DIO_PIN7,PullUp) ;
	DIO_SetPinDirection(PORTD,DIO_PIN6, DIO_INPUT) ;
	DIO_SetPin_PullUp(PORTD,DIO_PIN6,PullUp) ;
	DIO_SetPortValue(PORTC,seven_seg[0]) ;
	SEG_Init(seg1) ;
	while(1)
	{
		DIO_GetPinValue(PORTD, DIO_PIN7, &button1_status);
		DIO_GetPinValue(PORTD, DIO_PIN6, &button2_status);
		if (button1_status == 0 && button1_prev == 1) {
		    if (i == 0) i = 9; else i--;
		    DIO_SetPortValue(PORTC, seven_seg[i]);
		}
		if (button2_status == 0 && button2_prev == 1) {
		    if (i == 9) i = 0; else i++;
		    DIO_SetPortValue(PORTC, seven_seg[i]);
		}
		button1_prev = button1_status;
		button2_prev = button2_status;
	}
	return 0;
}