project(Networking-TS LANGUAGES CXX)

cmake_minimum_required(VERSION 3.1)

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

find_package(Threads REQUIRED)
if(WIN32)
        find_library(WS2_32_LIBRARY ws2_32 REQUIRED)
endif()

file( GLOB APP_SOURCES examples/*.cpp )

foreach ( test ${APP_SOURCES})
    get_filename_component( testname ${test} NAME_WE )
    add_executable(${testname} ${test})
    #set_property( TARGET ${testname} PROPERTY CXX_STANDARD 17 )
    if(WIN32)
        target_link_libraries(${testname} ${WS2_32_LIBRARY})
    endif()
        #install(TARGETS ${test} RUNTIME DESTINATION "${NANA_INSTALL_PATH}bin")
    message("... to build:  ${${dir}}/${test}" )
endforeach( test ${APP_SOURCES})