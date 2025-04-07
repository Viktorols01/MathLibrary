# Math Library
This project is dedicated to writing an extensive library of mathematical functions to be used in current and future projects.
Feel free to import the module as a submodule!

# Contents
- Vectors
- Matrices
- Numerical methods (e.g. GMRES, JFNK)

# Optimizations
None so far!

# Build
To build the project using CMake with generator Unix Makefiles: 
```bash
cmake -S src -I include -B build; make -C build Test
```