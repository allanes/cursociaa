#include "generadorDS.h"
#include "timer.h"

void InicializarDAC(void){
	Chip_SCU_DAC_Analog_Config();
	Chip_DAC_Init(LPC_DAC);
	Chip_DAC_UpdateValue(LPC_DAC, 0);
}

void GenerarDS(int max, int periodo){
	InicializarTimer(periodo, 411); //411 es el ejercicio 4_1a
}
