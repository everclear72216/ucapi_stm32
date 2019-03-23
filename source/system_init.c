#include <core_init.h>

#include "clock.h"
#include "flash.h"

#include "system_init.h"

extern void stm32_pre_sysclock_change(void)
{
    stm32_flash_set_latency();
}

extern void stm32_system_init(void)
{
    cortex_m_core_init();

    stm32_clock_init();
}
