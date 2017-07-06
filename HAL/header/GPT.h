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

#include <xmc_ccu4.h>
#include <xmc_scu.h>

namespace HAL
{
    typedef struct XMC_CCU_CONFIG
    {
        uint32_t module_frequency;
        XMC_SCU_CCU_TRIGGER_t syncstart_trigger_msk;
        XMC_CCU4_MODULE_t* module_ptr;
        XMC_CCU4_SLICE_MCMS_ACTION_t mcs_action;
        bool is_initialized;
    } XMC_CCU_Config_t;

    typedef struct XMC_CCU4_SLICE_COMPARE_CONFIG_t
    {
        union
        {
            struct
            {
                uint32_t timer_mode :1; /**< Edge aligned or Centre Aligned.
                 Accepts enum ::XMC_CCU4_SLICE_TIMER_COUNT_MODE_t */
                uint32_t monoshot :1; /**< Single shot or Continuous mode .
                 Accepts enum :: XMC_CCU4_SLICE_TIMER_REPEAT_MODE_t*/
                uint32_t shadow_xfer_clear :1; /**< Should PR and CR shadow xfer happen when timer is cleared? */
                uint32_t :10;
                uint32_t dither_timer_period :1; /**< Can the period of the timer dither? */
                uint32_t dither_duty_cycle :1; /**< Can the compare match of the timer dither? */
                uint32_t :1;
                uint32_t prescaler_mode :1; /**< Normal or floating prescaler mode.
                 Accepts enum :: XMC_CCU4_SLICE_PRESCALER_MODE_t*/
                uint32_t :8;
                uint32_t mcm_enable :1; /**< Multi-Channel mode enable? */
                uint32_t :6;
            };
            uint32_t tc;
        };
        uint32_t prescaler_initval :4; /**< Initial prescaler divider value
         Accepts enum :: XMC_CCU4_SLICE_PRESCALER_t */
        uint32_t float_limit :4; /**< The max value which the prescaler divider can increment to */
        uint32_t dither_limit :4; /**< The value that determines the spreading of dithering */
        uint32_t passive_level :1; /**< Configuration of ST and OUT passive levels.
         Accepts enum :: XMC_CCU4_SLICE_OUTPUT_PASSIVE_LEVEL_t*/
        uint32_t timer_concatenation :1; /**< Enables the concatenation of the timer if true.*/
    } XMC_CCU4_Slice_Compare_Config_t;

    typedef struct TIMER
    {
        uint32_t time_interval_value_us; /**< Timer interval value for which event is being generated */
        const uint32_t timer_max_value_us; /**< Maximum timer value in micro seconds for the available clock */
        const uint32_t timer_min_value_us; /**< Minimum timer value in micro seconds for the available clock */
        const uint32_t shadow_mask; /**< shadow transfer mask for the selected timer */
        XMC_CCU_Config_t* const global_ccu4_handler; /**< Reference to CCU4GLOBAL APP handler */
        XMC_CCU4_SLICE_t* const ccu4_slice_ptr; /**< Reference to CCU4-CC4 slice identifier data handler */
        const uint8_t ccu4_slice_number; /* Timer being used */
        XMC_CCU4_SLICE_COMPARE_CONFIG_t* const ccu4_slice_config_ptr; /**< Reference to initialization data structure of
         the core timer functionality */
        XMC_CCU4_SLICE_SR_ID_t const ccu4_period_match_node; /**< Service Request Id for period match event */
        uint16_t period_value; /**< Period value to be loaded into timer for the corresponding time tick */
        bool const start_control; /**< Indicate whether to start the APP during initialization itself */
        bool const period_match_enable; /**< Indicate the generation of period match event */
        bool initialized; /* flag to indicate the initialization state of the APP instance */
    } Timer_t;

    class GPT
    {
    public:
        // Constructor
        GPT ( XMC_CCU4_MODULE_t ccu_ptr, XMC_CCU4_SLICE_t slice_prt, void * isr_func, int32_t freq );

        void HAL::GPT::startTimer(void);
        void HAL::GPT::stopTimer(void);

    private:
        XMC_CCU_Config_t    ccu_config;
        XMC_CCU4_Slice_Compare_Config_t ccu_slice_config;
        Timer_t timer_config;
    };

} /* namespace HAL */

#endif /* HAL_GPT_H_ */
