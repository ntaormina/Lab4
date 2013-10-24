#include <msp430.h> 
#include "lcd.h"

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    char stringTop[] = "ECE382 is my favorite class!";
    char stringBottom[] = "ECE321 is not my favorite class!";
	
	while(1){}
}
