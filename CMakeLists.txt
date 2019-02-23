cmake_minimum_required(VERSION 3.1)

project(Networking-TS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

find_package(Threads REQUIRED)
if(WIN32)
        find_library(WS2_32_LIBRARY ws2_32 REQUIRED)
endif()

function(set_networking dir files)
    foreach ( test ${${files}})
        add_executable(${PROJECT_NAME} "${${dir}}/${test}.cpp")
        #set_property( TARGET ${test} PROPERTY CXX_STANDARD 17 )
        if(WIN32)
            target_link_libraries(${PROJECT_NAME} ${WS2_32_LIBRARY})
        endif()
        #install(TARGETS ${test} RUNTIME DESTINATION "${NANA_INSTALL_PATH}bin")
        message("... to build:  ${${dir}}/${test}.cpp" )
    endforeach( test ${${files}})
endfunction(set_networking)

set (source_dir examples)
set (sources networking-stream networking-async networking-sync)

set_networking(source_dir sources)