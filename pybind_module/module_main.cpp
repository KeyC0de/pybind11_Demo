#include "pybind11/pybind11.h"	// must go first
#include <iostream>

// create a Python module from C++
// you can then load it up from Python and use it

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
	m.def( "greet", &greet );
#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}


int main()
{
	_wputenv( L"PYTHONHOME=C:\\Program Files\\Python36" );
}

// Now to use that Python module from Python
// 
// go to the output directory
// open a python interpreter there
// import pybind_module as pm
// pm.greet()
