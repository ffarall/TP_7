#include "HD44780LCD.h"

#define CLEAR_DISPLAY 0x01
#define SPACE_ASCII 0x20
#define SECOND_LINE_ADDRESS 0x40
#define SET_DDRAM_ADDRESS(x) ((x) | (0x80))		// To the address x, makes sure bit 7 is 1, because instructio "Set DDRAM address" indicates it.

HD44780LCD::HD44780LCD(): err()
{
	try
	{
		handler = new FTDIHandler();			// Trying to create a FTDIHandler object. This can throw an ErrType exception.
		err.set_type(ErrType::LCD_NO_ERROR);	// Since there's no errors
		lcdUpdateCursor(0);								// Initialization of cursor position pointer.
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
// This function is meant to be called after creating an HD44780LCD object, to check if everything is ok.
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
// Getting error if there was one.
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
		for (int i = (cadd & 0x0F); i < 16; i++)		// What matters is the lsb of cadd, because any of the lines is being cleared.
		{
			handler->lcdWriteDR(SPACE_ASCII);
		}

		// Now the cursor has to be put back to its original position.
		if (cadd < 16)
		{
			handler->lcdWriteIR(SET_DDRAM_ADDRESS(cadd));
		}
		else
		{
			handler->lcdWriteIR(SET_DDRAM_ADDRESS((cadd & 0x0F) + 0x40));	// If the cursor is on the second line, DDRAM address has to be 0x4_ and not 0x2_.
		}
		return true;
	}
	catch (ErrType type_)
	{
		err.set_type(type_);
		return false;
	}
}

BasicLCD & HD44780LCD::operator<<(const unsigned char c)
{
	// TODO: insert return statement here
}

BasicLCD & HD44780LCD::operator<<(const unsigned char * c)
{
	// TODO: insert return statement here
}

bool HD44780LCD::lcdMoveCursorUp()
{
	try
	{
		handler->lcdWriteIR(SET_DDRAM_ADDRESS(cadd & 0x0F));		// Cursor goes to position in the first line, in whichever column it was before.
		lcdUpdateCursor(cadd & 0x0F);
		return true;
	}
	catch (ErrType type_)
	{
		err.set_type(type_);
		return false;
	}
}

bool HD44780LCD::lcdMoveCursorDown()
{
	try
	{
		handler->lcdWriteIR(SET_DDRAM_ADDRESS(cadd & 0x4F));		// Cursor goes to position in the second line, in whichever column it was before.
		lcdUpdateCursor(cadd & 0x1F);
		return true;
	}
	catch (ErrType type_)
	{
		err.set_type(type_);
		return false;
	}
}

bool HD44780LCD::lcdMoveCursorRight()
{
	if (cadd < 32)	// As long as the cursor is not on the last position...
	{
		try
		{
			handler->lcdWriteIR(SET_DDRAM_ADDRESS(cadd + 1));		
			lcdUpdateCursor(cadd + 1);
			return true;
		}
		catch (ErrType type_)
		{
			err.set_type(type_);
			return false;
		}
	}
}

bool HD44780LCD::lcdMoveCursorLeft()
{
	if (cadd > 0)	// As long as the cursor is not on the fisrt position...
	{
		try
		{
			handler->lcdWriteIR(SET_DDRAM_ADDRESS(cadd - 1));
			lcdUpdateCursor(cadd - 1);
			return true;
		}
		catch (ErrType type_)
		{
			err.set_type(type_);
			return false;
		}
	}
}

bool HD44780LCD::lcdSetCursorPosition(const cursorPosition pos)
{
	bool error = false;
	if (pos.row == 2 && cadd <= 16) // si me piden segunda fila y estoy en primera
	{
		if (!lcdMoveCursorDown())
		{
			error = true;
		}
	}
	else if (pos.row == 1 && cadd > 16 ) // lo contrario
	{
		if (!lcdMoveCursorUp())
		{
			error = true;
		}
	}
	if (pos.column < cadd % 17 && !error) // si debo moverme a la izquierda
	{
		for (int i = 0; i < cadd % 17 - pos.column && !error; i++)
		{
			if (!lcdMoveCursorLeft())
			{
				error = true;
			}
		}
	}
	else if( pos.column > cadd % 17 && !error) // a la derecha
	{
		for (int i = 0; i < pos.column - cadd % 17 && !error; i++)
		{
			if (!lcdMoveCursorRight())
			{
				error = true;
			}
		}
	}
	return !error;
}

cursorPosition HD44780LCD::lcdGetCursorPosition()
{
	cursorPosition temp; //esto esta hecho teniendo en cuenta que cadd va entre 1 y 32 no entre 0 y 31!!!!
	temp.row = cadd > 16 ? 2 : 1;
	temp.column = temp.row == 1 ? cadd : cadd - 16; //si cadd esta en la primera fila entonces cadd me dice fila, sino le resto 16 para corregir
	return temp;
}

void HD44780LCD::lcdUpdateCursor(int newCadd)
{
	cadd = newCadd;
}
