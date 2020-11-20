<h1 align="center">
	<a href="https://github.com/KeyC0de/pybind11_Demo">pybind11 demo</a>
</h1>
<hr>


Pybind11 is a lightweight header only library that exposes c++ types in Python. 8k lines entire library. 5k LOC core codebase. You can use it to extend python with C/C++ written python extensions - similar to CPython but in a much easier and up-to-date method. Or you can embed the python interpreter in C++ allowing for python scripting in a C++ application. It goes both ways it's not particularly hard and you basically get to marry the Beauty and the Beast together (and C++ is not the beauty..).

Visual Studio Setup:
1. create new project.
2. use the same platform architecture as that of your Python interpreter. eg if you have Python 64bit installed use x64
3. Download pybind11 from the github repository (linked down below)
4. Add in your project's includes the pybind `include` directory as well as your own Python distribution's `include` directory (eg `C:\Program Files\Python36\include`)
5. For libraries add the a directory to your Python distribution's `libs` folder (not the lib folder)
6. include the python3x.lib in Release configuration and python3x_d.lib in Debug configuration
7. `#include "path/to/pybind11/embed.h"` (first) and `#include "Python.h"` (second) minimally in your main file

Yes I know the initial configuration can be a bit of a pain. But that was it! Check pybinding/main.cpp for how simple it is.

This line:
```
py::scoped_interpreter guard{};
```
binds the Python interpreter.

I used Windows 8.1 x86_64, Visual Studio 2017, C++17 and Python Python 3.6.6 (with Debugging symbols) to build the project.

`pybind_module` is a static library project configured with `.pyd` target extension. `pybinding` is an application project.

Build the pybind_module project to create your very first custom python module from c++. It contains a single function called `greet()` now you can go to the output directory `x64/Debug/` where you'll find "pybind\_module.pyd" run the `python` interpreter and `import pybind_module`!

```
>>	python
>>>	import pybind_module as pm
>>>	pm.greet()
Hello World

```

Now in pybinding we can do whatever we would want from C++ using the python language. Check it out.

To take things to the next level and enable Mixed language debugging Python and C++ together we'll have to launch Visual Studio Installer (Tools -> Get Tools and Features) and tick Python Development -> "Python Native Development Tools". It's approximately a 3GB installation.

Then in your solution select the arrow next to debugging (the one with the play button) and select "Python/Native Debugging". Now you can add python file to your C++ solution make calls to them from the c++ code (like I do in my project) and place breakpoints either in C++ or Python code. It's really nice and intuitive. Hopefully you'll love it as much as I do.

I also plan to use pybind11 as a scripting language for a DirectX game. I never wanted to resort to Lua as I don't want to devote more time to learn another language (even though Lua is easy-peasy I still want to use the singularly beautiful Python).

Tip:</br>
If you don't have a python distribution installed on your system you can extract the python36.zip and python36.dll from the python-3.6.6-embed-amd64.zip file and place them on the same directory as the executable.
They will work exactly the same.


# Contribute

Please submit any bugs you find through GitHub repository 'Issues' page with details describing how to replicate the problem. If you liked it or you learned something new give it a star, clone it, laugh at it, contribute to it whatever. I appreciate all of it. Enjoy.


# License

Distributed under the GNU GPL V3 License. See "GNU GPL license.txt" for more information.


# Contact

email: *nik.lazkey@gmail.com*</br>
website: *www.keyc0de.net*


# Acknowledgements

Create a C++ extension for Python [Microsoft article](https://docs.microsoft.com/en-us/visualstudio/python/working-with-c-cpp-python-in-visual-studio?view=vs-2019).</br>
pybind11 [github](https://github.com/pybind/pybind11).

