#include "devconf.h"

#include "flash.h"
#include "registers/flash.h"

extern void stm32_flash_set_latency(void)
{
    flash->flash_acr.latency = DC_STM32F1XX_FLASH_LATENCY;
}
