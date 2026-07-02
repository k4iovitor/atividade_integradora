# ============================================================================
# CMakeLists.txt — Configuração de build do projeto central-alertas
# ============================================================================
# Este arquivo configura o sistema de build CMake para o projeto.
#
# Requisitos:
#   - CMake >= 3.16
#   - Compilador com suporte a C++17 (g++ 7+, clang++ 5+)
#
# Instruções de uso:
#   mkdir build && cd build
#   cmake ..
#   make
#   ./central-alertas
# ============================================================================

cmake_minimum_required(VERSION 3.16)
project(central-alertas LANGUAGES CXX)

# Define o padrão C++17 como obrigatório
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Habilita warnings rigorosos para código mais seguro
add_compile_options(-Wall -Wextra -Wpedantic)

# Em modo Debug, habilita sanitizers de memória e comportamento indefinido
# (AddressSanitizer e UndefinedBehaviorSanitizer)
if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR NOT CMAKE_BUILD_TYPE)
    add_compile_options(-fsanitize=address,undefined)
    add_link_options(-fsanitize=address,undefined)
endif()

# Define o executável e lista todos os arquivos-fonte do projeto
add_executable(central-alertas
    main.cpp
    alerta.cpp
    central.cpp
    alertas/alerta_critico.cpp
    alertas/alerta_aviso.cpp
    alertas/alerta_info.cpp
    alertas/alerta_debug.cpp
)
