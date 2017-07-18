/*
 * mcal_ccu4.h
 *
 *  Created on: Jul 12, 2017
 *      Author: smithj
 */

#ifndef MCAL_XMC4_MCAL_GPT_H_
#define MCAL_XMC4_MCAL_GPT_H_

#include <cstdint>
//#include "mcal_ccu4.h"
#include "mcal_reg_access.h"

namespace mcal {

	namespace gpt {

	template<	typename		addr_type,
				typename		reg_type,
				const		addr_type	ccu4x,
				const		addr_type	cc4x,
				reg_type		period	>
	class	GPT	{

	public:
		GPT(){}

		void init()
		{
			reg_type val =  0;

			// Configure the ccu4 and slice as a timer
			//ccu4x_initialized = ccu4x_resource.check_resource(ccu4x, cc4x);

			// If the ccu4x module is not initialize, initialize it, otherwise skip init
			// and assume its correct...
			//if( ccu4x_initialized == false )
			//{
				// Reset the ccu4 module in the SCU bitfield
				mcal::reg::access<addr_type, reg_type, scu_rcu_prset0, static_cast<reg_type>( 2 )>::bit_set();

				// Clear the CCU4 reset
				mcal::reg::access<addr_type, reg_type, scu_rcu_prclr0, UINT32_C( 2 )>::bit_set();

				// Enable clock to CCU4
				mcal::reg::access<addr_type, reg_type, scu_ccu_clkset, UINT32_C( 4 )>::bit_set();

				// Enable the prescalar
				mcal::reg::access<addr_type, reg_type, ccu4x_gidlc, UINT32_C( 8 )>::bit_set();

			//	ccu4x_initialized = true;
			//}
			//else
			//{
				ccu4x_initialized = true;
			//}

			// Configure needed registers

			// Enable interrupt on period match
			mcal::reg::access<addr_type, reg_type, cc4x_inte, zero>::bit_set();

			// Set period value
			mcal::reg::access<addr_type, reg_type, cc4x_prs, period>::reg_set();

			// Set prescalar
			mcal::reg::access<addr_type, reg_type, cc4x_psc, static_cast<reg_type>(0b1011)>::reg_set();

			// Issue shadow register transfer
			mcal::reg::access<addr_type, reg_type, ccu4x_gcss, UINT32_C( 0b111 )>::reg_set();

			// Enable the slice clock
			mcal::reg::access<addr_type, reg_type, ccu4x_gidlc, UINT32_C( 0 )>::bit_set();

			// Has been init
			init_successful = true;

		}

		void start()
		{
			mcal::reg::access<addr_type, reg_type, cc4x_tcset, UINT32_C( 0 )>::bit_set();
			timerRunning = true;
		}

		void stop()
		{
			mcal::reg::access<addr_type, reg_type, cc4x_tcclr, UINT32_C( 0 )>::bit_set();
			timerRunning = false;
		}

		void resetIRQ()
		{
			mcal::reg::access<addr_type, reg_type, cc4x_swr, static_cast<reg_type>( 0 )>::bit_set();
		}

		bool		timerRunning = false;
	private:

		//mcal::reg::access_dyn<addr_type, reg_type> regAccessDyn;
		//mcal::ccu4::CCU4x_Resource_Manager<addr_type> ccu4x_resource;

		bool		init_successful 		= false;
		bool		ccu4x_initialized	= false;

		static constexpr reg_type zero	= UINT32_C( 0 );

		static constexpr addr_type ccu4x_gctrl		= ccu4x	+ ccu4x_GCTRL_offset;
		//static constexpr addr_type ccu4x_gstat		= ccu4x	+ ccu4x_GSTAT_offset;
		static constexpr addr_type ccu4x_gidls		= ccu4x	+ ccu4x_GIDLS_offset;
		static constexpr addr_type ccu4x_gidlc		= ccu4x	+ ccu4x_GIDLC_offset;
		static constexpr addr_type ccu4x_gcss			= ccu4x	+ ccu4x_GCSS_offset;
		static constexpr addr_type ccu4x_gcsc			= ccu4x	+ ccu4x_GCSC_offset;
		//static constexpr addr_type ccu4x_gcst			= ccu4x	+ ccu4x_GCST_offset;
		//static constexpr addr_type ccu4x_midr			= ccu4x	+ ccu4x_MIDR_offset;

		// CCU4 Slice Registers
		static constexpr addr_type cc4x_ins			= cc4x + cc4x_INS_offset;
		static constexpr addr_type cc4x_cmc			= cc4x + cc4x_CMC_offset;
		//static constexpr addr_type cc4x_tst			= cc4x + cc4x_TST_offset;
		static constexpr addr_type cc4x_tcset			= cc4x + cc4x_TCSET_offset;
		static constexpr addr_type cc4x_tcclr			= cc4x + cc4x_TCCLR_offset;
		static constexpr addr_type cc4x_tc			= cc4x + cc4x_TC_offset;
		static constexpr addr_type cc4x_psl			= cc4x + cc4x_PSL_offset;
		//static constexpr addr_type cc4x_dit			= cc4x + cc4x_DIT_offset;
		static constexpr addr_type cc4x_dits			= cc4x + cc4x_DITS_offset;
		static constexpr addr_type cc4x_psc			= cc4x + cc4x_PSC_offset;
		static constexpr addr_type cc4x_fpc			= cc4x + cc4x_FPC_offset;
		static constexpr addr_type cc4x_fpcs			= cc4x + cc4x_FPCS_offset;
		//static constexpr addr_type cc4x_pr			= cc4x + cc4x_PR_offset;
		static constexpr addr_type cc4x_prs			= cc4x + cc4x_PRS_offset;
		//static constexpr addr_type cc4x_cr			= cc4x + cc4x_CR_offset;
		static constexpr addr_type cc4x_crs			= cc4x + cc4x_CRS_offset;
		static constexpr addr_type cc4x_timer			= cc4x + cc4x_TIMER_offset;
		//static constexpr addr_type cc4x_c0v			= cc4x + cc4x_C0V_offset;
		//static constexpr addr_type cc4x_c1v			= cc4x + cc4x_C1V_offset;
		//static constexpr addr_type cc4x_c2v			= cc4x + cc4x_C2V_offset;
		//static constexpr addr_type cc4x_c3v			= cc4x + cc4x_C3V_offset;
		//static constexpr addr_type cc4x_ints			= cc4x + cc4x_INTS_offset;
		static constexpr addr_type cc4x_inte			= cc4x + cc4x_INTE_offset;
		static constexpr addr_type cc4x_srs			= cc4x + cc4x_SRS_offset;
		static constexpr addr_type cc4x_sws			= cc4x + cc4x_SWS_offset;
		static constexpr addr_type cc4x_swr			= cc4x + cc4x_SWR_offset;
		//static constexpr addr_type cc4x_ecrd0			= cc4x + cc4x_ECRD0_offset;
		//static constexpr addr_type cc4x_ecrd1			= cc4x + cc4x_ECRD1_offset;

		static constexpr addr_type scu_rcu_prset0	= scu_address + scu_rcu_offset + scu_rcu_prset0_offset;
		static constexpr addr_type scu_rcu_prclr0	= scu_address + scu_rcu_offset + scu_rcu_prclr0_offset;
		static constexpr addr_type scu_ccu_clkset	= scu_address + scu_ccu_offset + scu_ccu_clkset_offset;

	};

    typedef GPT<std::uint32_t,
                std::uint32_t,
				ccu40,
				ccu40 + ccu4x_CC0_offset,
				UINT32_C( 60000 )> GPT_type;

    extern GPT_type timer1;
	}
}



#endif /* MCAL_XMC4_MCAL_GPT_H_ */
