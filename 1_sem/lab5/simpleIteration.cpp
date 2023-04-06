//
// Created by Мария on 16.11.2022.
//

#include "simpleIteration.h"

/**
* Функция для решения уравнения func(x) = 0 при помощи метода простой итерации с релаксацией
* inital - начальное приближение для решения
* func - функция, корень которой нужно найти
* tau - параметр в методе простой итерации
* numberOfIterations - количество итераций, которое должен освершить метод
**/

/*
Построить:
- зависимость ошибки от числа итераций
- зависимость ошибки от параметра при фиксированом количестве итераций (например, 10)
*/

[[nodiscard]] double simpleIterationMethod(double inital, const std::function<double(double)> & func, double tau, unsigned numberOfIterations) noexcept{
    double res = inital;
    for (int i = 0; i < numberOfIterations; ++i) {
        res = tau * func(res) + res;
    }
    return res;
}


//для зависимости ошибки от числа итераций
void calc_error(double inital, const std::function<double(double)> &func, double tau, double solution, unsigned numberOfIterations) {
    double res = inital;
    for (int i = 0; i < numberOfIterations; ++i)
        res = tau * func(res) + res;
    double error = std::abs(res - solution);
    
    //std::cout << "iterations: " << numberOfIterations << " error: " 
    std::cout << numberOfIterations << " " << error << std::endl;
    //std::cout << "res: " << res << " real: " << std::abs(func(res)) << std::endl;
    //std::cout << std::endl; 
}

//для зависимости ошибки от tau
double calc_error_tau(double inital, const std::function<double(double)> &func, const std::function<double(double)> &func_deriv, double tau, unsigned numberOfIterations) {
    double res = inital;
    double error = func(res) / func_deriv(res);
    for (int i = 0; i < numberOfIterations; ++i) {
        res = tau * func(res) + res;
        error = error * (1 + tau * func_deriv(res));
    }
    return error;
}

//для зависимости ошибки от тау при фикс числе операций
void variate_tau(double inital, const std::function<double(double)> &func, const std::function<double(double)> &func_deriv, unsigned numberOfIterations) {
    double tau = 5;
    double error;
    while(tau < 12) {
        error = calc_error_tau (inital, func, func_deriv, tau, numberOfIterations);
        std::cout << tau << " " << std::abs(error) << std::endl;
        tau += 0.1;
    }
}