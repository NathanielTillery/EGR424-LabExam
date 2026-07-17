// --- Systick.c ---
// --- Author: Chirag Parikh  ---

#include "msp.h"
#include "Systick.h"

// ----- Initialize SysTick ------
void SysTick_Init(void)
{
    SysTick -> CTRL = 0;          // disable SysTick during setup
    SysTick -> VAL = 0;           // any write to current clears it
    SysTick -> CTRL = 0x00000005; // enable SysTick, 3MHz, no interrupts
}

// ---- Configurable Systick delay from 1 microsec
void SysTick_delay(uint16_t delay)
{
    SysTick -> LOAD = ((delay*3) - 1);  // configure it to count from 1 microsecond count down to zero
    SysTick -> VAL = 0;                 // any write to CVR clears it and COUNTFLAG in CSR

    while((SysTick -> CTRL & 0x00010000) == 0);				// Wait for flag to be SET (Timeout happened)
}


