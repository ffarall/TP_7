#pragma once
#include <iostream>

using namespace std;

enum class ErrType{ LCD_NO_ERROR };

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

