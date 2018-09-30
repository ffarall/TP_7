#include "delay.h"
#include <chrono>

using namespace std::chrono;
void delay(unsigned int milisec)  // espera una catidad de milisegundos
{
	time_point<high_resolution_clock> ti, tf;
	
	ti = tf = high_resolution_clock::now();
	
	while ( (duration_cast<milliseconds>(tf - ti).count() ) < milisec)
	{
		tf = high_resolution_clock::now();
	}
}
