# Readme

Windows 8.1 x86_64, MSVS 2017, C++17
Python 3.6.6

Python and C++ easy interoperability with pybind11.
A demo application showing how-to.

// If you don't have a python distribution installed on your system you can extract the
// python36.zip and python36.dll from the python-3.6.6-embed-amd64.zip file and place them
// on the same directory as the executable.
// They will work exactly the same.

For Mixed language debugging Python + C++ launch MSVS Installer and tick: Python Development -> Python Native Development Tools (3GB installation).
Then in your solution select the arrow next to debugging (with the play button) and select "Python/Native Debugging"

