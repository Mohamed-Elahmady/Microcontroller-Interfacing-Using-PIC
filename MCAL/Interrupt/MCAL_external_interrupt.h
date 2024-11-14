/* 
 * File:   MCAL_external_interrupt.h
 * Author: Mohamed Elahmady
 *
 * Created on October 29, 2024, 9:04 PM
 */

/* Section 0 : File Guard */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* Section 1 : Includes */

#include "MCAL_Interrupt_CFG.h"

/* Section 2 : Macros Declarations */



/* Section 3 : Macros Functions Declarations */

#if EXTERNAL_INTERRUPT_INTX == INTERRUPT_FEATURE_ENABLE

// INT0

/* This routine clears the interrupt Flag for the external interrupt, INT0 */
#define EXT_INT0_FLAG_CLEAR()                   (INTCONbits.INT0IF = 0)

/* This routine clears the interrupt Enable for the external interrupt, INT0 */
#define EXT_INT0_INTERRUPT_DISABLE()            (INTCONbits.INT0IE = 0)
/* This routine sets the interrupt Enable for the external interrupt, INT0 */
#define EXT_INT0_INTERRUPT_ENABLE()             (INTCONbits.INT0IE = 1)

/* This routine set the edge detect of the extern interrupt to negative edge */
#define EXT_INT0_SET_FALLING_EDGE()                 (INTCON2bits.INTEDG0 = 0)
/* This routine set the edge detect of the extern interrupt to positive edge */
#define EXT_INT0_SET_RISING_EDGE()                  (INTCON2bits.INTEDG0 = 1)



// INT1

/* This routine clears the interrupt Flag for the external interrupt, INT1 */
#define EXT_INT1_FLAG_CLEAR()                   (INTCON3bits.INT1IF = 0)

/* This routine clears the interrupt Enable for the external interrupt, INT1 */
#define EXT_INT1_INTERRUPT_DISABLE()            (INTCON3bits.INT1IE = 0)
/* This routine sets the interrupt Enable for the external interrupt, INT1 */
#define EXT_INT1_INTERRUPT_ENABLE()             (INTCON3bits.INT1IE = 1)

/* This routine set the edge detect of the extern interrupt to negative edge */
#define EXT_INT1_SET_FALLING_EDGE()                 (INTCON2bits.INTEDG1 = 0)
/* This routine set the edge detect of the extern interrupt to positive edge */
#define EXT_INT1_SET_RISING_EDGE()                  (INTCON2bits.INTEDG1 = 1)



// INT2

/* This routine clears the interrupt Flag for the external interrupt, INT1 */
#define EXT_INT2_FLAG_CLEAR()                   (INTCON3bits.INT2IF = 0)

/* This routine clears the interrupt Enable for the external interrupt, INT2 */
#define EXT_INT2_INTERRUPT_DISABLE()            (INTCON3bits.INT2IE = 0)
/* This routine sets the interrupt Enable for the external interrupt, INT2 */
#define EXT_INT2_INTERRUPT_ENABLE()             (INTCON3bits.INT2IE = 1)

/* This routine set the edge detect of the extern interrupt to negative edge */
#define EXT_INT2_SET_FALLING_EDGE()                (INTCON2bits.INTEDG2 = 0)
/* This routine set the edge detect of the extern interrupt to positive edge */
#define EXT_INT2_SET_RISING_EDGE()                 (INTCON2bits.INTEDG2 = 1)

#if INTERRUPT_PRIORITY_LEVELS == INTERRUPT_FEATURE_ENABLE

/* This routine set the INT1 External Interrupt Priority to be Low priority */
#define EXT_INT1_LOW_PRIORITY()                (INTCON3bits.INT1IP = 0)
/* This routine set the INT1 External Interrupt Priority to be High priority */
#define EXT_INT1_HIGH_PRIORITY()               (INTCON3bits.INT1IP = 1)

/* This routine set the INT2 External Interrupt Priority to be Low priority */
#define EXT_INT2_LOW_PRIORITY()                (INTCON3bits.INT2IP = 0)
/* This routine set the INT2 External Interrupt Priority to be High priority */
#define EXT_INT2_HIGH_PRIORITY()               (INTCON3bits.INT2IP = 1)

#endif

#endif

#if EXTERNAL_INTERRUPT_OnChange == INTERRUPT_FEATURE_ENABLE

// RBx

/* This routine clears the interrupt Flag for the external interrupt, RBx */
#define EXT_RBx_FLAG_CLEAR()                     (INTCONbits.RBIF = 0)

/* This routine clears the interrupt Enable for the external interrupt, RBx */
#define EXT_RBx_INTERRUPT_DISABLE()              (INTCONbits.RBIE = 0)
/* This routine sets the interrupt Enable for the external interrupt, RBx */
#define EXT_RBx_INTERRUPT_ENABLE()               (INTCONbits.RBIE = 1)

// IOCB PINS for RBX in PIC18F46K20

#define IOCB_RB4_DISABLE()                        (IOCBbits.IOCB4 = 0)
#define IOCB_RB4_ENABLE()                         (IOCBbits.IOCB4 = 1)

#define IOCB_RB5_DISABLE()                        (IOCBbits.IOCB5 = 0)
#define IOCB_RB5_ENABLE()                         (IOCBbits.IOCB5 = 1)

#define IOCB_RB6_DISABLE()                        (IOCBbits.IOCB6 = 0)
#define IOCB_RB6_ENABLE()                         (IOCBbits.IOCB6 = 1)

#define IOCB_RB7_DISABLE()                        (IOCBbits.IOCB7 = 0)
#define IOCB_RB7_ENABLE()                         (IOCBbits.IOCB7 = 1)

#if INTERRUPT_PRIORITY_LEVELS == INTERRUPT_FEATURE_ENABLE

/* This routine set the RBx External Interrupt Priority to be LOW priority */
#define EXT_RBx_LOW_PRIORITY()                   (INTCON2bits.RBIP = 0)
/* This routine set the RBx External Interrupt Priority to be High priority */
#define EXT_RBx_HIGH_PRIORITY()                  (INTCON2bits.RBIP = 1)

#endif

#endif

/* Section 4 : User Defined Data Types Declarations */

typedef enum{
    EXT_INT0 = 0,
    EXT_INT1,
    EXT_INT2
}INTX_SRC;

typedef enum{
    INTERRUPT_FALLING_EDGE = 0,
    INTERRUPT_RISING_EDGE
}INTX_EDGE;

typedef struct{
    void (* ext_interrupt_handler)(void);
    PIN_CONFIG_T mcu_pin;
    INTX_EDGE edge;
    INTX_SRC source;
    INTERRUPT_PRIORITY_CFG priority;
}EXT_INTX_T;

typedef struct{
    void (* ext_interrupt_handler_low)(void);
    void (* ext_interrupt_handler_high)(void);
    PIN_CONFIG_T mcu_pin;
    INTERRUPT_PRIORITY_CFG priority;
}EXT_RBX_T;

/* Section 5 : Functions Declarations */

Std_ReturnType EXTERNAL_INTERRUPT_INTX_INIT(const EXT_INTX_T *INTX);
Std_ReturnType EXTERNAL_INTERRUPT_INTX_DEINIT(const EXT_INTX_T *INTX);

Std_ReturnType EXTERNAL_INTERRUPT_RBX_INIT(const EXT_RBX_T *RBX);
Std_ReturnType EXTERNAL_INTERRUPT_RBX_DEINIT(const EXT_RBX_T *RBX);

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

