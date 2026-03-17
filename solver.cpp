#include "solver.h"
#include <cmath>

std::vector<DataPoint> euler(std::function<double(double,double)> f,
                              double y0, double t0, double t_end, double h) {
    std::vector<DataPoint> results;
    double t = t0, y = y0;
    while (t <= t_end) {
        double exact = exp(-2 * t);
        results.push_back({t, y, exact, std::abs(y - exact)});
        y = y + h * f(t, y);
        t += h;
    }
    return results;
}

std::vector<DataPoint> rk2(std::function<double(double,double)> f,
                            double y0, double t0, double t_end, double h) {
    std::vector<DataPoint> results;
    double t = t0, y = y0;
    while (t <= t_end) {
        double exact = exp(-2 * t);
        results.push_back({t, y, exact, std::abs(y - exact)});
        double k1 = f(t, y);
        double k2 = f(t + h/2, y + h/2 * k1);
        y = y + h * k2;
        t += h;
    }
    return results;
}

std::vector<DataPoint> rk4(std::function<double(double,double)> f,
                            double y0, double t0, double t_end, double h) {
    std::vector<DataPoint> results;
    double t = t0, y = y0;
    while (t <= t_end) {
        double exact = exp(-2 * t);
        results.push_back({t, y, exact, std::abs(y - exact)});
        double k1 = f(t, y);
        double k2 = f(t + h/2, y + h/2 * k1);
        double k3 = f(t + h/2, y + h/2 * k2);
        double k4 = f(t + h, y + h * k3);
        y = y + (h/6) * (k1 + 2*k2 + 2*k3 + k4);
        t += h;
    }
    return results;
}
