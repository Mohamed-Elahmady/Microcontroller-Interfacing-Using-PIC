/* 
 * File:   ECU_DC_MOTOR.h
 * Author: Mohamed Elahmady
 *
 * Created on September 25, 2024, 6:26 AM
 */

/* Section 0 : File Guard */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/* Section 1 : Includes */

#include "../../MCAL/GPIO/HAL_GPIO.h"
#include "../../MCAL/Interrupt/MCAL_internal_interrupt.h"
#include "../../MCAL/Interrupt/MCAL_external_interrupt.h"
#include "ECU_DC_MOTOR_CFG.h"

/* Section 2 : Macros Declarations */

#define DC_MOTOR_OFF_STATUS              (LOGIC_T)0x00
#define DC_MOTOR_ON_STATUS               (LOGIC_T)0x01

/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */

typedef struct{
    PIN_CONFIG_T dc_motor_pin[2];
}DC_MOTOR_T;

/* Section 5 : Functions Declarations */

Std_ReturnType DC_MOTOR_INITIALIZE(const DC_MOTOR_T *motor);
Std_ReturnType DC_MOTOR_ROTATE_CW(const DC_MOTOR_T *motor);
Std_ReturnType DC_MOTOR_ROTATE_CCW(const DC_MOTOR_T *motor);
Std_ReturnType DC_MOTOR_STOP(const DC_MOTOR_T *motor);

#endif	/* ECU_DC_MOTOR_H */