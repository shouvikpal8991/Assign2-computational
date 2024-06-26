#include <stdio.h>
#include <math.h>

double f(double t, double y) {
    return y - t * t + 1;
}

double exact_solution(double t) {
    return pow(t + 1, 2) - 0.5 * exp(t);
}

int main() {
    double a = 0;
    double b = 2.0;
    double y0 = 0.5; 
    double h = 0.2; 
    double t0, t, y, w0, w, error, error_bound;
    double L, M;

    t0 = a;
    w0 = y0;

    int n = (b-a)/h;
    
    M = 1.5;
    L = 1.0;

    printf("t\tExact Solution\tEuler's Method\tError\tError Bound\n");
    
    
    printf("%.2lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n", t0, exact_solution(t0), y0, 0.0, 0.0);


    for (int i =0; i < n+1 ; i++) {

        w = w0 + h * f(t0, w0);
        t = t0 + h;

        y = exact_solution(t);
        error = fabs(exact_solution(t) - w); 

        error_bound = (h * M * (exp((t - a) * L) - 1))/(2*L); 

        printf("%.2lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n", t, exact_solution(t), w, error, error_bound);

        w0 = w;
        t0 = t;
    }

    return 0;
}