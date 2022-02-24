#include "pybind11/pybind11.h"	// must go first
#include <iostream>


namespace py = pybind11;

// Create a Python module from C++ code
// You can then load it up from Python and use it
// to add it as a permanent module of your Python environment check:
// https://docs.microsoft.com/en-us/visualstudio/python/working-with-c-cpp-python-in-visual-studio?view=vs-2019#make-the-dll-available-to-python

void greet()
{
	std::cout << "Hello World\n";
}

// binds c++ stuff to Python module that can then be accessible from Python interpreter
// m stands for module (the module named "pybind_module")
PYBIND11_MODULE( pybind_module, m )
{
	// name of the module
	m.doc() = "pybind_module";

	// bind the module's functions
	m.def( "greet",
		&greet );
#ifdef VERSION_INFO
	m.attr("__version__") = VERSION_INFO;
#else
	m.attr("__version__") = "dev";
#endif
}

// Now to use that Python module from Python
// 
// go to the output directory
// open a python interpreter there
// import pybind_module as pm
// pm.greet()