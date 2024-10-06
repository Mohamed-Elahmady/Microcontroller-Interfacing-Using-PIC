/* 
 * File:   Drivers_Main.h
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:54 PM
 */

/* Section 0 : File Guard */

#ifndef DRIVERS_MAIN_H
#define	DRIVERS_MAIN_H

/* Section 1 : Includes */

#include "ECUAL/ECU_INIT.h"

/* Section 2 : Macros Declarations */



/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */

KEYPAD_T keypad1; // variable was defined in ECU_INIT.c
LED_T led1;

/* Section 5 : Functions Declarations */

void Application_intialize(void);

#endif	/* DRIVERS_MAIN_H */

