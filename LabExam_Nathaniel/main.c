/* DriverLib Includes */
#include "driverlib.h"
#include "msp.h"

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

/* Custom Includes */
#include "GPIO.h"
#include "Systick.h"
#include "TimerA.h"


volatile int TIMER_A_CURRENT_PERIOD = 3000;
int compareValue = 0;

// --- This function imitates police siren and light show ----
void light_show(int bright)
{
    int wait = 1000-bright;
    int compareValueCount;


    // Compare value should range from 500 Hz to 1 KHz

    // Compute compare value using the value of "bright" that first ranges from 1 to 998 and then from 999 to 2
    compareValue = (bright) / 2;
    // After you devise a formula to compute the compare value, assign it to Timer A Compare register
    Timer_A_setCompareValue(TIMER_A2_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0, wait);
    // Use 50% DC




    on1();						// Turn ON on-board LED
    SysTick_delay(bright);	    // Delay for "bright" time
	off1();						// Turn OFF on-board LED
	SysTick_delay(bright);  	// Delay for "bright" time

	on2();						// Turn ON BLUE RGB LED
	SysTick_delay(wait);	    // Delay for "wait" time
	off2();				        // Turn OFF BLUE RGB LED
	SysTick_delay(wait);		// Delay for "wait" time
}


int main(void)
{
    volatile int i;

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;				// Stop Watchdog

    set_data_directions();      // Sets the direction of peripherals
    SysTick_Init();             // Initialize Systick peripheral
    TimerA_init();		        // Initialize Timer A peripheral


    while(1)
    {
        for(i=1; i<999; i++)
           light_show(i);

        for(i=999; i>1; i--)
           light_show(i);
    }
}

