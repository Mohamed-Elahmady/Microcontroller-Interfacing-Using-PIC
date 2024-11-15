/* 
 * File:   ECU_INIT.h
 * Author: Mohamed Elahmady
 *
 * Created on October 1, 2024, 5:39 PM
 */

/* Section 0 : File Guard */

#ifndef ECU_INIT_H
#define	ECU_INIT_H

/* Section 1 : Includes */

#include "LED/ECU_LED.h"
#include "Button/ECU_Button.h"
#include "Relay/ECU_RELAY.h"
#include "DC_Motor/ECU_DC_MOTOR.h"
#include "7_Segments/ECU_7_Segments.h"
#include "Keypad/ECU_KEYPAD.h"
#include "CHR_LCD/ECU_CHR_LCD.h"

#include "../MCAL/Interrupt/MCAL_internal_interrupt.h"
#include "../MCAL/Interrupt/MCAL_external_interrupt.h"
#include "../MCAL/EEPROM/HAL_EEPROM.h"

/* Section 2 : Macros Declarations */



/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */



/* Section 5 : Functions Declarations */

void ECU_LAYER_INITIALIZE(void);

#endif	/* ECU_INIT_H */

