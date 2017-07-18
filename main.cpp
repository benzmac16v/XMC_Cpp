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
#include "mcal/xmc4/mcal_gpt.h"

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. 
 */

uint32_t ledOn = 1;
uint32_t isrToggle = 0;

mcal::gpt::GPT <std::uint32_t,
				std::uint32_t,
				ccu40,
				ccu40 + ccu4x_CC0_offset,
				UINT32_C( 60000 )> timer1;

int main (void)
{
	timer1.init();

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

void CCU40_0_IRQHandler()
{
	if(isrToggle)
	{
		isrToggle = 0;
		mcal::led::led0.turnOn();
	}
	else
	{
		isrToggle = 1;
		mcal::led::led0.turnOff();
	}
}
