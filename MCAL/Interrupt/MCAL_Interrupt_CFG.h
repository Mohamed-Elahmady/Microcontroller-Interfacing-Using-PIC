/* 
 * File:   MCAL_Interrupt_CFG.h
 * Author: Mohamed Elahmady
 *
 * Created on October 29, 2024, 9:03 PM
 */

/* Section 0 : File Guard */

#ifndef MCAL_INTERRUPT_CFG_H
#define	MCAL_INTERRUPT_CFG_H

/* Section 1 : Includes */

#include "MCAL_interrupt_Generate_CFG.h"
#include "pic18f46k20.h"
#include "../GPIO/HAL_GPIO.h"
#include "../MCAL_STD_Types.h"
#include "../Device_Config.h"

/* Section 2 : Macros Declarations */

#define INTERRUPT_DISABLE                 0x00
#define INTERRUPT_ENABLE                  0x01

#define INTERRUPT_PRIORITY_DISABLE        0x00
#define INTERRUPT_PRIORITY_ENABLE         0x01

#define INTERRUPT_NOT_OCCUR               0x00
#define INTERRUPT_OCCUR                   0x01

/* Section 3 : Macros Functions Declarations */

/*              PRIORITY LEVELS ENABLED        */
#if INTERRUPT_PRIORITY_LEVELS == INTERRUPT_FEATURE_ENABLE
#define INTERRUPT_DISABLE_PRIORITY_LEVELS()                  (RCONbits.IPEN = 0)
#define INTERRUPT_ENABLE_PRIORITY_LEVELS()                   (RCONbits.IPEN = 1)

#define INTERRUPT_DISABLE_HIGH_PRIORITY_GLOBAL_INTERRUPT()   (INTCONbits.GIEH = 0)
#define INTERRUPT_ENABLE_HIGH_PRIORITY_GLOBAL_INTERRUPT()    (INTCONbits.GIEH = 1)

#define INTERRUPT_DISABLE_LOW_PRIORITY_GLOBAL_INTERRUPT()    (INTCONbits.GIEL = 0)
#define INTERRUPT_ENABLE_LOW_PRIORITY_GLOBAL_INTERRUPT()     (INTCONbits.GIEL = 1)

#else

/*              PRIORITY LEVELS DISABLED        */
#define INTERRUPT_DISABLE_PRIORITY_LEVELS()                  (RCONbits.IPEN = 0)

#define INTERRUPT_DISABLE_PERIPHERAL_INTERRUPT()             (INTCONbits.PEIE = 0)
#define INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT()              (INTCONbits.PEIE = 1)

#define INTERRUPT_DISABLE_GLOBAL_INTERRUPT()                (INTCONbits.GIE = 0)
#define INTERRUPT_ENABLE_GLOBAL_INTERRUPT()                 (INTCONbits.GIE = 1)

#endif

/* Section 4 : User Defined Data Types Declarations */

typedef enum{
    INTERRUPT_LOW_PRIORITY = 0,
    INTERRUPT_HIGH_PRIORITY
}INTERRUPT_PRIORITY_CFG;

/* Section 5 : Functions Declarations */

#endif	/* MCAL_INTERRUPT_CFG_H */

