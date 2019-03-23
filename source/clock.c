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
    rcc->cfgr.pllsrc = CLOCK_PLL_SOURCE;
    rcc->cfgr.pllmul = CLOCK_PLL_MULTIPLIER;
    rcc->cfgr.pllxtpre = CLOCK_PLL_ENTRY_DIVIDER;

    /* configure bus clocks */
    rcc->cfgr.hpre = CLOCK_AHB_PRESCALE;
    rcc->cfgr.ppre1 = CLOCK_APB1_PRESCALE;
    rcc->cfgr.ppre2 = CLOCK_APB2_PRESCALE;
    rcc->cfgr.usbpre = CLOCK_USB_PRESCALE;
    rcc->cfgr.adcpre = CLOCK_ADC_PRESCALE;

#if USING_HSE
    rcc->cr.hseon = 1;
    while(!rcc->cr.hserdy) {}
#endif /* USING_HSE */

#if USING_PLL
    rcc->cr.pllon = 1;
    while(!rcc->cr.pllrdy) {}
#endif /* USING_PLL */

    stm32_pre_sysclock_change();

    rcc->cfgr.sw = CLOCK_SOURCE;
    while(rcc->cfgr.sws != CLOCK_SOURCE) {}
}

extern void stm32_clock_init(void)
{
    sysclock_reset();
    sysclock_init();
}
