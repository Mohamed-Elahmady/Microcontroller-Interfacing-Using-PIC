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
#include "MCAL/Interrupt/MCAL_external_interrupt.h"

/* Section 2 : Macros Declarations */



/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */

// variable was defined in ECU_INIT.c
CHR_LCD_4BIT_T lcd1;
extern CHR_LCD_8BIT_T lcd2;

/* Section 5 : Functions Declarations */

void Application_intialize(void);

#endif	/* DRIVERS_MAIN_H */

