#pragma once

#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Surface_mesh_simplification/edge_collapse.h>
#include <CGAL/Surface_mesh_simplification/Policies/Edge_collapse/Count_ratio_stop_predicate.h>
#include <chrono>
#include <fstream>
#include <iostream>

typedef CGAL::Simple_cartesian<double>               Kernel;
typedef Kernel::Point_3                              Point_3;
typedef CGAL::Surface_mesh<Point_3>                  Surface_mesh;

namespace SMS = CGAL::Surface_mesh_simplification;

void generate_lod(std::string surface_mesh_file_name, double stop_ratio, Surface_mesh &surface_mesh);