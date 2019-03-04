
ucapi_stm32_sources = []
ucapi_stm32_sources += 'rcc.c'

ucapi_stm32_static = static_library('ucapi_stm32', ucapi_stm32_sources,
    include_directories: ucapi_stm32_include_dirs,
    dependencies: [ucapi_dep, ucapi_cortex_m_dep]
)