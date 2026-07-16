// --- TimerA.c ---
// --- Author: Chirag Parikh  ---

/* DriverLib Includes */
#include "driverlib.h"
#include "TimerA.h"

extern volatile int TIMER_A_CURRENT_PERIOD;


/* Timer_A UpMode Configuration Parameter */
const Timer_A_UpModeConfig upConfig =
{
    TIMER_A_CLOCKSOURCE_SMCLK,              	    // SMCLK Clock Source
    TIMER_A_CLOCKSOURCE_DIVIDER_1,          		// SMCLK/1 = 3 MHz
    3000,                                           // Variable period (3MHz clock starting at 1kHz, so start with 3000000/1000 = 3000)
    TIMER_A_TAIE_INTERRUPT_DISABLE,         		// Disable Timer interrupt
    TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE,    			// Enable CCR0 interrupt
    TIMER_A_DO_CLEAR                                // Clear value
};

// --- Initialize Timer A ---
void TimerA_init(void)
{
    Timer_A_configureUpMode(TIMER_A2_BASE, &upConfig);          // Configuring Timer_A2 for Up Mode
    NVIC->ISER[0] |= 1 << ((TA2_0_IRQn) & 31);	                // Enable NVIC to accept Timer interrupt
    Timer_A_startCounter(TIMER_A2_BASE, TIMER_A_UP_MODE);       // Start Timer
    __enable_interrupt();				                        // Enable Interrupt mechanism
}


// --- TA2_0 ISR ---
void TA2_0_IRQHandler(void)
{
	P2->OUT ^= BIT4;			        // Toggle BUZZER pin

	TIMER_A2->CCTL[0] &= ~CCIFG;        // Clear Capture-Compare Interrupt Flag for TA2.0
    
}

