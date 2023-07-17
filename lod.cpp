#include "lod.h"

void generate_lod(std::string surface_mesh_file_name, double stop_ratio, Surface_mesh &surface_mesh)
{
    std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();

    std::ifstream is(surface_mesh_file_name);
    if(!is || !(is >> surface_mesh))
    {
        std::cerr << "Failed to read input mesh: " << surface_mesh_file_name << std::endl;
        return;
    }

    if(!CGAL::is_triangle_mesh(surface_mesh))
    {
        std::cerr << "Input geometry is not triangulated." << std::endl;
        return;
    }

    SMS::Count_ratio_stop_predicate<Surface_mesh> stop(stop_ratio);
    int r = SMS::edge_collapse(surface_mesh, stop);

    std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
    std::cout << "\nFinished!\n" << r << " edges removed.\n" << surface_mesh.number_of_edges() << " final edges.\n";
    std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << "ms" << std::endl;
  
}

