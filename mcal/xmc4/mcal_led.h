/*
 * mcal_led.h
 *
 *  Created on: Jul 6, 2017
 *      Author: smithj
 */

#ifndef MCAL_XMC4_MCAL_LED_H_
#define MCAL_XMC4_MCAL_LED_H_

#include <cstdint>
#include "mcal_PortPin.h"
#include "../../Util/utility/noncopyable.h"

namespace mcal
{
	namespace led
	{
		template<typename	addr_type,
				 typename	reg_type,
				 const 		addr_type	port,
				 const		addr_type	iocr,
				 const		reg_type		bpos>
		class Led final : private util::noncopyable_namespace::noncopyable
		{
		public:
			Led()
			{
				// Turn pin off before setting output type
				port_pin_type::set_pin_low();

				// set pin direction to output
				port_pin_type::set_pin_mode();
			}

			static void toggle()
			{
				port_pin_type::toogle_pin();
			}

			static void turnOn()
			{
				port_pin_type::set_pin_high();
			}

			static void turnOff()
			{
				port_pin_type::set_pin_low();
			}

		private:
			typedef mcal::port::Port_Pin<addr_type,
	                                     reg_type,
	                                     port,
										iocr,
	                                     bpos> port_pin_type;
		};
	      typedef Led<std::uint32_t,
	                  std::uint32_t,
					  PORT5_BASE,
					  UINT32_C(0x8000),
					  UINT32_C(9)> led_type;

	      extern const led_type led0;
	}
}


#endif /* MCAL_XMC4_MCAL_LED_H_ */
