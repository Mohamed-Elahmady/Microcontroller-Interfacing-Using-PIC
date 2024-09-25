/* 
 * File:   HAL_GPIO.c
 * Author: Mohamed Elahmady
 * Created on September 9, 2024, 5:55 PM
 */

#include "HAL_GPIO.h"

//Reference to TRIS Register (To Control Ports Direction in Each Port)
volatile uint8 *TRIS_REG[] = {&TRISA,&TRISB,&TRISC,&TRISD,&TRISE};
//Reference to PORT Register (To Read Ports Status)
volatile uint8 *PORT_REG[] = {&PORTA,&PORTB,&PORTC,&PORTD,&PORTE};
//Reference to LAT Register (To Write/Read at Ports)
volatile uint8 *LAT_REG[] = {&LATA  ,&LATB ,&LATC ,&LATD ,&LATE };



/**************** GPIO FOR PINS *********************/

/**
 * 
 * @brief Intialize The Direcion of Specific Pin     // @ref DIRECTION_T
 * @param  _PIN_CONFIG Pointer to Pin Configuration  // @ref PIN_CONFIG_T
 * @return Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
#if GPIO_PORT_PIN_CONFIG == GPIO_CONFIG_ENABLE          // PRE COMPILE CONFIGURATION
Std_ReturnType GPIO_PIN_DIRECTION_INITIALIZE (const PIN_CONFIG_T *_PIN_CONFIG){
    Std_ReturnType Retval = E_NOT_OK;
    if(NULL == _PIN_CONFIG || _PIN_CONFIG->PIN >= PORT_PIN_MAX){
        Retval = E_NOT_OK;
    }
    else{
        switch(_PIN_CONFIG->DIRECTION){
            case GPIO_DIRECTION_OUTPUT:
                CLEAR_BIT(*TRIS_REG[_PIN_CONFIG->PORT],_PIN_CONFIG->PIN);
                Retval = E_OK;
                break;
            case GPIO_DIRECTION_INPUT:
                SET_BIT(*TRIS_REG[_PIN_CONFIG->PORT],_PIN_CONFIG->PIN);
                Retval = E_OK;
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}
#endif

/**
 * @brief Get The Direcion of Specific Pin     // @ref DIRECTION_T
 * @param  _PIN_CONFIG      Pointer to Pin Configuration  // @ref PIN_CONFIG_T
 * @param DIRECTION_STATUS  pointer to return pin direction
 * @return                   Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
#if GPIO_PORT_PIN_CONFIG == GPIO_CONFIG_ENABLE          // PRE COMPILE CONFIGURATION
Std_ReturnType GPIO_PIN_GET_DIRECTION_STATUS (const PIN_CONFIG_T *_PIN_CONFIG,DIRECTION_T *DIRECTION_STATUS){
    Std_ReturnType Retval= E_NOT_OK;
    if(NULL == _PIN_CONFIG || NULL == DIRECTION_STATUS || _PIN_CONFIG->PIN >= PORT_PIN_MAX){
        Retval= E_NOT_OK;
    }
    else{
    *DIRECTION_STATUS = READ_BIT(*TRIS_REG[_PIN_CONFIG->PORT],_PIN_CONFIG->PIN);
    Retval = E_OK;
    }
    
    return Retval;
}
#endif
/**
 * 
 * @param  _PIN_CONFIG Pointer to Pin Configuration  // @ref PIN_CONFIG_T
 * @param LOGIC        Variable to Write Pin Logic
 * @return             Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
#if GPIO_PORT_PIN_CONFIG == GPIO_CONFIG_ENABLE          // PRE COMPILE CONFIGURATION
Std_ReturnType GPIO_PIN_WRITE_LOGIC (const PIN_CONFIG_T *_PIN_CONFIG,LOGIC_T LOGIC){
    Std_ReturnType Retval= E_NOT_OK;
    if(NULL == _PIN_CONFIG || _PIN_CONFIG->PIN >= PORT_PIN_MAX){
        Retval= E_NOT_OK;
    }
    else{
        switch(LOGIC){
            case GPIO_LOW:
                CLEAR_BIT(*LAT_REG[_PIN_CONFIG->PORT],_PIN_CONFIG->PIN);
                Retval = E_OK;
                break;
            case GPIO_HIGH:
                SET_BIT(*LAT_REG[_PIN_CONFIG->PORT],_PIN_CONFIG->PIN);
                Retval = E_OK;
                break;
            default :
                Retval= E_NOT_OK;
                break;
        }
    }
    return Retval;
}
#endif
/**
 * 
 * @param  _PIN_CONFIG Pointer to Pin Configuration  // @ref PIN_CONFIG_T
 * @param LOGIC        pointer to return pin status
 * @return             Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
#if GPIO_PORT_PIN_CONFIG == GPIO_CONFIG_ENABLE          // PRE COMPILE CONFIGURATION
Std_ReturnType GPIO_PIN_READ_LOGIC (const PIN_CONFIG_T *_PIN_CONFIG,LOGIC_T *LOGIC){
    Std_ReturnType Retval= E_NOT_OK;
    if(NULL == _PIN_CONFIG || NULL == LOGIC || _PIN_CONFIG->PIN >= PORT_PIN_MAX){
        Retval= E_NOT_OK;
    }
    else{
        *LOGIC = READ_BIT(*PORT_REG[_PIN_CONFIG->PORT],_PIN_CONFIG->PIN);
        Retval = E_OK;
    }
    return Retval;
}
#endif
/**
 * 
 * @param  _PIN_CONFIG Pointer to Pin Configuration  // @ref PIN_CONFIG_T
 * @return Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
#if GPIO_PORT_PIN_CONFIG == GPIO_CONFIG_ENABLE          // PRE COMPILE CONFIGURATION
Std_ReturnType GPIO_PIN_TOGGLE_LOGIC (const PIN_CONFIG_T *_PIN_CONFIG){
    Std_ReturnType Retval= E_NOT_OK;
    if(NULL == _PIN_CONFIG || _PIN_CONFIG->PIN >= PORT_PIN_MAX){
        Retval= E_NOT_OK;
    }
    else{
        TOGGLE_BIT(*LAT_REG[_PIN_CONFIG->PORT],_PIN_CONFIG->PIN);
        Retval = E_OK;
    }
    return Retval;
}
#endif
/**
 * 
 * @param  _PIN_CONFIG Pointer to Pin Configuration  // @ref PIN_CONFIG_T
 * @return Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
#if GPIO_PORT_PIN_CONFIG == GPIO_CONFIG_ENABLE          // PRE COMPILE CONFIGURATION
Std_ReturnType GPIO_PIN_INITIALIZE (const PIN_CONFIG_T *_PIN_CONFIG){
    Std_ReturnType Retval = E_NOT_OK;
    if(NULL == _PIN_CONFIG || _PIN_CONFIG->PIN >= PORT_PIN_MAX){
        Retval = E_NOT_OK;
    }
    else{
        GPIO_PIN_DIRECTION_INITIALIZE(_PIN_CONFIG);
        GPIO_PIN_WRITE_LOGIC(_PIN_CONFIG,_PIN_CONFIG->LOGIC);
        Retval = E_OK;
    }
    return Retval;
}
#endif

/**************** GPIO FOR PORTS *********************/


