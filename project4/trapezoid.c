// 台形則

#include <stdio.h>
#include <math.h>

double trapezoid(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double s = (func(a) + func(b))/ 2.0;
    
    for (int i=1; i < n; i++) {
        s += func(a+h*i);
    }
    return s*h;
}

double func(double x) {
    return 4/(1+x*x);
}

int main(void) {
    double a = 0.0;
    double b = 1.0;
    int n = 1;
    while(n<=256) {
        printf("a=%.1f b=%.1f n=%d T=%.15f\n", a,b,n, trapezoid(func, a, b, n));
        n=n*2;
    }
    return 0;

}

