//ニュートン法
#include <stdio.h>
#include <math.h>
#define EPS (1e-10)
#define MAX_LOOP 4

double f(double x)
{
    // return exp(x) - (1.0/x);
    return x*x - 5;
}

double fdash(double x) 
{
    // return exp(x) + (1.0/(x*x));
    return 2*x;
}

double newton(double (*f)(double), double (*df)(double), double x0)
{
    double x = x0;
    double dx;
    int cnt = 0;

    do {
        dx = - f(x) / df(x);
        printf("%d\n x=%.15lf, f(x)=%.15lf, f'(x)=%.15lf, dx=%.15lf\n", cnt,x, f(x),df(x),dx);
        x = x + dx;
        cnt++;
    } while(fabs(dx/x) > EPS && cnt < MAX_LOOP);

    return x;

}

int main(void)
{
    double a= 2.0;
    printf("解答：%.15lf\n", newton(f, fdash, a));
    return 0;
}