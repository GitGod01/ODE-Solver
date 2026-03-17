#include <iostream>
#include <iomanip>
#include "solver.h"

int main() {
    auto f = [](double t, double y) { return -2 * y; };
    double y0 = 1.0, t0 = 0.0, t_end = 2.0, h = 0.1;

    auto euler_res = euler(f, y0, t0, t_end, h);
    auto rk2_res   = rk2(f, y0, t0, t_end, h);
    auto rk4_res   = rk4(f, y0, t0, t_end, h);

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "\n--- ODE Solver Comparison: dy/dt = -2y ---\n";
    std::cout << std::setw(8) << "t"
              << std::setw(14) << "Exact"
              << std::setw(14) << "Euler Err"
              << std::setw(14) << "RK2 Err"
              << std::setw(14) << "RK4 Err" << "\n";
    std::cout << std::string(64, '-') << "\n";

    for (int i = 0; i < (int)euler_res.size(); i++) {
        std::cout << std::setw(8)  << euler_res[i].t
                  << std::setw(14) << euler_res[i].exact
                  << std::setw(14) << euler_res[i].error
                  << std::setw(14) << rk2_res[i].error
                  << std::setw(14) << rk4_res[i].error << "\n";
    }
    return 0;
}
