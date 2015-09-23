
/*==================[inclusions]=============================================*/
#include "leds.h"


void InicializarLEDS(){
	Chip_GPIO_Init(LPC_GPIO_PORT);

	Chip_SCU_PinMux(2,0,MD_PUP,FUNC4); //mapea 2.0 a GPIO5[0] (RGB, R)
	Chip_SCU_PinMux(2,1,MD_PUP,FUNC4); //mapea 2.0 a GPIO5[1] (RGB, G)
	Chip_SCU_PinMux(2,2,MD_PUP,FUNC4); //mapea 2.0 a GPIO5[2] (RGB, B)
	Chip_SCU_PinMux(2,10,MD_PUP,FUNC0); //mapea 2.0 a GPIO0[14] (LED Amarillo)
	Chip_SCU_PinMux(2,11,MD_PUP,FUNC0); //mapea 2.0 a GPIO1[11] (LED Rojo)
	Chip_SCU_PinMux(2,12,MD_PUP,FUNC0); //mapea 2.0 a GPIO1[12] (LED Verde)

	Chip_GPIO_SetDir(LPC_GPIO_PORT, 5, (1<<0), 1); // !1 es SALIDA, LPC_GPIO_PORT
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 5, (1<<1), 1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 5, (1<<2), 1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1<<14), 1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 1, (1<<11), 1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 1, (1<<12), 1);

	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 0);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 1);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 2);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 14);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 11);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 12);
}

int PrenderLED(char LED, char COLOR){
	switch (LED) {
	case 'V': //VERDE
		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1, 12);
	  break;
	case 'A': //AMARILLO
		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 0, 14);
	  break;
	case 'R': //ROJO
		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1, 11);
		  break;
	case '3':
		switch(COLOR){
		case 'B': //BLANCO
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 0);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 1);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 2);
			break;
		case 'V': //VIOLETA
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 0);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 2);
			break;
		case 'A': //AMARILLO
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 0);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 1);
			break;
		case 'C': //CELESTE
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 1);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 2);
			break;
		default: return 0;
		}
		  break;
	default: return 0;
	  break;
	}
	return 1;
}

int ApagarLED(char LED){
	switch (LED) {
		case 'V': //VERDE
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 12);
		  break;
		case 'A': //AMARILLO
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 14);
		  break;
		case 'R': //ROJO
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 11);
		  break;
		case '3':
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 0);
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 1);
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 2);
		  break;
		default: return 0;
		  break;
		}
	return 1;
}

void ParpadearLED(char LED, char COLOR, int t1, int t2){
	int i,x;
	do{
		i=0;
		PrenderLED(LED, COLOR);
		for(i=0;i<5000000;i++){x=0;}
		ApagarLED(LED);
		for(i=0;i<5000000;i++){x=0;}
		x=1;
	}while (x==1);

}

void ApagarLEDS(int cuenta){
	switch(cuenta){
	case 0:
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 0); //R,G,B
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 1);
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 2);
		break;
	case 1:
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 14); //AMARILLO
		break;
	case 2:
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 11); //ROJO
		break;
	case 3:
		Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 12); //VERDE
		break;
	default: PrenderLEDS();
	}

}

void PrenderLEDS(void){
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1, 12); //VERDE
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 0, 14); //AMARILLO
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1, 11); //ROJO
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 0); //R,G,B
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 1);
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 2);
}
/*==================[end of file]============================================*/

