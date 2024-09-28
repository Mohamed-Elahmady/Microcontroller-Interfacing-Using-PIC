/* 
 * File:   ECU_7_Segments.h
 * Author: Mohamed Elahmady
 *
 * Created on September 27, 2024, 7:11 AM
 */

#include "ECU_7_Segments.h"

/**
 * 
 * @param seg
 * @return 
 */
Std_ReturnType SEGMENT_INITIALIZE (const SEGMENT_T *seg){
    Std_ReturnType Retval = E_OK;
    if(NULL == seg){
        Retval = E_NOT_OK;
    }
    else{
        for(int i = 0;i < SEGMENT_DECODER_PINS ; i++){
            Retval = GPIO_PIN_INITIALIZE(&(seg->SEGMENT_PIN[i]));
        }
    }
    return Retval;
}
/**
 * 
 * @param seg
 * @param number
 * @return 
 */
Std_ReturnType SEGMENT_WRITE_NUMBER (const SEGMENT_T *seg , const uint8 number){
    Std_ReturnType Retval = E_OK;
    if(NULL == seg || number > SEGMENT_DIGIT_LIMIT){
        Retval = E_NOT_OK;
    }
    else{
        for(int i = 0;i < SEGMENT_DECODER_PINS ; i++){
            Retval = GPIO_PIN_WRITE_LOGIC(&(seg->SEGMENT_PIN[i]) , ((number >> i) & 0x01));
        }
    }
    return Retval;
}