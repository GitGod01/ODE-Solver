#pragma once
#include <vector>
#include <functional>

struct DataPoint {
    double t;
    double y;
    double exact;
    double error;
};

std::vector<DataPoint> euler(std::function<double(double,double)> f, 
                              double y0, double t0, double t_end, double h);
std::vector<DataPoint> rk2(std::function<double(double,double)> f, 
                            double y0, double t0, double t_end, double h);
std::vector<DataPoint> rk4(std::function<double(double,double)> f, 
                            double y0, double t0, double t_end, double h);
