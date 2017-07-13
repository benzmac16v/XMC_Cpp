/*
 * reg_access.h
 *
 *  Created on: Jul 6, 2017
 *      Author: smithj
 */

#ifndef MCAL_REG_ACCESS_H_
#define MCAL_REG_ACCESS_H_


namespace mcal
{
	namespace reg
	{
		template<typename register_address_type,
				 typename register_value_type,
				 const register_address_type addr,
				 const register_value_type val = static_cast<register_value_type>(0)>
		struct access final
		{
			static void		reg_set() 	{ *reinterpret_cast<volatile register_value_type*>(addr) = val; }
			static void		reg_and()	{ *reinterpret_cast<volatile register_value_type*>(addr) &= val; }
			static void		reg_or()		{ *reinterpret_cast<volatile register_value_type*>(addr) |= val; }
			static void		reg_not()	{ *reinterpret_cast<volatile register_value_type*>(addr) &= register_value_type(~val); }
			static register_value_type
							reg_get()	{ return *reinterpret_cast<register_value_type*>(addr); }

			template<const register_value_type mask>

			static void		reg_msk()	{ *reinterpret_cast<volatile register_address_type*>(addr) =
										register_value_type(register_value_type(reg_get() & register_value_type(~mask)) |
												register_value_type(val & mask)); }

			static void		bit_set()	{ *reinterpret_cast<volatile register_value_type*>(addr)	|=
													static_cast<register_value_type>(1U << val); }

			static void		bit_clr()	{ *reinterpret_cast<volatile register_value_type*>(addr)	&=
													static_cast<register_value_type>(~static_cast<register_value_type>(1U << val)); }

			static void		bit_not()	{ *reinterpret_cast<volatile register_value_type*>(addr)	^=
													static_cast<register_value_type>(1U << val); }

			static bool		bit_get()	{ return (static_cast<volatile register_value_type>(reg_get() &
													static_cast<volatile register_value_type>(1<<val)) !=
															static_cast<volatile register_value_type>(0U)); }
		};
	}
}

#endif /* MCAL_REG_ACCESS_H_ */
