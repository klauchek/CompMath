#include "CubicSpline.hpp"

/*** Конструктор, в котором строится кубический сплайн ***/
CubicSpline::CubicSpline(const std::vector<double>& xArr, const std::vector<double>& yArr) {
    size = xArr.size();
    x = xArr;
    std::vector<double> a_tmp(size - 1), b_tmp(size - 1), c_tmp(size - 2), d_tmp(size - 1);
    std::vector<double> u_1(size - 1), u_2(size - 2), h(size - 1);

    for (int i = 1; i < size; ++i)
        h[i - 1] = x[i] - x[i - 1];

    matrix A(size - 2);
    for (int i = 0; i < size - 2; ++i)
        A[i].resize(size - 2);

    if (size > 2) {
        A[0][0] = 2;
        A[0][1] = h[1] / (h[1] + h[0]);

        for (int i = 1; i < size - 3; ++i) {
            A[i][i - 1] = h[i - 1] / (h[i] + h[i + 1]); //под диагональю
            A[i][i + 1] = h[i + 1] / (h[i] + h[i + 1]); //над диагональю
            A[i][i] = 2;
        }
        A[size - 3][size - 4] = h[size - 3] / (h[size - 3] + h[size - 2]);
        A[size - 3][size - 3] = 2;


        //построение разделенных разностей Ньютона
        // u_1 - рр 1 порядка
        // u_2 - рр 2 порядка
        u_1[0] = (yArr[1] - yArr[0]) / h[0];
        for (int i = 2; i < size; ++i) {
            u_1[i - 1] = (yArr[i] - yArr[i - 1]) / h[i - 1];
            u_2[i - 2] = (u_1[i - 1] - u_1[i - 2]) / (h[i - 2] + h[i - 1]);
        }

        std::vector<double> f(size - 2);
        for (int i = 0; i < size - 2; ++i)
            f[i] = 6 * u_2[i];
        c_tmp = solve_three_diagonal(A, f);
    }
    //условие с_N = 0
    c_tmp.push_back(0);

    b_tmp[0] = u_1[0] + (c_tmp[0] * h[0] / 3);
    d_tmp[0] = c_tmp[0] / h[0];
    for (int i = 1; i < size - 1; ++i) {
        b_tmp[i] = ((c_tmp[i] * h[i]) / 3) + ((c_tmp[i - 1] * h[i]) / 6) + u_1[i];
        d_tmp[i] = (1 / h[i]) * (c_tmp[i] - c_tmp[i - 1]); /// h[i];
    }
    if (size == 2) {
        b_tmp = {h[0], h[1]};
        d_tmp = {0,0};
        c_tmp = {0,0};
    }

    std::copy(yArr.begin() + 1, yArr.begin() + size, a_tmp.begin());

    a = a_tmp;
    c = c_tmp;
    b = b_tmp;
    d = d_tmp;
}

/*** Метод, выполняющий подсчет интерполянта в точке ***/
[[nodiscard]] double CubicSpline::interpolate(double x_0) const {
    if (size <= 2)
        return a[0] + b[0] * (x_0 - x[1]) + (c[0] / 2) * (x_0 - x[1]) * (x_0 - x[1]) + (d[0] / 6) * (x_0 - x[1]) * (x_0 - x[1]) * (x_0 - x[1]);

    if ((x_0 >= x[0]) && (x_0 <= x.back())) {
        for (int i = 0; i < size; ++i) {
            if (x[i] > x_0) {
                double arg = x_0 - x[i];
                return a[i - 1] + b[i - 1] * arg + (c[i - 1] / 2) * arg * arg + (d[i - 1] / 6) * arg * arg * arg;
            }
        }
    }
    return -1;
}

//реализация метода прогонки
std::vector<double> solve_three_diagonal(matrix A, std::vector<double> b) {
    double y;
    if (A.size() == 0 || A.size() != b.size())
        return std::vector<double>(0);
    int n = b.size();

    std::vector<double> a(n), B(n);
    y = A[0][0];
    a[0] = - A[0][1] / y;
    B[0] = b[0] / y;
    for (int i = 1; i< n - 1; ++i){
        y = A[i][i] + A[i][i - 1] * a[i - 1];
        a[i] = -A[i][i + 1] / y;
        B[i] = (b[i] - A[i][i - 1] * B[i - 1]) / y;
    }
    std::vector<double> res(n);
    res[n-1] = (b[n - 1] - A[n - 1][n - 2] * B[n - 2]) / (A[n - 1][n - 1] + A[n - 1][n - 2] * a[n - 2]);
    for (int i = n - 2; i >= 0; --i)
        res[i] = a[i] * res[i + 1] + B[i];
    return res;



}