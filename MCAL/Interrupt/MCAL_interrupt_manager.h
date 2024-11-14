/* 
 * File:   MCAL_interrupt_manager.h
 * Author: Mohamed Elahmady
 *
 * Created on October 29, 2024, 9:05 PM
 */

/* Section 0 : File Guard */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/* Section 1 : Includes */

#include "MCAL_Interrupt_CFG.h"
#include "MCAL_external_interrupt.h"
#include "MCAL_internal_interrupt.h"

/* Section 2 : Macros Declarations */

/* Section 3 : Macros Functions Declarations */

/* Section 4 : User Defined Data Types Declarations */

/* Section 5 : Functions Declarations */

void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(uint8 rb4);
void RB5_ISR(uint8 rb5);
void RB6_ISR(uint8 rb6);
void RB7_ISR(uint8 rb7);


#endif	/* MCAL_INTERRUPT_MANAGER_H */

