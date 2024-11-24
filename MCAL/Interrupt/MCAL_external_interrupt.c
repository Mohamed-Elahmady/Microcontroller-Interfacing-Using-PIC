/* 
 * File:   MCAL_external_interrupt.c
 * Author: Mohamed Elahmady
 *
 * Created on October 29, 2024, 9:04 PM
 */

#include "MCAL_external_interrupt.h"

/******************* Helper Functions Declerations *******************/

/******************* FOR INTX *******************/
static void (*int0_interrupt_handler)(void) = NULL;
static void (*int1_interrupt_handler)(void) = NULL;
static void (*int2_interrupt_handler)(void) = NULL;

static Std_ReturnType interrupt_intx_disable(const EXT_INTX_T *INTX);
static Std_ReturnType interrupt_intx_clear_flag(const EXT_INTX_T *INTX);
static Std_ReturnType interrupt_intx_priority_init(const EXT_INTX_T *INTX);
static Std_ReturnType interrupt_intx_edge_init(const EXT_INTX_T *INTX);
static Std_ReturnType interrupt_intx_pin_init(const EXT_INTX_T *INTX);
static Std_ReturnType interrupt_intx_enable(const EXT_INTX_T *INTX);

static Std_ReturnType int0_set_interrupt_handler(void (*interrupt_handler)(void));
static Std_ReturnType int1_set_interrupt_handler(void (*interrupt_handler)(void));
static Std_ReturnType int2_set_interrupt_handler(void (*interrupt_handler)(void));
static Std_ReturnType set_interrupt_intx_to_handle(const EXT_INTX_T *INTX);

/******************* FOR RBX *******************/
static void (*RB4_interrupt_handler_LOW)(void) = NULL;
static void (*RB4_interrupt_handler_HIGH)(void) = NULL;
static void (*RB5_interrupt_handler_LOW)(void) = NULL;
static void (*RB5_interrupt_handler_HIGH)(void) = NULL;
static void (*RB6_interrupt_handler_LOW)(void) = NULL;
static void (*RB6_interrupt_handler_HIGH)(void) = NULL;
static void (*RB7_interrupt_handler_LOW)(void) = NULL;
static void (*RB7_interrupt_handler_HIGH)(void) = NULL;

static Std_ReturnType interrupt_rbx_disable(const EXT_RBX_T *RBX);
static Std_ReturnType interrupt_rbx_clear_flag(const EXT_RBX_T *RBX);
static Std_ReturnType interrupt_rbx_priority_init(const EXT_RBX_T *RBX);
static Std_ReturnType interrupt_rbx_pin_init(const EXT_RBX_T *RBX);
static Std_ReturnType interrupt_rbx_enable(const EXT_RBX_T *RBX);

/******************* Main Functions *******************/

Std_ReturnType EXTERNAL_INTERRUPT_INTX_INIT(const EXT_INTX_T *INTX){
    Std_ReturnType Retval = E_OK;
    if(NULL == INTX){
        Retval = E_NOT_OK;
    }
    else{
        /*1.Disable Interrupt*/
        /*2.Clear Interrupt Flag*/
        /*3.Configure Interrupt Priority*/
        /*4.Configure Interrupt Edge*/
        /*5.Configure Interrupt I/O Pin*/
        /*6.Configure default Interrupt CallBack 
         * a) choose intx to handle
         * b) send function to pointer
         * c) assign the fp to another function pointer has a relation with ISR 
            */
        /*7.Enable Interrupt*/
        Retval = interrupt_intx_disable(INTX);
        Retval = interrupt_intx_clear_flag(INTX);
        Retval = interrupt_intx_edge_init(INTX);
        #if INTERRUPT_PRIORITY_LEVELS == INTERRUPT_FEATURE_ENABLE
        Retval = interrupt_intx_priority_init(INTX);
        #endif
        Retval = interrupt_intx_pin_init(INTX);
        Retval = set_interrupt_intx_to_handle(INTX);
        Retval = interrupt_intx_enable(INTX);
    }
    return Retval;
}

