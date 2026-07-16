/// --- GPIO.h ---
// --- Author: Chirag Parikh  ---

#ifndef GPIO_H_
#define GPIO_H_


// --- This function sets the direction of required peripherals ---
void set_data_directions(void);

// ---- Turns ON on-board LED ---
void on1(void);

// ---- Turns ON BLUE RGB LED ---
void on2(void);

// ---- Turns OFF on-board LED ---
void off1(void);

// ---- Turns OFF BLUE RGB LED ---
void off2(void);




#endif /* GPIO_H_ */
