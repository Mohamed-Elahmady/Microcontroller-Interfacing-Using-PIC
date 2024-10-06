/* 
 * File:   ECU_KEYPAD.c
 * Author: Mohamed Elahmady
 *
 * Created on October 1, 2024, 11:18 AM
 */

#include "ECU_KEYPAD.h"

const static uint8 KEYPAD_VALUES[KEYPAD_ROWS][KEYPAD_COLUMNS] = {
                                                                    {'7','8','9','/'},
                                                                    {'4','5','6','*'},
                                                                    {'1','2','3','-'},
                                                                    {'C','0','=','+'}
};

/**
 * 
 * @param keypad
 * @return 
 */
Std_ReturnType KEYPAD_INITIALIZE(const KEYPAD_T *keypad){
    Std_ReturnType Retval = E_OK;
    if(NULL == keypad){
        Retval = E_NOT_OK;
    }
    else{
        for(int r = ZERO_INIT; r < KEYPAD_ROWS ; r++){
            Retval = GPIO_PIN_INITIALIZE(&(keypad->KEYPAD_ROWS_PINS[r]));
        }
        for(int c = ZERO_INIT; c < KEYPAD_COLUMNS ; c++){
            Retval = GPIO_PIN_DIRECTION_INITIALIZE(&(keypad->KEYPAD_COLUMNS_PINS[c])); 
        }
    }
    return Retval;
}
/**
 * 
 * @param keypad
 * @param value
 * @return 
 */
Std_ReturnType KEYPAD_GET_VALUE(const KEYPAD_T *keypad , uint8 *value){
    Std_ReturnType Retval = E_OK;
    if((NULL == keypad) || (NULL == value)){
        Retval = E_NOT_OK;
    }
    else{
        LOGIC_T COLUMN_STATE = GPIO_LOW;
        
        for(int r1 = 0; r1 < KEYPAD_ROWS ; r1++){
            for(int r2 = 0; r2 < KEYPAD_ROWS ; r2++){
                Retval = GPIO_PIN_WRITE_LOGIC(&(keypad->KEYPAD_ROWS_PINS[r2]) , GPIO_LOW);
            }
            Retval = GPIO_PIN_WRITE_LOGIC(&(keypad->KEYPAD_ROWS_PINS[r1]) , GPIO_HIGH);
            for(int c1 = 0; c1 < KEYPAD_COLUMNS ; c1++){
                Retval = GPIO_PIN_READ_LOGIC(&(keypad->KEYPAD_COLUMNS_PINS[c1]) , &COLUMN_STATE);
                if(GPIO_HIGH == COLUMN_STATE){
                    *value = KEYPAD_VALUES[r1][c1];
                }
                else{}
            }
        }
    }
    return Retval;
}