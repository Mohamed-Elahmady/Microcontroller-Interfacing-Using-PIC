/* 
 * File:   ECU_Button.c
 * Author: Mohamed Elahmady
 *
 * Created on September 19, 2024, 6:45 AM
 */

#include "ECU_Button.h"

/**
 * @brief Intialize Assigned Pin to be input btn
 * @param btn pointer to btn configuration                    // @ref BUTTON_T
 * @return Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
Std_ReturnType BUTTON_INITIALIZE (const BUTTON_T *btn){
    Std_ReturnType Retval = E_OK;
    if(NULL == btn){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_DIRECTION_INITIALIZE(&(btn->BUTTON_PIN));
    }
    return Retval;
}

/**
 * @brief Read the state of btn
 * @param btn pointer to btn configuration                    // @ref BUTTON_T
 * @param btn_st pointer return the state of btn              // @ref BUTTON_STATE
 * @return Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
Std_ReturnType BUTTON_READ_STATUS (const BUTTON_T *btn,BUTTON_STATE *btn_st){
    Std_ReturnType Retval = E_OK;
    if((NULL == btn) || (NULL == btn_st)){
        Retval = E_NOT_OK;
    }
    else{
        LOGIC_T Btn_Log = GPIO_LOW;
        Retval = GPIO_PIN_READ_LOGIC(&(btn->BUTTON_PIN),&Btn_Log);
        if(BUTTON_ACTIVE_HIGH == btn->Button_connection){
            if(GPIO_HIGH == Btn_Log){
                *btn_st = BUTTON_PRESSED;
            }
            else{
                *btn_st = BUTTON_RELEASED;
            }
        }
        else if(BUTTON_ACTIVE_LOW == btn->Button_connection){
            if(GPIO_HIGH == Btn_Log){
                *btn_st = BUTTON_RELEASED;
            }
            else{
                *btn_st = BUTTON_PRESSED;
            }
        }
        else{
            Retval = E_NOT_OK;
        }
    }
    return Retval;
}