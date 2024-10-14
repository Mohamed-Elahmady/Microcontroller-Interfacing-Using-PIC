/* 
 * File:   ECU_CHR_LCD.c
 * Author: Mohamed Elahmady
 *
 * Created on October 5, 2024, 6:05 PM
 */

#include "ECU_CHR_LCD.h"

/************************************************************************/

// HELPER FUNCTIONS

static Std_ReturnType lcd_send_4bits(const CHR_LCD_4BIT_T *lcd , uint8 _data_command){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        for(int i = 0 ; i < 4 ; i++){
            Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->DATA_PINS[i]) , (_data_command >> i) & (uint8)0x01);
        }
    }
    return Retval;
}
static Std_ReturnType lcd_4bit_send_enable_signal(const CHR_LCD_4BIT_T *lcd){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->EN_PIN) , GPIO_HIGH);
        __delay_us(5);
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->EN_PIN) , GPIO_LOW);
    }
    return Retval;
}
static Std_ReturnType lcd_8bit_send_enable_signal(const CHR_LCD_8BIT_T *lcd){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->EN_PIN) , GPIO_HIGH);
        __delay_us(5);
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->EN_PIN) , GPIO_LOW);
    }
    return Retval;
}
static Std_ReturnType lcd_4bit_set_cursor(const CHR_LCD_4BIT_T *lcd , uint8 row , uint8 column){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->RS_PIN) , GPIO_LOW);
        column--;
        switch(row){
            case ROW1:
                Retval = LCD_4BIT_SEND_COMMAND((lcd) , (0x80 + column));
                break;
            case ROW2:
                Retval = LCD_4BIT_SEND_COMMAND((lcd) , (0xC0 + column));
                break;
            case ROW3:
                Retval = LCD_4BIT_SEND_COMMAND((lcd) , (0x94 + column));
                break;
            case ROW4:
                Retval = LCD_4BIT_SEND_COMMAND((lcd) , (0xD4 + column));
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}
static Std_ReturnType lcd_8bit_set_cursor(const CHR_LCD_8BIT_T *lcd , uint8 row , uint8 column){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->RS_PIN) , GPIO_LOW);
        column--;
        switch(row){
            case ROW1:
                Retval = LCD_8BIT_SEND_COMMAND((lcd) , (0x80 + column));
                break;
            case ROW2:
                Retval = LCD_8BIT_SEND_COMMAND((lcd) , (0xC0 + column));
                break;
            case ROW3:
                Retval = LCD_8BIT_SEND_COMMAND((lcd) , (0x94 + column));
                break;
            case ROW4:
                Retval = LCD_8BIT_SEND_COMMAND((lcd) , (0xD4 + column));
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

/************************************************************************/

// MAIN FUNCTIONS

Std_ReturnType LCD_4BIT_INITIALIZE(const CHR_LCD_4BIT_T *lcd){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_INITIALIZE(&(lcd->RS_PIN));
        Retval = GPIO_PIN_INITIALIZE(&(lcd->EN_PIN));
        for(int i = 0 ; i < 4 ; i++){
            Retval = GPIO_PIN_INITIALIZE(&(lcd->DATA_PINS[i]));
        }
        __delay_ms(20);
        Retval = LCD_4BIT_SEND_COMMAND(lcd , LCD_FNS_8BIT_DL_2LINE_F58);
        __delay_ms(5);
        Retval = LCD_4BIT_SEND_COMMAND(lcd , LCD_FNS_8BIT_DL_2LINE_F58);
        __delay_us(150);
        Retval = LCD_4BIT_SEND_COMMAND(lcd , LCD_FNS_8BIT_DL_2LINE_F58);
        
        Retval = LCD_4BIT_SEND_COMMAND(lcd , LCD_CLEAR_DISPLAY);
        Retval = LCD_4BIT_SEND_COMMAND(lcd , LCD_CURSOR_HOME);
        Retval = LCD_4BIT_SEND_COMMAND(lcd , LCD_ENTRY_MODE_INC_SHIFT_OFF);
        Retval = LCD_4BIT_SEND_COMMAND(lcd , LCD_DISPLAY_ON_ULC_OFF_BLC_OFF);
        Retval = LCD_4BIT_SEND_COMMAND(lcd , LCD_FNS_4BIT_DL_2LINE_F58);
        Retval = LCD_4BIT_SEND_COMMAND(lcd , LCD_DDRAM_START_ADD);
    }
    return Retval;
}

