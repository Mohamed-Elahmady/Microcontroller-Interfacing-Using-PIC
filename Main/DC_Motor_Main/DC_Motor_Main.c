/* 
 * File:   Drivers_Main.c
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:51 PM
 */

#include "Drivers_Main.h"

DC_MOTOR_T motor1 = {.dc_motor_pin[0].PORT = PORTC_INDEX ,
                     .dc_motor_pin[0].PIN = GPIO_PIN0 , 
                     .dc_motor_pin[0].DIRECTION = GPIO_DIRECTION_OUTPUT ,
                     .dc_motor_pin[0].LOGIC = DC_MOTOR_OFF_STATUS ,
                     .dc_motor_pin[1].PORT = PORTC_INDEX ,
                     .dc_motor_pin[1].PIN = GPIO_PIN1 , 
                     .dc_motor_pin[1].DIRECTION = GPIO_DIRECTION_OUTPUT ,
                     .dc_motor_pin[1].LOGIC = DC_MOTOR_OFF_STATUS};

DC_MOTOR_T motor2 = {.dc_motor_pin[0].PORT = PORTC_INDEX ,
                     .dc_motor_pin[0].PIN = GPIO_PIN2 , 
                     .dc_motor_pin[0].DIRECTION = GPIO_DIRECTION_OUTPUT ,
                     .dc_motor_pin[0].LOGIC = DC_MOTOR_OFF_STATUS,
                     .dc_motor_pin[1].PORT = PORTC_INDEX ,
                     .dc_motor_pin[1].PIN = GPIO_PIN3 , 
                     .dc_motor_pin[1].DIRECTION = GPIO_DIRECTION_OUTPUT ,
                     .dc_motor_pin[1].LOGIC = DC_MOTOR_OFF_STATUS};

Std_ReturnType Ret = E_NOT_OK;

int main() { 
    Application_intialize();
    while(1){
        Ret = DC_MOTOR_ROTATE_CW(&motor1);
        Ret = DC_MOTOR_ROTATE_CW(&motor2);
        __delay_ms(5000);
        Ret = DC_MOTOR_ROTATE_CCW(&motor1);
        Ret = DC_MOTOR_ROTATE_CCW(&motor2);
        __delay_ms(5000);
        Ret = DC_MOTOR_ROTATE_CW(&motor1);
        Ret = DC_MOTOR_ROTATE_CCW(&motor2);
        __delay_ms(5000);
        Ret = DC_MOTOR_ROTATE_CCW(&motor1);
        Ret = DC_MOTOR_ROTATE_CW(&motor2);
        __delay_ms(5000);
        Ret = DC_MOTOR_STOP(&motor1);
        Ret = DC_MOTOR_STOP(&motor2);
        __delay_ms(5000);
    }
    return (EXIT_SUCCESS);
}

void Application_intialize(void){
    Ret = DC_MOTOR_INITIALIZE(&motor1);
    Ret = DC_MOTOR_INITIALIZE(&motor2);
}