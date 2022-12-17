#ifndef __INTEGRATE__H__
#define __INTEGRATE__H__

#include <functional>
#include <vector>
#include <cmath>

[[nodiscard]] double integrateOneSeg(double a, double b, unsigned n, const std::function<double(double)> & func) noexcept;
[[nodiscard]] double integrate(double a, double b, unsigned n, unsigned s, const std::function<double(double)> & func) noexcept;

#endif //__INTEGRATE__H__