#ifndef __MATRIX__H__
#define __MATRIX__H__

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

namespace matrix {

const double EPSILON = 1e-12;

struct elem {
    double value;
    size_t col;
    size_t row;
};
class matrix_t {
    std::vector<double> arr_{};
    size_t cols_;
    size_t rows_;

    // i - строка row
    // j - столбец col
public:
    matrix_t(size_t cols, size_t rows) : cols_(cols), rows_(rows), arr_(rows * cols) {}

    void fill(const std::vector<double>& points, const std::vector<double>& y);
    void print();
    double get_elem(size_t pos);
    size_t get_rows();
    size_t get_cols();


    std::vector<double>::iterator begin() {
        return arr_.begin();
    }
};

}

#endif//__MATRIX__H__