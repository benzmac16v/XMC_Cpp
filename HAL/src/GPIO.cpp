/*
 * GPIO.cpp
 *
 *  Created on: Jun 14, 2017
 *      Author: smithj
 */

#include "../header/GPIO.h"

namespace HAL
{

    GPIO::GPIO (XMC_GPIO_PORT *p, uint8_t b, XMC_GPIO_CONFIG_t c) :
            port (p), pin (b), config (c)
    {
        XMC_GPIO_Init (port, pin, &config);

        if (config.output_level == XMC_GPIO_OUTPUT_LEVEL_LOW)
        {
            outputState = 0;
        }
        else
        {
            outputState = 1;
        }
    }

    // Toggle - Change the output from High to Low or Low to High
    void GPIO::toggle ()
    {
        XMC_GPIO_ToggleOutput (port, pin);
        if (outputState == 0)
        {
            outputState = 1;
        }
        else
        {
            outputState = 0;
        }
    }

    // setHigh - Change output from Low to High
    void GPIO::setHigh ()
    {
        XMC_GPIO_SetOutputHigh (port, pin);
        outputState = 1;
    }

    // setLow - Change output from High to Low
    void GPIO::setLow ()
    {
        XMC_GPIO_SetOutputLow (port, pin);
        this->outputState = 0;
    }

    // getState - Return the current output state
    uint8_t GPIO::getState (void)
    {
        return outputState;
    }

    GPIO::~GPIO ()
    {
// TODO Auto-generated destructor stub
    }

} /* namespace HAL */
