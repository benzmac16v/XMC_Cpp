/*
 * GPIO.h
 *
 *  Created on: Jun 14, 2017
 *      Author: smithj
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>
#include <xmc_gpio.h>
#include <xmc4_gpio.h>

namespace HAL
{

    class GPIO
    {
    public:

        // Constructor
        GPIO (XMC_GPIO_PORT *p, uint8_t b, XMC_GPIO_CONFIG_t c);

        // Toggle - Change the output from High to Low or Low to High
        void toggle();

        // setHigh - Change output from Low to High
        void setHigh();

        // setLow - Change output from High to Low
        void setLow();

        // getState - Return the current output state
        uint8_t getState();

        // Destructor
        virtual
        ~GPIO ();

    private:

        // Private Variables
        XMC_GPIO_PORT *port;
        uint8_t pin;
        const XMC_GPIO_CONFIG_t config;
        uint8_t outputState;
    };

} /* namespace HAL */

#endif /* GPIO_H_ */
