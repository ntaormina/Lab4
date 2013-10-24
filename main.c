#include <msp430.h> 
#include "lcd.h"
#include "buttons/button.h"

/*
 * main.c
 */


void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    char stringTop[] = "ECE382 is my favorite class!";
    char stringBottom[] = "ECE321 is not my favorite class!";
    char message[] = "Message?";
    char press[] = "Press123";
    char button1[] = "You're number 1!";
    char button2[] = "You're number 2!";
    char button3[] = "You're number 3!";

    initSPI();

    LCDinit();

    LCDclear();

    cursorToLineOne();

    writeString(message);

    cursorToLineTwo();

    writeString(press);


    configureP1PinAsButton(BIT1|BIT2|BIT3);         // configure pins 1, 2, and 3 as buttons

        P1DIR |= BIT0|BIT6;                             // set launchpad LEDs to output

        while (1) {
            char buttons[] = {BIT1, BIT2, BIT3};
            char pressedButton = pollP1Buttons(buttons, 3);

            switch (pressedButton) {
                case BIT1:
                	 while(1){



                	    cursorToLineOne();

                	    writeString(stringTop);

                	    scrollString(stringTop, getStringLength(stringTop));

                	    cursorToLineTwo();

                	    writeString(button1);

                	    scrollString(button1, getStringLength(button1));

                	    }
                    break;
                case BIT2:
                	 while(1){



                	    cursorToLineOne();

                	    writeString(stringTop);

                	    scrollString(stringTop, getStringLength(stringTop));

                	    cursorToLineTwo();

                	    writeString(button2);

                	    scrollString(button2, getStringLength(button2));

                	    }
                    break;
                case BIT3:
                	 while(1){



                	    cursorToLineOne();

                	    writeString(stringTop);

                	    scrollString(stringTop, getStringLength(stringTop));

                	    cursorToLineTwo();

                	    writeString(button3);

                	    scrollString(button3, getStringLength(button3));

                	    }
                    P1OUT ^= BIT0|BIT6;
                    waitForP1ButtonRelease(BIT3);
                    break;
            }
        }


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
