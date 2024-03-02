/*
 * mini_project4.c
 * By: Amr Mohamed Yousef
 * Diploma Number: 83
 * Facebook Name: Amr Mohamed
 * ======================================================================================================================================
 */
#include "icu.h"
#include "lcd.h"
#include <avr/interrupt.h>
#include "ultrasonic.h"

int main(void)
{
	uint16 dist;
	sei();
	LCD_init();
	Ultrasonic_init();
	LCD_displayString("Distance = ");
	while(1)
	{
		dist = Ultrasonic_readDistance();
		LCD_moveCursor(0,11);
		if(dist >= 100)
		{
			LCD_intgerToString(dist);
		}
		else
		{
			LCD_intgerToString(dist);
			LCD_displayCharacter(' ');
		}
		LCD_moveCursor(0,14);
		LCD_displayString("cm");
	}
	return 0;
}
