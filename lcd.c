/*
 * lcd.c
 *
 *  Created on: Oct 22, 2013
 *      Author: C15Nikolas.Taormina
 */
#include "lcd.h"
#include <msp430.h>

#define RS_MASK 0x40
char LCDCON;
char LCDDATA;
char LCDSEND;

void LCDinit()
{
    writeCommandNibble(0x03);

    writeCommandNibble(0x03);

    writeCommandNibble(0x03);

    writeCommandNibble(0x02);

    writeCommandByte(0x28);

    writeCommandByte(0x0C);

    writeCommandByte(0x01);

    writeCommandByte(0x06);

    writeCommandByte(0x01);

    writeCommandByte(0x02);

    SPI_send(0);
    delayMilli();
}


void LCDclear()
{
    writeCommandByte(1);
}

void writeCommandNibble(char commandNibble)
{
    LCDCON &= ~RS_MASK;
    LCD_write_4(commandNibble);
    delayMilli();
}

void writeCommandByte(char commandByte)
{
    LCDCON &= ~RS_MASK;
    LCD_write_8(commandByte);
    delayMilli();
}

void writeDataByte(char dataByte)
{
    LCDCON |= RS_MASK;
    LCD_write_8(dataByte);
    delayMilli();
}

void LCD_write_8(char byteToSend)
{
    unsigned char sendByte = byteToSend;

    sendByte &= 0xF0;

    sendByte = sendByte >> 4;               // rotate to the right 4 times

    LCD_write_4(sendByte);

    sendByte = byteToSend;

    sendByte &= 0x0F;

    LCD_write_4(sendByte);
}

void LCD_write_4(char byteToSend)
{
	unsigned char sendByte = byteToSend;

	sendByte &= 0x0F;

	sendByte |= LCDCON;

	sendByte &= 0x7f;

	SPI_send(sendByte);

	delayMilli();

	sendByte |= 0x80;

	SPI_send(sendByte);

	delayMilli();

	sendByte &= 0x7F;

	SPI_send(sendByte);

	delayMilli();
}

void SPI_send(char byteToSend)
{
    volatile char readByte;

    set_SS_lo();

    UCB0TXBUF = byteToSend;

    while(!(UCB0RXIFG & IFG2))
    {
        // wait until you've received a byte
    }

    readByte = UCB0RXBUF;

    set_SS_hi();
}

void initSPI() {

	UCB0CTL1 |= UCSWRST;

	UCB0CTL0 |= UCCKPH | UCMSB | UCMST | UCSYNC;

	UCB0CTL1 |= UCSSEL1;

	//UCB0STAT |= UCLISTEN;

	P1DIR |= BIT0;

	P1SEL |= BIT5;
	P1SEL2 |= BIT5;

	P1SEL |= BIT7;
	P1SEL2 |= BIT7;

	P1SEL |= BIT6;
	P1SEL2 |= BIT6;

	UCB0CTL1 &= ~UCSWRST;
}



void set_SS_hi(){
	P1OUT |= BIT0;
}

void set_SS_lo(){
	P1OUT &= ~BIT0;
}

void delayMilli(){
	_delay_cycles(1650);
}


void writeString(char string[]){
	unsigned int length, count = 0;



	length = getStringLength(string);

	while(count < length){
		writeDataByte(string[count]);
		count++;

	}
}
unsigned int getStringLength(char string[]){
	unsigned int i = 0;
	while(string[i] != 0){
		i++;
	}
	return i;
}

void cursorToLineOne(){
	writeCommandByte(0x02);
}

void cursorToLineTwo(){
	writeCommandByte(0xC0);
}

void scrollString(char string[], int stringLength){
	int iterator = 0;
	int helperChar = string[0];

	for(iterator; iterator < stringLength; iterator++){
		string[iterator] = string[iterator + 1];
	}
	string[stringLength - 1] = helperChar;

}

