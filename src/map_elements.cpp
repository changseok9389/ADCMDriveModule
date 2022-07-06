//
// Created by 오창석 on 2022/04/06.
//

#include "map_elements.h"
#include <iostream>

local_map::local_map() {
    // default initializer
    adcm::hdmap::setFilePath(MAP_FILE_PATH);
}

void local_map::update(Eigen::Vector3d location) {
    // get current grid
    int new_grid = adcm::hdmap::requestGridID_WGS84(location.x(), location.y());
    if (new_grid == current_grid)
        return;
    else
        current_grid=new_grid;

    // if grid changed, backup loaded grid information to cache
    for(auto grid : grid_loaded)
        set_cache(grid.first, grid.second);
    grid_loaded.clear();

    // insert new grid info.
    for (int i = 0; i < 9; i++) {
        int id = new_grid + ((i % 3) - 1) * GRID_VERTICAL_OFFSET +
                 ((i / 3 - 1) * GRID_HORIZONTAL_OFFSET);
        auto query = get_cache(id);
        if(query.first){
            grid_loaded.insert(std::pair<int, grid_map>(id, query.second));
        }
        else{
            LOCAL_MAP sm_local_map;
            adcm::hdmap::requestMapDataInGrid_ID(id,sm_local_map);
            grid_loaded.insert(std::pair<int, grid_map>(id, grid_map(sm_local_map)));
        }
    }
}

std::map<int, grid_map> &local_map::get_gridMap() {
    return grid_loaded;
}

std::pair<bool, grid_map> local_map::get_cache(int grid_id){
    auto query = grid_cache.find(grid_id);
    if(query == grid_cache.end())
        return std::pair<bool, grid_map>(false, grid_map());
    else
        return std::pair<bool, grid_map>(true, query->second);
}

void local_map::set_cache(int grid_id, grid_map map){
    if(grid_cache.find(grid_id) == grid_cache.end())
        grid_cache.insert(std::pair<int,grid_map>(grid_id, map));
}

grid_map::grid_map(){
}

grid_map::grid_map(LOCAL_MAP _grid) {
    for (auto &r : _grid.vRoads) {
        roads.push_back(road(r));
    }
    id = _grid.nID;
}

std::vector<road> &grid_map::get_road() { return roads; }

road::road(ROAD &_road) {
    id = _road.nID;
    std::vector<double> x, y, z;

    for (auto &l : _road.vLanes) {
        auto ll = lane(l);
        lanes.push_back(ll);
        x.push_back(ll.x_range.first);
        x.push_back(ll.x_range.second);
        y.push_back(ll.y_range.first);
        y.push_back(ll.y_range.second);
        z.push_back(ll.z_range.first);
        z.push_back(ll.z_range.second);
    }

    for (auto &l : _road.vLines) {
        auto ll = line(l);
        lines.push_back(ll);
        x.push_back(ll.x_range.first);
        x.push_back(ll.x_range.second);
        y.push_back(ll.y_range.first);
        y.push_back(ll.y_range.second);
        z.push_back(ll.z_range.first);
        z.push_back(ll.z_range.second);
    }

    auto _x_range = std::minmax_element(x.begin(), x.end());
    auto _y_range = std::minmax_element(y.begin(), y.end());
    auto _z_range = std::minmax_element(z.begin(), z.end());
    x_range = std::make_pair(*_x_range.first, *_x_range.second);
    y_range = std::make_pair(*_y_range.first, *_y_range.second);
    z_range = std::make_pair(*_z_range.first, *_z_range.second);
}

std::vector<line> &road::get_line() { return lines; }

std::vector<lane> &road::get_lane() { return lanes; }

line::line(LINE_VTX _line) : lineseg(_line), id(_line.sInfo.nID) {}

lane::lane(LANE_VTX _lane) : polygon(_lane), id(_lane.sInfo.nID) {}

long lane::get_id() {return id;}