//
// Created by 오창석 on 2022/04/06.
//

#ifndef ADCM_MODULES_GEO_POINTS_H
#define ADCM_MODULES_GEO_POINTS_H
#include "MapStructs.h"
#include <Eigen/Core>
#include <iostream>
class geo_points {
public:
    int n_points;
    Eigen::MatrixX3d data;
    std::pair<double, double> x_range;
    std::pair<double, double> y_range;
    std::pair<double, double> z_range;

public:
    geo_points();
    geo_points(Eigen::MatrixX3d &&_data);
    geo_points(const std::vector<VERTEX_INFO> &geometry);

    const Eigen::MatrixX3d &getData() const;
};

#endif // ADCM_MODULES_GEO_POINTS_H
