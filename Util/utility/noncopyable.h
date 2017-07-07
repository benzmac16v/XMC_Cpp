/*
 * noncopyable.h
 *
 *  Created on: Jul 6, 2017
 *      Author: smithj
 */

#ifndef UTIL_UTILITY_NONCOPYABLE_H_
#define UTIL_UTILITY_NONCOPYABLE_H_

namespace util
{
	namespace noncopyable_namespace
	{
		class noncopyable
		{
		protected:
			constexpr noncopyable() = default;
			~noncopyable() = default;

		private:
			noncopyable(const noncopyable&) = delete;
			noncopyable& operator=(const noncopyable&) = delete;
		};
	}
}



#endif /* UTIL_UTILITY_NONCOPYABLE_H_ */
