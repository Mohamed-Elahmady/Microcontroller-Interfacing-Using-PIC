/* 
 * File:   Drivers_Main.c
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:51 PM
 */

#include "Drivers_Main.h"

LED_T led1 = {
    .PORT =  PORTC_INDEX,
    .PIN  =  GPIO_PIN0,
    .LOGIC = GPIO_LOW
};
LED_T led2 = {
    .PORT =  PORTC_INDEX,
    .PIN  =  GPIO_PIN1,
    .LOGIC = GPIO_LOW
};
LED_T led3 = {
    .PORT =  PORTC_INDEX,
    .PIN  =  GPIO_PIN2,
    .LOGIC = GPIO_LOW
};
LED_T led4 = {
    .PORT =  PORTC_INDEX,
    .PIN  =  GPIO_PIN3,
    .LOGIC = GPIO_LOW
};

Std_ReturnType Ret = E_NOT_OK;

int main() {
    Application_intialize();
    while(1){
        LED_Turn_ON(&led1);
        __delay_ms(500);
        LED_Turn_OFF(&led1);
        LED_Turn_ON(&led2);
        __delay_ms(500);
        LED_Turn_OFF(&led2);
        LED_Turn_ON(&led3);
        __delay_ms(500);
        LED_Turn_OFF(&led3);
        LED_Turn_ON(&led4);
        __delay_ms(500);
        LED_Turn_OFF(&led4);
        LED_Turn_ON(&led3);
        __delay_ms(500);
        LED_Turn_OFF(&led3);
        LED_Turn_ON(&led2);
        __delay_ms(500);
        LED_Turn_OFF(&led2);
        
        LED_Turn_ON(&led1);
        __delay_ms(500);
        LED_TOGGLE(&led1);
        __delay_ms(500);
    }
    return (EXIT_SUCCESS);
}

void Application_intialize(void){
    Ret = LED_INITIALIZE (&led1);
    Ret = LED_INITIALIZE (&led2);
    Ret = LED_INITIALIZE (&led3);
    Ret = LED_INITIALIZE (&led4);
}








//PIN_CONFIG_T LED_1 = {
//    .PORT = PORTC_INDEX,
//    .PIN  = GPIO_PIN0,
//    .DIRECTION = GPIO_DIRECTION_OUTPUT,
//    .LOGIC = GPIO_LOW
//};
//
//PIN_CONFIG_T LED_2 = {
//    .PORT = PORTC_INDEX,
//    .PIN  = GPIO_PIN1,
//    .DIRECTION = GPIO_DIRECTION_OUTPUT,
//    .LOGIC = GPIO_LOW
//};
//PIN_CONFIG_T LED_3 = {
//    .PORT = PORTC_INDEX,
//    .PIN  = GPIO_PIN2,
//    .DIRECTION = GPIO_DIRECTION_OUTPUT,
//    .LOGIC = GPIO_LOW
//};
//
//PIN_CONFIG_T PB = {
//    .PORT = PORTD_INDEX,
//    .PIN  = GPIO_PIN0,
//    .DIRECTION = GPIO_DIRECTION_INPUT,
//    //.LOGIC = GPIO_LOW
//};
//
//Std_ReturnType Retval = E_NOT_OK;
//DIRECTION_T DIRECT;
//LOGIC_T log;
//uint8 Direct;
//uint8 Log;





//    Retval = GPIO_PIN_DIRECTION_INTIALIZE (&LED_1);
//    Retval = GPIO_PIN_WRITE_LOGIC(&LED_1,GPIO_HIGH);
//    Retval = GPIO_PIN_GET_DIRECTION_STATUS(&LED_1,&DIRECT);
//    
//    Retval = GPIO_PIN_DIRECTION_INTIALIZE (&LED_2);
//    Retval = GPIO_PIN_WRITE_LOGIC(&LED_2,GPIO_HIGH);
//    Retval = GPIO_PIN_GET_DIRECTION_STATUS(&LED_1,&DIRECT);
//    
//    Retval = GPIO_PIN_DIRECTION_INTIALIZE (&LED_3);
//    Retval = GPIO_PIN_WRITE_LOGIC(&LED_3,GPIO_HIGH);
//    Retval = GPIO_PIN_DIRECTION_INTIALIZE (NULL);
    
//    Retval = GPIO_PIN_DIRECTION_INTIALIZE (&PB);
//    Retval = GPIO_PORT_DIRECTION_INTIALIZE(LED_1.PORT,0X00);
//    Retval = GPIO_PORT_GET_DIRECTION_STATUS(LED_1.PORT,&Direct);
//    
//    while (1){
//        Retval = GPIO_PIN_READ_LOGIC(&PB,&log);
//        GPIO_PIN_TOGGLE_LOGIC(&LED_1);
//        GPIO_PIN_TOGGLE_LOGIC(&LED_2);
//__delay_ms(250);
//Application_intialize();
//        Application_intialize();
//    }


