// --- GPIO.c ---
// --- Author: Chirag Parikh  ---

#include "msp.h"
#include "GPIO.h"


// --- This function sets the direction of required peripherals ---
void set_data_directions(void)
{

    /* Set the directions of on-board LED and BLUE RGB LED */
    P2->SEL0 = 0; P2->SEL1 = 0;             // Set P2 GPIO (RGB B)
    P1->SEL0 &= ~BIT0; P1->SEL1 &= ~BIT0;   // Bit 0 for P1 set to GPIO (On-Board LED)
    P2->DIR |= (BIT2);                      //Set the RGB BLUE bit as output
    P1->DIR |= BIT0;                        // P1.0 output

    /* Set direction of BUZZER */
    P2->SEL0 &= ~BIT4; P2->SEL0 &= ~BIT4;    // P2.4 set to GPIO
    P2->DIR |= BIT4;                        // P2.4 is an output

    P2->OUT &= ~BIT4;                       // P2.4 off to start

	/* Turn all LEDs OFF */
    P2->OUT &= ~BIT2;                       // BLUE off to start
    P1->OUT &= ~BIT0;                       // LED off to start
}

// ---- Turns ON on-board LED ---
void on1(void)
{
    P1->OUT |= BIT0;    // Turns ON on-board LED
}

// ---- Turns ON BLUE RGB LED ---
void on2(void)
{
	P2->OUT |= BIT2;    // Turns ON BLUE RGB LED
}

// ---- Turns OFF on-board LED ---
void off1(void)
{
    P1->OUT &= ~BIT0;   // Turns OFF on-board LED
}

// ---- Turns OFF BLUE RGB LED ---
void off2(void)
{
    P2->OUT &= ~BIT2;   // BLUE RGB LED
}
