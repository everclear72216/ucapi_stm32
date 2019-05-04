#ifndef UCAPI_STM32_RCC_STM32F101XX_H_INCLUDED
#define UCAPI_STM32_RCC_STM32F101XX_H_INCLUDED

struct stm32_rcc_registers
{
    union {
        unsigned int reg;
        struct {
            unsigned int hsion:1;
            unsigned int hsirdy:1;
            unsigned int __reserved0:1;
            unsigned int hsitrim:5;
            unsigned int hsical:8;
            unsigned int hseon:1;
            unsigned int hserdy:1;
            unsigned int hsebyp:1;
            unsigned int csson:1;
            unsigned int __reserved1:4;
            unsigned int pllon:1;
            unsigned int pllrdy:1;
            unsigned int __reserved2:6;
        };
    } cr;

    union {
        unsigned int reg;
        struct {
            unsigned int sw:2;
            unsigned int sws:2;
            unsigned int hpre:3;
            unsigned int ppre1:3;
            unsigned int ppre2:3;
            unsigned int adcpre:2;
            unsigned int pllsrc:1;
            unsigned int pllxtpre:1;
            unsigned int pllmul:4;
            unsigned int usbpre:1;
            unsigned int __reserved0:1;
            unsigned int mco:3;
            unsigned int __reserved1:5;
        };
    } cfgr;

    union {
        unsigned int reg;
        struct {
            unsigned int lsirdyf:1;
            unsigned int lserdyf:1;
            unsigned int hsirdyf:1;
            unsigned int hserdyf:1;
            unsigned int pllrdyf:1;
            unsigned int __reserved0:2;
            unsigned int cssf:1;
            unsigned int lsirdyie:1;
            unsigned int lserdyie:1;
            unsigned int hsirdyie:1;
            unsigned int hserdyie:1;
            unsigned int pllrdyie:1;
            unsigned int __reserved1:3;
            unsigned int lsirdyc:1;
            unsigned int lserdyc:1;
            unsigned int hsirdyc:1;
            unsigned int hserdyc:1;
            unsigned int pllrdyc:1;
            unsigned int __reserved2:2;
            unsigned int cssc:1;
            unsigned int __reserved3:8;
        };
    } cir;

    union {
        unsigned int reg;
        struct {
            unsigned int afiorst:1;
            unsigned int __reserved0:1;
            unsigned int ioparst:1;
            unsigned int iopbrst:1;
            unsigned int iopcrst:1;
            unsigned int iopdrst:1;
            unsigned int ioperst:1;
            unsigned int iopfrst:1;
            unsigned int iopgrst:1;
            unsigned int adc1rst:1;
            unsigned int adc2rst:1;
            unsigned int tim1rst:1;
            unsigned int spi1rst:1;
            unsigned int tim8rst:1;
            unsigned int usart1rst:1;
            unsigned int adc3rst:1;
            unsigned int __reserved1:3;
            unsigned int tim9rst:1;
            unsigned int tim10rst:1;
            unsigned int tim11rst:1;
            unsigned int __reserved2:10;
        };
    } apb2rstr;

    union {
        unsigned int reg;
        struct {
            unsigned int tim2rst:1;
            unsigned int tim3rst:1;
            unsigned int tim4rst:1;
            unsigned int tim5rst:1;
            unsigned int tim6rst:1;
            unsigned int tim7rst:1;
            unsigned int tim12rst:1;
            unsigned int tim13rst:1;
            unsigned int tim14rst:1;
            unsigned int __reserved0:2;
            unsigned int wwdgrst:1;
            unsigned int __reserved1:2;
            unsigned int spi2rst:1;
            unsigned int spi3rst:1;
            unsigned int __reserved2:1;
            unsigned int usart2rst:1;
            unsigned int usart3rst:1;
            unsigned int uart4rst:1;
            unsigned int uart5rst:1;
            unsigned int i2c1rst:1;
            unsigned int i2c2rst:1;
            unsigned int __reserved3:1;
            unsigned int canrst:1;
            unsigned int __reserved4:1;
            unsigned int bkprst:1;
            unsigned int pwrrst:1;
            unsigned int dacrst:1;
            unsigned int __reserved5:2;
        };
    } apb1rstr;

    union {
        unsigned int reg;
        struct {
            unsigned int dma1en:1;
            unsigned int dma2ed:1;
            unsigned int sramen:1;
            unsigned int __reserved0:1;
            unsigned int flitfen:1;
            unsigned int __reserved1:1;
            unsigned int crcen:1;
            unsigned int __reserved2:1;
            unsigned int fsmcen:1;
            unsigned int __reserved3:1;
            unsigned int sdioen:1;
            unsigned int __reserved4:21;
        };
    } ahbenr;

    union {
        unsigned int reg;
        struct {
            unsigned int afioen:1;
            unsigned int __reserved0:1;
            unsigned int iopaen:1;
            unsigned int iopben:1;
            unsigned int iopcen:1;
            unsigned int iopden:1;
            unsigned int iopeen:1;
            unsigned int iopfen:1;
            unsigned int iopgen:1;
            unsigned int adc1en:1;
            unsigned int adc2en:1;
            unsigned int tim1en:1;
            unsigned int spi1en:1;
            unsigned int tim8en:1;
            unsigned int usart1en:1;
            unsigned int adc3en:1;
            unsigned int __reserved1:3;
            unsigned int tim9en:1;
            unsigned int tim10en:1;
            unsigned int tim11en:1;
            unsigned int __reserved2:10;
        };
    } apb2enr;

    union {
        unsigned int reg;
        struct {
            unsigned int tim2en:1;
            unsigned int tim3en:1;
            unsigned int tim4en:1;
            unsigned int tim5en:1;
            unsigned int tim6en:1;
            unsigned int tim7en:1;
            unsigned int tim12en:1;
            unsigned int tim13en:1;
            unsigned int tim14en:1;
            unsigned int __reserved0:2;
            unsigned int wwdgen:1;
            unsigned int __reserved1:2;
            unsigned int spi2en:1;
            unsigned int spi3en:1;
            unsigned int __reserved2:1;
            unsigned int usart2en:1;
            unsigned int usart3en:1;
            unsigned int uart4en:1;
            unsigned int uart5en:1;
            unsigned int i2c1en:1;
            unsigned int i2c2en:1;
            unsigned int __reserved3:1;
            unsigned int canen:1;
            unsigned int __reserved4:1;
            unsigned int bkpen:1;
            unsigned int pwren:1;
            unsigned int dacen:1;
            unsigned int __reserved5:2;
        };
    } apb1enr;

    union {
        unsigned int reg;
        struct {
            unsigned int lseon:1;
            unsigned int lserdy:1;
            unsigned int lsebyp:1;
            unsigned int __reserved0:5;
            unsigned int rtcsel:2;
            unsigned int __reserved1:5;
            unsigned int rtcen:1;
            unsigned int bdrst:1;
            unsigned int __reserved2:15;
        };
    } bdcr;

    union {
        unsigned int reg;
        struct {
            unsigned int lsion:1;
            unsigned int lsirdy:1;
            unsigned int __reserved0:22;
            unsigned int rmvf:1;
            unsigned int __reserved1:1;
            unsigned int pinrstf:1;
            unsigned int porrstf:1;
            unsigned int sftrstf:1;
            unsigned int iwdgrstf:1;
            unsigned int wwdgrstf:1;
            unsigned int lpwrstf:1;
        };
    } csr;
};

#define rcc ((volatile struct stm32_rcc_registers*)DC_STM32F1XX_BASES_RCC)

#endif /* UCAPI_STM32_RCC_STM32F101XX_H_INCLUDED */
