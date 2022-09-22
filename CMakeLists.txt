cmake_minimum_required(VERSION 3.24)
project(OpenGLTest)

set(INCLUDE_DIR include)
set(SOURCES ./src/main.c ${INCLUDE_DIR}/test.c ${INCLUDE_DIR}/test.h)

add_executable(OpenGLTest ${SOURCES})
target_include_directories(OpenGLTest PRIVATE ${INCLUDE_DIR})