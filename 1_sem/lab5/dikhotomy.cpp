//
// Created by Мария on 05.11.2022.
//
#include "dikhotomy.h"
[[nodiscard]] double bisectionMethod(double a, double b, const std::function<double(double)> & func, unsigned numberOfIterations) noexcept{
    unsigned k = 1;
    double c;
    /*
    while (numberOfIterations > k){
        double c = (a+b)/2;
        if (func(c) == 0) break;
        if (func(b)*func(c) < 0) a = c;
        else b = c;
        k++;

    }
     */
    for (int i = 1; i < numberOfIterations; i++){
        c = (a+b)/2;
        if (func(c) == 0) break;
        else if (func(a)*func(c) < 0) b = c;
        else a = c;

    }
    return (a+b)/2;
}

