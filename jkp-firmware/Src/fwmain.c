/*----------------------------------------------------------------
 * FILENAME :		fwmain.c
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

#include "fwmain.h"

/* --------------------------------------------------------------
 * VARIABLE DEFINITIONS
 * ------------------------------------------------------------*/

IS31FL3236_HandleTypeDef hw_leddrvr0_handle;
FW_ConfigState_t hw_leddrvr0_cfgstate = FW_CFG_STATE_NOT_CONFIGURED;

/* --------------------------------------------------------------
 * STATIC FUNCTION DECLARATIONS
 * ------------------------------------------------------------*/

static void FW_Setup_LEDDRVR0(void);
static void FW_Setup_INFINIKEYS(void);

/* --------------------------------------------------------------
 * FUNCTION DEFINITIONS
 * ------------------------------------------------------------*/

void FW_Setup(void)
{
	// Init leddrvr0
	FW_Setup_LEDDRVR0();
	// Init module InfiniKeys
	FW_Setup_INFINIKEYS();
}

void FW_Exec(void)
{
	while (1)
	{
		// Poll keyboard matrix and send keyboard report (infinikeys)
		IK_KeyboardPollCyleTick();
		// Delay the loop.
		HAL_Delay(FW_LOOPDELAY);
	}
}

void FW_ThrowError(uint32_t line, const char* module, const char* msg)
{
#if defined(FW_ERR_LED_ENABLED)
	if (hw_leddrvr0_cfgstate == FW_CFG_STATE_CONFIGURED)
	{
		// Turn on the error indicator LED.
		IS31FL3236_WriteRGBPWM(&hw_leddrvr0_handle, FW_ERR_RGB_CHANNEL, FW_ERR_RGB_COLR, FW_ERR_RGB_COLG, FW_ERR_RGB_COLB);
		IS31FL3236_Update(&hw_leddrvr0_handle);
	}
#endif

#if defined(FW_ERR_UARTMSG_ENABLED)
	// TODO: Send line, module & message over UART1.
#endif

#if defined(FW_ERR_LOCKUP)
	while(1) {}
#endif
}

/* --------------------------------------------------------------
 * STATIC FUNCTION DEFINITIONS
 * ------------------------------------------------------------*/

static void FW_Setup_LEDDRVR0(void)
{
	hw_leddrvr0_handle.Init.I2C_Bus = &hi2c1;
	hw_leddrvr0_handle.Init.I2C_Device_Address = IS31FL3236_GET_I2C_ADDR(IS31FL3236_I2C_AD_TO_GND);
	hw_leddrvr0_handle.Init.Chip_Enable_Signal_Pin = GPIO_PIN_5;
	hw_leddrvr0_handle.Init.Chip_Enable_Signal_Port = GPIOB;
	hw_leddrvr0_handle.Init.RGB_Mode_Color_1 = IS31FL3236_RGB_CONFIG_RED;
	hw_leddrvr0_handle.Init.RGB_Mode_Color_2 = IS31FL3236_RGB_CONFIG_GREEN;
	hw_leddrvr0_handle.Init.RGB_Mode_Color_3 = IS31FL3236_RGB_CONFIG_BLUE;

	IS31FL3236_Init(&hw_leddrvr0_handle);
	IS31FL3236_WriteGlobalLEDControl(&hw_leddrvr0_handle, IS31FL3236_LED_CURRENT_MAX, IS31FL3236_LED_STATE_ON);

	hw_leddrvr0_cfgstate = FW_CFG_STATE_CONFIGURED;
}

static void FW_Setup_INFINIKEYS(void)
{
	if (IK_Init() != 0)
	{
		FW_ThrowError(__LINE__, "fwmain", "");
	}
}
