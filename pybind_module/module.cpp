#include <iostream>
#include "pybind11/pybind11.h"

// create a Python module from C++
// you can then load it up from Python and use it

void greet()
{
	std::wcout << L"Hello World";
}

// binds c++ stuff to Python module that can then be accessible from Python interpreter
PYBIND11_MODULE( pybind_module, module )
{
	// name of the module
	module.doc() = "pybind_module";

	// bind the module's functions
	module.def( "greet", &greet );
}

int main()
{
	_wputenv( L"PYTHONHOME=C:\\Program Files\\Python36" );
}