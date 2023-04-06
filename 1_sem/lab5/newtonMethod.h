//
// Created by Мария on 23.11.2022.
//

#ifndef LABS_COMP_MATH_NEWTONMETHOD_H
#define LABS_COMP_MATH_NEWTONMETHOD_H
/**
* Функция для решения уравнения func(x) = 0 при помощи метода Ньютона
* inital - начальное приближение для решения
* func - функция, корень которой нужно найти
* numberOfIterations - количество итераций, которое должен освершить метод
* Производную стоит оценить численно (предложите схему не ниже 2 порядка самостоятельно)
**/
#include "functional"
[[nodiscard]] double newtonMethod(double inital, const std::function<double(double)> & func, unsigned numberOfIterations, double h) noexcept;
#endif //LABS_COMP_MATH_NEWTONMETHOD_H
