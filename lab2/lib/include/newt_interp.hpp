#ifndef __NEWT__INT__H__
#define __NEWT__INT__H__

#include "matrix.hpp"
//    конструктор по полям класса
//   метод интерполяции
namespace interpolate {

class NewtonianInterpolator {
    std::vector<double> x_;
    std::vector<double> y_;

public:

    /*** Конструктор по массиву аргументов и значений функции ***/
    explicit NewtonianInterpolator(const std::vector<double>& x, const std::vector<double>& y) : x_(x), y_(y) {}

    //std::vector<double> get_coefs();
    //double calc_poly(double x);


    /*** Метод, выполняющий подсчет интерполяционного полинома в точке ***/
//    [[nodiscard]] double interpolate(double x) const;
     //схема горнера
};
//cols rows
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

std::vector<double> get_coefs(const std::vector<double>& x, const std::vector<double>& y, double point) {
                //Формирование коэффициентов полинома
    matrix::matrix_t m{x.size(), x.size()};
    std::vector<double> coefs;
    //Первый столбец таблицы - значения в узлах, во всех последующих - разделённые разности соответствующего порядка
    m.fill(x, y);
    m.print();
    
    std::vector<double> poly{1};
    for(int i = 0; i < x.size(); ++i) {
        if(i != 0)
            poly = multiply(poly, {-x[i - 1], 1});
        double poly_coef = calc_poly(poly, point);
        double func_coef = m.get_elem(i * x.size() + i);
        std::cout << "poly coef " <<  poly_coef << " func_coef " << func_coef << std::endl;
        coefs.push_back(poly_coef * func_coef);
    }

    return coefs;
}
}


#endif //__NEWT__INT__H__
