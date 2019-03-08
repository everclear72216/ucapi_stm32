subdir('include')
subdir('source')

ucapi_stm32_dep = declare_dependency(
    link_with: ucapi_stm32_lib,
    dependencies: [ devconf_dep ],
    include_directories: ucapi_stm32_include_dirs
)