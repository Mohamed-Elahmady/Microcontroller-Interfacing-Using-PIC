/* 
 * File:   ECU_7_Segments.h
 * Author: Mohamed Elahmady
 *
 * Created on September 27, 2024, 7:11 AM
 */

/* Section 0 : File Guard */

#ifndef ECU_7_SEGMENTS_H
#define	ECU_7_SEGMENTS_H

/* Section 1 : Includes */

#include "../../MCAL/GPIO/HAL_GPIO.h"
#include "ECU_7_Segments_CFG.h"

/* Section 2 : Macros Declarations */

//#define SEGMENT_PIN0                0
//#define SEGMENT_PIN1                1
//#define SEGMENT_PIN2                2
//#define SEGMENT_PIN3                3

#define SEGMENT_DECODER_PINS        4
#define SEGMENT_DIGIT_LIMIT         9

/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */

typedef enum {
    SEGMENT_COMMON_ANODE = 0,
    SEGMENT_COMMON_CATHODE
}SEGMENT_TYPE_T;

typedef struct{
    PIN_CONFIG_T SEGMENT_PIN[SEGMENT_DECODER_PINS];
    SEGMENT_TYPE_T SEGMENT_TYPE;
}SEGMENT_T;

/* Section 5 : Functions Declarations */

Std_ReturnType SEGMENT_INITIALIZE (const SEGMENT_T *seg);
Std_ReturnType SEGMENT_WRITE_NUMBER (const SEGMENT_T *seg , const uint8 number);

#endif	/* ECU_7_SEGMENTS_H */

