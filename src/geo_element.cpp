//
// Created by 오창석 on 2022/04/06.
//

#include "geo_element.h"

lineseg::lineseg() {
    // default initializer
}
lineseg::lineseg(LINE_VTX _line) : geo_points(_line.vGeometry) {
    this->line_color = cv::Vec3b(0,255,0);
}

const Eigen::MatrixX3d &lineseg::getData() const { return data; }

cv::Vec3b lineseg::get_line_color() const {
    return line_color;
}

void lineseg::set_line_color(cv::Vec3b color){
    line_color = color;
}

polygon::polygon() {
    // default initializer
}
polygon::polygon(LANE_VTX _lane) : geo_points(_lane.vGeometry) {
    this->contour_color = cv::Vec3b(255,0,0);
    this->filled_color = cv::Vec3b(0,0,255);
}

const Eigen::MatrixX3d &polygon::getData() const { return data; }

cv::Vec3b polygon::get_contour_color() const {
    return contour_color;
}

void polygon::set_contour_color(cv::Vec3b color){
    contour_color = color;
}

cv::Vec3b polygon::get_filled_color() const {
    return filled_color;
}

void polygon::set_filled_color(cv::Vec3b color){
    filled_color = color;
}