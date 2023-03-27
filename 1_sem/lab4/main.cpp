//После реализации функций вычислить интеграл от cos x на отрезке [0, 10]
//Построить зависимость ошибки интегрирования в зависимости от количества отрезков составной формулы для n = 3, 4 5
//График представить в логарифмическом масштабе.
#include <iostream>
#include "integrate.hpp"


double func(double x) {
    return std::cos(x);
}

int main(){
    std::vector<int> steps(100);
    std::vector<double> error_3(100);
    std::vector<double> error_4(100);
    std::vector<double> error_5(100);
    for(int i = 0; i < 100; ++i)
    {
        error_3[i] = std::abs(integrate(0, 10, 3, i, func) - std::sin(10));
        error_4[i] = std::abs(integrate(0, 10, 4, i, func) - std::sin(10));
        error_5[i] = std::abs(integrate(0, 10, 5, i, func) - std::sin(10));

    }

    for (int i = 0; i < 100; i++)
        std:: cout << i << " " << error_3[i] << std::endl;
    return 0;

}
