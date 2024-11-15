/* 
 * File:   Drivers_Main.c
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:51 PM
 */

#include "Drivers_Main.h"

Std_ReturnType Ret = E_NOT_OK;

uint8 secs = 55 ,mins = 59,hrs = 23;

    
int main() { 
    Application_intialize();
    while(1){
        Clock();
    }
    return (EXIT_SUCCESS);
}

void Application_intialize(void){
    Ret = GPIO_PORT_DIRECTION_INITIALIZE(PORTC_INDEX,0x00);
    Ret = GPIO_PORT_DIRECTION_INITIALIZE(PORTD_INDEX,0xC0);
}

void Clock(void){
    for(int i = 0 ;i < 50; i++){
        Ret = GPIO_PORT_WRITE_LOGIC(PORTD_INDEX,0xDF);// 1101 1111
        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,(uint8)hrs/10);
        __delay_us(3333);
        Ret = GPIO_PORT_WRITE_LOGIC(PORTD_INDEX,0xEF);// 1110 1111
        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,(uint8)hrs%10);
        __delay_us(3333);
        Ret = GPIO_PORT_WRITE_LOGIC(PORTD_INDEX,0xF7);// 1111 0111
        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,(uint8)mins/10);
        __delay_us(3333);
        Ret = GPIO_PORT_WRITE_LOGIC(PORTD_INDEX,0xFB);// 1111 1011
        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,(uint8)mins%10);
        __delay_us(3333);
        Ret = GPIO_PORT_WRITE_LOGIC(PORTD_INDEX,0xFD);//1111 1101
        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,(uint8)secs/10);
        __delay_us(3333);
        Ret = GPIO_PORT_WRITE_LOGIC(PORTD_INDEX,0xFE);//1111 1110
        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,(uint8)secs%10);
        __delay_us(3333);
    }
    secs++;
    if(secs >= 60){
        secs = 0;
        mins++;
        if(mins >= 60){
            mins = 0;
            hrs++;
            if(hrs >= 24){
                hrs = 0;
            }
            else{}
        }
        else{}
    }
    else{}
}