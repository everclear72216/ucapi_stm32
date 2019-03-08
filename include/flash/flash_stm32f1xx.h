#ifndef UCAPI_STM32_FLASH_STM32F1XX_H_INCLUDED
#define UCAPI_STM32_FLASH_STM32F1XX_H_INCLUDED

struct stm32_flash_registers
{
    union {
        unsigned int reg;
        struct {
            unsigned int latency:3;
            unsigned int hlfcya:1;
            unsigned int prftbe:1;
            unsigned int prftbs:1;
            unsigned int __reserved0:26;
        };
    } flash_acr;
    unsigned int flash_keyr;
    unsigned int flash_optkeyr;
    union {
        unsigned int reg;
        struct {
            unsigned int bsy:1;
            unsigned int __reserved0:1;
            unsigned int pgerr:1;
            unsigned int __reserved1:1;
            unsigned int wrprterr:1;
            unsigned int eop:1;
            unsigned int __reserved2:26;
        };
    } flash_sr;
    union {
        unsigned int reg;
        struct {
            unsigned int pg:1;
            unsigned int per:1;
            unsigned int mer:1;
            unsigned int __reserved0:1;
            unsigned int optpg:1;
            unsigned int opter:1;
            unsigned int strt:1;
            unsigned int lock:1;
            unsigned int __reserved1:1;
            unsigned int optwre:1;
            unsigned int errie:1;
            unsigned int __reserved2:1;
            unsigned int eopie:1;
            unsigned int __reserved3:19;
        };
    } flash_cr;
    unsigned int flash_ar;
    unsigned int __reserved0;
    union {
        unsigned int reg;
        struct {
            unsigned int opterr:1;
            unsigned int rdprt:1;
            unsigned int wdg_sw:1;
            unsigned int nrst_stop:1;
            unsigned int nrst_stdby:1;
            unsigned int not_used:5;
            unsigned int data0:8;
            unsigned int data1:8;
            unsigned int __reserved0:6;
        };
    } flash_obr;
    unsigned int flash_wpr;
};

#define flash ((volatile struct stm32_flash_registers*)FLASH_BASE)

#endif /* UCAPI_STM32_FLASH_STM32F1XX_H_INCLUDED */
