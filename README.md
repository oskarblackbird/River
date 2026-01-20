# River

A high-performance Monte Carlo engine for estimating Texas Hold'em hand
equity and expected value, built with a C++ simulation core and Python
bindings.

This project is designed as a **systems-oriented probabilistic engine**,
separating performance-critical simulation logic from higher-level
experimentation and analysis.

------------------------------------------------------------------------

## Motivation

Exact enumeration of poker outcomes becomes computationally expensive
once hidden information and ranges are introduced. Monte Carlo
simulation provides a scalable and statistically sound alternative.

This engine focuses on:

-   Correct Monte Carlo methodology
-   Performance-aware C++ design
-   Clean Python interoperability
-   Extensibility toward ranges, parallelism, and game-theoretic
    analysis

------------------------------------------------------------------------

## Architecture

    Python (API, EV logic, experimentation)
            │
            │ pybind11
            ▼
    C++ Core (Monte Carlo simulation, hand evaluation)

### Design Principles

-   **C++ for hot loops**: card sampling, simulation, hand evaluation
-   **Python for orchestration**: EV calculations, analysis, CLI /
    notebooks
-   **Minimal interfaces** between layers
-   **Deterministic, testable components**

------------------------------------------------------------------------

## Features

-   Monte Carlo estimation of hand equity
-   Heads-up Texas Hold'em support
-   Efficient card sampling and deck management
-   Simple, correct baseline hand evaluator
-   Python API for rapid experimentation
-   Clean separation of concerns

------------------------------------------------------------------------

## Project Structure

    poker-mc-engine/
    ├── cpp/
    │   ├── include/
    │   ├── src/
    │   └── CMakeLists.txt
    ├── python/
    │   ├── poker_mc/
    │   └── main.py
    ├── tests/
    └── README.md

------------------------------------------------------------------------

## Installation & Build

### Requirements

-   C++17 compatible compiler
-   CMake ≥ 3.15
-   Python ≥ 3.9
-   pybind11

### Build

``` bash
mkdir build
cd build
cmake ..
make
```

------------------------------------------------------------------------

## Usage

``` python
from poker_mc import equity, ev_call

hero = [51, 50]
board = [12, 25, 38]

eq = equity(hero, board, iterations=200_000)
ev = ev_call(eq, pot=100, call=40)

print(eq, ev)
```

------------------------------------------------------------------------

## License

MIT License
