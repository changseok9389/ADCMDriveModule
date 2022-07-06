//
// Created by 오창석 on 2022/04/06.
//

#ifndef ADCM_MODULES_GEO_ELEMENT_H
#define ADCM_MODULES_GEO_ELEMENT_H
#include "geo_points.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

class lineseg : public geo_points {
private:
    cv::Vec3b line_color;

public:
    lineseg();
    lineseg(LINE_VTX _line);
    const Eigen::MatrixX3d &getData() const;

    cv::Vec3b get_line_color() const;
    void set_line_color(cv::Vec3b color);
};

class polygon : public geo_points {
private:
    cv::Vec3b contour_color;
    cv::Vec3b filled_color;

public:
    polygon();
    polygon(LANE_VTX _lane);
    const Eigen::MatrixX3d &getData() const;

    cv::Vec3b get_contour_color() const;
    void set_contour_color(cv::Vec3b color);
    cv::Vec3b get_filled_color() const;
    void set_filled_color(cv::Vec3b color);
};

#endif // ADCM_MODULES_GEO_ELEMENT_H
