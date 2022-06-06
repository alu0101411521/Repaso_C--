cmake_minimum_required(VERSION 3.1)  # Mandatory

# set the project name 
project(vida_juego                # Mandatory
    VERSION 1.0
    DESCRIPTION "A simple CMake project for the Fibonacci Sum application"
    LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17) 						# Use c++14
set(CMAKE_CXX_STANDARD_REQUIRED True)

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -fsanitize=address -pedantic-errors -Wall -Wextra -DDEBUG -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O0 -fsanitize=address -pedantic-errors -Wall -Wextra -DDEBUG -ggdb")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/src)

# Adds an executable target called "vida_juego_main" to be built from the source files listed in the command invocation.
add_executable(celula_test
    test/celula_main.cc
    src/celula.cc)

add_executable(tablero_test
    test/tablero_main.cc
    src/celula.cc
    src/tablero.cc)

add_executable(juego_test
    test/juego_main.cc
    src/celula.cc
    src/tablero.cc
    src/vida_juego.cc
)