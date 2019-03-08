#ifndef UCAPI_STM32_CLOCK_H_INCLUDED
#define UCAPI_STM32_CLOCK_H_INCLUDED

#define USING_PLL (CLOCK_SOURCE == CLOCK_SOURCE_PLL)
#define USING_HSE ((CLOCK_SOURCE == CLOCK_SOURCE_HSE) || ((CLOCK_SOURCE == CLOCK_SOURCE_PLL) && (CLOCK_PLL_SOURCE == CLOCK_PLL_SOURCE_HSE)))

#if USING_HSE
#   define BASE_CLOCK CLOCK_HSE_FREQUENCY
#else
#   define BASE_CLOCK 8000000
#endif /* USING_HSE */

#if USING_PLL
#   if PLL_SOURCE == CLOCK_PLL_SOURCE_HSE
#       define PLL_SOURCE_CLOCK (BASE_CLOCK / CLOCK_PLL_ENTRY_DIVIDER_VALUE)
#   else
#       define PLL_SOURCE_CLOCK (BASE_CLOCK / 2)
#   endif /* PLL_SOURCE == CLOCK_PLL_SOURCE_HSE */
#   define PLLCLK (PLL_SOURCE_CLOCK * CLOCK_PLL_MULTIPLIER_VALUE)
#   define SYSCLOCK PLLCLK
#else
#   define SYSCLOCK BASE_CLOCK
#endif /* USING_PLL */

/**
 * @brief      This function shall be called during clock initialization before
 *             the new clock settings take effect. The new expected clock rate
 *             is passed as parameter so clock rate dependent settings can be
 *             updated.
 *
 * @param[in]  clockrate  The new clockrate
 */
void flash_sysclock_change();

#endif /* UCAPI_STM32_CLOCK_H_INCLUDED */
