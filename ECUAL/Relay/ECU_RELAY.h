/* 
 * File:   ECU_RELAY.h
 * Author: Mohamed Elahmady
 *
 * Created on September 22, 2024, 6:20 PM
 */

/* Section 0 : File Guard */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/* Section 1 : Includes */

#include "../../MCAL/GPIO/HAL_GPIO.h"
#include "ECU_RELAY_CFG.h"

/* Section 2 : Macros Declarations */

#define RELAY_DIRECT_OUTPUT         (DIRECTION_T)GPIO_DIRECTION_OUTPUT

/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */

typedef enum {
    RELAY_OFF = 0,
    RELAY_ON
}RELAY_STATUS;

typedef struct {
    uint8   PORT             :3;
    uint8   PIN              :3;
    uint8   RELAY_LOGIC      :1;
    uint8   RESERVED         :1;
}RELAY_T;

/* Section 5 : Functions Declarations */

Std_ReturnType RELAY_INITIALIZE(const RELAY_T *relay);
Std_ReturnType RELAY_TURN_ON(const RELAY_T *relay);
Std_ReturnType RELAY_TURN_OFF(const RELAY_T *relay);

#endif	/* ECU_RELAY_H */

