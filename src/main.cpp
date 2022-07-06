#include "map_elements.h"
#include "raster_utils.h"
#include <iostream>
#include <chrono>
#include <fstream>

int main() {
    local_map map;
    raster_utils rasterizer(map);
    std::ifstream input( "/home/changseok/Desktop/testrun/rasterization_utils/gps_log_file.log", std::ios::binary );
    int num_of_points;
    input.read(reinterpret_cast<char*>(&num_of_points), sizeof(int));
    std::cout<<num_of_points<<std::endl;
    vector<double> lats;
    vector<double> lons;
    double lat;
    double lon;
    for (int i=0;i<num_of_points;i++){
        input.read(reinterpret_cast<char*>(&lat), sizeof(double));
        lats.push_back(lat);
    }
    for (int i=0;i<num_of_points;i++){
        input.read(reinterpret_cast<char*>(&lon), sizeof(double));
        lons.push_back(lon);
    }
    std::cout<<lats.size()<<std::endl;
    std::cout<<lons.size()<<std::endl;

    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    for (int i=0;i<num_of_points;i++){
        rasterizer.update(Eigen::Vector3d(lons[i], lats[i], 0));
        rasterizer.raster_route();
        rasterizer.raster_map();
        rasterizer.crop_image(Eigen::Vector3d(lons[i], lats[i], 0), 225, 0);
        rasterizer.raster_ego(Eigen::Vector3d(lons[i], lats[i], 0));
        rasterizer.debug_save();
    }
    
    std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
    std::cout << num_of_points << " data points process time : " << sec.count() << " seconds" << std::endl;
    return 0;
}
