/* 
 * File:   HAL_EEPROM.h
 * Author: Mohamed Elahmady
 *
 * Created on November 14, 2024, 11:15 PM
 */

/* Section 0 : File Guard */

#ifndef HAL_EEPROM_H
#define	HAL_EEPROM_H

/* Section 1 : Includes */

#include "pic18f46k20.h"
#include "../Interrupt/MCAL_internal_interrupt.h"
#include "../MCAL_STD_Types.h"
#include "HAL_EEPROM_CFG.h"
#include "../Device_Config.h"

/* Section 2 : Macros Declarations */



/* Section 3 : Macros Functions Declarations */

#define ACCESS_EEPROM_MEMORY()                            (EECON1bits.EEPGD = 0)
#define ACCESS_FLASH_MEMORY()                             (EECON1bits.EEPGD = 1)

#define ACCESS_FLASH_AND_EEPROM()                         (EECON1bits.CFGS = 0)
#define ACCESS_CONFIGURATION_REGISTERS()                  (EECON1bits.CFGS = 1)

#define INHABIT_EEPROM_WRITE()                            (EECON1bits.WREN = 0)
#define ALLOW_EEPROM_WRITE()                              (EECON1bits.WREN = 1)

#define INITIATE_EEPROM_1BYTE_WRITE_ERASE()               (EECON1bits.WR = 1)
#define EEPROM_1BYTE_READ_ERASE_COMPLETED()               (EECON1bits.RD = 1)

/* Section 4 : User Defined Data Types Declarations */



/* Section 5 : Functions Declarations */

Std_ReturnType DATA_EEPROM_WRITE_BYTE(uint16 ADD , uint8 Data);
Std_ReturnType DATA_EEPROM_READ_BYTE(uint16 ADD , uint8 *Data);


#endif	/* HAL_EEPROM_H */

