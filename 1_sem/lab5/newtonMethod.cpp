//
// Created by Мария on 23.11.2022.
//

#include "newtonMethod.h"
[[nodiscard]] double newtonMethod(double initial, const std::function<double(double)> & func, unsigned numberOfIterations, double h) noexcept {
    double func_deriv = (func(initial + h)- func(initial-h))/(2*h);
    double res = initial - func(initial)/func_deriv;
    for (int i = 1; i < numberOfIterations;i++){
        func_deriv = (func(res + h)- func(res-h))/(2*h);
        res = res - func(res)/func_deriv;
    }
    return res;
}