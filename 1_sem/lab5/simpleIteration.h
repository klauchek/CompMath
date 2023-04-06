//
// Created by Мария on 16.11.2022.
//

#ifndef LABS_COMP_MATH_SIMPLEITERATION_H
#define LABS_COMP_MATH_SIMPLEITERATION_H
#include <functional>
#include <cmath>
#include <iostream>
#include <iomanip>


[[nodiscard]] double simpleIterationMethod(double inital, const std::function<double(double)> & func, double tau, unsigned numberOfIterations) noexcept;
void calc_error(double inital, const std::function<double(double)> &func, double tau, double solution, unsigned numberOfIterations);
double calc_error_tau(double inital, const std::function<double(double)> &func, const std::function<double(double)> &func_deriv, double tau, unsigned numberOfIterations);
void variate_tau(double inital, const std::function<double(double)> &func, const std::function<double(double)> &func_deriv, unsigned numberOfIterations);

#endif //LABS_COMP_MATH_SIMPLEITERATION_H
