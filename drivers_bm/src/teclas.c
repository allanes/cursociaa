#include "teclas.h"

void InicializarBotones(){
	Chip_SCU_PinMux(1,0,MD_PUP|MD_EZI|MD_ZI,FUNC0); //mapea 1.0 a GPIO0[4] (pulsador 1)
	Chip_SCU_PinMux(1,1,MD_PUP|MD_EZI|MD_ZI,FUNC0); //mapea 1.1 a GPIO0[8] (pulsador 1)
	Chip_SCU_PinMux(1,2,MD_PUP|MD_EZI|MD_ZI,FUNC0); //mapea 1.2 a GPIO0[9] (pulsador 1)
	Chip_SCU_PinMux(1,6,MD_PUP|MD_EZI|MD_ZI,FUNC0); //mapea 1.6 a GPIO1[9] (pulsador 1)

	Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1<<4), 0); //pongo como entrada
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1<<8), 0);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1<<9), 0);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 1, (1<<9), 0);
}

void EscanearBotones(){
	int lectura;
	do{
		lectura = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 4);
		if (!lectura) {ParpadearLED('3','B',1,1);}
		lectura = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 8);
		if (!lectura) {ParpadearLED('A','B',1,1);}
		lectura = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 9);
		if (!lectura) {ParpadearLED('R','B',1,1);}
		lectura = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 1, 9);
		if (!lectura) {ParpadearLED('V','B',1,1);}
	}while(1);
}


