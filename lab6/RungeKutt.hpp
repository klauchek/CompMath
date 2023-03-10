#ifndef __RUNGE__KUTT__HPP
#define __RUNGE__KUTT__HPP

#include "third_party/Eigen/Core"
#include <cmath>

#include <iostream>
/*** Vec - класс вектора, удовлетворяющий аксиомам линейного пространтсва.
 * Можно использовать библиотеку Eigen, можно любой другой класс
 */
using Vec = Eigen::VectorXd;
using Mat = Eigen::MatrixXd;

/*** Тип времени. Можно использовать double, а можно свой тип
 */
using Time = double;

/*** Структура состояния ***/
struct State {
    Vec state;
    Time t;
};

/** Функция правой части дифференциального уравнения y' = f(t, y)
 *
 * @param time время t
 * @param state состояние y
 * @return правая часть f(t, y)
 */
[[nodiscard]] Vec rightPart(const Time& time, const Vec& state) noexcept {
    
    double mu = 3.8e14;
    double x = state[0];
    double y = state[1];
    double z = state[2];
    double r = std::sqrt(x * x + y * y + z * z);
    double r_sqr = r * r;
    double r_cub =  r_sqr * r;
    //std::cout << state.x << " " << state.y << std::endl;
    Vec res(6);
    res << state[3], state[4], state[5], -mu * x / r_cub, -mu * y / r_cub, -mu * z / r_cub;
    
    return res;
}

/** Таблица Бутчера **/
template <unsigned s>
struct ButcherTable {
    std::array<double, s> column;
    std::array<double, s> string;
    std::array<std::array<double, s>, s> matrix;
};

/** Функция явного метода рунге-Кутты
 *
 * @tparam s  стадийность метода
 * @param initial начальное условие
 * @param step  шаг интегрирования
 * @param iterations количество шагов, которые необходимо сделать
 * @param rightPart функция правой части дифференциального уравнения
 * @param table таблица бутчера метода
 * @return массив решений
 */

template <unsigned s>
Vec count_next_y(Vec &y, Time t, double step, const std::function<Vec(Time, Vec)>& rightPart, const ButcherTable<s>& table){

    Vec k1 = rightPart(t, y);
    Vec k2 = rightPart(t + table.column[1] * step, y + 0.5 * step * k1);
    Vec k3 = rightPart(t + table.column[2] * step, y + 0.5 * step * k2);
    Vec k4 = rightPart(t + table.column[3] * step, y + step * k3);

    y = y + step * (k1 + 2 * k2 + 2 * k3 +  k4);

    return y;
}

template <unsigned s>
[[nodiscard]] std::vector<Vec> explicitRK(
    const State& initial,
    double step,
    unsigned iterations,
    const std::function<Vec(Time, Vec)>& rightPart,
    const ButcherTable<s>& table
    ) noexcept {

    State y_init = initial;
    std::vector<Vec> res;

    Vec y = y_init.state;
    Time t = y_init.t;

    for (int i = 0; i < iterations; ++i) {
        y = count_next_y(y, t, step, rightPart, table);
        res.push_back(y);
        t += step;
    }
    return res;
}

#endif //__RUNGE__KUTT__HPP
