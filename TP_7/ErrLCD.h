#pragma once
#include <iostream>

using namespace std;

enum class ErrType{};

class ErrLCD
{
public:
	ErrLCD();
	~ErrLCD();

	void set_type(ErrType type_);
	ErrType get_type();
	string get_description();

	void update_description();	// Sets description corresponding to type.

private:
	ErrType type;
	string description;
};

