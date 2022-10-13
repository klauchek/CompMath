#include "matrix.hpp"
#include <numeric>
#include <optional>


// [[nodiscard]] std::vector<double> firstDer(const std::vector<double>& points) noexcept {


// }

// Интерфейс не важен
// Не делайте ввод и вывод
// Просто проинтуиализируйте в main

std::vector<double> solve_system(matrix::matrix_t &m) {
    size_t rows = m.get_rows();
    size_t cols = m.get_cols();
    std::vector<double> v{};

    for(size_t i = rows - 1, j = cols - 1; i >= 0, j >= 1; --i, --j) {
        double b_coef = m.get_elem(i * cols + (cols - 1));
        double cur_coef = m.get_elem(i * cols + (j - 1));
        //вектор коэф строки
        std::cout << m.get_elem((i * cols + j)) << std::endl;
        double sum_to_sub = std::inner_product(v.begin(), v.end(), m.begin() + (i * cols + j), 0.0);
        std::cout << "sum " << sum_to_sub <<std::endl;
        double x = (b_coef - sum_to_sub) / cur_coef;
        v.push_back(x);
    }
    return v;
}

int main() {
    size_t rows = 0;
    size_t cols = 0;

    std::cin >> rows >> cols;
    matrix::matrix_t m{cols, rows};

    m.fill();
    m.print();
    std::cout << std::endl;
    m.gauss();
    m.print();
    std::cout << std::endl;

    std::vector<double> answer = solve_system(m);
    for (double n : answer) {
        std::cout << n << " ";
    }


    return 0;
}
