//
// Created by 오창석 on 2022/04/12.
//

#ifndef ADCM_MODULES_MAP_UTILS_H
#define ADCM_MODULES_MAP_UTILS_H
#include "map_elements.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template <typename T> class map_utils {
public:
    map_utils() {
        // default initializer
    }

    std::vector<std::pair<double, double>>
    cube_range(const std::vector<T> &element) {
        std::vector<double> x, y, z;
        for (const auto &e : element) {
            x.push_back(e.x_range.first);
            x.push_back(e.x_range.second);
            y.push_back(e.y_range.first);
            y.push_back(e.y_range.second);
            z.push_back(e.z_range.first);
            z.push_back(e.z_range.second);
        }

        std::vector<std::pair<double, double>> _return;
        auto temp = std::minmax_element(x.begin(), x.end());
        _return.push_back(std::make_pair(*temp.first, *temp.second));
        temp = std::minmax_element(y.begin(), y.end());
        _return.push_back(std::make_pair(*temp.first, *temp.second));
        temp = std::minmax_element(z.begin(), z.end());
        _return.push_back(std::make_pair(*temp.first, *temp.second));
        return _return;
    }
};

#endif // ADCM_MODULES_MAP_UTILS_H
