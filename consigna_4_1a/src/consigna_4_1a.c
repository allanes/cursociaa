#include "consigna_4_1a.h"
#include "leds.h"


#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif


int main(void)
{
	InicializarDAC();

	return 0;
}

