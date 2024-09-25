/* 
 * File:   ECU_LED.c
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:54 PM
 */

#include "ECU_LED.h"


/**
 * @brief Intialize Assigned Pin to be input Button
 * @param btn pointer to led configuration                    // @ref LED_T
 * @return Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
Std_ReturnType LED_INITIALIZE (const LED_T *led){
    Std_ReturnType Retval = E_OK;
    if(NULL == led){
        Retval = E_NOT_OK;
    }
    else{
        PIN_CONFIG_T PIN_OBJ = {
            .PORT = led->PORT,
            .PIN = led->PIN,
            .DIRECTION = LED_DIRECT,
            .LOGIC = led->LOGIC
        };
        
        Retval = GPIO_PIN_INITIALIZE(&PIN_OBJ);
    }
    return Retval;
}

/**
 * @brief Turn The Led on
 * @param led pointer to led configuration                    // @ref LED_T
 * @return Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */

Std_ReturnType LED_Turn_ON(const LED_T * led){
    Std_ReturnType Retval = E_OK;
    if(NULL == led){
        Retval = E_NOT_OK;
    }
    else{
        PIN_CONFIG_T PIN_OBJ = {
            .PORT = led->PORT,
            .PIN = led->PIN,
            .DIRECTION = LED_DIRECT,
            .LOGIC = led->LOGIC
        };
        
        Retval = GPIO_PIN_WRITE_LOGIC(&PIN_OBJ , GPIO_HIGH);
    }
    return Retval;
}

/**
 * @brief Turn The Led Off
 * @param led pointer to led configuration                    // @ref LED_T
 * @return Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */

Std_ReturnType LED_Turn_OFF(const LED_T *led){
    Std_ReturnType Retval = E_OK;
    if(NULL == led){
        Retval = E_NOT_OK;
    }
    else{
        PIN_CONFIG_T PIN_OBJ = {
            .PORT = led->PORT,
            .PIN = led->PIN,
            .DIRECTION = LED_DIRECT,
            .LOGIC = led->LOGIC
        };
        
        Retval = GPIO_PIN_WRITE_LOGIC(&PIN_OBJ , GPIO_LOW);
    }
    return Retval;
}

/**
 * @brief Toggle The Led Status  " on => off " " off => on "
 * @param led pointer to led configuration                    // @ref LED_T
 * @return Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
Std_ReturnType LED_TOGGLE(const LED_T *led){
    Std_ReturnType Retval = E_OK;
    if(NULL == led){
        Retval = E_NOT_OK;
    }
    else{
        PIN_CONFIG_T PIN_OBJ = {
            .PORT = led->PORT,
            .PIN = led->PIN,
            .DIRECTION = LED_DIRECT,
            .LOGIC = led->LOGIC
        };
        
        Retval = GPIO_PIN_TOGGLE_LOGIC(&PIN_OBJ);
    }
    return Retval;
}