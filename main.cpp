/*
 * main.c
 *
 *  Created on: 2017 Jun 12 16:23:59
 *  Author: smithj
 */

#include <xmc_common.h>
#include <xmc_gpio.h>
//#include "HAL/header/GPIO.h"
#include "mcal/xmc4/mcal_led.h"

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. 
 */

uint32_t ledOn = 1;

int main (void)
{

    /* Placeholder for user application code. The while loop below can be replaced with user application code. */
    while (1U)
    {
        if (ledOn == 1)
        {
            mcal::led::led0.turnOn();
        }
        else
        {
        		mcal::led::led0.turnOff();
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