/**
 * 
 * @param PORT         variable assign port_index
 * @param DIRECTION    variable assign port_direction
 * @return             Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action 
 */
#if GPIO_PORT_CONFIG == GPIO_CONFIG_ENABLE
Std_ReturnType GPIO_PORT_DIRECTION_INITIALIZE (PORT_INDEX_T PORT,uint8 DIRECTION){
    Std_ReturnType Retval= E_NOT_OK;
    if(PORT >= PORT_MAX){
        Retval= E_NOT_OK;
    }
    else{
        *TRIS_REG[PORT] = DIRECTION;
        Retval= E_OK;
    }
    return Retval;
}
#endif
/**
 * 
 * @param PORT               variable assign port_index
 * @param DIRECTION_STATUS   pointer return port direction
 * @return                   Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
#if GPIO_PORT_CONFIG == GPIO_CONFIG_ENABLE
Std_ReturnType GPIO_PORT_GET_DIRECTION_STATUS (PORT_INDEX_T PORT,uint8 *DIRECTION_STATUS){
    Std_ReturnType Retval= E_NOT_OK;
    if(NULL == DIRECTION_STATUS || PORT >= PORT_MAX){
        Retval= E_NOT_OK;
    }
    else{
        *DIRECTION_STATUS = *TRIS_REG[PORT];
    }
    return Retval;
}
#endif
/**
 * 
 * @param PORT       variable assign port_index
 * @param LOGIC      variable assign port logic
 * @return           Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
#if GPIO_PORT_CONFIG == GPIO_CONFIG_ENABLE
Std_ReturnType GPIO_PORT_WRITE_LOGIC (PORT_INDEX_T PORT,uint8 LOGIC){
    Std_ReturnType Retval= E_NOT_OK;
    if(PORT >= PORT_MAX){
        Retval= E_NOT_OK;
    }
    else{
        *LAT_REG[PORT] = LOGIC;
        Retval= E_OK;
    }
    return Retval;
}
#endif
/**
 * 
 * @param PORT        variable assign port_index
 * @param LOGIC       pointer return port logic
 * @return            Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
#if GPIO_PORT_CONFIG == GPIO_CONFIG_ENABLE
Std_ReturnType GPIO_PORT_READ_LOGIC (PORT_INDEX_T PORT,uint8 *LOGIC){
    Std_ReturnType Retval= E_NOT_OK;
    if(NULL == LOGIC || PORT >= PORT_MAX){
        Retval= E_NOT_OK;
    }
    else{
        *LOGIC = *PORT_REG[PORT];
    }
    return Retval;
}
#endif
/**
 * 
 * @param PORT     variable assign port_index
 * @return         Status of the function
 *         (E_OK)        : The Function Done Successfully
 *         (E_NOT_OK)    : The Function has issue to perform this action
 */
#if GPIO_PORT_CONFIG == GPIO_CONFIG_ENABLE
Std_ReturnType GPIO_PORT_TOGGLE_LOGIC (PORT_INDEX_T PORT){
    Std_ReturnType Retval= E_NOT_OK;
    if(PORT >= PORT_MAX){
        Retval= E_NOT_OK;
    }
    else{
        *LAT_REG[PORT] ^= PORT_MASK;
        Retval= E_OK;
    }
    return Retval;
}
#endif