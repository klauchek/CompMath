#include "../include/matrix.hpp"

namespace matrix {

void matrix_t::fill(const std::vector<double>& x, const std::vector<double>& y) {
    double elem = 0.0;
    for(int i = 0; i < rows_; ++i)
        arr_[i * cols_] = y[i];
    for(int j = 1; j < cols_; ++j) {
        for(int i = j; i < rows_; ++i) {
            std::cout << "i: " << i << "j: " << j << std::endl; 
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

elem matrix_t::max_elem(size_t col, size_t row) {
    elem max{};
    for(size_t i = row; i < rows_; ++i) {
        if(std::abs(arr_[i * cols_ + col]) > std::abs(max.value)) {
            max.value = arr_[i * cols_ + col];
            max.row = i;
        }
    }
    max.col = col;
    return max;
}


//строки
void matrix_t::swap_rows(size_t row_1, size_t row_2) {
    for(size_t col = 0; col < cols_; ++col) {
        std::swap(arr_[row_1 * cols_ + col], arr_[row_2 * cols_ + col]);
    }
}
//столбцы
void matrix_t::swap_columns(size_t col_1, size_t col_2) {
    for(size_t row = 0; row < rows_; ++row)
        std::swap(arr_[row * cols_ + col_1], arr_[row * cols_ + col_2]);
}

void matrix_t::eliminate(size_t row) {
    double coef = 0.0;
    for(size_t i = row + 1; i < rows_; ++i) {
        coef = static_cast<double>(arr_[i * cols_ + row]) / arr_[row * cols_ + row];
        for(size_t j = 0; j < cols_; ++j) {
            arr_[i * cols_ + j] -= coef * arr_[row * cols_ + j];
        }
    }
}

void matrix_t::gauss() {
    elem pivot{};
    for(size_t i = 0, j = 0; i < rows_, j < cols_ - 1; ++i, ++j) {
        pivot = max_elem(j, i);
        if(dbl_cmp(pivot.value, 0.0) && i == 0)
            return;

        if(i != pivot.row) {
            swap_rows(i, pivot.row);
            pivot.row = i;
        }

        if(!dbl_cmp(arr_[i * cols_ + i], 0.0))
            eliminate(i);
    }
}

double matrix_t::get_elem(size_t pos) {
    return arr_[pos];
}

size_t matrix_t::get_rows() { return rows_; }
size_t matrix_t::get_cols() { return cols_; }

int dbl_cmp(double first, double second) {
    if((std::abs(first - second)) < EPSILON)
        return 1;
    return 0;
}

}
