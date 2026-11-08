#include <iostream>


double dynamics(double x, double u) {
    double xdot = -x + u;
    return xdot;
}

double rk4(double y, double u, double h, 
        double (*f)(double, double)) {
    // runge kutte 4th order explicit
    double k1 = f(y, u);
    double k2 = f(y + 0.5*h*k1, u);
    double k3 = f(y + 0.5*h*k2, u);
    double k4 = f(y + h*k3, u);

    return y + h/6.0 * (k1 + 2*k2 + 2*k3 + k4);
}


int main() {

    double h = 0.1;
    double y = 0.0;
    double t0 = 0.0;
    double tf = 10.0;
    double u;

    std::cout << "Choose control input?";
    std::cin >> u;

    while (t0 < tf) {
        y = rk4(y, u, h, dynamics);
        std::cout << y << std::endl;
        t0 += h;
    }
 
}