//void Application_intialize(void){
//    Retval = GPIO_PIN_DIRECTION_INTIALIZE (&LED_1);
//    Retval = GPIO_PIN_DIRECTION_INTIALIZE (&LED_2);
//    Retval = GPIO_PIN_DIRECTION_INTIALIZE (&LED_3);
//    Retval = GPIO_PIN_DIRECTION_INTIALIZE (&PB);
    
//    Retval = GPIO_PORT_WRITE_LOGIC(LED_1.PORT,0x55);
//    Retval = GPIO_PORT_READ_LOGIC(LED_1.PORT,&Log);
//    __delay_ms(100);
//    Retval = GPIO_PORT_TOGGLE_LOGIC(LED_1.PORT);
//    Retval = GPIO_PORT_READ_LOGIC(LED_1.PORT,&Log);
//    __delay_ms(100);
//}

/*************** struct and union with Bit Manipulation *******************/
//        SELF_LATC_REG -> LATC_REG = 0x55;
//        __delay_ms(500);
//        D_SELF_LATC_REG . SELF_LATC0 = 0;
//        D_SELF_LATC_REG . SELF_LATC2 = 0;
//        D_SELF_LATC_REG . SELF_LATC4 = 0;
//        D_SELF_LATC_REG . SELF_LATC6 = 0;
//        D_SELF_LATC_REG . SELF_LATC1 = 1;
//        D_SELF_LATC_REG . SELF_LATC3 = 1;
//        D_SELF_LATC_REG . SELF_LATC5 = 1;
//        D_SELF_LATC_REG . SELF_LATC7 = 1;
//        __delay_ms(500);
          /*************** For LED *******************/
//        Mohamed_LATC = 0x02;
//        __delay_ms(1000);
//        Mohamed_LATC = 0x04; 
//        __delay_ms(1000);
//        for(int i = 0; i < 8; i++){
//        Mohamed_LATC |= (1 << i);
//        __delay_ms(50);
//        }
//        for(int i = 7; i >= 0 ; i--){
//        Mohamed_LATC ^= (1 << i);
//        __delay_ms(50);
//        }
        /*************** For LED _ PushButton *******************/
//        if(PORTD == 0x01)
//        {
//        Mohamed_LATC |= ((uint8_t)(1 << 0)| (uint8_t)(1 << 7));
//        __delay_ms(50);
//        Mohamed_LATC |= ((uint8_t)(1 << 1)| (uint8_t)(1 << 6));
//        __delay_ms(50);
//        Mohamed_LATC |= ((uint8_t)(1 << 2)| (uint8_t)(1 << 5));
//        __delay_ms(50);
//        Mohamed_LATC |= ((uint8_t)(1 << 3)| (uint8_t)(1 << 4));
//        __delay_ms(50);
//        Mohamed_LATC = 0x00;
//        __delay_ms(50);
//        }



/*
 #define HWREG8(_x) (*((volatile uint8_t *)(_x)))
#define Mohamed_TRISC HWREG8(0xF94)
//#define Mohamed_LATC HWREG8(0xF8B)
//#define Mohamed_TRISD HWREG8(0xF95)
//#define Mohamed_PORTD HWREG8(0xF83)
#define _XTAL_FREQ 8000000
//
//
//#define SET_BIT(REG,BIT_POSITION) (REG |= (1 << BIT_POSITION))
//#define CLEAR_BIT(REG,BIT_POSITION) (REG &= ~(1 << BIT_POSITION))
//#define TOAGLE_BIT(REG,BIT_POSITION) (REG ^= (1 << BIT_POSITION))
//
//#define SET_BIT_BY_REGISTER_ADDRESS(REG_ADDR,BIT_POSITION) (*REG_ADDR |= (1 << BIT_POSITION))
//#define CLEAR_BIT_BY_REGISTER_ADDRESS(REG_ADDR,BIT_POSITION) (*REG_ADDR &= ~(1 << BIT_POSITION))
//#define TOAGLE_BIT_BY_REGISTER_ADDRESS(REG_ADDR,BIT_POSITION) (*REG_ADDR ^= (1 << BIT_POSITION))

//typedef union {
//    struct{
//        unsigned SELF_LATC0             :1;
//        unsigned SELF_LATC1             :1;
//        unsigned SELF_LATC2             :1;
//        unsigned SELF_LATC3             :1;
//        unsigned SELF_LATC4             :1;
//        unsigned SELF_LATC5             :1;
//        unsigned SELF_LATC6             :1;
//        unsigned SELF_LATC7             :1;
//    };
//    uint8_t LATC_REG;
//}SELF_LATC;
//
//#define SELF_LATC_REG      ((volatile SELF_LATC *)(0xF8B))
//#define D_SELF_LATC_REG    (*((volatile SELF_LATC *)(0xF8B)))
 */