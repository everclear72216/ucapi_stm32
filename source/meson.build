target = 'ucapi_stm32'

sources = files(
    'clock.c',
    'flash.c'
)

ucapi_stm32_lib = static_library(
    target, sources,
    dependencies: [ devconf_dep, ucapi_dep ],
    include_directories: ucapi_stm32_include_dirs
)