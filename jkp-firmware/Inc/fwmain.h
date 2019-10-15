/*----------------------------------------------------------------
 * FILENAME :		fwmain.h
 * PROJECT :		JKP-Firmware-InfiniKeys-v1.x
 * AUTHOR :			Johannes Berndorfer
 * BREIF :			Firmware main module.
 * 
 * Copyright (c) 2019 Johannes Berndorfer. All rights reserved.
 * ---------------------------------------------------------------
 * DATE CREATED :	15.10.2019	
 * VERSION :		1.0
 * ---------------------------------------------------------------
 * DESCRIPTION :
 * 		Main module of the JKP firmware.
 * 
 *--------------------------------------------------------------*/

#ifndef FWMAIN_H_
#define FWMAIN_H_

/* --------------------------------------------------------------
 * INCLUDES
 * ------------------------------------------------------------*/

#include <stdint.h>

#include "main.h"
#include "stm32f1xx_hal.h"
#include "is31fl3236_driver.h"
#include "infinikeys.h"

/* --------------------------------------------------------------
 * DEFINITIONS
 * ------------------------------------------------------------*/

#define FW_LOOPDELAY				1

#define FW_ERR_LED_ENABLED
//#define FW_ERR_UARTMSG_ENABLED
#define FW_ERR_LOCKUP
#define FW_ERR_RGB_CHANNEL			1
#define FW_ERR_RGB_COLR				0xff
#define FW_ERR_RGB_COLG				0x00
#define FW_ERR_RGB_COLB				0x00

/* --------------------------------------------------------------
 * ENUMS
 * ------------------------------------------------------------*/

/*
 * Description
 * Represents the configuration state of a particular configurable
 * system / struct / HAL-module / ...
 */
typedef enum {
	FW_CFG_STATE_NOT_CONFIGURED = 0,
	FW_CFG_STATE_CONFIGURED,
	FW_CFG_STATE_CONFIGERR
} FW_ConfigState_t;

/* --------------------------------------------------------------
 * VARIABLE DECLARATIONS
 * ------------------------------------------------------------*/

/*
 * Handle for the RGB-LED driver on the board.
 */
extern IS31FL3236_HandleTypeDef hw_leddrvr0_handle;

/*
 * Configuration state of leddrvr0
 */
extern FW_ConfigState_t hw_leddrvr0_cfgstate;

/* --------------------------------------------------------------
 * FUNCTION DECLARATIONS
 * ------------------------------------------------------------*/

/*
 * Description
 * Main firmware setup function. All other setups and inits are
 * called from this function.
 */
void FW_Setup(void);

/*
 * Description
 * Main firmware execution function. When this function returns,
 * the processor halts. This function usually contains an
 * infinite while loop.
 */
void FW_Exec(void);

/*
 * Description
 * Error handler for general software errors.
 *
 * Parameters
 * - uint32_t line: The line of code the error was thrown. (Usually __LINE__)
 * - const char* module: The module the error was thrown in. (Usually module name or __FILE__)
 * - const char* msg: The error message - what went wrong.
 */
void FW_ThrowError(uint32_t line, const char* module, const char* msg);

#endif /* FWMAIN_H_ */
