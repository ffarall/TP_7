#include <iostream>

#include "FTDIHandler.h"
#include "HD44780LCD.h"
#include "ErrLCD.h"


int main(void)
{
	try 
	{
		/*FTDIHandler primer;
		string a =  "Hola mundo" ;
		
		for (char text : a)
		{
			primer.lcdWriteDR(text);
		}
		getchar();*/

		HD44780LCD hola;
		for (int i = 0; i < 5; i++) {
			hola.lcdMoveCursorRight();
			getchar();
		}
		
		hola.lcdMoveCursorDown();
		getchar();
		
		for (int i = 0; i < 5; i++) {
			hola.lcdMoveCursorRight();
			getchar();
		}
		
		std::cout << "columna " << hola.lcdGetCursorPosition().column << std::endl;
		std::cout << "fila " << hola.lcdGetCursorPosition().row << std::endl;
		
		hola.lcdMoveCursorUp();
		
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