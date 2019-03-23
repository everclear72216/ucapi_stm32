#include <ucapi/init.h>

#include "system_init.h"

extern void ucapi_init(void)
{
    stm32_system_init();
}
