/* 
 * File:   MCAL_STD_Types.h
 * Author: Mohamed Elahmady
 *
 * Created on September 9, 2024, 5:57 PM
 */

/* Section 0 : File Guard */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* Section 1 : Includes */

#include "STD_Libraries.h"
#include "Compiler.h"

/* Section 2 : Macros Declarations */

#define CONFIG_ENABLE      0x01
#define CONFIG_DISABLE     0x00

#define HIGH_V             0x01
#define LOW_V              0x00

#define ON_ST              0x01
#define OFF_ST             0x00

#define ACTIVE_ST          0x01
#define IDLE_ST            0x00


#define CPU_T8 8
#define CPU_T16 16
#define CPU_T32 32
#define CPU_T64 64

#define CPU_ARCH (CPU_T8)

/* Section 3 : Macros Functions Declarations */

/* Section 4 : User Defined Data Types Declarations */

#if (CPU_ARCH == CPU_T8)
//typedef bool boolean; // bit = 1 bit

typedef unsigned char uint8;
typedef unsigned short uint16; // short == int = 16 bit
typedef unsigned long uint32; // long == long long = 32 bit

typedef signed char sint8;
typedef signed short sint16; // short == int = 16 bit
typedef signed long sint32; // long == long long = 32 bit

typedef float float32; // float == double == long double = 32

#define HWREG8(_X)                    (*((volatile uint8 * )(_X)))

#elif (CPU_ARCH == CPU_T16)
typedef unsigned char boolean;

typedef unsigned char uint8;
typedef unsigned short uint16; // short == int = 16 bit
typedef unsigned long uint32;
typedef unsigned long long uint64;

typedef signed char sint8;
typedef signed short sint16; // short == int = 16 bit
typedef signed long sint32;
typedef signed long long sint64;

typedef float float32;
typedef double float64;

#define HWREG16(_X)                    (*((volatile uint16 * )(_X)))


#elif (CPU_ARCH == CPU_T32)
typedef unsigned char boolean;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32; // long == int = 32 bit
typedef unsigned long long uint64;

typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32; // long == int = 32 bit
typedef signed long long sint64;

typedef float float32;
typedef double float64;

#define HWREG32(_X)                    (*((volatile uint32 * )(_X)))

#elif (CPU_ARCH == CPU_T64)
typedef unsigned char boolean;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32; // int == long = 32 bit
typedef unsigned long long uint64;

typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32; // int == long = 32 bit
typedef signed long long sint64;

typedef float float32;
typedef double float64;
typedef long double float128;

#define HWREG64(_X)                    (*((volatile uint64 * )(_X)))

#endif

typedef enum {
    E_NOT_OK =                0x00,
    E_OK     =                0x01
}Std_ReturnType;

/* Section 5 : Functions Declarations */

#endif	/* MCAL_STD_TYPES_H */



/*





*/