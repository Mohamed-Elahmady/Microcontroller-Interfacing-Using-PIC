/* 
 * File:   Drivers_Main.c
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:51 PM
 */

#include "Drivers_Main.h"

void one_line_welcome_shift(void);
void welcome_message(void);
void Loading_Screen(void);

Std_ReturnType Ret = E_NOT_OK;

uint8 left_half[8] = { 0x00, 0x00, 0x02, 0x07, 0x03, 0x01, 0x00, 0x00 };
uint8 right_half[8] = { 0x00, 0x00, 0x08, 0x1C, 0x18, 0x10, 0x00, 0x00 };
uint8 completed_heart[8] = { 0x00, 0x00, 0x0A, 0x1F, 0x0E, 0x04, 0x00, 0x00 };

uint8 charge_battery_00[8] = { 0x0E, 0x1F, 0x11, 0x11, 0x11, 0x11, 0x1F, 0x1F };
uint8 charge_battery_25[8] = { 0x0E, 0x1F, 0x11, 0x11, 0x11, 0x1F, 0x1F, 0x1F };
uint8 charge_battery_50[8] = { 0x0E, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F };
uint8 charge_battery_75[8] = { 0x0E, 0x1F, 0x11, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F };
uint8 charge_battery_100[8] = { 0x0E, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F };

int main() { 
    Application_intialize();
    while(1){
//        Ret = LCD_8BIT_SEND_CUSTOM_CHARACTER(&lcd2 , 1 , 1 , left_half , 0x00 );
//        Ret = LCD_8BIT_SEND_CUSTOM_CHARACTER(&lcd2 , 1 , 2 , right_half , 0x01 );
//        Ret = LCD_4BIT_SEND_CUSTOM_CHARACTER(&lcd1 , 1 , 1 , left_half , 0x00 );
//        Ret = LCD_4BIT_SEND_CUSTOM_CHARACTER(&lcd1 , 1 , 2 , right_half , 0x01 );
//        
//        Ret = LCD_8BIT_SEND_CUSTOM_CHARACTER(&lcd2 , 1 , 3 , completed_heart , 0x02 );
//        Ret = LCD_4BIT_SEND_CUSTOM_CHARACTER(&lcd1 , 1 , 3 , completed_heart , 0x02 );
        
        Ret = LCD_4BIT_SEND_CUSTOM_CHARACTER(&lcd1 , 1 , 20 , charge_battery_00 , 0x00 );
        Ret = LCD_8BIT_SEND_CUSTOM_CHARACTER(&lcd2 , 1 , 20 , charge_battery_00 , 0x00 );
        __delay_ms(500);
        Ret = LCD_4BIT_SEND_CUSTOM_CHARACTER(&lcd1 , 1 , 20 , charge_battery_25 , 0x01 );
        Ret = LCD_8BIT_SEND_CUSTOM_CHARACTER(&lcd2 , 1 , 20 , charge_battery_25 , 0x01 );
        __delay_ms(500);
        Ret = LCD_4BIT_SEND_CUSTOM_CHARACTER(&lcd1 , 1 , 20 , charge_battery_50 , 0x02 );
        Ret = LCD_8BIT_SEND_CUSTOM_CHARACTER(&lcd2 , 1 , 20 , charge_battery_50 , 0x02 );
        __delay_ms(500);
        Ret = LCD_4BIT_SEND_CUSTOM_CHARACTER(&lcd1 , 1 , 20 , charge_battery_75 , 0x03 );
        Ret = LCD_8BIT_SEND_CUSTOM_CHARACTER(&lcd2 , 1 , 20 , charge_battery_75 , 0x03 );
        __delay_ms(500);
        Ret = LCD_4BIT_SEND_CUSTOM_CHARACTER(&lcd1 , 1 , 20 , charge_battery_100 , 0x04 );
        Ret = LCD_8BIT_SEND_CUSTOM_CHARACTER(&lcd2 , 1 , 20 , charge_battery_100 , 0x04 );
        __delay_ms(500);

    }
    return (EXIT_SUCCESS);
}

void Application_intialize(void){
    ECU_LAYER_INITIALIZE();
}

