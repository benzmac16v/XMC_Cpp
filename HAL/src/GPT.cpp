/*
 * GPT.cpp
 *
 *  Created on: Jun 14, 2017
 *      Author: smithj
 */

#include "GPT.h"

namespace HAL
{

    HAL::GPT::GPT ( XMC_CCU4_MODULE_t ccu_ptr, XMC_CCU4_SLICE_t slice_prt, void * isr_func, int32_t freq )
    {
        this->ccu_config.module_frequency = 144000000U;
        this->ccu_config.module_ptr = ccu_ptr;
        this->ccu_config.mcs_action = (XMC_CCU4_SLICE_MCMS_ACTION_t)XMC_CCU4_SLICE_MCMS_ACTION_TRANSFER_PR_CR;
        this->ccu_config.syncstart_trigger_msk = XMC_SCU_CCU_TRIGGER_CCU40;
        this->ccu_config.is_initialized = true;
    }

    void HAL::GPT::startTimer (void)
    {

    }
    void HAL::GPT::stopTimer (void)
    {

    }
} /* namespace HAL */
