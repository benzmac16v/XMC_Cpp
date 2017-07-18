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

// CCU4 Base Registers
constexpr std::uint32_t ccu40	= CCU40_BASE;
constexpr std::uint32_t ccu41	= CCU41_BASE;
constexpr std::uint32_t ccu42	= CCU42_BASE;
constexpr std::uint32_t ccu43	= CCU43_BASE;

// CCU4x Global Offsets
constexpr std::uint32_t ccu4x_GCTRL_offset	= UINT32_C( 0x000 );
constexpr std::uint32_t ccu4x_GSTAT_offset	= UINT32_C( 0x004 );
constexpr std::uint32_t ccu4x_GIDLS_offset	= UINT32_C( 0x008 );
constexpr std::uint32_t ccu4x_GIDLC_offset	= UINT32_C( 0x00C );
constexpr std::uint32_t ccu4x_GCSS_offset	= UINT32_C( 0x010 );
constexpr std::uint32_t ccu4x_GCSC_offset	= UINT32_C( 0x014 );
constexpr std::uint32_t ccu4x_GCST_offset	= UINT32_C( 0x018 );
constexpr std::uint32_t ccu4x_MIDR_offset	= UINT32_C( 0x080 );

// CCU4 Slice Addresses
constexpr std::uint32_t ccu4x_CC0_offset		= UINT32_C( 0x100 );
constexpr std::uint32_t ccu4x_CC1_offset		= UINT32_C( 0x200 );
constexpr std::uint32_t ccu4x_CC2_offset		= UINT32_C( 0x300 );
constexpr std::uint32_t ccu4x_CC3_offset		= UINT32_C( 0x400 );

// CCU4 Slice Register Offsets (from Slice Offsets)
constexpr std::uint32_t cc4x_INS_offset		= UINT32_C( 0x000 );
constexpr std::uint32_t cc4x_CMC_offset		= UINT32_C( 0x004 );
constexpr std::uint32_t cc4x_TST_offset		= UINT32_C( 0x008 );
constexpr std::uint32_t cc4x_TCSET_offset	= UINT32_C( 0x00C );
constexpr std::uint32_t cc4x_TCCLR_offset	= UINT32_C( 0x010 );
constexpr std::uint32_t cc4x_TC_offset		= UINT32_C( 0x014 );
constexpr std::uint32_t cc4x_PSL_offset		= UINT32_C( 0x018 );
constexpr std::uint32_t cc4x_DIT_offset		= UINT32_C( 0x01C );
constexpr std::uint32_t cc4x_DITS_offset		= UINT32_C( 0x020 );
constexpr std::uint32_t cc4x_PSC_offset		= UINT32_C( 0x024 );
constexpr std::uint32_t cc4x_FPC_offset		= UINT32_C( 0x028 );
constexpr std::uint32_t cc4x_FPCS_offset		= UINT32_C( 0x02C );
constexpr std::uint32_t cc4x_PR_offset		= UINT32_C( 0x030 );
constexpr std::uint32_t cc4x_PRS_offset		= UINT32_C( 0x034 );
constexpr std::uint32_t cc4x_CR_offset		= UINT32_C( 0x038 );
constexpr std::uint32_t cc4x_CRS_offset		= UINT32_C( 0x03C );
constexpr std::uint32_t cc4x_TIMER_offset	= UINT32_C( 0x070 );
constexpr std::uint32_t cc4x_C0V_offset		= UINT32_C( 0x074 );
constexpr std::uint32_t cc4x_C1V_offset		= UINT32_C( 0x078 );
constexpr std::uint32_t cc4x_C2V_offset		= UINT32_C( 0x07C );
constexpr std::uint32_t cc4x_C3V_offset		= UINT32_C( 0x080 );
constexpr std::uint32_t cc4x_INTS_offset		= UINT32_C( 0x0A0 );
constexpr std::uint32_t cc4x_INTE_offset		= UINT32_C( 0x0A4 );
constexpr std::uint32_t cc4x_SRS_offset		= UINT32_C( 0x0A8 );
constexpr std::uint32_t cc4x_SWS_offset		= UINT32_C( 0x0AC );
constexpr std::uint32_t cc4x_SWR_offset		= UINT32_C( 0x0B0 );
constexpr std::uint32_t cc4x_ECRD0_offset	= UINT32_C( 0x0B0 );
constexpr std::uint32_t cc4x_ECRD1_offset	= UINT32_C( 0x0BC );




#endif /* MCAL_XMC4_MCAL_REG_H_ */
