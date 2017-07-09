/*
 * re_access.h
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
				 typename register_value_type>
		struct access final
		{
			static void	reg_set(register_address_type addr, register_value_type val)
			{
				*reinterpret_cast<volatile register_value_type*>(addr) = val;
			}

			static void	reg_and(register_address_type addr, register_value_type val)
			{
				*reinterpret_cast<volatile register_value_type*>(addr) &= val;
			}

			static void	reg_or(register_address_type addr, register_value_type val)
			{
				*reinterpret_cast<volatile register_value_type*>(addr) |= val;
			}

			static void	reg_not(register_address_type addr, register_value_type val)
			{
				*reinterpret_cast<volatile register_value_type*>(addr) &= register_value_type(~val);
			}

			static register_value_type reg_get(register_address_type addr)
			{
				return *reinterpret_cast<register_value_type*>(addr);
			}

			template<const register_value_type mask>

			static void	reg_msk(register_address_type addr, register_value_type val, register_value_type mask)
			{
				*reinterpret_cast<volatile register_address_type*>(addr) =
							register_value_type(register_value_type(reg_get(addr) & register_value_type(~mask)) |
							register_value_type(val & mask));
			}

			static void	bit_set(register_address_type addr, register_value_type val)
			{
				*reinterpret_cast<volatile register_value_type*>(addr)	|=
													static_cast<register_value_type>(1U << val);
			}

			static void	bit_clr(register_address_type addr, register_value_type val)
			{
				*reinterpret_cast<volatile register_value_type*>(addr)	&=
								static_cast<register_value_type>(~static_cast<register_value_type>(1U << val));
			}

			static void	bit_not(register_address_type addr, register_value_type val)
			{
				*reinterpret_cast<volatile register_value_type*>(addr)	^=
													static_cast<register_value_type>(1U << val);
			}

			static bool	bit_get(register_address_type addr, register_value_type val)
			{
				return (static_cast<volatile register_value_type>(reg_get(addr, val) &
									static_cast<volatile register_value_type>(1<<val)) !=
									static_cast<volatile register_value_type>(0U));
			}
		};
	}
}

#endif /* MCAL_REG_ACCESS_H_ */
