#include "consigna_2.h"


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
	InicializarLEDS();
	InicializarBotones();
	EscanearBotones();
	return 0;
}

