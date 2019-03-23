target = 'ucapi_stm32'

sources = files(
    'init.c',
    'clock.c',
    'flash.c',
    'system_init.c'
)

ucapi_stm32_lib = static_library(
    target, sources,
    include_directories: ucapi_stm32_include_dirs,
    dependencies: [ devconf_dep, ucapi_dep, ucapi_cortex_m_dep ]
)