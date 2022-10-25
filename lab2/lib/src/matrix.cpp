#include "matrix.hpp"

namespace matrix {

void matrix_t::fill(const std::vector<double>& x, const std::vector<double>& y) {
    double elem = 0.0;
    for(int i = 0; i < rows_; ++i)
        arr_[i * cols_] = y[i];
    for(int j = 1; j < cols_; ++j) {
        for(int i = j; i < rows_; ++i) {
            arr_[i * cols_ + j] = (arr_[(j - 1) * cols_ + (j - 1)] - arr_[i * cols_ + (j - 1)]) / (x[j - 1] - x[i]);
        }
    }

}

void matrix_t::print() {
    for(int i = 0; i < rows_; ++i) {
        for(int j = 0; j < cols_; ++j)
            std::cout << " " << arr_[i * cols_ + j];
        std::cout << std::endl;
    }
}

double matrix_t::get_elem(size_t pos) { return arr_[pos]; }
size_t matrix_t::get_rows() { return rows_; }
size_t matrix_t::get_cols() { return cols_; }

int dbl_cmp(double first, double second) {
    if((std::abs(first - second)) < EPSILON)
        return 1;
    return 0;
}

}
