cmake_minimum_required(VERSION 3.10.0)
project(MedusaCompiler VERSION 0.1.0 LANGUAGES C CXX)

add_executable(MedusaCompiler AST.cpp App.cpp lexer.cpp)

