/* 
 * File:   ECU_Button.h
 * Author: Mohamed Elahmady
 *
 * Created on September 19, 2024, 6:45 AM
 */

/* Section 0 : File Guard */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H

/* Section 1 : Includes */

#include "../../MCAL/GPIO/HAL_GPIO.h"
#include "ECU_Button_CFG.h"

/* Section 2 : Macros Declarations */



/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */

typedef enum {
    BUTTON_PRESSED = 0,
    BUTTON_RELEASED
}BUTTON_STATE;

typedef enum {
    BUTTON_ACTIVE_HIGH = 0, // INPUT PULL DOWN
    BUTTON_ACTIVE_LOW       // INPUT PULL UP
}BUTTON_ACTIVE_T;

typedef struct {
    PIN_CONFIG_T BUTTON_PIN;
    BUTTON_STATE Button_st;
    BUTTON_ACTIVE_T Button_connection;
}BUTTON_T;

/* Section 5 : Functions Declarations */

Std_ReturnType BUTTON_INITIALIZE (const BUTTON_T *btn);
Std_ReturnType BUTTON_READ_STATUS (const BUTTON_T *btn,BUTTON_STATE *btn_st);


#endif	/* ECU_BUTTON_H */

