#include "matrix.hpp"
#include <numeric>
#include <optional>
#include <algorithm>


// [[nodiscard]] std::vector<double> firstDer(const std::vector<double>& points) noexcept {


std::vector<double> solve_system(matrix::matrix_t &m) {
    size_t rows = m.get_rows();
    size_t cols = m.get_cols();
    std::vector<double> v{};

    for(size_t i = rows - 1, j = cols - 1; i >= 0, j >= 1; --i, --j) {
        double b_coef = m.get_elem(i * cols + (cols - 1));
        double cur_coef = m.get_elem(i * cols + (j - 1));
        std::cout << m.get_elem((i * cols + j)) << std::endl;
        double sum_to_sub = std::inner_product(v.begin(), v.end(), m.begin() + (i * cols + j), 0.0);
        std::cout << "sum " << sum_to_sub <<std::endl;
        double x = (b_coef - sum_to_sub) / cur_coef;
        v.push_back(x);
    }
    return v;
}

int main() {
    std::vector<double> data_points_1{-1, 0, 1};
    std::vector<double> data_points_2{0, 1, 2};
    std::vector<double> data_points_3{0, -1};

    size_t rows = 0;
    size_t cols = 0;

    //ctor for matrix with data_points.size() rows and data_points.size() + 1 columns
    // -- because we nees b_coef column
    double x_01 = data_points_1[1];
    double x_02 = data_points_2[0];
    double x_03 = data_points_3[0];

    matrix::matrix_t m{data_points_3.size() + 1, data_points_3.size()};
    std::cout << "num_cols" << m.get_cols() << std::endl;
    std::cout << "num_rows" << m.get_rows() << std::endl;

    m.fill(data_points_3, x_03);
    m.print();
    std::cout << std::endl;
    m.gauss();
    m.print();
    std::cout << std::endl;

    std::vector<double> answer = solve_system(m);
    std::reverse(answer.begin(), answer.end());
    for (double n : answer) {
        std::cout << n << " ";
    }


    return 0;
}
