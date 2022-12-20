#ifndef __CUBIC__SPLINE__HPP__
#define __CUBIC__SPLINE__HPP__


#include <cmath>
#include <ostream>
#include <iostream>
#include <vector>

using matrix = std::vector<std::vector<double>>;

class CubicSpline {

private:
    int size;
    std::vector<double> x, a, c, b, d;

public:

    /*** Конструктор, в котором строится кубический сплайн ***/
    explicit CubicSpline(const std::vector<double>& xArr, const std::vector<double>& yArr);

    /*** Метод, выполняющий подсчет интерполянта в точке ***/
    [[nodiscard]] double interpolate(double x0) const;
};

std::vector<double> solve_three_diagonal(matrix A, std::vector<double> b);

#endif //__CUBIC__SPLINE__HPP__