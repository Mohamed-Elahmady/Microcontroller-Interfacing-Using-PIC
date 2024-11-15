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

#include "ECUAL/LED/ECU_LED.h"
#include "ECUAL/Button/ECU_Button.h"
#include "ECUAL/Relay/ECU_RELAY.h"
#include "ECUAL/DC_Motor/ECU_DC_MOTOR.h"
#include "ECUAL/7_Segments/ECU_7_Segments.h"

/* Section 2 : Macros Declarations */

/* Section 3 : Macros Functions Declarations */

/* Section 4 : User Defined Data Types Declarations */

/* Section 5 : Functions Declarations */

void Application_intialize(void);
void Counter_7_Segment (void);
void Seconds_7_Segment(void);
#define _XTAL_FREQ 8000000UL

#endif	/* DRIVERS_MAIN_H */

