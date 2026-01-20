#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "monte_carlo.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_poker_mc, m){
    m.def("estimate_equity",&estimate_equity,
          py::arg("hero"),
          py::arg("board"),
          py::arg("iterations")=100000);
}
