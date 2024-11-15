/* 
 * File:   ECU_KEYPAD.h
 * Author: Mohamed Elahmady
 *
 * Created on October 1, 2024, 11:18 AM
 */

/* Section 0 : File Guard */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/* Section 1 : Includes */

#include "../../MCAL/GPIO/HAL_GPIO.h"
#include "ECU_KEYPAD_CFG.h"

/* Section 2 : Macros Declarations */



/* Section 3 : Macros Functions Declarations */

#define KEYPAD_ROWS                           0x04
#define KEYPAD_COLUMNS                        0x04

/* Section 4 : User Defined Data Types Declarations */

typedef struct{
    PIN_CONFIG_T KEYPAD_ROWS_PINS[KEYPAD_ROWS];
    PIN_CONFIG_T KEYPAD_COLUMNS_PINS[KEYPAD_COLUMNS];
}KEYPAD_T;

/* Section 5 : Functions Declarations */

Std_ReturnType KEYPAD_INITIALIZE(const KEYPAD_T *keypad);
Std_ReturnType KEYPAD_GET_VALUE(const KEYPAD_T *keypad , uint8 *value);

#endif	/* ECU_KEYPAD_H */

