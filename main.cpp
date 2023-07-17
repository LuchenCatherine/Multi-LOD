#include "lod.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

int main(int argc, char** argv)
{
  const std::string body_path = argv[1];
  const std::string output_organ_AS_dir = argv[2];
  double stop_ratio = std::stod(argv[3]);

  // create a directory for the output meshes.
  if (!fs::exists(output_organ_AS_dir)) fs::create_directory(output_organ_AS_dir);
  
  // traverse all the anatomical structures
  fs::path dir(output_organ_AS_dir);
  for (fs::directory_entry& organ_path : fs::directory_iterator(body_path)) 
  {

      auto organ_name = organ_path.path().stem();
      fs::path output_organ_dir = dir / organ_name;

      for (fs::directory_entry& entry : fs::directory_iterator(organ_path)) 
      {
          std::string path = entry.path().string();
          fs::path name = entry.path().stem();

          Surface_mesh surface_mesh;
          generate_lod(path, stop_ratio, surface_mesh);

          if (!fs::exists(output_organ_dir)) fs::create_directory(output_organ_dir);
          auto output_file_path = output_organ_dir / name;

          CGAL::IO::write_polygon_mesh(output_file_path.string() + "_" + argv[3] + ".off", surface_mesh, CGAL::parameters::stream_precision(17));            

      }

  }
  
  return EXIT_SUCCESS;

}