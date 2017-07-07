/*
 * PortPin.h
 *
 *  Created on: Jul 6, 2017
 *      Author: smithj
 */

#ifndef MCAL_XMC4_MCAL_PORTPIN_H_
#define MCAL_XMC4_MCAL_PORTPIN_H_

#include "mcal_reg_access.h"

namespace mcal {

	namespace port {

		typedef void config_type;

		inline void init(const config_type*) {};

		template<typename			addr_type,
				 typename			reg_type,
				 const addr_type		port,
				 const reg_type		iocr,
				 const reg_type		bpos>
		class Port_Pin {
			public:
				static void set_pin_mode( )
				{
					if( bpos <= static_cast<reg_type>(3) )
					{
						mcal::reg::access<addr_type, reg_type, port_iocr0_reg, iocr>::reg_or();
					}
					else if ( bpos <= static_cast<reg_type>(7) )
					{
						mcal::reg::access<addr_type, reg_type, port_iocr4_reg, iocr>::reg_or();
					}
					else if ( bpos <= static_cast<reg_type>(11) )
					{
						mcal::reg::access<addr_type, reg_type, port_iocr8_reg, iocr>::reg_or();
					}
					else
					{
						mcal::reg::access<addr_type, reg_type, port_iocr12_reg, iocr>::reg_or();
					}
				}

				static void set_pin_high()
				{
					mcal::reg::access<addr_type, reg_type, port, bpos>::bit_set();
				}

				static void set_pin_low()
				{
					mcal::reg::access<addr_type, reg_type, port, bpos>::bit_clr();
				}

				static void toggle_pin()
				{
					mcal::reg::access<addr_type, reg_type, port, bpos>::bit_not();
				}

				static bool get_input_val()
				{
					return mcal::reg::access<addr_type, reg_type, port_input_reg, bpos>::bit_get();
				}

			private:
				static constexpr addr_type port_out_reg		= port + gpio_OUT_offset;
				static constexpr addr_type port_omr_reg		= port + gpio_OMR_offset;
				static constexpr addr_type port_iocr0_reg	= port + gpio_IOCR0_offset;
				static constexpr addr_type port_iocr4_reg	= port + gpio_IOCR4_offset;
				static constexpr addr_type port_iocr8_reg	= port + gpio_IOCR8_offset;
				static constexpr addr_type port_iocr12_reg	= port + gpio_IOCR12_offset;
				static constexpr addr_type port_input_reg	= port + gpio_IN_offset;
				static constexpr addr_type port_pdr_reg		= port + gpio_PDR0_offset;
				static constexpr addr_type port_pdisc_reg	= port + gpio_PDISC_offset;
				static constexpr addr_type port_pps_reg		= port + gpio_PPS_offset;
				static constexpr addr_type port_hwsel		= port + gpio_HWSEL_offset;
			};

	} /* namespace port */

} /* namespace mcal */

#endif /* MCAL_XMC4_MCAL_PORTPIN_H_ */
