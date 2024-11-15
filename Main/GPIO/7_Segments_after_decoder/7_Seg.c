/* 
 * File:   Drivers_Main.c
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:51 PM
 */

#include "Drivers_Main.h"

Std_ReturnType Ret = E_NOT_OK;

int main() { 
    Application_intialize();
    while(1){
        Counter_7_Segment();
    }
    return (EXIT_SUCCESS);
}

void Application_intialize(void){
    Ret = GPIO_PORT_DIRECTION_INITIALIZE(PORTC_INDEX,0xF0);
    Ret = GPIO_PORT_DIRECTION_INITIALIZE(PORTD_INDEX,0xF0);
    Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,0x00);
    Ret = GPIO_PORT_WRITE_LOGIC(PORTD_INDEX,0x00);
    __delay_ms(1000);
    Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,0x01);
    Ret = GPIO_PORT_WRITE_LOGIC(PORTD_INDEX,0x01);
    __delay_ms(1000);
}
void Counter_7_Segment(void){
    for(int i = 0; i < 10 ; i++){
        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,0x00);
        Ret = GPIO_PORT_WRITE_LOGIC(PORTD_INDEX,i);
        for(int j = 0; j < 10 ; j++){
        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,j);
        __delay_ms(250);
        }
    }
}
void Seconds_7_Segment(void){
    for(int i = 0; i < 6 ; i++){
        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,0x00);
        Ret = GPIO_PORT_WRITE_LOGIC(PORTD_INDEX,i);
        for(int j = 0; j < 10 ; j++){
        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,j);
        __delay_ms(250);
        }
    }
}