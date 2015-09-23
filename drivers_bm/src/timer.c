#include "teclas.h"
#include "leds.h"

int cuenta = 0;
int ejercicio;

int getCuenta(void){return cuenta;}

void Contar(void){
	cuenta++;
	if (cuenta>3) cuenta = 0;

}

void InicializarTimer(int tiempo, int ej){

	InicializarLEDS();
	ejercicio = ej;

	Chip_RIT_Init(LPC_RITIMER);
	Chip_RIT_ClearInt(LPC_RITIMER);
	NVIC_EnableIRQ(RITIMER_IRQn);
	Chip_RIT_SetTimerInterval(LPC_RITIMER, tiempo);

}

void TimerHandler(void){
	if (ejercicio == 31){
		ApagarLEDS(cuenta);
		Contar();
	}elseif (ejercicio == 411){

	}
	Chip_RIT_ClearInt(LPC_RITIMER);
}