Std_ReturnType EXTERNAL_INTERRUPT_INTX_DEINIT(const EXT_INTX_T *INTX){
    Std_ReturnType Retval = E_OK;
    if(NULL == INTX){
        Retval = E_NOT_OK;
    }
    else{
        Retval = interrupt_intx_disable(INTX);
    }
    return Retval;
}

void INT0_ISR(void){
    /* 1. Clear Flag */
    /* 2. Code to excute in ISR */
    /* 3. callback function */
    EXT_INT0_FLAG_CLEAR();
    
    if(int0_interrupt_handler){
    int0_interrupt_handler();
    }
}

void INT1_ISR(void){
    /* 1. Clear Flag */
    /* 2. Code to excute in ISR */
    /* 3. callback function */
    EXT_INT1_FLAG_CLEAR();
    
    if(int1_interrupt_handler){
    int1_interrupt_handler();
    }
}

void INT2_ISR(void){
    /* 1. Clear Flag */
    /* 2. Code to excute in ISR */
    /* 3. callback function */
    EXT_INT2_FLAG_CLEAR();
    
    if(int2_interrupt_handler){
    int2_interrupt_handler();
    }
}


Std_ReturnType EXTERNAL_INTERRUPT_RBX_INIT(const EXT_RBX_T *RBX){
    Std_ReturnType Retval = E_OK;
    if(NULL == RBX){
        Retval = E_NOT_OK;
    }
    else{
        /*1.Disable Interrupt*/
        /*2.Clear Interrupt Flag*/
        /*3.Configure Interrupt Priority*/
        /*4.Configure Interrupt I/O Pin*/
        /*5. Set IOCB for RBX in only PIC18F46K20*/
        /*6.Configure default Interrupt CallBack*/
        /*7.Enable Interrupt*/
        EXT_RBx_INTERRUPT_DISABLE();
        EXT_RBx_FLAG_CLEAR();
        #if INTERRUPT_PRIORITY_LEVELS == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_ENABLE_PRIORITY_LEVELS();
            if(INTERRUPT_LOW_PRIORITY == RBX->priority){
                INTERRUPT_ENABLE_LOW_PRIORITY_GLOBAL_INTERRUPT();
                INTERRUPT_ENABLE_HIGH_PRIORITY_GLOBAL_INTERRUPT();
                EXT_RBx_LOW_PRIORITY();
            }
            else if (INTERRUPT_HIGH_PRIORITY == RBX->priority){
                INTERRUPT_ENABLE_LOW_PRIORITY_GLOBAL_INTERRUPT();
                INTERRUPT_ENABLE_HIGH_PRIORITY_GLOBAL_INTERRUPT();
                EXT_RBx_HIGH_PRIORITY();
            }
            else{/*Nothing*/}
        #else
            INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
            INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
        #endif
        Retval = GPIO_PIN_DIRECTION_INITIALIZE(&(RBX->mcu_pin));
            switch (RBX->mcu_pin.PIN){
                case GPIO_PIN4:
                    IOCB_RB4_ENABLE();
                    RB4_interrupt_handler_HIGH = RBX->ext_interrupt_handler_high;
                    RB4_interrupt_handler_LOW = RBX->ext_interrupt_handler_low;
                    break;
                case GPIO_PIN5:
                    IOCB_RB5_ENABLE();
                    RB5_interrupt_handler_HIGH = RBX->ext_interrupt_handler_high;
                    RB5_interrupt_handler_LOW = RBX->ext_interrupt_handler_low;
                    break;
                case GPIO_PIN6:
                    IOCB_RB6_ENABLE();
                    RB6_interrupt_handler_HIGH = RBX->ext_interrupt_handler_high;
                    RB6_interrupt_handler_LOW = RBX->ext_interrupt_handler_low;
                    break;
                case GPIO_PIN7:
                    IOCB_RB7_ENABLE();
                    RB7_interrupt_handler_HIGH = RBX->ext_interrupt_handler_high;
                    RB7_interrupt_handler_LOW = RBX->ext_interrupt_handler_low;
                    break;
                default:
                    Retval = E_NOT_OK;
                    break;
            }
        EXT_RBx_INTERRUPT_ENABLE();
    }
    return Retval;
}

