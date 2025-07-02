cmake_minimum_required(VERSION 3.10)
project(Hangman)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic -Werror")

file(GLOB SOURCES "*.cpp")
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/secret_words.txt DESTINATION ${CMAKE_BINARY_DIR})

add_executable(Hangman
    ${SOURCES}
)

set_target_properties(Hangman PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

add_custom_target(run
    COMMAND ${CMAKE_BINARY_DIR}/bin/Hangman
    DEPENDS Hangman
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Building and running Hangman"
)
