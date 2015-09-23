#ifndef TIMER_H_
#define TIMER_H_

#include "stdint.h"
#include "chip.h"

void InicializarTimer(int tiempo, int ejercicio);
void TimerHandler(void);
int getCuenta(void);
void Contar(void)

#endif /* TIMER_H_ */
