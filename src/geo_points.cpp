//
// Created by 오창석 on 2022/04/06.
//

#include "geo_points.h"

geo_points::geo_points() {
    // default initializer
}

geo_points::geo_points(Eigen::MatrixX3d &&_data) {
    n_points = _data.size();
    data = _data;
}

#include <iostream>
using namespace std;

geo_points::geo_points(const std::vector<VERTEX_INFO> &geometry) {
    n_points = geometry.size();
    data = Eigen::MatrixX3d(n_points, 3);

    int i = 0;
    for (const auto &point : geometry) {
        data(i, 0) = point.dx;
        data(i, 1) = point.dy;
        data(i, 2) = point.dz;
        i++;
    }
    auto min_range = data.colwise().minCoeff();
    auto max_range = data.colwise().maxCoeff();
    x_range = std::make_pair(min_range.x(), max_range.x());
    y_range = std::make_pair(min_range.y(), max_range.y());
    z_range = std::make_pair(min_range.z(), max_range.z());
}

const Eigen::MatrixX3d &geo_points::getData() const { return data; }
