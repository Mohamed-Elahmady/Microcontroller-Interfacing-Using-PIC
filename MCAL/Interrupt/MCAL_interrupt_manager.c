/* 
 * File:   MCAL_interrupt_manager.h
 * Author: Mohamed Elahmady
 *
 * Created on October 29, 2024, 9:05 PM
 */

#include "MCAL_interrupt_manager.h"

static volatile uint8 rb4_flag = 0;
static volatile uint8 rb5_flag = 0;
static volatile uint8 rb6_flag = 0;
static volatile uint8 rb7_flag = 0;


#if INTERRUPT_PRIORITY_LEVELS == INTERRUPT_FEATURE_ENABLE
void __interrupt() interrupt_manager_HIGH(){
    if((INTERRUPT_ENABLE == INTCONbits.INT0IE ) && (INTERRUPT_OCCUR == INTCONbits.INT0IF)){
        INT0_ISR();
    }
    else{/*Nothing*/}
    
    
    if((INTERRUPT_ENABLE == INTCON3bits.INT2IE ) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF)){
        INT2_ISR();
    }
    else{/*Nothing*/}
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE ) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            &&(GPIO_LOW == PORTBbits.RB4) && (1 == rb4_flag)){
        rb4_flag = 0;
        RB4_ISR(0);
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE ) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (GPIO_HIGH == PORTBbits.RB4) && (0 == rb4_flag)){
        rb4_flag = 1;
        RB4_ISR(1);
    }
    else{/*Nothing*/}
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE ) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (GPIO_LOW == PORTBbits.RB6) && ( 1 == rb6_flag)){
        rb6_flag = 0;
        RB6_ISR(0);
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE ) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (GPIO_HIGH == PORTBbits.RB6) && ( 0 == rb6_flag)){
        rb6_flag = 1;
        RB6_ISR(1);
    }
    else{/*Nothing*/}
}
void __interrupt(low_priority) interrupt_manager_LOW(){
    if((INTERRUPT_ENABLE == INTCON3bits.INT1IE ) && (INTERRUPT_OCCUR == INTCON3bits.INT1IF)){
        INT1_ISR();
    }
    else{/*Nothing*/}
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE ) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (GPIO_LOW == PORTBbits.RB5) && (1 == rb5_flag)){
        rb5_flag = 0;
        RB5_ISR(0);
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE ) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (GPIO_HIGH == PORTBbits.RB5) && (0 == rb5_flag)){
        rb5_flag = 1;
        RB5_ISR(1);
    }
    else{/*Nothing*/}
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE ) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (GPIO_LOW == PORTBbits.RB7) && ( 1 == rb7_flag)){
        rb7_flag = 0;
        RB7_ISR(0);
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE ) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (GPIO_HIGH == PORTBbits.RB7) && ( 0 == rb7_flag)){
        rb7_flag = 1;
        RB7_ISR(1);
    }
    else{/*Nothing*/}
}
#else

void __interrupt() interrupt_manager(){
    
        /* INTX INTERRUPTS */
    
    if((INTERRUPT_ENABLE == INTCONbits.INT0IE ) && (INTERRUPT_OCCUR == INTCONbits.INT0IF)){
        INT0_ISR();
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCON3bits.INT1IE ) && (INTERRUPT_OCCUR == INTCON3bits.INT1IF)){
        INT1_ISR();
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCON3bits.INT2IE ) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF)){
        INT2_ISR();
    }
    else{/*Nothing*/}
    
        /* RBX INTERRUPTS */
    
    if((INTERRUPT_ENABLE == INTCONbits.RBIE ) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            &&(GPIO_LOW == PORTBbits.RB4) && (1 == rb4_flag)){
        rb4_flag = 0;
        RB4_ISR(0);
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE ) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (GPIO_HIGH == PORTBbits.RB4) && (0 == rb4_flag)){
        rb4_flag = 1;
        RB4_ISR(1);
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE ) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (GPIO_LOW == PORTBbits.RB5) && (1 == rb5_flag)){
        rb5_flag = 0;
        RB5_ISR(0);
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE ) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (GPIO_HIGH == PORTBbits.RB5) && (0 == rb5_flag)){
        rb5_flag = 1;
        RB5_ISR(1);
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE ) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (GPIO_LOW == PORTBbits.RB6) && ( 1 == rb6_flag)){
        rb6_flag = 0;
        RB6_ISR(0);
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE ) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (GPIO_HIGH == PORTBbits.RB6) && ( 0 == rb6_flag)){
        rb6_flag = 1;
        RB6_ISR(1);
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE ) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (GPIO_LOW == PORTBbits.RB7) && ( 1 == rb7_flag)){
        rb7_flag = 0;
        RB7_ISR(0);
    }
    else{/*Nothing*/}
    if((INTERRUPT_ENABLE == INTCONbits.RBIE ) && (INTERRUPT_OCCUR == INTCONbits.RBIF) 
            && (GPIO_HIGH == PORTBbits.RB7) && ( 0 == rb7_flag)){
        rb7_flag = 1;
        RB7_ISR(1);
    }
    else{/*Nothing*/}
    
}

#endif