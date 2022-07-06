//
// Created by 오창석 on 2022/04/12.
//

#include "raster_utils.h"
int counter = 0;
raster_utils::raster_utils(local_map _map) : map(_map) {}

void raster_utils::raster_map() {
//    map.get_gridMap();
    map_utils<road> utils;
    std::vector<road> rs;
    for(std::pair<int, grid_map> g : map.get_gridMap()){
        auto temp = g.second.get_road();
        rs.insert(rs.end(), temp.begin(), temp.end());
    }

    if (rs.size()==0) return;
    // get cubic range
    auto range = utils.cube_range(rs);

    // get 2d resolution & point offset
    cv::Size2i size(range[0].second - range[0].first + 1,
                    range[1].second - range[1].first + 1);
    point_offset = Eigen::Vector3d(range[0].first, range[1].first, range[2].first);
    size = size*MAP_PRECISION;

    // generate white img
    world_raster = cv::Mat( size, CV_8UC3, cv::Scalar( 0, 0, 0 ) );

    for (road &r : rs) {
        // line raster
        for (line &line : r.get_line()) {
            Eigen::MatrixX3d data = line.getData().array().rowwise()
                                    - point_offset.transpose().array();
            data *= MAP_PRECISION;
            for (int i = 0; i < line.data.rows()-1; i++){
                cv::line(world_raster,
                         cv::Point(data.row(i).x(), data.row(i).y()),
                         cv::Point(data.row(i+1).x(), data.row(i+1).y()),
                         line.get_line_color());
            }
        }
        // lane raster
        for (lane &lane : r.get_lane()) {
            Eigen::MatrixX3d data = lane.getData().array().rowwise()
                                    - point_offset.transpose().array();
            data *= MAP_PRECISION;
            for (int i = 0; i < lane.data.rows()-1; i++){
                cv::line(world_raster,
                         cv::Point(data.row(i).x(), data.row(i).y()),
                         cv::Point(data.row(i+1).x(), data.row(i+1).y()),
                         lane.get_contour_color());
            }
        }
    }
}

void raster_utils::raster_ego(const Eigen::Vector3d &location) {
    //get center UTM coordinate
    double out_x, out_y;
    WGS2UTM(location, out_x, out_y);

    //raster vehicle polygon
    int width = crop_raster.size().width;
    int height = crop_raster.size().height;
    int v_width = 10;
    int v_height = 20;
    cv::Rect Ego(width/2-v_width/2, height/2-v_height/2, v_width, v_height);
    cv::rectangle(crop_raster, Ego, WHITE, 1);
}

//no perception model yet...
void raster_utils::raster_agent() {}

//no routing module yet...
void raster_utils::raster_route() {
    for(auto &gridmap : map.get_gridMap()){
        for(road &rs : gridmap.second.get_road()){
            for(lane &lane : rs.get_lane()){
                if (lane.get_id()%10 == 0)
                    lane.set_contour_color(cv::Vec3b(0,0,255));
            }
        }
    }
}

void raster_utils::crop_image(const Eigen::Vector3d &location, int crop_resolution, int rotation){
    double out_x, out_y;
    WGS2UTM(location, out_x, out_y);
    Eigen::Vector3d new_location(out_x*MAP_PRECISION-point_offset[0]*MAP_PRECISION,
                                 out_y*MAP_PRECISION-point_offset[1]*MAP_PRECISION,
                                 0);
    //prepare area crop
    cv::Rect world_bounds(0,0,world_raster.cols,world_raster.rows);
    int rotate_crop_resolution = crop_resolution * sqrt(2);
    cv::Rect rotate_crop_area(new_location.x()-rotate_crop_resolution/2,
                             new_location.y()-rotate_crop_resolution/2,
                             rotate_crop_resolution,
                             rotate_crop_resolution);
    cv::Rect ROI(rotate_crop_resolution/2-crop_resolution/2,
                 rotate_crop_resolution/2-crop_resolution/2,
                  crop_resolution,
                  crop_resolution);

    //sample debug code
    cv::rectangle(world_raster, rotate_crop_area, WHITE, 1);


    //prepare rotation matrix
    cv::Mat rotation_matrix = cv::getRotationMatrix2D(
            cv::Point2f(rotate_crop_resolution/2,rotate_crop_resolution/2),
            rotation,
            1.0);
    //crop rotation area
    cv::Mat subImage = world_raster(rotate_crop_area & world_bounds);
    //rotate pixels
    crop_raster = subImage.clone();
    if (crop_raster.rows == 0 && crop_raster.cols == 0) return;
    cv::warpAffine(subImage, crop_raster, rotation_matrix, subImage.size());
    //crop ROI
    cv::Rect crop_bounds(0,0,crop_raster.cols, crop_raster.rows);
    crop_raster = crop_raster(ROI & crop_bounds);
}

void raster_utils::WGS2UTM(const Eigen::Vector3d location, double &out_x, double &out_y){
    double in_x, in_y;
    in_x = location.x();
    in_y = location.y();
    adcm::hdmap::transWGStoUTM(&out_x, &out_y, &in_x, &in_y);
    Eigen::Vector3d new_location(out_x*MAP_PRECISION-point_offset[0]*MAP_PRECISION,
                                 out_y*MAP_PRECISION-point_offset[1]*MAP_PRECISION,
                                 0);
}

void raster_utils::debug_save(){
//    if (world_raster.rows != 0 && world_raster.cols != 0)
//        cv::imwrite("/home/changseok/Desktop/testrun/rasterization_utils/test/world_raster"+ to_string(counter)+".png", world_raster);
    if (crop_raster.rows != 0 && crop_raster.cols != 0){
        cv::imshow("window1", crop_raster);
        cv::waitKey(0);
    }


//        cv::imwrite("/home/changseok/Desktop/testrun/rasterization_utils/test/crop_raster"+ to_string(counter++)+".png", crop_raster);
}

void raster_utils::update(const Eigen::Vector3d &location){
    map.update(location);
}