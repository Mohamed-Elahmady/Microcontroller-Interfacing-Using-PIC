/* 
 * File:   Drivers_Main.c
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:51 PM
 */

#include "Drivers_Main.h"

RELAY_T relay1 = {
    .PORT = PORTD_INDEX,
    .PIN  = GPIO_PIN0,
    .RELAY_LOGIC = RELAY_OFF,
};
RELAY_T relay2 = {
    .PORT = PORTD_INDEX,
    .PIN  = GPIO_PIN1,
    .RELAY_LOGIC = RELAY_OFF,
};

Std_ReturnType Ret = E_NOT_OK;

int main() { 
    
    Application_intialize();
    while(1){
        Ret = RELAY_TURN_ON(&relay1);
        Ret = RELAY_TURN_OFF(&relay2);
        __delay_ms(5000);
        Ret = RELAY_TURN_OFF(&relay1);
        Ret = RELAY_TURN_ON(&relay2);
        __delay_ms(5000);
    }
    
    return (EXIT_SUCCESS);
}

void Application_intialize(void){
    Ret = LED_INITIALIZE(&relay1);
    Ret = LED_INITIALIZE(&relay2);
    
}