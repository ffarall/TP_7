#pragma once
#include "BasicLCD.h"
#include "FTDIHandler.h"
#include "ErrLCD.h"

class HD44780LCD :
	public BasicLCD
{
public:
	HD44780LCD();
	virtual ~HD44780LCD();

	virtual bool lcdInitOk();
	virtual FT_STATUS lcdGetError();
	virtual bool lcdClear();
	virtual bool lcdClearToEOL();
	virtual BasicLCD& operator<<(const unsigned char c);
	virtual BasicLCD& operator<<(const unsigned char * c);
	virtual bool lcdMoveCursorUp();
	virtual bool lcdMoveCursorDown();
	virtual bool lcdMoveCursorRight();
	virtual bool lcdMoveCursorLeft();
	virtual bool lcdSetCursorPosition(const cursorPosition pos);
	virtual cursorPosition lcdGetCursorPosition();

protected:
	int cadd;
	ErrLCD err;	// Contains FT_STATUS
	FTDIHandler handler;

	void lcdUpdateCursor();
};