void one_line_welcome_shift(void){
    for(uint8 i = 1 ; i < 12 ; i++){
        Ret = LCD_4BIT_SEND_STRING_POS(&lcd1 , 1 , i , "HELLO_ALL");
        __delay_ms(250);
        Ret = LCD_4BIT_SEND_CHARACTER_DATA_POS(&lcd1 , 1 , i , ' ');  
    }
    Ret = LCD_4BIT_SEND_STRING_POS(&lcd1 , 1 , 1 , "                    ");
    for(uint8 i = 12 ; i > 0 ; i--){
        Ret = LCD_4BIT_SEND_STRING_POS(&lcd1 , 1 , i , "HELLO_ALL");
        __delay_ms(250);
        if(i > 1){
        Ret = LCD_4BIT_SEND_CHARACTER_DATA_POS(&lcd1 , 1 , i+8 , ' ');  
        }
    }
}

void welcome_message(void){
    for(uint8 i = 1 ; i <= 5 ; i++){
        Ret = LCD_4BIT_SEND_STRING_POS(&lcd1 , 1 , 7 , "HELLO_ALL");
        Ret = LCD_4BIT_SEND_STRING_POS(&lcd1 , 2 , 3 , "Embedded_Diploma");
        __delay_ms(500);
        Ret = LCD_4BIT_SEND_COMMAND(&lcd1 , LCD_CLEAR_DISPLAY);
        __delay_ms(100);
    }
}

void Loading_Screen(void){
    Ret = LCD_8BIT_SEND_STRING_POS(&lcd2 , 1 , 1 , "Loading");
    for(uint8 i = 8 ; i < 11 ; i++){
        Ret = LCD_8BIT_SEND_CHARACTER_DATA_POS(&lcd2 , 1 , i , '.');
        __delay_ms(250);
    }
//    Ret = LCD_8BIT_SEND_COMMAND(&lcd2 , LCD_CLEAR_DISPLAY);
    Ret = LCD_8BIT_SEND_STRING_POS(&lcd2 , 1 , 8 , "        ");
}



//    Ret = LCD_4BIT_SEND_CHARACTER_DATA(&lcd1 , 'T');
//    Ret = LCD_8BIT_SEND_CHARACTER_DATA(&lcd2 , 'P');
//    Ret = LCD_4BIT_SEND_STRING(&lcd1 , "MOHAMMED");
//    Ret = LCD_8BIT_SEND_STRING(&lcd2 , "MARIAM");
//        Ret = LCD_4BIT_SEND_CHARACTER_DATA_POS(&lcd1 , 3 , 6 , 'L');
//        Ret = LCD_8BIT_SEND_CHARACTER_DATA_POS(&lcd2 , 3 , 6 , 'L');
//        Ret = LCD_4BIT_SEND_STRING_POS(&lcd1 , 3 , 6 , "LMAN");
//        Ret = LCD_8BIT_SEND_STRING_POS(&lcd2 , 3 , 6 , "LMAN");





//RIGHT SHIFT FOR ONE LINE
//        for(uint8 i = 5 ; i < 10 ; i++){
//            Ret = LCD_4BIT_SEND_STRING_POS(&lcd1 , 1 , i , "HELLO_ALL");
//            __delay_ms(250);
//            Ret = LCD_4BIT_SEND_CHARACTER_DATA_POS(&lcd1 , 1 , i , ' ');  
//        }
//        Ret = LCD_4BIT_SEND_STRING_POS(&lcd1 , 1 , 5 , "             ");
//        //LEFT SHIFT FOR ONE LINE
//        for(uint8 i = 10 ; i > 5 ; i--){
//            Ret = LCD_4BIT_SEND_STRING_POS(&lcd1 , 1 , i , "HELLO_ALL");
//            __delay_ms(250);
//            Ret = LCD_4BIT_SEND_CHARACTER_DATA_POS(&lcd1 , 1 , i+8 , ' ');  
//        } 


//uint8 lcd_counter = 0; // lcd = 245 => "245"
//uint8 lcd_counter_str[4];
//Ret = LCD_8BIT_SEND_STRING_POS(&lcd2 , 1 , 1 , "Counter : ");
//Ret = CONVERT_CHAR_TO_STRING(lcd_counter , lcd_counter_str);
//        Ret = LCD_8BIT_SEND_STRING_POS(&lcd2 , 1 , 11 , lcd_counter_str);
//        if(lcd_counter < ((pow(2,8))-1)){
//            lcd_counter++;
//        }
//        else{
//            lcd_counter = 0;
//            Ret = LCD_8BIT_SEND_STRING_POS(&lcd2 , 1 , 10 , "                            ");  
//        }
//        __delay_ms(20);