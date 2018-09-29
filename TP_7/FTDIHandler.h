#pragma once

#define FTD2XX_EXPORTS
#include "ftd2xx.h"

#define ENABLE_0 0xFE //este tengo que hacer un and para usarlo 
#define ENABLE_1 0x01 // este lo uso con or
#define RS_DR 0x02 // se usa con or
#define RS_IR 0xFD // se usa con and

typedef BYTE unsigned char;

class FTDIHandler
{
public:
	FTDIHandler();
	//Escribe un byte al IR
	void lcdWriteIR( BYTE valor );
	//Escribe un byte al DR
	void lcdWriteDR( BYTE valor );

	~FTDIHandler();

private:

	void lcdWriteNibble( BYTE value);
	bool set4BitsMode(void);

	FT_HANDLE deviceHandler;
};

