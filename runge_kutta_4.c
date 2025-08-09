#include <stdio.h>

// Define the differential equation dy/dt = f(x, y)
double f(double x, double y) {
    return x + y;
}

int main() {
    double x0 = 0.0;         // Initial value of x
    double y0 = 1.0;         // Initial value of y
    double h = 1.0 / 100.0;  // Step size
    double x = x0;
    double y = y0;

    // We want to compute y at x = 0.2
    double x_target = 0.2;

    // Runge-Kutta 4th order iteration
    while (x < x_target) {
        // Adjust step size for the last step to exactly hit x_target
        if (x + h > x_target) {
            h = x_target - x;
        }

        // Compute Runge-Kutta terms
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2.0, y + k1 / 2.0);
        double k3 = h * f(x + h / 2.0, y + k2 / 2.0);
        double k4 = h * f(x + h, y + k3);

        // Update y and x
        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        x = x + h;
    }

    printf("The value of y(%.2f) is approximately %.6f\n", x_target, y);

    return 0;
}
