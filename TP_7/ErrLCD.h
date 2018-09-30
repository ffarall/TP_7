#pragma once
#include <iostream>

#include <windows.h>
#ifndef FTD2XX_EXPORTS
#define FTD2XX_EXPORTS
#endif
#include "ftd2xx.h"

using namespace std;

enum class ErrType{ LCD_NO_ERROR , LCD_CHAGE_MODE_ERROR , LCD_SETTING_ERROR , LCD_NOT_FOUND , LCD_NO_ESCRIBE };

class ErrLCD
{
public:
	ErrLCD();
	~ErrLCD();

	void set_type(ErrType type_);
	ErrType get_type();
	string get_description();
	FT_STATUS get_status();


private:
	ErrType type;
	string description;
	FT_STATUS ftStatus;

	void update_description();	// Sets description corresponding to type.
};

