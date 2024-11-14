/* 
 * File:   MCAL_interrupt_Generate_CFG.h
 * Author: Mohamed Elahmady
 *
 * Created on October 29, 2024, 10:09 PM
 */

/* Section 0 : File Guard */

#ifndef MCAL_INTERRUPT_GENERATE_CFG_H
#define	MCAL_INTERRUPT_GENERATE_CFG_H

/* Section 1 : Includes */

/* Section 2 : Macros Declarations */

#define INTERRUPT_FEATURE_DISABLE   0x00
#define INTERRUPT_FEATURE_ENABLE    0x01

//#define INTERRUPT_PRIORITY_LEVELS           INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INTERRUPT_INTX             INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INTERRUPT_OnChange         INTERRUPT_FEATURE_ENABLE

/* Section 3 : Macros Functions Declarations */

/* Section 4 : User Defined Data Types Declarations */

/* Section 5 : Functions Declarations */

#endif	/* MCAL_INTERRUPT_GENERATE_CFG_H */

