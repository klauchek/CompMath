#ifndef __NEWT__INT__H__
#define __NEWT__INT__H__

#include "matrix.hpp"
#include <algorithm>
#include <numeric>
//    конструктор по полям класса
//   метод интерполяции
namespace interpolate {

class NewtonianInterpolator {
    std::vector<double> x_;
    std::vector<double> y_;

public:

    /*** Конструктор по массиву аргументов и значений функции ***/
    explicit NewtonianInterpolator(const std::vector<double>& x, const std::vector<double>& y) : x_(x), y_(y) {}

    /*** Метод, выполняющий подсчет интерполяционного полинома в точке ***/
    [[nodiscard]] double interpolate(double x) const;
     //схема горнера
};

double calc_poly(const std::vector<double> &coefs, double x);
std::vector<double> multiply(const std::vector<double> &poly1, const std::vector<double> &poly2);
void print_poly(const std::vector<double> &poly);

}


#endif //__NEWT__INT__H__
