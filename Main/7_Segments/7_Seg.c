/* 
 * File:   Drivers_Main.c
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:51 PM
 */

#include "Drivers_Main.h"

Std_ReturnType Ret = E_NOT_OK;

SEGMENT_T seg1 = {
    .SEGMENT_PIN[0].PORT = PORTC_INDEX,
    .SEGMENT_PIN[0].PIN = GPIO_PIN0,
    .SEGMENT_PIN[0].DIRECTION = GPIO_DIRECTION_OUTPUT,
    .SEGMENT_PIN[0].LOGIC = GPIO_LOW,
    
    .SEGMENT_PIN[1].PORT = PORTC_INDEX,
    .SEGMENT_PIN[1].PIN = GPIO_PIN1,
    .SEGMENT_PIN[1].DIRECTION = GPIO_DIRECTION_OUTPUT,
    .SEGMENT_PIN[1].LOGIC = GPIO_LOW,
    
    .SEGMENT_PIN[2].PORT = PORTC_INDEX,
    .SEGMENT_PIN[2].PIN = GPIO_PIN2,
    .SEGMENT_PIN[2].DIRECTION = GPIO_DIRECTION_OUTPUT,
    .SEGMENT_PIN[2].LOGIC = GPIO_LOW,
    
    .SEGMENT_PIN[3].PORT = PORTC_INDEX,
    .SEGMENT_PIN[3].PIN = GPIO_PIN3,
    .SEGMENT_PIN[3].DIRECTION = GPIO_DIRECTION_OUTPUT,
    .SEGMENT_PIN[3].LOGIC = GPIO_LOW,
    
    .SEGMENT_TYPE = SEGMENT_COMMON_CATHODE
};

PIN_CONFIG_T seg1_en = {
    .PORT = PORTC_INDEX,
    .PIN = GPIO_PIN4,
    .DIRECTION = GPIO_DIRECTION_OUTPUT,
    .LOGIC = GPIO_LOW,
};

PIN_CONFIG_T seg2_en = {
    .PORT = PORTC_INDEX,
    .PIN = GPIO_PIN5,
    .DIRECTION = GPIO_DIRECTION_OUTPUT,
    .LOGIC = GPIO_LOW,
};

int n = 0;

int main() { 
    Application_intialize();
    while(1){
        /* for 2 " 7segments " */
//        for(int i = 0;i < 10 ; i++){
//            Ret = SEGMENT_WRITE_NUMBER(&seg2 , i);
//            for(int j = 0;j < 10 ; j++){
//            Ret = SEGMENT_WRITE_NUMBER(&seg1 , j);
//            __delay_ms(100);
//            }
//        }
        
        /* for 1 " 7segments " by multiplexing */
        for(int i = 0;i < 50 ; i++){
            Ret = GPIO_PIN_WRITE_LOGIC(&seg1_en,GPIO_LOW);
            Ret = GPIO_PIN_WRITE_LOGIC(&seg2_en,GPIO_HIGH);
            Ret = SEGMENT_WRITE_NUMBER(&seg1 , n/10);
            __delay_ms(10);
            Ret = SEGMENT_WRITE_NUMBER(&seg1 , n%10);
            Ret = GPIO_PIN_WRITE_LOGIC(&seg1_en,GPIO_HIGH);
            __delay_ms(10);
            Ret = GPIO_PIN_WRITE_LOGIC(&seg1_en,GPIO_LOW); 
        }
        n++;
    }
    return (EXIT_SUCCESS);
}

void Application_intialize(void){
    Ret = SEGMENT_INITIALIZE(&seg1);
    Ret = GPIO_PIN_INITIALIZE(&seg1_en);
    Ret = GPIO_PIN_INITIALIZE(&seg2_en);
//    Ret = SEGMENT_INITIALIZE(&seg2);
}
//
//
//SEGMENT_T seg2 = {
//    .SEGMENT_PIN[0].PORT = PORTC_INDEX,
//    .SEGMENT_PIN[0].PIN = GPIO_PIN4,
//    .SEGMENT_PIN[0].DIRECTION = GPIO_DIRECTION_OUTPUT,
//    .SEGMENT_PIN[0].LOGIC = GPIO_LOW,
//    
//    .SEGMENT_PIN[1].PORT = PORTC_INDEX,
//    .SEGMENT_PIN[1].PIN = GPIO_PIN5,
//    .SEGMENT_PIN[1].DIRECTION = GPIO_DIRECTION_OUTPUT,
//    .SEGMENT_PIN[1].LOGIC = GPIO_LOW,
//    
//    .SEGMENT_PIN[2].PORT = PORTC_INDEX,
//    .SEGMENT_PIN[2].PIN = GPIO_PIN6,
//    .SEGMENT_PIN[2].DIRECTION = GPIO_DIRECTION_OUTPUT,
//    .SEGMENT_PIN[2].LOGIC = GPIO_LOW,
//    
//    .SEGMENT_PIN[3].PORT = PORTC_INDEX,
//    .SEGMENT_PIN[3].PIN = GPIO_PIN7,
//    .SEGMENT_PIN[3].DIRECTION = GPIO_DIRECTION_OUTPUT,
//    .SEGMENT_PIN[3].LOGIC = GPIO_LOW,
//    
//    .SEGMENT_TYPE = SEGMENT_COMMON_CATHODE
//};