Std_ReturnType LCD_4BIT_SEND_COMMAND(const CHR_LCD_4BIT_T *lcd , uint8 command){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->RS_PIN) , GPIO_LOW);
        Retval = lcd_send_4bits(lcd , (command >> 4));
        Retval = lcd_4bit_send_enable_signal(lcd);
        Retval = lcd_send_4bits(lcd , (command));
        Retval = lcd_4bit_send_enable_signal(lcd);
    }
    return Retval;
}

Std_ReturnType LCD_4BIT_SEND_CHARACTER_DATA(const CHR_LCD_4BIT_T *lcd , uint8 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->RS_PIN) , GPIO_HIGH);
        Retval = lcd_send_4bits(lcd , (data >> 4));
        Retval = lcd_4bit_send_enable_signal(lcd);
        Retval = lcd_send_4bits(lcd , (data));
        Retval = lcd_4bit_send_enable_signal(lcd);
    }
    return Retval;
}

Std_ReturnType LCD_4BIT_SEND_CHARACTER_DATA_POS(const CHR_LCD_4BIT_T *lcd , uint8 row , uint8 column , uint8 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = lcd_4bit_set_cursor(lcd , row , column);
        Retval = LCD_4BIT_SEND_CHARACTER_DATA(lcd , data);
    }
    return Retval;
}

Std_ReturnType LCD_4BIT_SEND_STRING(const CHR_LCD_4BIT_T *lcd , uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        while(*str){
            Retval = LCD_4BIT_SEND_CHARACTER_DATA(lcd , *str++);
        }
    }
    return Retval;
}

Std_ReturnType LCD_4BIT_SEND_STRING_POS(const CHR_LCD_4BIT_T *lcd , uint8 row , uint8 column , uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        Retval = lcd_4bit_set_cursor(lcd , row , column);
        while(*str){
            Retval = LCD_4BIT_SEND_CHARACTER_DATA(lcd ,*str++);
        }
    }
    return Retval;
}

Std_ReturnType LCD_4BIT_SEND_CUSTOM_CHARACTER(const CHR_LCD_4BIT_T *lcd , uint8 row , uint8 column , const uint8 chr[] , uint8 mem_pos){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = LCD_4BIT_SEND_COMMAND(lcd , LCD_CGRAM_START_ADD + (mem_pos*8));
        for(uint8 i = 0 ; i < 8 ; i++){
            Retval = LCD_4BIT_SEND_CHARACTER_DATA(lcd , chr[i]);
        }
        Retval = LCD_4BIT_SEND_CHARACTER_DATA_POS(lcd , row , column , mem_pos);
    }
    return Retval;
}

/*********************************************************/

// LCD_8BIT_FUNCTIONS  

Std_ReturnType LCD_8BIT_INITIALIZE(const CHR_LCD_8BIT_T *lcd){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_INITIALIZE(&(lcd->RS_PIN));
        Retval = GPIO_PIN_INITIALIZE(&(lcd->EN_PIN));
        for(int i = 0; i < 8 ; i++){
            Retval = GPIO_PIN_INITIALIZE(&(lcd->DATA_PINS[i]));
        }
        __delay_ms(20);
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->RS_PIN) , GPIO_LOW);
        Retval = LCD_8BIT_SEND_COMMAND(lcd , LCD_FNS_8BIT_DL_2LINE_F58);
        __delay_ms(5);
        Retval = LCD_8BIT_SEND_COMMAND(lcd , LCD_FNS_8BIT_DL_2LINE_F58);
        __delay_us(150);
        Retval = LCD_8BIT_SEND_COMMAND(lcd , LCD_FNS_8BIT_DL_2LINE_F58);
        
        Retval = LCD_8BIT_SEND_COMMAND(lcd , LCD_CLEAR_DISPLAY);
        Retval = LCD_8BIT_SEND_COMMAND(lcd , LCD_CURSOR_HOME);
        Retval = LCD_8BIT_SEND_COMMAND(lcd , LCD_ENTRY_MODE_INC_SHIFT_OFF);
        Retval = LCD_8BIT_SEND_COMMAND(lcd , LCD_DISPLAY_ON_ULC_OFF_BLC_OFF);
        Retval = LCD_8BIT_SEND_COMMAND(lcd , LCD_FNS_8BIT_DL_2LINE_F58);
        Retval = LCD_8BIT_SEND_COMMAND(lcd , LCD_DDRAM_START_ADD);
    }
    return Retval;
}

