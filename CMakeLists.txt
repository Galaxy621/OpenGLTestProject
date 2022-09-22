cmake_minimum_required(VERSION 3.16)
project(OpenGLTest)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

set(INCLUDE_DIR include)
set(SOURCES ./src/main.c ${INCLUDE_DIR}/test.c ${INCLUDE_DIR}/test.h)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

add_executable(OpenGLTest ${SOURCES})
target_include_directories(OpenGLTest PRIVATE ${INCLUDE_DIR} ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
target_link_libraries(OpenGLTest ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARY})