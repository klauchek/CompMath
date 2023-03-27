cmake_minimum_required(VERSION 3.14)

project(newt_interp)

set(CMAKE_CXX_STANDARD 20)

set(SRCS
    src/main.cpp
    lib/src/matrix.cpp
    lib/src/newt_interp.cpp
)
set (EXEC_FILE "newt_interp")

add_executable(${EXEC_FILE} ${SRCS})

target_include_directories (${EXEC_FILE} PRIVATE ${CMAKE_SOURCE_DIR}/lib/include/)