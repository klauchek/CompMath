#include "lib/include/newt_interp.hpp"
#include "lib/include/matrix.hpp"

double func(double x) {
    return std::pow(x, x);
}

int main() {
    std::vector<double> coefs;
    std::vector<double> x = {1, 2, 3, 4};
    std::vector<double> y = {1, 4, 9, 16};

    std::vector<double> x1 = {0, 1, 2, 3};
    std::vector<double> y1 = {1, 2, 9, 28};
    coefs = interpolate::get_coefs(x1, y1, 3.0);

    for(auto x: coefs) {
        std::cout << x << " ";
    }

    double res = 0.0;
    for(auto x: coefs) {
        res += x;
    }
    std::cout << "\n\nres " << res;     
    //std::vector<double> poly = interpolate::multiply(x, y);
    //interpolate::print_poly(poly);
}