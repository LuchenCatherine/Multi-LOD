cmake_minimum_required(VERSION 3.9)
project(LOD)

# set variables
set(CMAKE_BUILD_TYPE "Release")
set(CGAL_DIR "$ENV{HOME}/CGAL-5.5.2")

 message("${CGAL_DIR}")

# find packages
find_package(CGAL REQUIRED)
find_package (Eigen3 REQUIRED NO_MODULE)
find_package(Boost 1.45.0 COMPONENTS filesystem)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 


add_executable(lod_generator main.cpp lod.cpp)
target_include_directories(lod_generator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(lod_generator CGAL::CGAL)
target_link_libraries(lod_generator Eigen3::Eigen)

if (Boost_FOUND)
    target_link_libraries(lod_generator ${Boost_LIBRARIES})
endif()