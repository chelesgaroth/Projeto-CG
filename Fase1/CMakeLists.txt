cmake_minimum_required(VERSION 3.10)
project(Fase1)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(motor src/Motor/motor.cpp)
add_executable(gerador src/Gerador/gerador.cpp)

add_library(
        Lib
        src/tinyXML/tinystr.cpp
        src/tinyXML/tinyxml.cpp
        src/tinyXML/tinyxmlerror.cpp
        src/tinyXML/tinyxmlparser.cpp
)

add_library(
        motorLib
        src/Motor/drawFunctions.cpp
        src/Motor/drawFunctions.hpp
)

add_library(
        geradorLib
        src/Gerador/calculaVertices.cpp
)

target_link_libraries(gerador geradorLib)
target_link_libraries(gerador Lib)

target_link_libraries(motor motorLib)
target_link_libraries(motor Lib)
target_link_libraries(motor ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

