/* 
 * File:   Drivers_Main.c
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:51 PM
 */

#include "Drivers_Main.h"
#define _XTAL_FREQ 4000000

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
BUTTON_T BTN1 = {
    .BUTTON_PIN.PORT = PORTD_INDEX,
    .BUTTON_PIN.PIN  = GPIO_PIN0,
    .BUTTON_PIN.DIRECTION = GPIO_DIRECTION_INPUT,
    .BUTTON_PIN.LOGIC = GPIO_LOW,               // default value not used
    .Button_connection = BUTTON_ACTIVE_HIGH,    // INPUT PULL DOWN
    .Button_st = BUTTON_RELEASED
};

BUTTON_T BTN2 = {
    .BUTTON_PIN.PORT = PORTD_INDEX,
    .BUTTON_PIN.PIN  = GPIO_PIN1,
    .BUTTON_PIN.DIRECTION = GPIO_DIRECTION_INPUT,
    .BUTTON_PIN.LOGIC = GPIO_HIGH,               // default value not used
    .Button_connection = BUTTON_ACTIVE_LOW,      // INPUT PULL UP
    .Button_st = BUTTON_RELEASED
};



BUTTON_STATE btn_high_status = BUTTON_RELEASED;
BUTTON_STATE btn_high_valid_status = BUTTON_RELEASED;
BUTTON_STATE btn_high_last_valid_status = BUTTON_RELEASED;
uint32 btn_high_valid = 0;
uint8 Program_Selected = 0;
Std_ReturnType Ret = E_NOT_OK;

int main() { 
    
    Application_intialize();
    
    //Ret = BUTTON_READ_STATUS(&BTN1,&btn_ST1);
    //Ret = LED_INITIALIZE(&led1);

    while(1){
        Ret = BUTTON_READ_STATUS(&BTN1, &btn_high_status);
        
        if(BUTTON_PRESSED == btn_high_status){
            btn_high_valid++;
            if(btn_high_valid > 500){
                btn_high_valid_status = BUTTON_PRESSED;
            }
        }
        else{
            btn_high_valid = 0;
            btn_high_valid_status = BUTTON_RELEASED;
        }
        if(btn_high_valid_status != btn_high_last_valid_status){
            btn_high_last_valid_status = btn_high_valid_status;
            if(BUTTON_PRESSED == btn_high_valid_status){
                if(Program_Selected == 3){
                    Program_Selected = 0;
                }
                Program_Selected++;
                    switch (Program_Selected){
                        case 1: program1(); break;
                        case 2: program2(); break;
                        case 3: program3(); break;
                        default: break;
                    }
            }
        }
        
    }
    return (EXIT_SUCCESS);
}

void Application_intialize(void){
    Ret = LED_INITIALIZE(&led1);
    Ret = LED_INITIALIZE(&led2);
    Ret = BUTTON_INITIALIZE(&BTN1);
    Ret = BUTTON_INITIALIZE(&BTN2);
}
void program1(void){
    Ret = LED_Turn_ON(&led1);
    __delay_ms(500);
    Ret = LED_Turn_OFF(&led1);
    __delay_ms(500);
}
void program2(void){
    for(int i = 0; i < 2; i++){
        Ret = LED_Turn_ON(&led1);
        __delay_ms(500);
        Ret = LED_Turn_OFF(&led1);
        __delay_ms(500);
    }
}
void program3(void){
    for(int i = 0; i < 3; i++){
        Ret = LED_Turn_ON(&led1);
        __delay_ms(500);
        Ret = LED_Turn_OFF(&led1);
        __delay_ms(500);
    }
}

//Std_ReturnType Ret = E_NOT_OK;
//BUTTON_STATE btn_ST1 = BUTTON_RELEASED;
//BUTTON_STATE btn_ST2 = BUTTON_RELEASED;
//uint8 count = 0;

//        Ret = BUTTON_READ_STATUS(&BTN1,&btn_ST1);
//        if((BUTTON_PRESSED == btn_ST1) && (count == 0)){
//            Ret = LED_Turn_ON(&led1);
//            count++;
//        }
//        else if ((BUTTON_PRESSED == btn_ST1) && (count == 1)){
//            Ret = LED_Turn_OFF(&led1);
//            count--;
//        }
        
//        if(BUTTON_PRESSED == btn_ST1){
//            if(count%2 == 0){
//                Ret = LED_Turn_ON(&led1);
//            }
//            else{
//                Ret = LED_Turn_OFF(&led1);
//            }
//            count++;
//        }
        
//        Ret = BUTTON_READ_STATUS(&BTN1,&btn_ST1);
//        if(BUTTON_PRESSED == btn_ST1){
//            Ret = LED_Turn_ON(&led1);
//            Ret = LED_Turn_OFF(&led1);
//        }
//        else{
//            Ret = LED_Turn_OFF(&led1);
//        }
        
//        Ret = BUTTON_READ_STATUS(&BTN2,&btn_ST2);
//        if(BUTTON_PRESSED == btn_ST2){
//            Ret = LED_Turn_ON(&led2);
//            Ret = LED_Turn_OFF(&led2);
//        }
//        else{
//            Ret = LED_Turn_OFF(&led2);
//        }


//LED_STAT led1_status = LED_OFF;

//if(btn_high_valid_status != btn_high_last_valid_status){
//            btn_high_last_valid_status = btn_high_valid_status;
//            if(BUTTON_PRESSED == btn_high_valid_status){
//                if(LED_OFF == led1_status){
//                    LED_Turn_ON(&led1);
//                    led1_status = LED_ON;
//                }
//                else{
//                    LED_Turn_OFF(&led1);
//                    led1_status = LED_OFF;
//                }
//            }
//        }