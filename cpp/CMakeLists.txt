cmake_minimum_required(VERSION 3.15)
project(poker_mc_core)

# Modern way to fetch pybind11
include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG        v2.11.1  # latest stable release
)
FetchContent_MakeAvailable(pybind11)

# Add your module
pybind11_add_module(_poker_mc
    src/bindings.cpp
    src/monte_carlo.cpp
    src/evaluator.cpp
    src/deck.cpp
)

# Place the built .pyd into the python package so `import poker_mc` finds ._poker_mc
set_target_properties(_poker_mc PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../python/poker_mc"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../python/poker_mc"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../python/poker_mc"
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_SOURCE_DIR}/../python/poker_mc"
    RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_SOURCE_DIR}/../python/poker_mc"

    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../python/poker_mc"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../python/poker_mc"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../python/poker_mc"
    LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_SOURCE_DIR}/../python/poker_mc"
    LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_SOURCE_DIR}/../python/poker_mc"

    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../python/poker_mc"
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/../python/poker_mc"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/../python/poker_mc"
)

message(STATUS "Pybind11 module will be written to: ${CMAKE_SOURCE_DIR}/../python/poker_mc")

target_include_directories(_poker_mc PRIVATE include)
