#include <iostream>
#include <Python.h>
#include "pybind11/embed.h"

namespace py = pybind11;


int main()
{
	_wputenv( L"PYTHONHOME=C:\\Program Files\\Python36" );
	py::scoped_interpreter guard{};
	auto sys = py::module::import( "sys" );
	py::print( sys.attr( "path" ) );

	std::system( "pause" );
}