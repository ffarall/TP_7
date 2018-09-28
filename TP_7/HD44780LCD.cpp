#include "HD44780LCD.h"



HD44780LCD::HD44780LCD(): err()
{
	try
	{
		handler = FTDIHandler();
	}
	catch (ErrType type_)
	{
		err.set_type(type_);
		err.update_description();
	}
}


HD44780LCD::~HD44780LCD()
{
}
