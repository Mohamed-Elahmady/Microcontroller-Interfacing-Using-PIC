/* 
 * File:   Drivers_Main.c
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:51 PM
 */

#include "Drivers_Main.h"

Std_ReturnType Ret = E_NOT_OK;
uint8 val = 0;

int main() { 
    Application_intialize();
    while(1){
        Ret = KEYPAD_GET_VALUE(&keypad1 , &val);
        
        if(val == '5'){
            Ret = LED_Turn_ON(&led1);
        }
        else if (val == '8'){
            Ret = LED_Turn_OFF(&led1);
        }
    }
    return (EXIT_SUCCESS);
}

void Application_intialize(void){
    ECU_LAYER_INITIALIZE();
}