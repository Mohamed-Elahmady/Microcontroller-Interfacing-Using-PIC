/* 
 * File:   ECU_CHR_LCD.h
 * Author: Mohamed Elahmady
 *
 * Created on October 5, 2024, 6:05 PM
 */

/* Section 0 : File Guard */

#ifndef ECU_CHR_LCD_H
#define	ECU_CHR_LCD_H

/* Section 1 : Includes */

#include "../../MCAL/GPIO/HAL_GPIO.h"
#include "../../MCAL/Interrupt/MCAL_internal_interrupt.h"
#include "../../MCAL/Interrupt/MCAL_external_interrupt.h"
#include "ECU_CHR_LCD_CFG.h"

/* Section 2 : Macros Declarations */

/*    CLEAR_DIPLAY    */
#define LCD_CLEAR_DISPLAY                   0x01

/*    CURSOR_HOME    */
#define LCD_CURSOR_HOME                     0x02

/*    ENTRY_MODE_SET    */
#define LCD_ENTRY_MODE_DEC_SHIFT_OFF        0x04
#define LCD_ENTRY_MODE_DEC_SHIFT_ON         0x05
#define LCD_ENTRY_MODE_INC_SHIFT_OFF        0x06
#define LCD_ENTRY_MODE_INC_SHIFT_ON         0x07

/*    DIPLAY ON/OFF    */
#define LCD_DISPLAY_OFF_ULC_OFF_BLC_OFF     0x08
#define LCD_DISPLAY_ON_ULC_OFF_BLC_OFF      0x0C
#define LCD_DISPLAY_ON_ULC_OFF_BLC_ON       0x0D
#define LCD_DISPLAY_ON_ULC_ON_BLC_OFF       0x0E
#define LCD_DISPLAY_ON_ULC_ON_BLC_ON        0x0F

/*    MOVE_CURSOR_AND_SHIFT_DISPLAY    */
#define LCD_MOVE_CURSOR_LEFT                0x10
#define LCD_MOVE_CURSOR_RIGHT               0x14
#define LCD_SHIFT_DISPLAY_LEFT              0x18
#define LCD_SHIFT_DISPLAY_RIGHT             0x1C

/*    FUNCTION_SET_4BIT_LCD    */
#define LCD_FNS_4BIT_DL_1LINE_F58           0x20
#define LCD_FNS_4BIT_DL_1LINE_F511          0x24
#define LCD_FNS_4BIT_DL_2LINE_F58           0x28
#define LCD_FNS_4BIT_DL_2LINE_F511          0x2C

/*    FUNCTION_SET_8BIT_LCD    */
#define LCD_FNS_8BIT_DL_1LINE_F58           0x30
#define LCD_FNS_8BIT_DL_1LINE_F511          0x34
#define LCD_FNS_8BIT_DL_2LINE_F58           0x38
#define LCD_FNS_8BIT_DL_2LINE_F511          0x3C

/*    CGRAM_START_ADDRESS    */
#define LCD_CGRAM_START_ADD                 0x40
/*    DDRAM_START_ADDRESS    */
#define LCD_DDRAM_START_ADD                 0x80

/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */

typedef enum{
    ROW1 = 1,
    ROW2,
    ROW3,
    ROW4
}ROW_T;

typedef struct {
    PIN_CONFIG_T RS_PIN;
    PIN_CONFIG_T EN_PIN;
    PIN_CONFIG_T DATA_PINS[4];
}CHR_LCD_4BIT_T;

typedef struct {
    PIN_CONFIG_T RS_PIN;
    PIN_CONFIG_T EN_PIN;
    PIN_CONFIG_T DATA_PINS[8];
}CHR_LCD_8BIT_T;

/* Section 5 : Functions Declarations */

Std_ReturnType LCD_4BIT_INITIALIZE(const CHR_LCD_4BIT_T *lcd);
Std_ReturnType LCD_4BIT_SEND_COMMAND(const CHR_LCD_4BIT_T *lcd , uint8 command);
Std_ReturnType LCD_4BIT_SEND_CHARACTER_DATA(const CHR_LCD_4BIT_T *lcd , uint8 data);
Std_ReturnType LCD_4BIT_SEND_CHARACTER_DATA_POS(const CHR_LCD_4BIT_T *lcd , uint8 row , uint8 column , uint8 data);
Std_ReturnType LCD_4BIT_SEND_STRING(const CHR_LCD_4BIT_T *lcd , uint8 *str);
Std_ReturnType LCD_4BIT_SEND_STRING_POS(const CHR_LCD_4BIT_T *lcd , uint8 row , uint8 column , uint8 *str);
Std_ReturnType LCD_4BIT_SEND_CUSTOM_CHARACTER(const CHR_LCD_4BIT_T *lcd , uint8 row , uint8 column , const uint8 chr[] , uint8 mem_pos);

Std_ReturnType LCD_8BIT_INITIALIZE(const CHR_LCD_8BIT_T *lcd);
Std_ReturnType LCD_8BIT_SEND_COMMAND(const CHR_LCD_8BIT_T *lcd , uint8 command);
Std_ReturnType LCD_8BIT_SEND_CHARACTER_DATA(const CHR_LCD_8BIT_T *lcd , uint8 data);
Std_ReturnType LCD_8BIT_SEND_CHARACTER_DATA_POS(const CHR_LCD_8BIT_T *lcd , uint8 row , uint8 column , uint8 data);
Std_ReturnType LCD_8BIT_SEND_STRING(const CHR_LCD_8BIT_T *lcd , uint8 *str);
Std_ReturnType LCD_8BIT_SEND_STRING_POS(const CHR_LCD_8BIT_T *lcd , uint8 row , uint8 column , uint8 *str);
Std_ReturnType LCD_8BIT_SEND_CUSTOM_CHARACTER(const CHR_LCD_8BIT_T *lcd , uint8 row , uint8 column , uint8 chr[] , uint8 mem_pos);

Std_ReturnType CONVERT_CHAR_TO_STRING(uint8 data , uint8 *str);
Std_ReturnType CONVERT_SHORT_TO_STRING(uint16 data , uint8 *str);
Std_ReturnType CONVERT_INT_TO_STRING(uint32 data , uint8 *str);

#endif	/* ECU_CHR_LCD_H */

