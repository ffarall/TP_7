#include <iostream>

#include "FTDIHandler.h"
#include "HD44780LCD.h"
#include "ErrLCD.h"


int main(void)
{
	try 
	{
		/*FTDIHandler primer;
		string a =  "ES DE UN CURSO";
		string b = "SUPERIOR";
		
		for (char text : a)
		{
			primer.lcdWriteDR(text);
		}
		
		primer.lcdWriteIR(0xC0);
		getchar();
		for (char text : b)
		{
			primer.lcdWriteDR(text);
		}
		getchar();*/
		
		HD44780LCD hola;

		string a = "hola mundo hola mundo";

		for (char text : a)
		{
			hola << text;
		}

		/*for (int i = 0; i < 5; i++) {
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
		*/
		getchar();

		hola.lcdClear();
		std::cout << "columna " << hola.lcdGetCursorPosition().column << std::endl;
		std::cout << "fila " << hola.lcdGetCursorPosition().row << std::endl;

		getchar();
		
		for (char text : a)
		{
			hola << text;
		}
		
		hola.lcdMoveCursorUp();

		std::cout << "columna " << hola.lcdGetCursorPosition().column << std::endl;
		std::cout << "fila " << hola.lcdGetCursorPosition().row << std::endl;

		getchar();

		hola.lcdClearToEOL();

		std::cout << "columna " << hola.lcdGetCursorPosition().column << std::endl;
		std::cout << "fila " << hola.lcdGetCursorPosition().row << std::endl;

		getchar();

		hola << 'a' << 'b';

		getchar();

		hola.lcdClear();

		a = "hola hola hola hola hola hola hola hola";

		for (char text : a)
		{
			hola << text;
		}

		std::cout << "columna " << hola.lcdGetCursorPosition().column << std::endl;
		std::cout << "fila " << hola.lcdGetCursorPosition().row << std::endl;

		getchar();

		for (int i = 0; i < 10; i++)
		{
			hola.lcdMoveCursorLeft();
		}
		
		hola.lcdClearToEOL();
		std::cout << "columna " << hola.lcdGetCursorPosition().column << std::endl;
		std::cout << "fila " << hola.lcdGetCursorPosition().row << std::endl;

		getchar();

		hola.lcdClear();
		hola << (const unsigned char *)"hola que tal??    todo bien :)";
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