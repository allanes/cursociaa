#include "consigna_3a.h"
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
	InicializarTimer(500);

	do{
		switch(getCuenta()){
		case 0: PrenderLED('3','B');break;
		case 1: PrenderLED('A','B');break;
		case 2: PrenderLED('R','B');break;
		case 3: PrenderLED('V','B');break;
		default: PrenderLEDS();break;
		}
	}while(1);

	return 0;
}

