cmake_minimum_required(VERSION 3.10)
project(Fase1)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(motor Motor/motor.cpp)
add_executable(gerador Gerador/gerador.cpp)

add_library(
        Lib
        tinyXML/tinystr.cpp
        tinyXML/tinyxml.cpp
        tinyXML/tinyxmlerror.cpp
        tinyXML/tinyxmlparser.cpp
)

add_library(
        motorLib
        Motor/drawFunctions.cpp
        Motor/drawFunctions.hpp
)

add_library(
        geradorLib
        Gerador/calculaVertices.cpp
)

target_link_libraries(gerador geradorLib)
target_link_libraries(gerador Lib)

target_link_libraries(motor motorLib)
target_link_libraries(motor Lib)
target_link_libraries(motor ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

