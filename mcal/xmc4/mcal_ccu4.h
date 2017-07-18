/*
 * mcal_ccu4.h
 *
 *  Created on: Jul 12, 2017
 *      Author: smithj
 *
 *  Description: This class determines if a ccu4x module tracks if a ccu4x/cc4x
 *  resource has already been used.  Determines if the ccu4x module still needs
 *  to be configured.
 *
 *  Currently cannot release a resource.
 *
 */

// TODO: Enable the tracking of ccu4 slice resources as well as the ccu4 module

#ifndef MCAL_XMC4_MCAL_CCU4_H_
#define MCAL_XMC4_MCAL_CCU4_H_

#include "mcal_reg.h"
#include "../../Util/utility/noncopyable.h"

namespace mcal
{

	namespace ccu4
	{

	struct	ccu4x_data
	{

		bool		ccu4			= false;
		bool		cc0			= false;
		bool		cc1			= false;
		bool		cc2			= false;
		bool		cc3			= false;
	};

	template<	typename		addr_type>
	class	CCU4x_Resource_Manager final : private util::noncopyable_namespace::noncopyable
	{
	public:
		CCU4x_Resource_Manager(){}

		bool	check_resource(addr_type ccu4x_check, addr_type cc4x_check)
		{
			if( ccu4x_check == ccu40 )
			{
				if( ccu40_data.ccu4 )
				{
					return false;
				}
				else
				{
					ccu40_data.ccu4 = true;
					return true;
				}
			}
			else if( ccu4x_check == ccu41 )
			{
				if( ccu41_data.ccu4 )
				{
					return false;
				}
				else
				{
					ccu41_data.ccu4 = true;
					return true;
				}
			}
			else if( ccu4x_check == ccu42 )
			{
				if( ccu42_data.ccu4 )
				{
					return false;
				}
				else
				{
					ccu42_data.ccu4 = true;
					return true;
				}
			}
			else
			{
				if( ccu43_data.ccu4 )
				{
					return false;
				}
				else
				{
					ccu43_data.ccu4 = true;
					return true;
				}
			}
		}

	private:
		static	ccu4x_data	ccu40_data;
		static	ccu4x_data	ccu41_data;
		static	ccu4x_data	ccu42_data;
		static	ccu4x_data	ccu43_data;
	};

	}
}


#endif /* MCAL_XMC4_MCAL_CCU4_H_ */
