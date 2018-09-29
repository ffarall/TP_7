#include "ErrLCD.h"


ErrLCD::ErrLCD()
{
	type = ErrType::LCD_NO_ERROR;
	description = "NO_ERROR DEFAULT";
}

ErrLCD::~ErrLCD()
{
}

void ErrLCD::set_type(ErrType type_)
{
	type = type_;
	update_description();
}

ErrType ErrLCD::get_type()
{
	return type;
}

string ErrLCD::get_description()
{
	return description;
}

FT_STATUS ErrLCD::get_status()
{
	return ftStatus;
}

void ErrLCD::update_description()
{
	switch (type)
	{
	case ErrType::LCD_NO_ERROR:
		description = "NO_ERROR DEFAULT";
		break;
	default:
		break;
	}
}
