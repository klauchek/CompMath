//
// Created by Мария on 05.11.2022.
//

#ifndef LABS_COMP_MATH_DIKHOTOMY_H
#define LABS_COMP_MATH_DIKHOTOMY_H
#include "functional"
#include "cmath"

//const double epsilon = std::numeric_limits<double>::min();
[[nodiscard]] double bisectionMethod(double a, double b, const std::function<double(double)> & func, unsigned numberOfIterations) noexcept;

#endif //LABS_COMP_MATH_DIKHOTOMY_H
