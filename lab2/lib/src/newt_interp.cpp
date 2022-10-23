#include "../include/newt_interp.hpp"

namespace interpolate {

double calc_poly(const std::vector<double> &coefs, double x) {
    double res = 0.0;
    for(int i = 0; i < coefs.size(); ++i)
        res += coefs[i] * std::pow(x, i);
    return res;
}

std::vector<double> multiply(const std::vector<double> &poly1, const std::vector<double> &poly2) {
    std::vector<double> prod(poly1.size() + poly2.size() - 1);
    for (int i = 0; i < poly1.size(); ++i) {
        for (int j = 0; j < poly2.size(); ++j)
            prod[i + j] += poly1[i] * poly2[j];
    }
    return prod;
}

void print_poly(const std::vector<double> &poly) {
    for (int i = 0; i < poly.size(); i++) {
       std::cout << poly[i];
       if (i != 0)
        std::cout << "x^" << i ;
       if (i != poly.size() - 1)
        std::cout << " + ";
    }
}
[[nodiscard]] double NewtonianInterpolator::interpolate(double point) const {
    matrix::matrix_t m{x_.size(), x_.size()};
    std::vector<double> coefs;
    m.fill(x_, y_);
    m.print();
    
    std::vector<double> poly{1};
    for(int i = 0; i < x_.size(); ++i) {
        if(i != 0)
            poly = multiply(poly, {-x_[i - 1], 1});
        double poly_coef = calc_poly(poly, point);
        double func_coef = m.get_elem(i * x_.size() + i);
        std::cout << "poly coef " <<  poly_coef << " func_coef " << func_coef << std::endl;
        coefs.push_back(poly_coef * func_coef);
    }
    return std::accumulate(coefs.begin(), coefs.end(), 0.0);
}

}