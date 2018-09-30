#include <iostream>

#include "FTDIHandler.h"
#include "ErrLCD.h"


int main(void)
{
	try 
	{
		FTDIHandler primer;
		primer.lcdWriteIR(0x0F);
		string a =  "hola mundo" ;
		for (char text : a)
		{
			primer.lcdWriteDR(text);
		}
		getchar();
		
	}
	catch (ErrType errores)
	{
		ErrLCD lcderror;
		lcderror.set_type(errores);

		std::cout << lcderror.get_description().c_str() << std::endl;
	}
	return 0;
}