
cmake_minimum_required(VERSION 3.14)

project(first_der)

set(CMAKE_CXX_STANDARD 20)

option(PRINT_QUADS "PRINT_QUADS" OFF)

set(SRCS

    src/main.cpp
    lib/src/matrix.cpp
)
set (EXEC_FILE "first_der")

add_executable(${EXEC_FILE} ${SRCS})

target_include_directories (${EXEC_FILE} PRIVATE ${CMAKE_SOURCE_DIR}/lib/include/)