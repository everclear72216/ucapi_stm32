#include "devconf.h"

#include "clock.h"

#include "registers/rcc.h"

static void sysclock_reset(void)
{
    /* switch on the internal high-speed oscillator */
    rcc->cr.hsion = 1;

    /* clear current core clock and bus clock configuration */
    rcc->cfgr.reg = 0;

    /* switch off the other clock sources */
    rcc->cr.hseon = 0;
    rcc->cr.csson = 0;
    rcc->cr.pllon = 0;

    /* clear hse bypass */
    rcc->cr.hsebyp = 0;

    /* disable all interrupts */
    rcc->cir.reg = 0;
}

static void sysclock_init(void)
{
    /* configure the phase-locked loop */
    rcc->cfgr.pllsrc = DC_STM32F1XX_RCC_CONFIG_PLLSOURCE;
    rcc->cfgr.pllmul = DC_STM32F1XX_RCC_CONFIG_PLLMULTIPLIER;
    rcc->cfgr.pllxtpre = DC_STM32F1XX_RCC_CONFIG_PLLENTRYDIVIDER;

    /* configure bus clocks */
    rcc->cfgr.hpre = DC_STM32F1XX_RCC_CONFIG_AHBPRESCALE;
    rcc->cfgr.ppre1 = DC_STM32F1XX_RCC_CONFIG_APB1PRESCALE;
    rcc->cfgr.ppre2 = DC_STM32F1XX_RCC_CONFIG_APB2PRESCALE;
    rcc->cfgr.usbpre = DC_STM32F1XX_RCC_CONFIG_USBPRESCALE;
    rcc->cfgr.adcpre = DC_STM32F1XX_RCC_CONFIG_ADCPRESCALE;

#if USING_HSE
    rcc->cr.hseon = 1;
    while(!rcc->cr.hserdy) {}
#endif /* USING_HSE */

#if USING_PLL
    rcc->cr.pllon = 1;
    while(!rcc->cr.pllrdy) {}
#endif /* USING_PLL */

    stm32_pre_sysclock_change();

    rcc->cfgr.sw = DC_STM32F1XX_RCC_CONFIG_CLOCKSOURCE;
    while(rcc->cfgr.sws != DC_STM32F1XX_RCC_CONFIG_CLOCKSOURCE) {}
}

extern void stm32_clock_init(void)
{
    sysclock_reset();
    sysclock_init();
}
