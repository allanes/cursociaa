#include "stdint.h"
#include "chip.h"

void InicializarLEDS(void);
int PrenderLED(char LED, char COLOR);
void PrenderLEDS(void);
int ApagarLED(char LED);
void ApagarLEDS(int cuenta);
void ParpadearLED(char LED, char COLOR, int t1, int t2);
