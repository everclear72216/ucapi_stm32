project('ucapi_stm32', 'c')

ucapi_dep = dependency('ucapi', fallback: ['ucapi', 'ucapi_dep'])
ucapi_cortex_m_dep = dependency('ucapi_cortex-m', fallback: ['ucapi_cortex-m', 'ucapi_cortex_m_dep'])

subdir('include')
subdir('source')

ucapi_stm32_dep = declare_dependency(
    link_with: ucapi_stm32_static,
    include_directories: ucapi_stm32_include_dirs
)