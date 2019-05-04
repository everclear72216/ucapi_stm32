#ifndef UCAPI_STM32_CLOCK_H_INCLUDED
#define UCAPI_STM32_CLOCK_H_INCLUDED

#define USING_PLL (DC_STM32F1XX_RCC_CONFIG_CLOCKSOURCE_VALUE == DC_STM32F1XX_RCCCONFIGS_CLOCKSOURCE_PLL)
#define USING_HSE ((DC_STM32F1XX_RCC_CONFIG_CLOCKSOURCE_VALUE == DC_STM32F1XX_RCCCONFIGS_CLOCKSOURCE_HSE) || ((DC_STM32F1XX_RCC_CONFIG_CLOCKSOURCE_VALUE == DC_STM32F1XX_RCCCONFIGS_CLOCKSOURCE_PLL) && (DC_STM32F1XX_RCC_CONFIG_PLLSOURCE_VALUE == DC_STM32F1XX_RCCCONFIGS_PLLSOURCE_HSE)))

#if USING_HSE
#   define BASE_CLOCK CLOCK_HSE_FREQUENCY
#else
#   define BASE_CLOCK 8000000
#endif /* USING_HSE */

#if USING_PLL
#   if DC_STM32F1XX_RCC_CONFIG_PLLSOURCE_VALUE == DC_STM32F1XX_RCCCONFIGS_PLLSOURCE_HSE
#       define PLL_SOURCE_CLOCK (BASE_CLOCK / DC_STM32F1XX_RCC_CONFIG_PLLENTRYDIVIDER_VALUE)
#   else
#       define PLL_SOURCE_CLOCK (BASE_CLOCK / 2)
#   endif /* DC_STM32F1XX_RCC_CONFIG_PLLSOURCE_VALUE == DC_STM32F1XX_RCCCONFIGS_PLLSOURCE_HSE */
#   define PLLCLK (PLL_SOURCE_CLOCK * DC_STM32F1XX_RCC_CONFIG_PLLMULTIPLIER_VALUE)
#   define SYSCLOCK PLLCLK
#else
#   define SYSCLOCK BASE_CLOCK
#endif /* USING_PLL */

/**
 * @brief      Initializes the system clocks.
 */
extern void stm32_clock_init(void);

/**
 * @brief      This function shall be called during clock initialization before
 *             the new clock settings take effect.
 */
extern void stm32_pre_sysclock_change(void);

#endif /* UCAPI_STM32_CLOCK_H_INCLUDED */
