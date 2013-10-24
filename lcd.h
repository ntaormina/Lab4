/*
 * lcd.h
 *
 *  Created on: Oct 22, 2013
 *      Author: C15Nikolas.Taormina
 */

#ifndef LCD_H_
#define LCD_H_

void initSPI();

void LCDinit();

void LCDclear();

void cursorToLineTwo();

void cursorToLineOne();

void writeChar(char asciiChar);

void writeString(char * string);

void scrollString(char * string1, char * string2);

void set_SS_hi();

void set_SS_lo();


#endif /* LCD_H_ */
