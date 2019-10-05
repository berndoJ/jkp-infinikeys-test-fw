/*----------------------------------------------------------------
 * FILENAME :		fwtasks.c
 * PROJECT :		jkp-infinikeys-test-fw
 * AUTHOR :			Johannes Berndorfer
 * BREIF :			FreeRTOS Task Routines
 *
 * Copyright (c) 2019 Johannes Berndorfer. All rights reserved.
 * ---------------------------------------------------------------
 * DATE CREATED :	05.10.2019
 * VERSION :		1.0
 * ---------------------------------------------------------------
 * DESCRIPTION :
 * 		This file contains the task routines of all FreeRTOS
 *      tasks.
 *
 *--------------------------------------------------------------*/

#include "fwtasks.h"

#include "cmsis_os.h"
#include "is31fl3236_driver.h"
#include "main.h"

void TASK_ExecMain(void const* arg)
{
    // Main Task: Initialisation.
    IS31FL3236_WriteRGBPWM(&h_rgb_controller, 1, 0x00, 0xff, 0xff);
    IS31FL3236_Update(&h_rgb_controller);

    // Main Task: Loop.
    for (;;)
    {
        osDelay(1);
    }
}