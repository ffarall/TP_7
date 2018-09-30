#pragma once

#include <cstdint>

#include <windows.h>
#ifndef FTD2XX_EXPORTS
#define FTD2XX_EXPORTS
#endif

#include "ftd2xx.h"

#define ENABLE_0 0xFE //este tengo que hacer un and para usarlo 
#define ENABLE_1 0x01 // este lo uso con or
#define RS_DR 0x02 // se usa con or
#define RS_IR 0xFD // se usa con and

#define BITMODE8 0x30
#define BITMODE4 0x20 
#define LINES2AND5x8 0x08
#define DIPLAYONOFF 0x0C
#define CLEAR 0x01
#define ENTRYMODE 0x06
#define RETHOME 0x02

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

