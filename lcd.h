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

void writeString(char string[]);

void scrollString(char string1[], int stringLength);

void set_SS_hi();

void set_SS_lo();

void writeCommandNibble(char commandNibble);

void writeCommandByte(char commandByte);

void writeDataByte(char dataByte);

void LCD_write_8(char byteToSend);

void LCD_write_4(char byteToSend);

void SPI_send(char byteToSend);

void delayMilli();

unsigned int getStringLength(char string[]);


#endif /* LCD_H_ */
