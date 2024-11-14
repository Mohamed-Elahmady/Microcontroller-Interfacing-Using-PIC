/* 
 * File:   ECU_LED.h
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:54 PM
 */

/* Section 0 : File Guard */

#ifndef ECU_LED_H
#define	ECU_LED_H

/* Section 1 : Includes */

#include "../../MCAL/GPIO/HAL_GPIO.h"
#include "../../MCAL/Interrupt/MCAL_internal_interrupt.h"
#include "../../MCAL/Interrupt/MCAL_external_interrupt.h"
#include "ECU_LED_CFG.h"


/* Section 2 : Macros Declarations */
#define LED_DIRECT               (DIRECTION_T)GPIO_DIRECTION_OUTPUT
/* Section 3 : Macros Functions Declarations */

/* Section 4 : User Defined Data Types Declarations */

typedef enum {
    LED_OFF = 0,
    LED_ON
}LED_STAT;

typedef struct{
    uint8 PORT            :3;
    uint8 PIN             :3;
    uint8 LOGIC           :1;
    uint8 reserved        :1;
}LED_T;

/* Section 5 : Functions Declarations */
Std_ReturnType LED_INITIALIZE (const LED_T *led);
Std_ReturnType LED_Turn_ON(const LED_T *led);
Std_ReturnType LED_Turn_OFF(const LED_T *led);
Std_ReturnType LED_TOGGLE(const LED_T *led);


#endif	/* ECU_LED_H */