/**
 * 
 * @param RBX
 * @return 
 */
Std_ReturnType EXTERNAL_INTERRUPT_RBX_DEINIT(const EXT_RBX_T *RBX){
    Std_ReturnType Retval = E_OK;
    if(NULL == RBX){
        Retval = E_NOT_OK;
    }
    else{
        EXT_RBx_INTERRUPT_DISABLE();
        EXT_RBx_FLAG_CLEAR();
    }
    return Retval;
}

void RB4_ISR(uint8 rb4){
    EXT_RBx_FLAG_CLEAR();
    
    if(1 == rb4){
        if(RB4_interrupt_handler_HIGH){
            RB4_interrupt_handler_HIGH();
        }
    }
    else if(0 == rb4){
        if(RB4_interrupt_handler_LOW){
            RB4_interrupt_handler_LOW();
        }
        else{/*Nothing*/}
    }
    else{/*Nothing*/}
}
void RB5_ISR(uint8 rb5){
    EXT_RBx_FLAG_CLEAR();

    if(1 == rb5){
        if(RB5_interrupt_handler_HIGH){
            RB5_interrupt_handler_HIGH();
        }
    }
    else if(0 == rb5){
        if(RB5_interrupt_handler_LOW){
            RB5_interrupt_handler_LOW();
        }
        else{/*Nothing*/}
    }
    else{/*Nothing*/}
}
void RB6_ISR(uint8 rb6){
    EXT_RBx_FLAG_CLEAR();
    if(1 == rb6){
        if(RB6_interrupt_handler_HIGH){
            RB6_interrupt_handler_HIGH();
        }
    }
    else if(0 == rb6){
        if(RB6_interrupt_handler_LOW){
            RB6_interrupt_handler_LOW();
        }
        else{/*Nothing*/}
    }
    else{/*Nothing*/}
}
void RB7_ISR(uint8 rb7){
    EXT_RBx_FLAG_CLEAR();
    if(1 == rb7){
        if(RB7_interrupt_handler_HIGH){
            RB7_interrupt_handler_HIGH();
        }
    }
    else if(0 == rb7){
        if(RB7_interrupt_handler_LOW){
            RB7_interrupt_handler_LOW();
        }
        else{/*Nothing*/}
    }
    else{/*Nothing*/}
}


/******************* Helper Functions *******************/

/******************* FOR INTX *******************/

