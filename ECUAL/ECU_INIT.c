/* 
 * File:   ECU_INIT.c
 * Author: Mohamed Elahmady
 *
 * Created on October 1, 2024, 5:39 PM
 */

#include "ECU_INIT.h"

// each variable was defined here must be declared  as extern variable in driver main

CHR_LCD_4BIT_T lcd1 = {
    .RS_PIN.PORT = PORTC_INDEX,
    .RS_PIN.PIN = GPIO_PIN0,
    .RS_PIN.DIRECTION = GPIO_DIRECTION_OUTPUT,
    .RS_PIN.LOGIC = GPIO_LOW,
    
    .EN_PIN.PORT = PORTC_INDEX,
    .EN_PIN.PIN = GPIO_PIN1,
    .EN_PIN.DIRECTION = GPIO_DIRECTION_OUTPUT,
    .EN_PIN.LOGIC = GPIO_LOW,
    
    .DATA_PINS[0].PORT = PORTC_INDEX,
    .DATA_PINS[0].PIN = GPIO_PIN2,
    .DATA_PINS[0].DIRECTION = GPIO_DIRECTION_OUTPUT,
    .DATA_PINS[0].LOGIC = GPIO_LOW,
    
    .DATA_PINS[1].PORT = PORTC_INDEX,
    .DATA_PINS[1].PIN = GPIO_PIN3,
    .DATA_PINS[1].DIRECTION = GPIO_DIRECTION_OUTPUT,
    .DATA_PINS[1].LOGIC = GPIO_LOW,
    
    .DATA_PINS[2].PORT = PORTC_INDEX,
    .DATA_PINS[2].PIN = GPIO_PIN4,
    .DATA_PINS[2].DIRECTION = GPIO_DIRECTION_OUTPUT,
    .DATA_PINS[2].LOGIC = GPIO_LOW,
    
    .DATA_PINS[3].PORT = PORTC_INDEX,
    .DATA_PINS[3].PIN = GPIO_PIN5,
    .DATA_PINS[3].DIRECTION = GPIO_DIRECTION_OUTPUT,
    .DATA_PINS[3].LOGIC = GPIO_LOW,
};

CHR_LCD_8BIT_T lcd2 = {
    .RS_PIN.PORT = PORTC_INDEX,
    .RS_PIN.PIN = GPIO_PIN6,
    .RS_PIN.DIRECTION = GPIO_DIRECTION_OUTPUT,
    .RS_PIN.LOGIC = GPIO_LOW,
    
    .EN_PIN.PORT = PORTC_INDEX,
    .EN_PIN.PIN = GPIO_PIN7,
    .EN_PIN.DIRECTION = GPIO_DIRECTION_OUTPUT,
    .EN_PIN.LOGIC = GPIO_LOW,
    
    .DATA_PINS[0].PORT = PORTD_INDEX,
    .DATA_PINS[0].PIN = GPIO_PIN0,
    .DATA_PINS[0].DIRECTION = GPIO_DIRECTION_OUTPUT,
    .DATA_PINS[0].LOGIC = GPIO_LOW,
    
    .DATA_PINS[1].PORT = PORTD_INDEX,
    .DATA_PINS[1].PIN = GPIO_PIN1,
    .DATA_PINS[1].DIRECTION = GPIO_DIRECTION_OUTPUT,
    .DATA_PINS[1].LOGIC = GPIO_LOW,
    
    .DATA_PINS[2].PORT = PORTD_INDEX,
    .DATA_PINS[2].PIN = GPIO_PIN2,
    .DATA_PINS[2].DIRECTION = GPIO_DIRECTION_OUTPUT,
    .DATA_PINS[2].LOGIC = GPIO_LOW,
    
    .DATA_PINS[3].PORT = PORTD_INDEX,
    .DATA_PINS[3].PIN = GPIO_PIN3,
    .DATA_PINS[3].DIRECTION = GPIO_DIRECTION_OUTPUT,
    .DATA_PINS[3].LOGIC = GPIO_LOW,
    
    .DATA_PINS[4].PORT = PORTD_INDEX,
    .DATA_PINS[4].PIN = GPIO_PIN4,
    .DATA_PINS[4].DIRECTION = GPIO_DIRECTION_OUTPUT,
    .DATA_PINS[4].LOGIC = GPIO_LOW,
    
    .DATA_PINS[5].PORT = PORTD_INDEX,
    .DATA_PINS[5].PIN = GPIO_PIN5,
    .DATA_PINS[5].DIRECTION = GPIO_DIRECTION_OUTPUT,
    .DATA_PINS[5].LOGIC = GPIO_LOW,
    
    .DATA_PINS[6].PORT = PORTD_INDEX,
    .DATA_PINS[6].PIN = GPIO_PIN6,
    .DATA_PINS[6].DIRECTION = GPIO_DIRECTION_OUTPUT,
    .DATA_PINS[6].LOGIC = GPIO_LOW,
    
    .DATA_PINS[7].PORT = PORTD_INDEX,
    .DATA_PINS[7].PIN = GPIO_PIN7,
    .DATA_PINS[7].DIRECTION = GPIO_DIRECTION_OUTPUT,
    .DATA_PINS[7].LOGIC = GPIO_LOW,
};

void ECU_LAYER_INITIALIZE(void){
    Std_ReturnType Ret = E_NOT_OK;
    Ret = LCD_4BIT_INITIALIZE(&(lcd1));
    Ret = LCD_8BIT_INITIALIZE(&(lcd2));
}