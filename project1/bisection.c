
#include <stdio.h>
#include <math.h>
#define EPS (1e-10)


// 目的関数
double f(double x){
    return x*x*x + x - 1.0;
}
// 引数：関数f,範囲[a,b], 中点m = a+b/2
double bisection(double (*func)(double), double a, double b) {
    double m;
    while(fabs(a-b) > EPS) {
        m = (a+b)/2.0;
        printf("%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf,%.10lf\n", a,b,m,fabs(a-b),f(a),f(m),f(a)*f(m));
        if (func(a)*func(m) < 0.0) {
            b = m;
        }
        else {
            a = m;
        }


    }
    return (a+b)/2.0;
}

int main(void)
{
    double a = 0.0;
    double b = 1.0;
    printf("m = %.10lf\n", bisection(f, a, b));
    return 0;
}