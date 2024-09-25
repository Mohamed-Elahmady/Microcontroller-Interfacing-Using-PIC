/* 
 * File:   HAL_GPIO.h
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:55 PM
 */

/* Section 0 : File Guard */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* Section 1 : Includes */

#include "pic18f46k20.h"
#include "../MCAL_STD_Types.h"
#include "../Device_Config.h"
#include "HAL_GPIO_CFG.h"

/* Section 2 : Macros Declarations */
#define BIT_MASK        (uint8)0x01
#define PORT_MASK       (uint8)0xFF

#define PORT_PIN_MAX       8
#define PORT_MAX           5



/* Section 3 : Macros Functions Declarations */
#define SET_BIT(REG,BIT_POSN)         (REG |= ((BIT_MASK) << BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)       (REG &= ~((BIT_MASK) << BIT_POSN))
#define TOGGLE_BIT(REG,BIT_POSN)      (REG ^= ((BIT_MASK) << BIT_POSN))
#define READ_BIT(REG,BIT_POSN)        ((REG >> BIT_POSN) & (BIT_MASK))  


/* Section 4 : User Defined Data Types Declarations */

// enum for LAT LOGIC => (LOW/HIGH)
typedef enum {
    GPIO_LOW = 0,
    GPIO_HIGH
}LOGIC_T;

// enum for TRIS DIRECTION => (OUTPUT/INPUT)
typedef enum {
    GPIO_DIRECTION_OUTPUT = 0,
    GPIO_DIRECTION_INPUT
}DIRECTION_T;

typedef enum {
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}PIN_INDEX_T;

typedef enum {
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}PORT_INDEX_T;

typedef struct{
    uint8 PORT             :3;        /*    @ref PORT_INDEX_T       */    // 3 is the Number of BITS 
    uint8 PIN              :3;         /*    @ref PIN_INDEX_T      */    // 3 is the Number of BITS
    uint8 DIRECTION        :1;          /*    @ref DIRECTION_T    */    // 1 is the Number of BITS
    uint8 LOGIC            :1;           /*    @ref LOGIC_T      */    // 1 is the Number of BITS
}PIN_CONFIG_T;

/* Section 5 : Functions Declarations */

/**************** GPIO FOR PINS *********************/
Std_ReturnType GPIO_PIN_DIRECTION_INITIALIZE (const PIN_CONFIG_T *_PIN_CONFIG);
Std_ReturnType GPIO_PIN_GET_DIRECTION_STATUS (const PIN_CONFIG_T *_PIN_CONFIG,DIRECTION_T *DIRECTION_STATUS);
Std_ReturnType GPIO_PIN_WRITE_LOGIC (const PIN_CONFIG_T *_PIN_CONFIG,LOGIC_T LOGIC);
Std_ReturnType GPIO_PIN_READ_LOGIC (const PIN_CONFIG_T *_PIN_CONFIG,LOGIC_T *LOGIC);
Std_ReturnType GPIO_PIN_TOGGLE_LOGIC (const PIN_CONFIG_T *_PIN_CONFIG);
Std_ReturnType GPIO_PIN_INITIALIZE (const PIN_CONFIG_T *_PIN_CONFIG);  // With Output Devices Only

/**************** GPIO FOR PORTS *********************/
Std_ReturnType GPIO_PORT_DIRECTION_INITIALIZE (PORT_INDEX_T PORT,uint8 DIRECTION);
Std_ReturnType GPIO_PORT_GET_DIRECTION_STATUS (PORT_INDEX_T PORT,uint8 *DIRECTION_STATUS);
Std_ReturnType GPIO_PORT_WRITE_LOGIC (PORT_INDEX_T PORT,uint8 LOGIC);
Std_ReturnType GPIO_PORT_READ_LOGIC (PORT_INDEX_T PORT,uint8 *LOGIC);
Std_ReturnType GPIO_PORT_TOGGLE_LOGIC (PORT_INDEX_T PORT);


#endif	/* HAL_GPIO_H */

