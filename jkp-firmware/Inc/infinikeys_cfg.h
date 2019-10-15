/*----------------------------------------------------------------
 * FILENAME :		infinikeys_cfg.h
 * PROJECT :		infinikeys-arm32
 * AUTHOR :			Johannes Berndorfer
 * BREIF :			InfiniKeys Configuration File
 * 
 * Copyright (c) 2019 Johannes Berndorfer. All rights reserved.
 * ---------------------------------------------------------------
 * DATE CREATED :	16.09.2019	
 * VERSION :		1.0
 * ---------------------------------------------------------------
 * DESCRIPTION :
 * 		Configuration header for the InfiniKeys firmware
 * 		extension.
 * 
 *--------------------------------------------------------------*/

#ifndef INFINIKEYS_CFG_H_
#define INFINIKEYS_CFG_H_

// Include the platform-specific configuration file.
#include "infinikeys_cfg_stm32cube.h"

// Define the target platform this extension will run on:
#define IK_PLATFORM_STM32_CUBE
#define IK_PLATFORM_STM32_CUBE_DEVICE_F1XX

// Matrix sense and probe line counts.
#define IK_MATRIX_PROBE_LINE_COUNT				22
#define IK_MATRIX_SENSE_LINE_COUNT				7

// Key rollover specifier.
#define IK_KEY_ROLLOVER							5

// Maximum amount of key map table matrix key layers.
#define IK_MATRIX_MAX_KEY_LAYERS				8

#endif /* INFINIKEYS_CFG_H_ */
