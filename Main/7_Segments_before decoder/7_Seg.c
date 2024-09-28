/* 
 * File:   Drivers_Main.c
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:51 PM
 */

#include "Drivers_Main.h"

uint8 seg7_ca[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
uint8 seg7_cc[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
uint8 c = 0;
uint8 cc = 0;
Std_ReturnType Ret = E_NOT_OK;

int main() { 
    Application_intialize();
    while(1){
//        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,0xC0);
//        __delay_ms(1000);
//        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,0xF9);
//        __delay_ms(1000);
//        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,0xA4);
//        __delay_ms(1000);
//        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,0xB0);
//        __delay_ms(1000);
//        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,0x99);
//        __delay_ms(1000);
//        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,0x92);
//        __delay_ms(1000);
        //Counter_7_Segment();
        Counter_7_Segment();
    }
    return (EXIT_SUCCESS);
}

void Application_intialize(void){
    Ret = GPIO_PORT_DIRECTION_INITIALIZE(PORTC_INDEX,0x80);
    Ret = GPIO_PORT_DIRECTION_INITIALIZE(PORTD_INDEX,0x80);
}
void Counter_7_Segment(void){
    for(int i = 0;i < 100;i++){
        if((i%10) == 0){
            c = 0;
            GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,seg7_ca[c]);
            GPIO_PORT_WRITE_LOGIC(PORTD_INDEX,seg7_ca[cc]);
            c++;
            cc++;
            __delay_ms(100);
        }
        else{
            Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,seg7_ca[c]);
            c++;
            __delay_ms(100);
        }
        if(i == 99){
            c = 0;
            cc = 0;
            GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,seg7_ca[c]);
            GPIO_PORT_WRITE_LOGIC(PORTD_INDEX,seg7_ca[cc]);
        }
    }
    for(int i = 0; i < 10 ; i++){
        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,seg7_ca[0]);
        Ret = GPIO_PORT_WRITE_LOGIC(PORTD_INDEX,seg7_ca[i]);
        for(int j = 0; j < 10 ; j++){
        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,seg7_ca[j]);
        __delay_ms(100);
        }
    }
}
void Seconds_7_Segment(void){
    for(int i = 0; i < 6 ; i++){
        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,seg7_ca[0]);
        Ret = GPIO_PORT_WRITE_LOGIC(PORTD_INDEX,seg7_ca[i]);
        for(int j = 0; j < 10 ; j++){
        Ret = GPIO_PORT_WRITE_LOGIC(PORTC_INDEX,seg7_ca[j]);
        __delay_ms(100);
        }
    }
}