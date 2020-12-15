/*
11/5 
電気システム工学科66180380 平山大葵
数値解析5-シンプソン則

実行方法
gcc simpson.c -lm
./a.out

*/

#include <stdio.h>
#include <math.h>
#define EPS (1e-7)

double func(double x);
double simpson(double (*func)(double), double a, double b, double n);

int main(void) 
{
    int n=2;
    double a =0.0,b =1.0;
    double old_ans = simpson(func, a,b,n);
    printf("%d %1.5f\n",n,old_ans);

    while(1) {
        n *=2;
        double ans = simpson(func,a,b,n);
        printf("%d %1.5f\n",n,ans);
        if (fabs(old_ans-ans) < EPS*fabs(ans)){
            break;
        }
        old_ans = ans;
    }
    return 0;
}

double func(double x)
{
    return 10000 * sqrt(x);
}

double simpson(double (*func)(double), double a, double b, double n)
{
    double h = (b - a) / n;
    double s = func(a) + func(b) +4.0*func(a+h);

    for (int k =1; k< n/2; k++) {
        s += 2.0 * func(a+2*k*h) + 4.0 * func(a+ (2*k+1)*h);

    }
    return s*h/3.0;
}
