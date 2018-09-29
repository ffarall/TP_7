#include "FTDIHandler.h"
#include <chrono>
#include <windows.h>

#define CONNECTING_TIME 5 //en segundos

FTDIHandler::FTDIHandler()
{
	FT_STATUS status = !FT_OK;
	DWORD sizeSent = 0;

	/*The display has a settling time after the physical connection so the attempt to connect will be done for a few seconds*/
	std::chrono::seconds MaxTime(CONNECTING_TIME);

	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	std::chrono::time_point<std::chrono::system_clock> current = start;

	while (status != FT_OK && ((current - start) < MaxTime))//loop till succesful connection o max connecting time is exceeded
	{
		status = FT_Open(1, deviceHandler);

		if (status == FT_OK)
		{
			UCHAR Mask = 0xFF;	//Selects all FTDI pins.
			UCHAR Mode = 1; 	// Set asynchronous bit-bang mode
			if (FT_SetBitMode(deviceHandler, Mask, Mode) == FT_OK)	// Sets LCD as asynch bit mode. Otherwise it doesn't work.
			{
				/*Set 4 bits mode */
				if (FT_Write(lcdHandle, &info, 1, &sizeSent) == FT_OK)
				{
					//If success continue with the program (...)
				}
				else
					printf("Error writing to the LCD\n");
			}
			else
				printf("Couldn't configure LCD\n");

		}
		current = std::chrono::system_clock::now();
	}

	if (status != FT_OK)
	{
		//trow exeption
	}
	
}

void FTDIHandler::lcdWriteIR(BYTE valor)
{
	BYTE temp =  ((valor & 0xF0) | ENABLE_1 & RS_IR ) ;
	lcdWriteNibble(temp);
	temp = (((valor & 0x0F) << 4) | ENABLE_1 & RS_IR);
	lcdWriteNibble(temp);
}

void FTDIHandler::lcdWriteDR(BYTE valor)
{
	BYTE temp = ((valor & 0xF0) | ENABLE_1 | RS_DR);
	lcdWriteNibble(temp);
	temp = (((valor & 0x0F) << 4) | ENABLE_1 | RS_DR);
	lcdWriteNibble(temp);
}


FTDIHandler::~FTDIHandler()
{

}

void FTDIHandler::lcdWriteNibble(BYTE value ) 
{
	FT_STATUS status = !FT_OK ;
	
	DWORD bytesWriten;
	status = FT_Write(deviceHandler, value & ENABLE_0 , 1 , bytesWriten);
	if (status != FT_OK)
	{
		//throw exepction 
	}
	status = !FT_OK;
	//wait ( 2 ) // tiempo en milisegundos

	status = FT_Write(deviceHandler, value | ENABLE_1 , 1, bytesWriten);
	if (status != FT_OK)
	{
		//throw exepction 
	}
	status = !FT_OK;
	//wait ( 2 ) // tiempo en milisegundos

	status = FT_Write(deviceHandler, value & ENABLE_0 , 1, bytesWriten);
	if (status != FT_OK)
	{
		//throw exepction 
	}
	status = !FT_OK;
	//wait ( 1 ) // tiempo en milisegundos


}

bool FTDIHandler::set4BitsMode(void)
{
	bool exito = false;

	return exito;
}
