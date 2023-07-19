# Multi-LOD: Generate multiple level of detail (LOD) models
**Version:** 1.0.0

**Release date:** 19 July 2023

## Overview:

Multi-LOD project includes: 
1. a C++ library to generate multiple level of detail models using CGAL library.  
2. different resolution (0.2, 0.4, 0.6, 0.8) models for 3D reference organ models are provided.
3. a Python library for converting glb files to off (Object File Format) files, which is the underlying 3D model format for generating multi-LOD models. 

## Dependencies
For C++ libraries [1] [2]:
1. CMake
    ```bash
    sudo apt-get install build-essential libssl-dev
    cd /tmp
    wget https://github.com/Kitware/CMake/releases/download/v3.20.0/cmake-3.20.0.tar.gz
    tar -zxvf cmake-3.20.0.tar.gz
    cd cmake-3.20.0
    ./bootstrap
    make
    sudo make install
    ```
2. Boost
    ```bash
    sudo apt-get update
    sudo apt-get install libboost-all-dev
    ```
3. GMP
    ```bash
    sudo apt-get install libgmp-dev
    ```
4. MPFR
    ```bash
    sudo apt-get install libmpfr-dev
    ```
3. CGAL
    ```bash
    sudo apt-get install libcgal-dev
    ```
4. Eigen3
    ```bash
    sudo apt install libeigen3-dev
    ```

For Python library [3]:
1. pygltflib
    ```bash
    pip install pygltflib
    ```
## Compilation

We use CMake to configure the program with third-party dependencies and generate the native build system by creating a CMakeLists.txt file.
```bash
mkdir build
cd build
cmake ..
make
```
