#include "matrix.hpp"
#include <numeric>
#include <optional>
#include <array>
#include <algorithm>
#include <iomanip>

double func(double x) {
    return std::pow(x, x);
}
double calc_der(const std::vector<double>& coefs, const std::vector<double>& points, double x) {
    double res = 0.0;
    double h = fabs(points[1] - points[0]);
    for(int i = 0; i < coefs.size(); ++i)
        res += (1/h) * coefs[i] * func(x + points[i]);
    return res;
}

std::vector<double> solve_system(matrix::matrix_t m) {
    size_t rows = m.get_rows();
    size_t cols = m.get_cols();
    std::vector<double> v{};

    for(size_t i = rows - 1, j = cols - 1; i >= 0, j >= 1; --i, --j) {
        double b_coef = m.get_elem(i * cols + (cols - 1));
        double cur_coef = m.get_elem(i * cols + (j - 1));
        double sum_to_sub = std::inner_product(v.rbegin(), v.rend(), m.begin() + (i * cols + j), 0.0);
        double x = (b_coef - sum_to_sub) / cur_coef;
        v.push_back(x);
    }
    std::reverse(v.begin(), v.end());
    return v;
}

//Требуется написать функцию, которая будет реализовывать метод неопределенных коэффициентов
//для приближенного поиска первой производной с наибольшим возможным порядком.

[[nodiscard]] std::vector<double> firstDer(const std::vector<double>& points, double x0) noexcept {
    //ctor for matrix with data_points.size() rows and data_points.size() + 1 columns -- because we need b_coef column
    matrix::matrix_t m{points.size() + 1, points.size()};
    double h = fabs(points[1] - points[0]);
    m.fill(points, x0);
    m.gauss();
    std::vector<double> answer = solve_system(m);
    std::for_each(answer.begin(), answer.end(), [h](double &n){ n *= h; });
    return answer;
}

void get_data() {
    for(double h = 0.5; h > 1e-12; h /= 2) {
        std::vector<double> data_points{-2 * h, -h, 0, h, 2 * h};
        std::vector<double> ans = firstDer(data_points, data_points[2]);
        double res = calc_der(ans, data_points, M_PI);
        //std::cout << std::setprecision(10) << res << std::endl;
        double error = 78.20148341 - res;
        std::cout << std::setprecision(10) << std::abs(error) << std::endl;
    }    
}

int main() {
    std::vector<double> data_points_1{-1, 0, 1};
    std::vector<double> data_points_2{0, 1, 2};
    std::vector<double> data_points_3{0, -1};

    size_t rows = 0;
    size_t cols = 0;

    double x_01 = data_points_1[1];
    double x_02 = data_points_2[0];
    double x_03 = data_points_3[0];

    std::vector<double> ans_1 = firstDer(data_points_1, x_01);
    std::vector<double> ans_2 = firstDer(data_points_2, x_02);
    std::vector<double> ans_3 = firstDer(data_points_3, x_03);

    for (double n : ans_1) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    for (double n : ans_2) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    for (double n : ans_3) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    //-------------------------------
    get_data();
    return 0;
}
