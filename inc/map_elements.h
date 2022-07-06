//
// Created by 오창석 on 2022/04/06.
//

#ifndef ADCM_MODULES_MAP_ELEMENTS_H
#define ADCM_MODULES_MAP_ELEMENTS_H
#include "geo_element.h"
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include "MDAL.h"


#define MAP_FILE_PATH "/home/changseok/Desktop/testrun/rasterization_utils/map_binary"
#define GRID_VERTICAL_OFFSET 1
#define GRID_HORIZONTAL_OFFSET 2424

class grid_map;
class road;
class line;
class lane;

class local_map {
private:
    int current_grid;
    std::map<int, grid_map> grid_loaded;
    std::map<int, grid_map> grid_cache;

public:
    local_map();
    /*
     * input : WGS84 localization coordinate in EIGEN vector 3d form
     * process : calculate current map grid and rank1 near grids
     * output : loaded road elements of current and rank1 near grids
     */
    void update(Eigen::Vector3d location);
    std::map<int, grid_map> &get_gridMap();
    std::pair<bool, grid_map> get_cache(int grid_id);
    void set_cache(int grid_id, grid_map map);
};

class grid_map {
private:
    long id;
    std::vector<road> roads;

public:
    grid_map();
    grid_map(LOCAL_MAP _grid);
    std::vector<road> &get_road();
};

class road {
private:
    long id;
    std::vector<line> lines;
    std::vector<lane> lanes;

public:
    std::pair<double, double> x_range;
    std::pair<double, double> y_range;
    std::pair<double, double> z_range;

public:
    road(ROAD &_road);
    std::vector<line> &get_line();
    std::vector<lane> &get_lane();
};

class line : public lineseg {
private:
    long id;
public:
    line(LINE_VTX _line);
};

class lane : public polygon {
private:
    long id;
public:
    lane(LANE_VTX _lane);
    long get_id();
};

#endif // ADCM_MODULES_MAP_ELEMENTS_H
