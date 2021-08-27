#include "pybind11/embed.h"
//#include <Python.h>
#include <iostream>
#include <string>
#include "utils.h"


namespace py = pybind11;

void talkToMe()
{
	std::cout << "Say something dammit!" << '\n';
}

static int g_counter = 0;
void setCounter( int count )
{
	g_counter = count;
}

int getCounter()
{
	return g_counter;
}

// here we can embed Python to C++

struct Vec2
{
	float x;
	float y;
};

// The C++ - Python Bridge
// embed a python module
PYBIND11_EMBEDDED_MODULE( embedded_module, m )
{
	m.doc() = "Embedded module";

	// expose C++ stuff to the Python module
	m.def( "talkToMe", &talkToMe );
	m.def( "setCounter", &setCounter );
	m.def( "getCounter", &getCounter );

	py::class_<Vec2>( m, "Vec2" )
		.def_readwrite( "x", &Vec2::x )
		.def_readwrite( "y", &Vec2::y );
}


int main( int argc, char* argv[] )
{
	Py_SetProgramName( s2ws( argv[0] ).data() );

	char pythonHome[] = "PYTHONHOME=C:\\Program Files\\Python36";
	_putenv( pythonHome );
	py::scoped_interpreter guard{};
	Py_SetPythonHome( s2ws( pythonHome ).data() );
	
	
	py::exec( "print('hello world')" );

	py::exec( "import os" );
	py::exec( "cwd = os.getcwd()" );
	py::exec( "print( cwd )" );
	// import embedded module into the python environment
	py::exec( "import embedded_module as em" );
	py::exec( "em.talkToMe()" );
	py::exec( "em.setCounter(100)" );
	py::exec( "print( em.getCounter() )" );

	// the module you import must be in the python path
	auto sys = py::module::import( "sys" );
	py::print( sys.attr( "path" ) );

	Vec2 vec{12, 43};


	// import a py module file
	auto bestie = py::module::import( "bestie" );
	// get module path
	std::cout << bestie.attr("__file__").cast<std::string>() << '\n';
	auto callFromCppFunction = bestie.attr( "callFromCpp" );
	callFromCppFunction( vec );

	std::system( "pause" );
}