Std_ReturnType LCD_8BIT_SEND_COMMAND(const CHR_LCD_8BIT_T *lcd , uint8 command){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->RS_PIN) , GPIO_LOW);
        for(int i = 0 ; i < 8 ; i++){
            Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->DATA_PINS[i]) , (command >> i) & 0x01);
        }
        Retval = lcd_8bit_send_enable_signal(lcd);
    }
    return Retval;
}

Std_ReturnType LCD_8BIT_SEND_CHARACTER_DATA(const CHR_LCD_8BIT_T *lcd , uint8 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->RS_PIN) , GPIO_HIGH);
        for(int i = 0 ; i < 8 ; i++){
            Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->DATA_PINS[i]) , (data >> i) & 0x01);
        }
        Retval = lcd_8bit_send_enable_signal(lcd);
    }
    return Retval;
}

Std_ReturnType LCD_8BIT_SEND_CHARACTER_DATA_POS(const CHR_LCD_8BIT_T *lcd , uint8 row , uint8 column , uint8 data){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = lcd_8bit_set_cursor(lcd , row , column);
        Retval = LCD_8BIT_SEND_CHARACTER_DATA(lcd , data);
    }
    return Retval;
}

Std_ReturnType LCD_8BIT_SEND_STRING(const CHR_LCD_8BIT_T *lcd , uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        while(*str){
            Retval = LCD_8BIT_SEND_CHARACTER_DATA(lcd , *str++);
        }
    }
    return Retval;
}

Std_ReturnType LCD_8BIT_SEND_STRING_POS(const CHR_LCD_8BIT_T *lcd , uint8 row , uint8 column , uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd || NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        Retval = lcd_8bit_set_cursor(lcd , row , column);
        while(*str){
            Retval = LCD_8BIT_SEND_CHARACTER_DATA(lcd , *str++);
        }
    }
    return Retval;
}


Std_ReturnType LCD_8BIT_SEND_CUSTOM_CHARACTER(const CHR_LCD_8BIT_T *lcd , uint8 row , uint8 column , uint8 chr[] , uint8 mem_pos){
    Std_ReturnType Retval = E_OK;
    if(NULL == lcd){
        Retval = E_NOT_OK;
    }
    else{
        Retval = LCD_8BIT_SEND_COMMAND(lcd , LCD_CGRAM_START_ADD + (mem_pos*8));
        for(uint8 i = 0 ; i < 8 ; i++){
            Retval = LCD_8BIT_SEND_CHARACTER_DATA(lcd , chr[i]);
        }
        Retval = LCD_8BIT_SEND_CHARACTER_DATA_POS(lcd , row , column , mem_pos);
    }
    return Retval;
}


Std_ReturnType CONVERT_CHAR_TO_STRING(uint8 data , uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        memset(str , '\0' ,4);
        sprintf(str , "%i" , data);
    }
    return Retval;
}

Std_ReturnType CONVERT_SHORT_TO_STRING(uint16 data , uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        memset(str , '\0' ,6);
        sprintf(str , "%i" , data);
    }
    return Retval;
}

Std_ReturnType CONVERT_INT_TO_STRING(uint32 data , uint8 *str){
    Std_ReturnType Retval = E_OK;
    if(NULL == str){
        Retval = E_NOT_OK;
    }
    else{
        memset(str , '\0' ,11);
        sprintf(str , "%i" , data);
    }
    return Retval;
}