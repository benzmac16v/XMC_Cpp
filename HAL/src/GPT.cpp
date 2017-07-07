/*
 * GPT.cpp
 *
 *  Created on: Jun 14, 2017
 *      Author: smithj
 */

#include <GPT.h>

namespace HAL

//XMC_CCU4_MODULE_t

{

    HAL::GPT::GPT ( XMC_CCU4_MODULE_t* ccu_ptr, XMC_CCU4_SLICE_t* slice_ptr, void * isr_func, int32_t freq )
    {
        ccu_config.module_frequency 			= 144000000U;
        ccu_config.module_ptr 				= ccu_ptr;
        ccu_config.mcs_action 				= (XMC_CCU4_SLICE_MCMS_ACTION_t)XMC_CCU4_SLICE_MCMS_ACTION_TRANSFER_PR_CR;
        ccu_config.syncstart_trigger_msk 	= XMC_SCU_CCU_TRIGGER_CCU40;
        ccu_config.is_initialized 			= true;

        ccu_slice_config.timer_mode			= XMC_CCU4_SLICE_TIMER_COUNT_MODE_EA;
        ccu_slice_config.monoshot			= XMC_CCU4_SLICE_TIMER_REPEAT_MODE_REPEAT;
        ccu_slice_config.shadow_xfer_clear	= false;
        ccu_slice_config.dither_timer_period	= false;
        ccu_slice_config.dither_duty_cycle	= false;
        ccu_slice_config.prescaler_mode		= XMC_CCU4_SLICE_PRESCALER_MODE_NORMAL;
        ccu_slice_config.mcm_enable			= false;
        ccu_slice_config.prescaler_initval	= 0U;
        ccu_slice_config.float_limit			= 0U;
        ccu_slice_config.dither_limit		= 0U;
        ccu_slice_config.passive_level		= XMC_CCU4_SLICE_OUTPUT_PASSIVE_LEVEL_LOW;
        ccu_slice_config.timer_concatenation	= false;

        //timer_config.ccu4_slice_ptr			= slice_ptr;
        timer_config.ccu4_slice_number		= 0U;
        timer_config.time_interval_value_us	= 100U;
        timer_config.timer_max_value_us		= 1491285300U;
        timer_config.timer_min_value_us		= 10U;
        timer_config.global_ccu4_handler		= &ccu_config;
        timer_config.ccu4_slice_config_ptr	= &ccu_slice_config;
        timer_config.shadow_mask				= (uint32_t)((uint32_t)XMC_CCU4_SHADOW_TRANSFER_SLICE_0 |
        										(uint32_t)XMC_CCU4_SHADOW_TRANSFER_PRESCALER_SLICE_3);
        timer_config.ccu4_period_match_node	= XMC_CCU4_SLICE_SR_ID_0;
        timer_config.period_value			= 143U;
        timer_config.start_control			= true;
        timer_config.period_match_enable		= true;
        timer_config.initialized				= false;

    }

    void HAL::GPT::startTimer (void)
    {

    }
    void HAL::GPT::stopTimer (void)
    {

    }

    void HAL::GPT::init(Timer_t* handle_ptr)
    {
      /* Initialize the global registers */
      GLOBAL_CCU4_Init(handle_ptr->global_ccu4_handler);

      /* Enable the clock for selected timer */
      XMC_CCU4_EnableClock(handle_ptr->global_ccu4_handler->module_ptr, handle_ptr->ccu4_slice_number);
      /* Configure the timer with required settings */
      XMC_CCU4_SLICE_CompareInit(handle_ptr->ccu4_slice_ptr, handle_ptr->ccu4_slice_config_ptr);
      /* programs the timer period and compare register according to time interval value and do the shadow transfer */
      shadowTransfer(handle_ptr);

      if (true == handle_ptr->period_match_enable)
      {
        /* Binds a period match event to an NVIC node  */
        XMC_CCU4_SLICE_SetInterruptNode(handle_ptr->ccu4_slice_ptr, XMC_CCU4_SLICE_IRQ_ID_PERIOD_MATCH,
                                        handle_ptr->ccu4_period_match_node);
        /* Enables a timer(period match) event  */
        XMC_CCU4_SLICE_EnableEvent(handle_ptr->ccu4_slice_ptr, XMC_CCU4_SLICE_IRQ_ID_PERIOD_MATCH);
      }

      /* Clears the timer register */
      XMC_CCU4_SLICE_ClearTimer(handle_ptr->ccu4_slice_ptr);

      /* update the initialization flag as true for particular instance*/
      handle_ptr->initialized = true;

      /* Check whether the start of the timer is enabled during initialization or not */
      if (handle_ptr->start_control == true)
      {
        /* Start the timer */
        XMC_CCU4_SLICE_StartTimer(handle_ptr->ccu4_slice_ptr);
      }

    }

    /*
     * This function configures timer period and compare values and triggers the shadow transfer operation
     */
    void HAL::GPT::shadowTransfer(Timer_t* handle_ptr)
    {
      /* programs the timer period register according to time interval value */
      XMC_CCU4_SLICE_SetTimerPeriodMatch(handle_ptr->ccu4_slice_ptr, handle_ptr->period_value);
      /* programs the timer compare register for 50% duty cycle */
      XMC_CCU4_SLICE_SetTimerCompareMatch(handle_ptr->ccu4_slice_ptr, TIMER_CMP_100_DUTY);
      /* Transfers value from shadow timer registers to actual timer registers */
      XMC_CCU4_EnableShadowTransfer(handle_ptr->global_ccu4_handler->module_ptr, handle_ptr->shadow_mask);
    }
} /* namespace HAL */
