cmake_minimum_required(VERSION 3.15)
project(poker_mc_core)

find_package(pybind11 REQUIRED)

pybind11_add_module(poker_mc_core
    src/bindings.cpp
    src/monte_carlo.cpp
    src/evaluator.cpp
    src/deck.cpp
)

target_include_directories(poker_mc_core PRIVATE include)