static Std_ReturnType interrupt_intx_enable(const EXT_INTX_T *INTX){
    Std_ReturnType Retval = E_OK;
    if(NULL == INTX){
        Retval = E_NOT_OK;       
    }
    else{
        switch(INTX->source){
            case EXT_INT0:
                #if INTERRUPT_PRIORITY_LEVELS == INTERRUPT_FEATURE_ENABLE
                    INTERRUPT_ENABLE_HIGH_PRIORITY_GLOBAL_INTERRUPT();
                #elif INTERRUPT_PRIORITY_LEVELS != INTERRUPT_FEATURE_ENABLE
                    INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
                    INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
                #endif
                EXT_INT0_INTERRUPT_ENABLE();
                break;
            case EXT_INT1:
                #if INTERRUPT_PRIORITY_LEVELS == INTERRUPT_FEATURE_ENABLE
                    INTERRUPT_ENABLE_PRIORITY_LEVELS();
                    if(INTERRUPT_LOW_PRIORITY == INTX->priority){
                        INTERRUPT_ENABLE_LOW_PRIORITY_GLOBAL_INTERRUPT();
                        INTERRUPT_ENABLE_HIGH_PRIORITY_GLOBAL_INTERRUPT();
                    }
                    else if(INTERRUPT_HIGH_PRIORITY == INTX->priority){
                        INTERRUPT_ENABLE_LOW_PRIORITY_GLOBAL_INTERRUPT();
                        INTERRUPT_ENABLE_HIGH_PRIORITY_GLOBAL_INTERRUPT();
                    }
                    else{/*Nothing*/}
                #elif INTERRUPT_PRIORITY_LEVELS != INTERRUPT_FEATURE_ENABLE
                    INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
                    INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
                #endif
                EXT_INT1_INTERRUPT_ENABLE();
                break;
            case EXT_INT2:
                #if INTERRUPT_PRIORITY_LEVELS == INTERRUPT_FEATURE_ENABLE
                    INTERRUPT_ENABLE_PRIORITY_LEVELS();
                    if(INTERRUPT_LOW_PRIORITY == INTX->priority){
                        INTERRUPT_ENABLE_LOW_PRIORITY_GLOBAL_INTERRUPT();
                        INTERRUPT_ENABLE_HIGH_PRIORITY_GLOBAL_INTERRUPT();
                    }
                    else if(INTERRUPT_HIGH_PRIORITY == INTX->priority){
                        INTERRUPT_ENABLE_LOW_PRIORITY_GLOBAL_INTERRUPT();
                        INTERRUPT_ENABLE_HIGH_PRIORITY_GLOBAL_INTERRUPT();
                    }
                    else{/*Nothing*/}
                #elif INTERRUPT_PRIORITY_LEVELS != INTERRUPT_FEATURE_ENABLE
                    INTERRUPT_ENABLE_GLOBAL_INTERRUPT();
                    INTERRUPT_ENABLE_PERIPHERAL_INTERRUPT();
                #endif
                EXT_INT2_INTERRUPT_ENABLE();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}
static Std_ReturnType interrupt_intx_disable(const EXT_INTX_T *INTX){
    Std_ReturnType Retval = E_OK;
    if(NULL == INTX){
        Retval = E_NOT_OK;       
    }
    else{
        switch(INTX->source){
            case EXT_INT0:
                EXT_INT0_INTERRUPT_DISABLE();
                break;
            case EXT_INT1:
                EXT_INT1_INTERRUPT_DISABLE();
                break;
            case EXT_INT2:
                EXT_INT2_INTERRUPT_DISABLE();
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

static Std_ReturnType interrupt_intx_clear_flag(const EXT_INTX_T *INTX){
    Std_ReturnType Retval = E_OK;
    if(NULL == INTX){
        Retval = E_NOT_OK;       
    }
    else{
        switch(INTX->source){
            case EXT_INT0:
                EXT_INT0_FLAG_CLEAR();
                break;
            case EXT_INT1:
                EXT_INT1_FLAG_CLEAR();                
                break;
            case EXT_INT2:
                EXT_INT2_FLAG_CLEAR();
                break;
            default:
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}
#if INTERRUPT_PRIORITY_LEVELS == INTERRUPT_FEATURE_ENABLE
static Std_ReturnType interrupt_intx_priority_init(const EXT_INTX_T *INTX){
    Std_ReturnType Retval = E_OK;
    if(NULL == INTX){
        Retval = E_NOT_OK;       
    }
    else{
        switch(INTX->source){
            case EXT_INT0:
                Retval = E_NOT_OK;
                break;
            case EXT_INT1:
                if(INTERRUPT_LOW_PRIORITY == INTX->priority){
                    EXT_INT1_LOW_PRIORITY();
                }
                else if(INTERRUPT_HIGH_PRIORITY == INTX->priority){
                    EXT_INT1_HIGH_PRIORITY();
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case EXT_INT2:
                if(INTERRUPT_LOW_PRIORITY == INTX->priority){
                    EXT_INT2_LOW_PRIORITY();
                }
                else if(INTERRUPT_HIGH_PRIORITY == INTX->priority){
                    EXT_INT2_HIGH_PRIORITY();
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}
#endif
static Std_ReturnType interrupt_intx_edge_init(const EXT_INTX_T *INTX){
    Std_ReturnType Retval = E_OK;
    if(NULL == INTX){
        Retval = E_NOT_OK;       
    }
    else{
        switch(INTX->source){
            case EXT_INT0:
                if(INTERRUPT_FALLING_EDGE == INTX->edge){
                    EXT_INT0_SET_FALLING_EDGE();
                }
                else if(INTERRUPT_RISING_EDGE == INTX->edge){
                    EXT_INT0_SET_RISING_EDGE();
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case EXT_INT1:
                if(INTERRUPT_FALLING_EDGE == INTX->edge){
                    EXT_INT1_SET_FALLING_EDGE();
                }
                else if(INTERRUPT_RISING_EDGE == INTX->edge){
                    EXT_INT1_SET_RISING_EDGE();
                }
                else{
                    Retval = E_NOT_OK;
                }
                break;
            case EXT_INT2:
                if(INTERRUPT_FALLING_EDGE == INTX->edge){
                    EXT_INT2_SET_FALLING_EDGE();
                }
                else if(INTERRUPT_RISING_EDGE == INTX->edge){
                    EXT_INT2_SET_RISING_EDGE();
                }
                else{
                Retval = E_NOT_OK;
                }
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}
static Std_ReturnType interrupt_intx_pin_init(const EXT_INTX_T *INTX){
    Std_ReturnType Retval = E_OK;
    if(NULL == INTX){
        Retval = E_NOT_OK;       
    }
    else{
        Retval = GPIO_PIN_DIRECTION_INITIALIZE(&(INTX->mcu_pin));
    }
    return Retval;
}
static Std_ReturnType int0_set_interrupt_handler(void (*interrupt_handler)(void)){
    Std_ReturnType Retval = E_OK;
    if(NULL == interrupt_handler){
        Retval = E_NOT_OK;
    }
    else{
        int0_interrupt_handler =  interrupt_handler;
    }
    return Retval;
}
static Std_ReturnType int1_set_interrupt_handler(void (*interrupt_handler)(void)){
    Std_ReturnType Retval = E_OK;
    if(NULL == interrupt_handler){
        Retval = E_NOT_OK;
    }
    else{
        int1_interrupt_handler =  interrupt_handler;
    }
    return Retval;
}
static Std_ReturnType int2_set_interrupt_handler(void (*interrupt_handler)(void)){
    Std_ReturnType Retval = E_OK;
    if(NULL == interrupt_handler){
        Retval = E_NOT_OK;
    }
    else{
        int2_interrupt_handler =  interrupt_handler;
    }
    return Retval;
}
static Std_ReturnType set_interrupt_intx_to_handle(const EXT_INTX_T *INTX){
    Std_ReturnType Retval = E_OK;
    if(NULL == INTX){
        Retval = E_NOT_OK;       
    }
    else{
        switch(INTX->source){
            case EXT_INT0:
                Retval = int0_set_interrupt_handler(INTX->ext_interrupt_handler);
                break;
            case EXT_INT1:
                Retval = int1_set_interrupt_handler(INTX->ext_interrupt_handler);
                break;
            case EXT_INT2:
                Retval = int2_set_interrupt_handler(INTX->ext_interrupt_handler);
                break;
            default :
                Retval = E_NOT_OK;
                break;
        }
    }
    return Retval;
}

/******************* FOR RBX *******************/

static Std_ReturnType interrupt_rbx_enable(const EXT_RBX_T *RBX){
    Std_ReturnType Retval = E_OK;
    if(NULL == RBX){
        Retval = E_NOT_OK;       
    }
    else{
        
    }
    return Retval;
}
static Std_ReturnType interrupt_rbx_clear_flag(const EXT_RBX_T *RBX){
    Std_ReturnType Retval = E_OK;
    if(NULL == RBX){
        Retval = E_NOT_OK;       
    }
    else{
        
    }
    return Retval;
}
static Std_ReturnType interrupt_rbx_disable(const EXT_RBX_T *RBX){
    Std_ReturnType Retval = E_OK;
    if(NULL == RBX){
        Retval = E_NOT_OK;       
    }
    else{
        
    }
    return Retval;
}
static Std_ReturnType interrupt_rbx_priority_init(const EXT_RBX_T *RBX){
    Std_ReturnType Retval = E_OK;
    if(NULL == RBX){
        Retval = E_NOT_OK;       
    }
    else{
        
    }
    return Retval;
}
static Std_ReturnType interrupt_rbx_pin_init(const EXT_RBX_T *RBX){
    Std_ReturnType Retval = E_OK;
    if(NULL == RBX){
        Retval = E_NOT_OK;       
    }
    else{
        Retval = GPIO_PIN_DIRECTION_INITIALIZE(&(RBX->mcu_pin));
    }
    return Retval;
}