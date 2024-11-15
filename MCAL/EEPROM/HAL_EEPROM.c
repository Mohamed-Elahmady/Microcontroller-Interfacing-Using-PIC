/* 
 * File:   HAL_EEPROM.c
 * Author: Mohamed Elahmady
 *
 * Created on November 14, 2024, 11:15 PM
 */

#include "HAL_EEPROM.h"


Std_ReturnType DATA_EEPROM_WRITE_BYTE(uint16 ADD , uint8 Data){
    Std_ReturnType Retval = E_OK;
    if(ADD > 0x3FF){
        Retval = E_NOT_OK;
    }
    else{
        /*1. Read The interrupt status GIE/GIEH */        
        uint8 GIE_STATUS = INTCONbits.GIE;
        /*2. Write ADD in the EEADR & EEADRH */
        EEADRH = (uint8)((ADD >> 8) & 0x03);
        EEADR = (uint8)((ADD) & 0xFF);
        /*3. WRITE DATA in EERDATA */
        EEDATA = Data;
        /*4. Clear EEPGD & CFGS in EECON1 */
        ACCESS_EEPROM_MEMORY();
        ACCESS_FLASH_AND_EEPROM();
        /*5. Set WREN in EECON1 */
        ALLOW_EEPROM_WRITE();
        /*6. CLEAR GIE/GIEH in INTCON Register "Disable interrupts" */       
        INTERRUPT_DISABLE_GLOBAL_INTERRUPT();
        /*7. Set Sequence in EECON2 0x55 -> 0x0AA */
        EECON2 = 0x55;
        EECON2 = 0xAA;
        /*8. Set WR in EECON1 */
        INITIATE_EEPROM_1BYTE_WRITE_ERASE();
        /*9. wait to clear WR by MCU */
        while(EECON1bits.WR);
        /*10. Inhabit WREN in EECON1 */
        INHABIT_EEPROM_WRITE();
        /*11. Restore the GIE/GIEH Status */
        INTCONbits.GIE = GIE_STATUS;
    } 
    return Retval;
}
Std_ReturnType DATA_EEPROM_READ_BYTE(uint16 ADD , uint8 *Data){
    Std_ReturnType Retval = E_OK;
    if(NULL ==  Data || ADD > 0x3FF){
        Retval = E_NOT_OK;
    }
    else{
        /*1. Write ADD in the EEADR & EEADRH */
        EEADRH = (uint8)((ADD >> 8) & 0x03);
        EEADR = (uint8)((ADD) & 0xFF);
        /*2. Clear EEPGD & CFGS in EECON1 */
        ACCESS_EEPROM_MEMORY();
        ACCESS_FLASH_AND_EEPROM();
        /*3. Set RD in EECON1 */
        EEPROM_1BYTE_READ_ERASE_COMPLETED();
        /*4. Wait 2 instruction time no operations */
        NOP();
        NOP();
        /*5. Read Data in EEDATA*/
        *Data = EEDATA;
    }
    return Retval;
}