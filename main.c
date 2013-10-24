#include <msp430.h> 
#include "lcd.h"

/*
 * main.c
 */


void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    char stringTop[] = "ECE382 is my favorite class!";
    char stringBottom[] = "ECE321 is not my favorite class!";

    initSPI();

    LCDinit();

    LCDclear();



    while(1){



    cursorToLineOne();

    writeString(stringTop);

    scrollString(stringTop, getStringLength(stringTop));

    cursorToLineTwo();

    writeString(stringBottom);

    scrollString(stringBottom, getStringLength(stringBottom));

    }

	
	while(1){}
}
