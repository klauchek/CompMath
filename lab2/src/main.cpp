#include "newt_interp.hpp"
#include "matrix.hpp"
#include <utility>
#include <array>

double func(double x) {
    return cos(x);
}

// отрезки инитерполяции: 
// #1: [0;8]; #2: [0;4]; #3: [0;2]; #4: [0;1]
// #5: [0;0.5]; #6: [0;0.25]; #7: [0;0.125]

int main() {
    std::array<std::pair<double, double>, 7> segments{std::make_pair(0.0, 8.0), std::make_pair(0.0, 4.0), std::make_pair(0.0, 2.0), 
        std::make_pair(0.0, 1.0), std::make_pair(0.0, 0.5), std::make_pair(0.0, 0.25), std::make_pair(0.0, 0.125)};

    //------ интерполяция по 3 точкам на всех приведенных выше отрезках интерполяции ----------//
    //---------------- точки на каждом отрезке будем распрелять равномерно --------------------//

    std::array<std::vector<double>, 7> x_3pts;
    std::array<std::vector<double>, 7> y_3pts;

    for(int i = 0; i < segments.size(); ++i) {
        double step = std::abs(segments[i].second - segments[i].first) / 2;
        //std::cout << "step " << step << std::endl; 
        for(int j = 0; j < 3; ++j) {
            x_3pts[i].push_back(segments[i].first + j * step);
            //std::cout << "x " << x_3pts[i][j] << std::endl;
            y_3pts[i].push_back(func(x_3pts[i][j]));
            //std::cout << "y " << y_3pts[i][j] << std::endl;
        }
    }

    //error calculation
    for(int i = 0; i < segments.size(); ++i) {
        interpolate::NewtonianInterpolator newt_int_3pts(x_3pts[i], y_3pts[i]); //интерполянт на данном отрезке
        std::vector<double> temp_err;
        double step = std::abs(segments[i].second - segments[i].first) / 999;
        double point = x_3pts[i][0];
        for(int j = 0; j < 1000; ++j) {
            point =+ step * j;
            //std::cout << "point " << point << std::endl;
            //std::cout << "cos " << func(point) << std::endl;
            //std::cout << "interp " << newt_int_3pts.interpolate(point) << std::endl;
            temp_err.push_back(std::abs(func(point) - newt_int_3pts.interpolate(point)));
        }
        auto err = std::max_element(temp_err.begin(), temp_err.end());
        std::cout << "err: " << *err << ", seg len: " << segments[i].second << std::endl;
    }
    //------ интерполяция по 5 точкам на всех приведенных выше отрезках интерполяции ----------//
    //---------------- точки на каждом отрезке будем распрелять равномерно --------------------//

    std::cout << "========================================" << std::endl;

    std::array<std::vector<double>, 7> x_5pts;
    std::array<std::vector<double>, 7> y_5pts;

    for(int i = 0; i < segments.size(); ++i) {
        double step = std::abs(segments[i].second - segments[i].first) / 4;
        //std::cout << "step " << step << std::endl; 
        for(int j = 0; j < 5; ++j) {
            x_5pts[i].push_back(segments[i].first + j * step);
            //std::cout << "x " << x_5pts[i][j] << std::endl;
            y_5pts[i].push_back(func(x_5pts[i][j]));
            //std::cout << "y " << y_5pts[i][j] << std::endl;
        }
    }

    //error calculation
    for(int i = 0; i < segments.size(); ++i) {
        interpolate::NewtonianInterpolator newt_int_5pts(x_5pts[i], y_5pts[i]); //интерполянт на данном отрезке
        std::vector<double> temp_err;
        double step = std::abs(segments[i].second - segments[i].first) / 999;
        double point = x_5pts[i][0];
        for(int j = 0; j < 1000; ++j) {
            point =+ step * j;
            //std::cout << "point " << point << std::endl;
            //std::cout << "cos " << func(point) << std::endl;
            //std::cout << "interp " << newt_int_3pts.interpolate(point) << std::endl;
            temp_err.push_back(std::abs(func(point) - newt_int_5pts.interpolate(point)));
        }
        auto err = std::max_element(temp_err.begin(), temp_err.end());
        std::cout << "err: " << *err << ", seg len: " << segments[i].second << std::endl;
    }

    //------ интерполяция по 10 точкам на всех приведенных выше отрезках интерполяции ----------//
    //---------------- точки на каждом отрезке будем распрелять равномерно --------------------//
    std::cout << "========================================" << std::endl;    

    std::array<std::vector<double>, 7> x_10pts;
    std::array<std::vector<double>, 7> y_10pts;

    for(int i = 0; i < segments.size(); ++i) {
        double step = std::abs(segments[i].second - segments[i].first) / 9;
        //std::cout << "step " << step << std::endl; 
        for(int j = 0; j < 10; ++j) {
            x_10pts[i].push_back(segments[i].first + j * step);
            //std::cout << "x " << x_10pts[i][j] << std::endl;
            y_10pts[i].push_back(func(x_10pts[i][j]));
            //std::cout << "y " << y_10pts[i][j] << std::endl;
        }
    }

    //error calculation
    for(int i = 0; i < segments.size(); ++i) {
        interpolate::NewtonianInterpolator newt_int_10pts(x_10pts[i], y_10pts[i]); //интерполянт на данном отрезке
        std::vector<double> temp_err;
        double step = std::abs(segments[i].second - segments[i].first) / 999;
        double point = x_10pts[i][0];
        for(int j = 0; j < 1000; ++j) {
            point =+ step * j;
            //std::cout << "point " << point << std::endl;
            //std::cout << "cos " << func(point) << std::endl;
            //std::cout << "interp " << newt_int_3pts.interpolate(point) << std::endl;
            temp_err.push_back(std::abs(func(point) - newt_int_10pts.interpolate(point)));
        }
        auto err = std::max_element(temp_err.begin(), temp_err.end());
        std::cout << "err: " << *err << ", seg len: " << segments[i].second << std::endl;
    }

}