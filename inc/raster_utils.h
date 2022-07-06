//
// Created by 오창석 on 2022/04/12.
//

#ifndef ADCM_MODULES_RASTER_UTILS_H
#define ADCM_MODULES_RASTER_UTILS_H
#include "map_elements.h"
#include "map_utils.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

#define MAP_PRECISION 5
#define WHITE cv::Vec3b(255,255,255)
#define BLACK cv::Vec3b(0,0,0)
#define RED cv::Vec3b(0,0,255)
#define GREEN cv::Vec3b(0,255,0)
#define BLUE cv::Vec3b(255,0,0)
#define GRAY50 cv::Vec3b(255/2,255/2,255/2)

class raster_utils {
private:
    local_map map;
    cv::Mat world_raster;
    cv::Mat crop_raster;
    Eigen::Vector3d point_offset;

public:
    raster_utils(local_map _map);

    // raster functions
    void raster_map(); // rasterize whole map
    void raster_ego(const Eigen::Vector3d &location);
    void raster_agent(); // rasterize Agents
    void raster_route(); // rasterize route plan
    void crop_image(const Eigen::Vector3d &location, int crop_resolution, int rotation);
    void WGS2UTM(const Eigen::Vector3d location, double &out_x, double &out_y);
    void debug_save();
    void update(const Eigen::Vector3d &location);
};

#endif // ADCM_MODULES_RASTER_UTILS_H