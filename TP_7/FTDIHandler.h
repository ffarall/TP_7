#pragma once

#include <cstdint>

#include <windows.h>
#ifndef FTD2XX_EXPORTS
#define FTD2XX_EXPORTS
#endif

#include "ftd2xx.h"


class FTDIHandler
{
public:
	FTDIHandler();
	//Escribe un byte al IR
	void lcdWriteIR(uint8_t valor);
	//Escribe un byte al DR
	void lcdWriteDR(uint8_t valor);

	~FTDIHandler();

private:

	void lcdWriteNibble(uint8_t value);
	void set4BitsMode(void);

	FT_HANDLE deviceHandler;
};

