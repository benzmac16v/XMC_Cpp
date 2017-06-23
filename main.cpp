/*
 * main.c
 *
 *  Created on: 2017 Jun 12 16:23:59
 *  Author: smithj
 */

#include <xmc_common.h>
#include <xmc_gpio.h>
#include "HAL/header/GPIO.h"

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. 
 */

uint32_t ledOn = 1;

XMC_GPIO_CONFIG_t led1Config =
    { .mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL, .output_level =
            XMC_GPIO_OUTPUT_LEVEL_HIGH, .output_strength =
            XMC_GPIO_OUTPUT_STRENGTH_STRONG_SHARP_EDGE };

HAL::GPIO led1(XMC_GPIO_PORT5, 9, led1Config);

int main (void)
{

    /* Placeholder for user application code. The while loop below can be replaced with user application code. */
    while (1U)
    {
        if (ledOn == 1)
        {
            led1.setHigh();
        }
        else
        {
            led1.setLow();
        }
    }
    return 0;
}

void _exit (int a)
{
    while (1)
    {

    }
}
