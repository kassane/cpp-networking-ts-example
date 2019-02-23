project(Networking-TS LANGUAGES CXX)

cmake_minimum_required(VERSION 3.1)

include_directories(include)

find_package(Threads REQUIRED)
if(WIN32)
    message( STATUS "Your OS: ${CMAKE_SYSTEM}")
    find_library(WS2_32_LIBRARY ws2_32 REQUIRED)
endif()

file( GLOB APP_SOURCES examples/*.cpp )

foreach ( files ${APP_SOURCES})
    get_filename_component( filename ${files} NAME_WE )
    add_executable(${filename} ${files})
    if(WIN32)
        target_link_libraries(${filename} ${WS2_32_LIBRARY})
    endif()
    message("... to build:  ${${dir}}/${files}" )
endforeach( files ${APP_SOURCES})
