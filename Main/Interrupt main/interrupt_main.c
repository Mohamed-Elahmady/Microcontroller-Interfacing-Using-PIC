/* 
 * File:   Drivers_Main.c
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:51 PM
 */

#include "Drivers_Main.h"

Std_ReturnType Ret = E_NOT_OK;

void int0_ISR_TT(void);
void RB4_ISR_LOW_TT(void);
void RB4_ISR_HIGH_TT(void);
void RB5_ISR_LOW_TT(void);
void RB5_ISR_HIGH_TT(void);
void RB6_ISR_LOW_TT(void);
void RB6_ISR_HIGH_TT(void);
void RB7_ISR_LOW_TT(void);
void RB7_ISR_HIGH_TT(void);


LED_T led1 = {.PORT = PORTC_INDEX,.PIN = GPIO_PIN0,.LOGIC = GPIO_LOW};

LED_T led2 = {.PORT = PORTC_INDEX,.PIN = GPIO_PIN1,.LOGIC = GPIO_LOW};

LED_T led3 = {.PORT = PORTC_INDEX,.PIN = GPIO_PIN2,.LOGIC = GPIO_LOW};

LED_T led4 = {.PORT = PORTC_INDEX,.PIN = GPIO_PIN3,.LOGIC = GPIO_LOW};

EXT_INTX_T int0={
   .ext_interrupt_handler = int0_ISR_TT,
   .mcu_pin.PORT = PORTB_INDEX,
   .mcu_pin.PIN = GPIO_PIN0,
   .mcu_pin.DIRECTION = GPIO_DIRECTION_INPUT,
   .edge = INTERRUPT_RISING_EDGE,
   .source = EXT_INT0,
   .priority = INTERRUPT_HIGH_PRIORITY
};

EXT_RBX_T RB4__ = {
    .ext_interrupt_handler_high = RB4_ISR_HIGH_TT,
    .ext_interrupt_handler_low = RB4_ISR_LOW_TT,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .mcu_pin.PORT = PORTB_INDEX,
    .mcu_pin.PIN = GPIO_PIN4,
    .mcu_pin.DIRECTION = GPIO_DIRECTION_INPUT
};

EXT_RBX_T RB5__ = {
    .ext_interrupt_handler_high = RB5_ISR_HIGH_TT,
    .ext_interrupt_handler_low = RB5_ISR_LOW_TT,
    .priority = INTERRUPT_LOW_PRIORITY,
    .mcu_pin.PORT = PORTB_INDEX,
    .mcu_pin.PIN = GPIO_PIN5,
    .mcu_pin.DIRECTION = GPIO_DIRECTION_INPUT
};

EXT_RBX_T RB6__ = {
    .ext_interrupt_handler_high = RB6_ISR_HIGH_TT,
    .ext_interrupt_handler_low = RB6_ISR_LOW_TT,
    .priority = INTERRUPT_HIGH_PRIORITY,
    .mcu_pin.PORT = PORTB_INDEX,
    .mcu_pin.PIN = GPIO_PIN6,
    .mcu_pin.DIRECTION = GPIO_DIRECTION_INPUT
};

EXT_RBX_T RB7__ = {
    .ext_interrupt_handler_high = RB7_ISR_HIGH_TT,
    .ext_interrupt_handler_low = RB7_ISR_LOW_TT,
    .priority = INTERRUPT_LOW_PRIORITY,
    .mcu_pin.PORT = PORTB_INDEX,
    .mcu_pin.PIN = GPIO_PIN7,
    .mcu_pin.DIRECTION = GPIO_DIRECTION_INPUT
};
int main() { 
    Application_intialize();
    
    Ret = LED_INITIALIZE(&led1);
    Ret = LED_INITIALIZE(&led2);
    Ret = LED_INITIALIZE(&led3);
    Ret = LED_INITIALIZE(&led4);
//    Ret = EXTERNAL_INTERRUPT_INTX_INIT(&int0);
    Ret = EXTERNAL_INTERRUPT_RBX_INIT(&RB4__);
    Ret = EXTERNAL_INTERRUPT_RBX_INIT(&RB5__);
    Ret = EXTERNAL_INTERRUPT_RBX_INIT(&RB6__);
    Ret = EXTERNAL_INTERRUPT_RBX_INIT(&RB7__);

    while(1){
        
    }
    return (EXIT_SUCCESS);
}

void Application_intialize(void){
    ECU_LAYER_INITIALIZE();
}

void int0_ISR_TT(void){
    Ret = LED_TOGGLE(&led1);
    
}

void RB4_ISR_HIGH_TT(void){
    Ret = LED_Turn_ON(&led1);
}
void RB4_ISR_LOW_TT(void){
    Ret = LED_Turn_ON(&led2);  
}
void RB5_ISR_HIGH_TT(void){
    Ret = LED_Turn_OFF(&led1);
}
void RB5_ISR_LOW_TT(void){
    Ret = LED_Turn_OFF(&led2);
}
void RB6_ISR_HIGH_TT(void){
    Ret = LED_Turn_ON(&led3);
}
void RB6_ISR_LOW_TT(void){
    Ret = LED_Turn_ON(&led4);
}
void RB7_ISR_HIGH_TT(void){
    Ret = LED_Turn_OFF(&led3);
}
void RB7_ISR_LOW_TT(void){
    Ret = LED_Turn_OFF(&led4);
}