#ifndef __MATRIX__H__
#define __MATRIX__H__

#include <iostream>
#include <cmath>
#include <vector>

namespace matrix {

const double EPSILON = 1e-11;

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

    void swap_rows(size_t row_1, size_t row_2);
    void swap_columns(size_t col_1, size_t col_2);
    void fill();
    void print();
    double get_elem(size_t pos);
    elem max_elem(size_t col, size_t row);
    void eliminate(size_t row);//???
    void gauss();

    size_t get_rows();
    size_t get_cols();
    std::vector<double>::iterator begin() {
        return arr_.begin();
    }
};

int dbl_cmp(double first, double second);

}

#endif//__MATRIX__H__