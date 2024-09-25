#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Interfacing_Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Interfacing_Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECUAL/Button/ECU_Button.c ECUAL/LED/ECU_LED.c ECUAL/Relay/ECU_RELAY.c MCAL/GPIO/HAL_GPIO.c MCAL/Device_Config.c Drivers_Main.c ECUAL/DC_Motor/ECU_DC_MOTOR.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECUAL/Button/ECU_Button.p1 ${OBJECTDIR}/ECUAL/LED/ECU_LED.p1 ${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.p1 ${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.p1 ${OBJECTDIR}/MCAL/Device_Config.p1 ${OBJECTDIR}/Drivers_Main.p1 ${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECUAL/Button/ECU_Button.p1.d ${OBJECTDIR}/ECUAL/LED/ECU_LED.p1.d ${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.p1.d ${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.p1.d ${OBJECTDIR}/MCAL/Device_Config.p1.d ${OBJECTDIR}/Drivers_Main.p1.d ${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECUAL/Button/ECU_Button.p1 ${OBJECTDIR}/ECUAL/LED/ECU_LED.p1 ${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.p1 ${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.p1 ${OBJECTDIR}/MCAL/Device_Config.p1 ${OBJECTDIR}/Drivers_Main.p1 ${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.p1

# Source Files
SOURCEFILES=ECUAL/Button/ECU_Button.c ECUAL/LED/ECU_LED.c ECUAL/Relay/ECU_RELAY.c MCAL/GPIO/HAL_GPIO.c MCAL/Device_Config.c Drivers_Main.c ECUAL/DC_Motor/ECU_DC_MOTOR.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Interfacing_Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F46K20
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECUAL/Button/ECU_Button.p1: ECUAL/Button/ECU_Button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/Button" 
	@${RM} ${OBJECTDIR}/ECUAL/Button/ECU_Button.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/Button/ECU_Button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/Button/ECU_Button.p1 ECUAL/Button/ECU_Button.c 
	@-${MV} ${OBJECTDIR}/ECUAL/Button/ECU_Button.d ${OBJECTDIR}/ECUAL/Button/ECU_Button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/Button/ECU_Button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/LED/ECU_LED.p1: ECUAL/LED/ECU_LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/LED" 
	@${RM} ${OBJECTDIR}/ECUAL/LED/ECU_LED.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/LED/ECU_LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/LED/ECU_LED.p1 ECUAL/LED/ECU_LED.c 
	@-${MV} ${OBJECTDIR}/ECUAL/LED/ECU_LED.d ${OBJECTDIR}/ECUAL/LED/ECU_LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/LED/ECU_LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.p1: ECUAL/Relay/ECU_RELAY.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/Relay" 
	@${RM} ${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.p1 ECUAL/Relay/ECU_RELAY.c 
	@-${MV} ${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.d ${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.p1: MCAL/GPIO/HAL_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.p1 MCAL/GPIO/HAL_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.d ${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Device_Config.p1: MCAL/Device_Config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/Device_Config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Device_Config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Device_Config.p1 MCAL/Device_Config.c 
	@-${MV} ${OBJECTDIR}/MCAL/Device_Config.d ${OBJECTDIR}/MCAL/Device_Config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Device_Config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Drivers_Main.p1: Drivers_Main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Drivers_Main.p1.d 
	@${RM} ${OBJECTDIR}/Drivers_Main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Drivers_Main.p1 Drivers_Main.c 
	@-${MV} ${OBJECTDIR}/Drivers_Main.d ${OBJECTDIR}/Drivers_Main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Drivers_Main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.p1: ECUAL/DC_Motor/ECU_DC_MOTOR.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.p1 ECUAL/DC_Motor/ECU_DC_MOTOR.c 
	@-${MV} ${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.d ${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECUAL/Button/ECU_Button.p1: ECUAL/Button/ECU_Button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/Button" 
	@${RM} ${OBJECTDIR}/ECUAL/Button/ECU_Button.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/Button/ECU_Button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/Button/ECU_Button.p1 ECUAL/Button/ECU_Button.c 
	@-${MV} ${OBJECTDIR}/ECUAL/Button/ECU_Button.d ${OBJECTDIR}/ECUAL/Button/ECU_Button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/Button/ECU_Button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/LED/ECU_LED.p1: ECUAL/LED/ECU_LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/LED" 
	@${RM} ${OBJECTDIR}/ECUAL/LED/ECU_LED.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/LED/ECU_LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/LED/ECU_LED.p1 ECUAL/LED/ECU_LED.c 
	@-${MV} ${OBJECTDIR}/ECUAL/LED/ECU_LED.d ${OBJECTDIR}/ECUAL/LED/ECU_LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/LED/ECU_LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.p1: ECUAL/Relay/ECU_RELAY.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/Relay" 
	@${RM} ${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.p1 ECUAL/Relay/ECU_RELAY.c 
	@-${MV} ${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.d ${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/Relay/ECU_RELAY.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.p1: MCAL/GPIO/HAL_GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.p1 MCAL/GPIO/HAL_GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.d ${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/HAL_GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Device_Config.p1: MCAL/Device_Config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL" 
	@${RM} ${OBJECTDIR}/MCAL/Device_Config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Device_Config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Device_Config.p1 MCAL/Device_Config.c 
	@-${MV} ${OBJECTDIR}/MCAL/Device_Config.d ${OBJECTDIR}/MCAL/Device_Config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Device_Config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Drivers_Main.p1: Drivers_Main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Drivers_Main.p1.d 
	@${RM} ${OBJECTDIR}/Drivers_Main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Drivers_Main.p1 Drivers_Main.c 
	@-${MV} ${OBJECTDIR}/Drivers_Main.d ${OBJECTDIR}/Drivers_Main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Drivers_Main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.p1: ECUAL/DC_Motor/ECU_DC_MOTOR.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECUAL/DC_Motor" 
	@${RM} ${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.p1.d 
	@${RM} ${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.p1 ECUAL/DC_Motor/ECU_DC_MOTOR.c 
	@-${MV} ${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.d ${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECUAL/DC_Motor/ECU_DC_MOTOR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Interfacing_Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Interfacing_Drivers.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Interfacing_Drivers.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/Interfacing_Drivers.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/Interfacing_Drivers.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Interfacing_Drivers.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mdownload -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Interfacing_Drivers.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif