cmake_minimum_required(VERSION 3.16)
project(MedusaCompiler VERSION 0.1.0 LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(medusa
    src/main.cpp
    src/lexer.cpp
)
target_include_directories(medusa PRIVATE include)
target_compile_options(medusa PRIVATE
    -fpermissive
)
