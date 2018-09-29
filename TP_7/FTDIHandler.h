#pragma once
#include <cstdint>

class FTDIHandler
{
public:
	FTDIHandler();
	~FTDIHandler();

	//Escribe un byte al IR 
	void lcdWriteIR(uint8_t valor);
	//Escribe un byte al DR
	void lcdWriteDR(uint8_t valor); 
};

