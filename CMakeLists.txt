cmake_minimum_required(VERSION 3.16)
project(OpenGLTest)

set(INCLUDE_DIR include)
set(SOURCES ./src/main.c ${INCLUDE_DIR}/test.c ${INCLUDE_DIR}/test.h)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

add_executable(OpenGLTest ${SOURCES})
target_include_directories(OpenGLTest PRIVATE ${INCLUDE_DIR})