#include <iostream>

#include "FTDIHandler.h"
#include "ErrLCD.h"


int main(void)
{
	try 
	{
		FTDIHandler primer;
		string a =  "Hola mundo aaaaaaaaaaaaaaaaaaaaaaaa" ;
		
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