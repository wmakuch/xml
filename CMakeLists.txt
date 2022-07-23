cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 17)

project(xml)

set(XML_MAJOR_VERSION 0)
set(XML_MINOR_VERSION 0)
set(XML_PATCH_VERSION 1)
set(XML_VERSION ${XML_MAJOR_VERSION}.${XML_MINOR_VERSION}.${XML_PATCH_VERSION})

configure_file("${PROJECT_SOURCE_DIR}/version.h.in" "${PROJECT_BINARY_DIR}/version.h" ESCAPE_QUOTES @ONLY)

include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(xml ${SRC_FILES})