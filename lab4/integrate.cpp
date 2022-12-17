#include "integrate.hpp"

//Реализовать квадратуры Гаусса для интегрирования на произвольном отрезке.
//Реализовать составные формулы для интегрирования на произвольном отрезке.


/*** Функция для интегрирования на одном отрезке
* a - начало отезка
* b - конец отрезка
* n - количество точек для квадратуры
* func - функция для интегрирования
***/
[[nodiscard]] double integrateOneSeg(double a, double b, unsigned n, const std::function<double(double)> & func) noexcept {
    double res = 0.0;
    std::vector<double> x(n), omega(n);
    if (n == 3) {
        x = {-sqrt(3.0 / 5), 0, sqrt(3.0 / 5)};
        omega = {5.0 / 9, 8.0 / 9, 5.0 / 9};
    }
    if (n == 4){
        x = {-sqrt(3.0 / 7 + 2.0 / 7 * sqrt(6.0 / 5)),
            -sqrt(3.0 / 7 - 2.0 / 7 * sqrt(6.0 / 5)),
            sqrt(3.0 / 7 - 2.0 / 7 * sqrt(6.0 / 5)),
            sqrt(3.0 / 7 + 2.0 / 7 * sqrt(6.0 / 5))};
        omega = {(18 - sqrt(30)) / 36,
                (18 + sqrt(30)) / 36,
                (18 + sqrt(30)) / 36,
                (18 - sqrt(30)) / 36};
    }
    if (n == 5){
        x = {(-1.0) / 3 * sqrt(5 + 2 * sqrt(10.0 / 7)),
            (-1.0) / 3 * sqrt(5 - 2 * sqrt(10.0 / 7)),
            0,
            1.0 / 3 * sqrt(5 - 2 * sqrt(10.0 / 7)),
            1.0 / 3 * sqrt(5 + 2 * sqrt(10.0 / 7))};
        omega = {double(322 - 13 * sqrt(70)) / 900,
                double(322 + 13 * sqrt(70)) / 900, 
                128.0 / 225,
                double(322 + 13 * sqrt(70)) / 900,
                double(322 - 13 * sqrt(70)) / 900};
    }

    for (int i = 0; i < n; ++i) {
        x[i] = (b + a) / 2 + (b - a) / 2 * x[i];
        res += func(x[i]) * omega[i];
    }
    res = res * (b - a) / 2;
    return res;
}

/*** Функция для интегрирования на всем отрезке
* a - начало отезка
* b - конец отрезка
* n - количество точек для квадратуры
* s - количество отрезков
* func - функция для интегрирования
***/
[[nodiscard]] double integrate(double a, double b, unsigned n, unsigned s, const std::function<double(double)> & func) noexcept{
    double res = 0.0;
    for(int i = 0; i < s; ++i)
        res += integrateOneSeg(a + ((b - a) * i) / s, a + (b - a) * (i + 1) / s, n, func);
    return res;
}