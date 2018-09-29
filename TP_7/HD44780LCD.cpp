#include "HD44780LCD.h"
#include "ErrLCD.h"

#define CLEAR_DISPLAY 0x01
#define SPACE_ASCII 0x20

HD44780LCD::HD44780LCD(): err()
{
	try
	{
		handler = new FTDIHandler();
		err.set_type(ErrType::LCD_NO_ERROR);
	}
	catch (ErrType type_)
	{
		err.set_type(type_);
	}


}


HD44780LCD::~HD44780LCD()
{
	delete handler;
}

bool HD44780LCD::lcdInitOk()
{
	if (err.get_type() == ErrType::LCD_NO_ERROR)
	{
		return true;
	}
	else
	{
		return false;
	}
}

FT_STATUS HD44780LCD::lcdGetError()
{
	return err.get_status();
}

bool HD44780LCD::lcdClear()
{
	handler->lcdWriteIR(CLEAR_DISPLAY);
}

bool HD44780LCD::lcdClearToEOL()
{
	try
	{
		handler->lcdWriteDR(SPACE_ASCII);
	}
	catch (ErrType type_)
	{
		err.set_type(type_);
	}
}
