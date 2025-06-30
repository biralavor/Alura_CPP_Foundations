cmake_minimum_required(VERSION 3.10)
project(GuessTheNumber)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic -Werror")

file(GLOB SOURCES "*.cpp")

add_executable(GuessTheNumber
    ${SOURCES}
)

set_target_properties(GuessTheNumber PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

add_custom_target(run
    COMMAND ${CMAKE_BINARY_DIR}/bin/GuessTheNumber
    DEPENDS GuessTheNumber
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Building and running GuessTheNumber"
)
