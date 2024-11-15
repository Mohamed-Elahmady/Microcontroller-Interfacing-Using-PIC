/* 
 * File:   Drivers_Main.c
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:51 PM
 */

#include "Drivers_Main.h"

uint8 var = 0;
uint8 var_bcd = 0;
Std_ReturnType Ret = E_NOT_OK;

int main() { 
    Application_intialize();
    while(1){
        var_bcd = ((uint8)var%10) | (uint8)(var/10) << 4;
        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,var_bcd);
        var++;
        __delay_ms(100);
        if(var == 100){
            var = 0;
        }
    }
    return (EXIT_SUCCESS);
}

void Application_intialize(void){
    Ret = GPIO_PORT_DIRECTION_INITIALIZE(PORTC_INDEX,0x00);
}