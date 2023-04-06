//
// Created by Мария on 16.11.2022.
//

#include <iostream>
#include <cmath>
#include <vector>

#include "dikhotomy.h"
#include "simpleIteration.h"
#include "newtonMethod.h"

double pi =  3.1415926535;

double func1(double x) {
    return (pi / 4 - x + 0.1 * std::sin(x));
}
double func1_deriv(double x){
 //
}
//---------------------------
double func2(double x){
    return ((4 * x / pi) - std::tan(x));
}
double func2_deriv(double x){
    return (- 1/(std::cos(x) * std::cos(x)) + 4 / pi);
}
//-----------------------------
double func3(double x){
    return (-std::log(std::cosh(x)));
}
double func3_deriv(double x){
    return -std::sinh(2*x)/(std::cosh(2*x) + 1);
}

int main(){

    ///////////////////////////////
    ////////// BISECTION //////////
    ///////////////////////////////

    std::cout << "bisection method for first" << std::endl;
    for (unsigned i = 1; i<100; i++){
    double res = bisectionMethod(0, 10, func1, i);
    std::cout << i << " " << std::abs(res-0.861265) << std::endl;
    }
    std::cout << "bisection method for second" << std::endl;
    for (unsigned i = 1; i<100; i++){
        double res = bisectionMethod(0.5, 1, func2, i);
        std::cout << i << " " << std::abs(res - 0.78539816) << std::endl;
    }
    std::cout << "bisection method for third" << std::endl;
    for (unsigned i = 1; i<100; i++){
        double res = bisectionMethod(-1, 1, func3, i);
        std::cout << i << " " << std::abs(res) << std::endl;
    }

    ///////////////////////////////
    /////// SIMPLE ITERATION //////
    ///////////////////////////////

    std::cout << std::endl;
    std::cout << "/t/t SIMPLE ITERATION" << std::endl;
    std::cout << std::endl;

    std::cout << "simple it method for first" << std::endl;
    //here was chosen tau = 0.05 and x0 = 0.9
    //solution is x = 0.861265
    for (unsigned i = 1; i < 1000; i+=10){
        //std::cout << std::endl;
        //std::cout << "NUM OF ITERATIONS " << i << std::endl;
        double res = simpleIterationMethod(0.9, func1, 0.05, i);
        calc_error(0.9, func1, 0.05, 0.861265, i);
    }


    std::cout << "simple it method for second" << std::endl; 
    //here was chosen tau = 0.05 and x0 = 0.8
    //solution is x = 0.785398163..

    for (unsigned i = 1; i < 1000; i+=10){
        //std::cout << std::endl;
        //std::cout << "NUM OF ITERATIONS " << i << std::endl;
        double res = simpleIterationMethod(0.8, func2, 0.05, i);
        calc_error(0.8, func2, 0.05, 0.78539816, i);
    }
    variate_tau(0.8, func2, func2_deriv, 10);

    std::cout << "simple it method for third" << std::endl;
    //here was chosen tau = 0.05 and x0 = 0.1
    //solution is x = 0

    for (unsigned i = 1; i < 5000; i+=50){
        //std::cout << std::endl;
        //std::cout << "NUM OF ITERATIONS " << i << std::endl;
        double res = simpleIterationMethod(0.1, func3, 0.05, i);
        calc_error(0.1, func3, 0.05, 0, i);
    }
    variate_tau(0.1, func3, func3_deriv, 10);
    ///////////////////////////////
    /////////// NEWTON ////////////
    ///////////////////////////////
//    for (unsigned i = 1; i < 100; i++){
//        std::cout << std::endl;
//        std::cout << "NUM OF ITERATIONS " << i << std::endl;
//        double res = newtonMethod(0.8, func2, i, 0.6);
//        std::cout << "res: " << res << " solution: " << std::abs(-tan(res) + 4 * res / pi) << std::endl;
//        std::cout << std::endl;
//    }
//    std::cout <<"newton for first func" << std::endl;
//    for (unsigned i = 1; i < 100; i++){
//        std::cout << std::endl;
//        std::cout << "NUM OF ITERATIONS " << i << std::endl;
//        double res = newtonMethod(2, func1, i, 0.71);
//        std::cout << "res: " << res << " solution: " << std::abs(res-0.1*std::sin(res)-pi/4) << std::endl;
//        std::cout << std::endl;
//    }
    std::cout <<"newton for first func" << std::endl;
    for (unsigned i = 1; i < 100; i++){
        double res = newtonMethod(1, func1, i, 0.002);
        std::cout << i << " " << std::abs(res-0.861265) << std::endl;
        std::cout << std::endl;
    }
    std::cout <<"newton for second func" << std::endl;
    for (unsigned i = 1; i < 100; i++){
        double res = newtonMethod(1, func2, i, 0.002);
        std::cout << i << " " << std::abs(res - 0.78539816) << std::endl;
        std::cout << std::endl;
    }
    std::cout <<"newton for third func" << std::endl;
    for (unsigned i = 1; i < 100; i++){
        double res = newtonMethod(0.001, func3, i, 0.002);
        std::cout << i << " " << std::abs(res) << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
