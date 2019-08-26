cmake_minimum_required(VERSION 3.1)

project(Networking-TS LANGUAGES CXX)

#Define C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(networking-ts-impl/include)

find_package(Threads REQUIRED)
if(WIN32)
    find_library(WS2_32_LIBRARY ws2_32 REQUIRED)
endif()

file( GLOB APP_SOURCES examples/*.cpp )

foreach ( files ${APP_SOURCES})
    get_filename_component( filename ${files} NAME_WE )
    add_executable(${filename} ${files})
    if(WIN32)
        target_link_libraries(${filename} PRIVATE ${WS2_32_LIBRARY})
    endif()
    message("... to build:  ${${dir}}/${files}" )
endforeach( files ${APP_SOURCES})
