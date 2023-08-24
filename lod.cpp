#include "lod.h"

// load non-manifold
void load_non_manifold_mesh(std::string file_path, Surface_mesh &mesh)
{
  std::ifstream input(file_path);
  std::vector<Point_3> points;
  std::vector<std::vector<std::size_t> > polygons;

  if (!CGAL::IO::read_polygon_soup(file_path, points, polygons) || points.empty())
  {
    std::cerr << "Cannot open file " << std::endl;
    return;
  }

  CGAL::Polygon_mesh_processing::orient_polygon_soup(points, polygons);
  CGAL::Polygon_mesh_processing::polygon_soup_to_polygon_mesh(points, polygons, mesh);

}

void generate_lod(std::string surface_mesh_file_name, double stop_ratio, Surface_mesh &surface_mesh)
{
    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();

    load_non_manifold_mesh(surface_mesh_file_name, surface_mesh);

    if(!CGAL::is_triangle_mesh(surface_mesh))
    {
        std::cerr << "Input geometry is not triangulated." << std::endl;
        return;
    }

    SMS::Count_ratio_stop_predicate<Surface_mesh> stop(stop_ratio);
    int r = SMS::edge_collapse(surface_mesh, stop);

    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
    if (surface_mesh.number_of_edges() == 0) std::cout << surface_mesh_file_name << " edge number is 0, please fix the mesh" << std::endl; 
    // std::cout << "\nFinished!\n" << r << " edges removed.\n" << surface_mesh.number_of_edges() << " final edges.\n";
    // std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << "ms" << std::endl;
  
}

