/* 
 * File:   Drivers_Main.c
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:51 PM
 */

#include "Drivers_Main.h"

Std_ReturnType Ret = E_NOT_OK;
void program1(void);
void program2(void);
void int0_ISR_TT(void);

LED_T led1 = {.PORT = PORTC_INDEX,.PIN = GPIO_PIN0,.LOGIC = GPIO_LOW};
LED_T led2 = {.PORT = PORTC_INDEX,.PIN = GPIO_PIN1,.LOGIC = GPIO_LOW};


EXT_INTX_T int0={
   .ext_interrupt_handler = int0_ISR_TT,
   .mcu_pin.PORT = PORTB_INDEX,
   .mcu_pin.PIN = GPIO_PIN0,
   .mcu_pin.DIRECTION = GPIO_DIRECTION_INPUT,
   .edge = INTERRUPT_RISING_EDGE,
   .source = EXT_INT0,
   .priority = INTERRUPT_HIGH_PRIORITY
};

volatile uint8 counter = 0;
uint8 tt = 0;


int main() { 
    Application_intialize();
    Ret = LED_INITIALIZE(&led1);
    Ret = LED_INITIALIZE(&led2);
    Ret = EXTERNAL_INTERRUPT_INTX_INIT(&int0);
    //Ret = DATA_EEPROM_WRITE_BYTE(0x3FF , 0);
    while(1){
        Ret = DATA_EEPROM_READ_BYTE(0x3FF , &tt);
        if(tt%2 != 0){
            program1();
        }
        else if(tt%2 == 0 && tt > 0){
            program2();
        }
        
    }
    return (EXIT_SUCCESS);
}

void Application_intialize(void){
    ECU_LAYER_INITIALIZE();
}

void program1(void){
    Ret = LED_Turn_ON(&led1);
    Ret = LED_Turn_OFF(&led2);
    __delay_ms(100);
    Ret = LED_Turn_OFF(&led1);
        __delay_ms(100);

}

void program2(void){
    Ret = LED_Turn_ON(&led2);
    Ret = LED_Turn_OFF(&led1);
    __delay_ms(100);
    Ret = LED_Turn_OFF(&led2);
        __delay_ms(100);
}

void int0_ISR_TT(void){
    Ret = DATA_EEPROM_WRITE_BYTE(0x3FF , ++counter);
}