/*
 * GPT.h
 *
 *  Created on: Jun 14, 2017
 *      Author: smithj
 *
 *      General Purpose Timer (GPT) - Implements a CCU4-CCx as a timer
 *      to fire an interrupt at a specified interval.
 */

#ifndef HAL_GPT_H_
#define HAL_GPT_H_

namespace HAL
{
    class GPT
    {
    public:
        // Constructor
        GPT ();

        // Destructor
        virtual ~GPT ();
    };

} /* namespace HAL */

#endif /* HAL_GPT_H_ */
