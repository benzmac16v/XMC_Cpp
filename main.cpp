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
uint32_t inISR = 0;
uint8_t isrCounter = 0;

int main (void)
{
	NVIC_ClearPendingIRQ(CCU40_0_IRQn);
	NVIC_EnableIRQ(CCU40_0_IRQn);

	mcal::gpt::timer1.init();
	mcal::gpt::timer1.start();

    /* Placeholder for user application code. The while loop below can be replaced with user application code. */
    while (1U)
    {
        if (ledOn == 1)
        {
            //mcal::led::led0.turnOn();
        }
        else
        {
        		//mcal::led::led0.turnOff();
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

extern "C"
void CCU40_0_IRQHandler() __attribute__ ((interrupt));
void CCU40_0_IRQHandler()
{
	isrCounter++;
	mcal::gpt::timer1.resetIRQ();

	inISR = 1;
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
