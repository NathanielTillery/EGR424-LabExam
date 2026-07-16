// --- Systick.h ---
// --- Author: Chirag Parikh  ---

#ifndef SYSTICK_H_
#define SYSTICK_H_

void SysTick_Init(void);

// ---- Configurable Systick delay from 1 microsec
void SysTick_delay(uint16_t delay);

#endif /* SYSTICK_H_ */
