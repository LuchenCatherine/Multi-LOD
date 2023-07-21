# Multi-LOD: Generate multiple level of detail (LOD) models
**Version:** 1.0.0

**Release date:** 19 July 2023

## Overview:

Multi-LOD project includes: 
1. a C++ library to generate multiple level of detail models using CGAL library.  
2. different resolution (0.2, 0.4, 0.6, 0.8) models for 3D reference organ models are provided.
3. a Python library for converting glb files to off (Object File Format) files, which is the underlying 3D model format for generating multi-LOD models. 

## Dependencies
For C++ libraries [1]:
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
## Model
In the model directory:

1. multi_lod_0.2: Models where the number of edges of the models drops below 20% of the initial count. 
2. multi_lod_0.4: Models where the number of edges of the models drops below 40% of the initial count. 
3. multi_lod_0.6: Models where the number of edges of the models drops below 60% of the initial count. 
4. multi_lod_0.8: Models where the number of edges of the models drops below 80% of the initial count.

## Usage
1. convert glb files of 3D models to off (Object File Format) files:
    ```bash
    cd $scripts
    python glb_parser.py input_dir_3D_model_glb output_dir_3D_model_off
    ```
2. generate different LOD models by specifiying the resolution parameter $k$,
   ```bash
   ./build/lod_generator body_path ./multi_lod_k k,
   e.g.,  ./build/lod_generator ./model/plain_v4 ./multi_lod_0.2 0.2,
   or
   chmod +x ./run.sh
   ./run.sh
   ```
note: 
   
   
