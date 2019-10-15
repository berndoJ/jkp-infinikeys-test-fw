/*----------------------------------------------------------------
 * FILENAME :		infinikeys_cfg_stm32cube.h
 * PROJECT :		infinikeys-arm32
 * AUTHOR :			Johannes Berndorfer
 * BREIF :			STM32 Cube SW platform specific configuration.
 * 
 * Copyright (c) 2019 Johannes Berndorfer. All rights reserved.
 * ---------------------------------------------------------------
 * DATE CREATED :	21.09.2019	
 * VERSION :		1.0
 * ---------------------------------------------------------------
 * DESCRIPTION :
 * 		Config header for the STM32 Cube software platform.
 * 
 *--------------------------------------------------------------*/

#ifndef INFINIKEYS_CFG_STM32CUBE_H_
#define INFINIKEYS_CFG_STM32CUBE_H_

/* --------------------------------------------------------------
 * USB CONFIGURATION
 * ------------------------------------------------------------*/

#define IK_USB_MAX_DEVICE_CURRENT			200 // Maximum USB device current in 2-milliampere steps. (200 > 400mA max.)

/* --------------------------------------------------------------
 * HAL CONFIGURATION
 * ------------------------------------------------------------*/

#define IK_STM32CUBE_HAL_MATRIX_SENSE_LINE_PORTS {\
	GPIOA,/*SL 0*/\
	GPIOA,/*SL 1*/\
	GPIOA,/*SL 2*/\
	GPIOA,/*SL 3*/\
	GPIOA,/*SL 4*/\
	GPIOA,/*SL 5*/\
	GPIOA,/*SL 6*/\
}

#define IK_STM32CUBE_HAL_MATRIX_SENSE_LINE_PINS {\
	GPIO_PIN_0,/*SL 0*/\
	GPIO_PIN_6,/*SL 1*/\
	GPIO_PIN_5,/*SL 2*/\
	GPIO_PIN_4,/*SL 3*/\
	GPIO_PIN_3,/*SL 4*/\
	GPIO_PIN_2,/*SL 5*/\
	GPIO_PIN_1,/*SL 6*/\
}

#define IK_STM32CUBE_HAL_MATRIX_PROBE_LINE_PORTS {\
	GPIOA,/*PL 0*/\
	GPIOC,/*PL 1*/\
	GPIOC,/*PL 2*/\
	GPIOC,/*PL 3*/\
	GPIOC,/*PL 4*/\
	GPIOB,/*PL 5*/\
	GPIOB,/*PL 6*/\
	GPIOB,/*PL 7*/\
	GPIOB,/*PL 8*/\
	GPIOB,/*PL 9*/\
	GPIOB,/*PL 10*/\
	GPIOB,/*PL 11*/\
	GPIOB,/*PL 12*/\
	GPIOC,/*PL 13*/\
	GPIOC,/*PL 14*/\
	GPIOA,/*PL 15*/\
	GPIOB,/*PL 16*/\
	GPIOB,/*PL 17*/\
	GPIOC,/*PL 18*/\
	GPIOC,/*PL 19*/\
	GPIOC,/*PL 20*/\
	GPIOC,/*PL 21*/\
}

#define IK_STM32CUBE_HAL_MATRIX_PROBE_LINE_PINS {\
	GPIO_PIN_8,/*PL 0*/\
	GPIO_PIN_9,/*PL 1*/\
	GPIO_PIN_8,/*PL 2*/\
	GPIO_PIN_7,/*PL 3*/\
	GPIO_PIN_6,/*PL 4*/\
	GPIO_PIN_15,/*PL 5*/\
	GPIO_PIN_14,/*PL 6*/\
	GPIO_PIN_13,/*PL 7*/\
	GPIO_PIN_12,/*PL 8*/\
	GPIO_PIN_11,/*PL 9*/\
	GPIO_PIN_10,/*PL 10*/\
	GPIO_PIN_1,/*PL 11*/\
	GPIO_PIN_0,/*PL 12*/\
	GPIO_PIN_5,/*PL 13*/\
	GPIO_PIN_4,/*PL 14*/\
	GPIO_PIN_7,/*PL 15*/\
	GPIO_PIN_8,/*PL 16*/\
	GPIO_PIN_9,/*PL 17*/\
	GPIO_PIN_1,/*PL 18*/\
	GPIO_PIN_13,/*PL 19*/\
	GPIO_PIN_14,/*PL 20*/\
	GPIO_PIN_15,/*PL 21*/\
}

#endif /* INFINIKEYS_CFG_STM32CUBE_H_ */
