subdir('include')
subdir('source')
subdir('link')

ucapi_stm32_dep = declare_dependency(
    link_with: ucapi_stm32_lib,
    include_directories: ucapi_stm32_include_dirs,
    dependencies: [ devconf_dep, ucapi_stm32_link_dep ]
)
