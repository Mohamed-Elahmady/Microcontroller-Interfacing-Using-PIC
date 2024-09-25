
/* 
 * File:   ECU_RELAY.c
 * Author: Mohamed Elahmady
 *
 * Created on September 22, 2024, 6:20 PM
 */

#include "ECU_RELAY.h"

/**
 * 
 * @brief Initialize relay pin as output pin
 * @param relay pointer point to relay struct at // @ref RELAY_T
 * @return Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
Std_ReturnType RELAY_INITIALIZE(const RELAY_T *relay){
    Std_ReturnType Retval = E_OK;
    if(NULL == relay){
        Retval = E_NOT_OK;
    }
    else{
        PIN_CONFIG_T pin = {.PORT = relay->PORT,
                            .PIN = relay->PIN,
                            .DIRECTION = RELAY_DIRECT_OUTPUT,
                            .LOGIC = relay->RELAY_LOGIC};
        Retval = GPIO_PIN_INITIALIZE(&pin);
    }
    return Retval;
}
/**
 * 
 * @brief Turn on relay pin
 * @param relay pointer point to relay struct at // @ref RELAY_T
 * @return Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
Std_ReturnType RELAY_TURN_ON(const RELAY_T *relay){
    Std_ReturnType Retval = E_OK;
    if(NULL == relay){
        Retval = E_NOT_OK;
    }
    else{
        LOGIC_T state = (LOGIC_T)RELAY_ON;
        PIN_CONFIG_T pin = {.PORT = relay->PORT,
                            .PIN = relay->PIN,
                            .DIRECTION = RELAY_DIRECT_OUTPUT,
                            .LOGIC = relay->RELAY_LOGIC};
        Retval = GPIO_PIN_WRITE_LOGIC(&pin,state);
    }
    return Retval;
}
/**
 * 
 * @brief Turn off relay pin
 * @param relay pointer point to relay struct at // @ref RELAY_T
 * @return Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
Std_ReturnType RELAY_TURN_OFF(const RELAY_T *relay){
    Std_ReturnType Retval = E_OK;
    if(NULL == relay){
        Retval = E_NOT_OK;
    }
    else{
        LOGIC_T state = (LOGIC_T)RELAY_OFF;
        PIN_CONFIG_T pin = {.PORT = relay->PORT,
                            .PIN = relay->PIN,
                            .DIRECTION = RELAY_DIRECT_OUTPUT,
                            .LOGIC = relay->RELAY_LOGIC};
        Retval = GPIO_PIN_WRITE_LOGIC(&pin,state);
    }
    return Retval;
}