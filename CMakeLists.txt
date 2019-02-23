cmake_minimum_required(VERSION 3.1)

project(Networking-TS LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURC_FILES
	examples/networking-stream.cpp
)

find_package(Threads REQUIRED)
if(WIN32)
    find_library(WS2_32_LIBRARY ws2_32 REQUIRED)
    add_executable(${PROJECT_NAME} ${SOURC_FILES})
    target_link_libraries(${PROJECT_NAME} ${WS2_32_LIBRARY})
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/sources
    PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR})
