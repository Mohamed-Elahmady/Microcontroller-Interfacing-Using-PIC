/* 
 * File:   ECU_DC_MOTOR.h
 * Author: Mohamed Elahmady
 *
 * Created on September 25, 2024, 6:26 AM
 */

#include "ECU_DC_MOTOR.h"

/**
 * 
 * @param motor
 * @return 
 */
Std_ReturnType DC_MOTOR_INITIALIZE(const DC_MOTOR_T *motor){
    Std_ReturnType Retval = E_OK;
    if(NULL == motor){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_INITIALIZE(&(motor->dc_motor_pin[0]));
        Retval = GPIO_PIN_INITIALIZE(&(motor->dc_motor_pin[1]));
    }
    return Retval;
}
/**
 * 
 * @param motor
 * @return 
 */
Std_ReturnType DC_MOTOR_ROTATE_CW(const DC_MOTOR_T *motor){
    Std_ReturnType Retval = E_OK;
    if(NULL == motor){
        Retval = E_NOT_OK;
    }
    else{
        LOGIC_T IN1 = DC_MOTOR_ON_STATUS;
        LOGIC_T IN2 = DC_MOTOR_OFF_STATUS;
        Retval = GPIO_PIN_WRITE_LOGIC(&(motor->dc_motor_pin[0]) , IN1);
        Retval = GPIO_PIN_WRITE_LOGIC(&(motor->dc_motor_pin[1]) , IN2);
    }
    return Retval;
}
/**
 * 
 * @param motor
 * @return 
 */
Std_ReturnType DC_MOTOR_ROTATE_CCW(const DC_MOTOR_T *motor){
    Std_ReturnType Retval = E_OK;
    if(NULL == motor){
        Retval = E_NOT_OK;
    }
    else{
        LOGIC_T IN1 = DC_MOTOR_OFF_STATUS;
        LOGIC_T IN2 = DC_MOTOR_ON_STATUS;
        Retval = GPIO_PIN_WRITE_LOGIC(&(motor->dc_motor_pin[0]) , IN1);
        Retval = GPIO_PIN_WRITE_LOGIC(&(motor->dc_motor_pin[1]) , IN2);
    }
    return Retval;
}
/**
 * 
 * @param motor
 * @return 
 */
Std_ReturnType DC_MOTOR_STOP(const DC_MOTOR_T *motor){
    Std_ReturnType Retval = E_OK;
    if(NULL == motor){
        Retval = E_NOT_OK;
    }
    else{
        LOGIC_T IN1 = DC_MOTOR_OFF_STATUS;
        LOGIC_T IN2 = DC_MOTOR_OFF_STATUS;
        Retval = GPIO_PIN_WRITE_LOGIC(&(motor->dc_motor_pin[0]) , IN1);
        Retval = GPIO_PIN_WRITE_LOGIC(&(motor->dc_motor_pin[1]) , IN2);
    }
    return Retval;
}