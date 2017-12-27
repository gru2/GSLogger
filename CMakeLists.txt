project(GSLogger)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O2")

set(GVAL_SOURCES GSLogger.cpp)

set(HEADER_FILES GSLogger.h)

include_directories(.)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    message("Release mode.")
    add_library(GSLogger STATIC ${GVAL_SOURCES} ${HEADER_FILES})
    add_executable(GSLoggerTest GSLoggerTest.cpp ${HEADER_FILES})
    target_link_libraries(GSLoggerTest GSLogger)
endif(CMAKE_BUILD_TYPE STREQUAL "Release")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Debug mode.")
    add_library(GSLoggerd STATIC ${GVAL_SOURCES} ${HEADER_FILES})
    add_executable(GSLoggerTestd GSLoggerTest.cpp ${HEADER_FILES})
    target_link_libraries(GSLoggerTestd GSLoggerd)
endif(CMAKE_BUILD_TYPE STREQUAL "Debug") 
