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
To build the project using CMake with Ninja and run: 
```bash
cmake -S src -B build -G "Ninja"; ninja -C build ManualTest AutoTest; ./build/ManualTest.exe
```

# Testing
To test, run:
```bash
ctest --test-dir build
```