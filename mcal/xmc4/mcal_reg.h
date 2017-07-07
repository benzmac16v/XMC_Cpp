/*
 * mcal_reg.h
 *
 *  Created on: Jul 6, 2017
 *      Author: smithj
 */

#ifndef MCAL_XMC4_MCAL_REG_H_
#define MCAL_XMC4_MCAL_REG_H_

//#include <xmc4_gpio.h>
#include <cstdint>
#include <xmc4_gpio_map.h>
#include <XMC4700.h>

// GPIO Registers
constexpr std::uint32_t port0	= PORT0_BASE;
constexpr std::uint32_t port1	= PORT1_BASE;
constexpr std::uint32_t port2	= PORT2_BASE;
constexpr std::uint32_t port3	= PORT3_BASE;
constexpr std::uint32_t port4	= PORT4_BASE;
constexpr std::uint32_t port5	= PORT5_BASE;
constexpr std::uint32_t port6	= PORT6_BASE;
constexpr std::uint32_t port7	= PORT7_BASE;
constexpr std::uint32_t port8	= PORT8_BASE;
constexpr std::uint32_t port9	= PORT9_BASE;

constexpr std::uint32_t port14	= PORT14_BASE;
constexpr std::uint32_t port15	= PORT15_BASE;

// GPIO Offsets
constexpr std::uint32_t gpio_OUT_offset		= 0x0;
constexpr std::uint32_t gpio_OMR_offset		= 0x4;
constexpr std::uint32_t gpio_IOCR0_offset	= 0x10;
constexpr std::uint32_t gpio_IOCR4_offset	= 0x14;
constexpr std::uint32_t gpio_IOCR8_offset	= 0x18;
constexpr std::uint32_t gpio_IOCR12_offset	= 0x1C;
constexpr std::uint32_t gpio_IN_offset		= 0x24;
constexpr std::uint32_t gpio_PDR0_offset		= 0x40;
constexpr std::uint32_t gpio_PDR1_offset		= 0x44;
constexpr std::uint32_t gpio_PDISC_offset	= 0x60;
constexpr std::uint32_t gpio_PPS_offset		= 0x70;
constexpr std::uint32_t gpio_HWSEL_offset	= 0x74;






#endif /* MCAL_XMC4_MCAL_REG_H_ */
