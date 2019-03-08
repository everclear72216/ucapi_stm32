#include "devconf.h"

#include "clock.h"

#include "flash/flash.h"

void flash_sysclock_change(void)
{
    flash->flash_acr.latency = FLASH_LATENCY;
}
