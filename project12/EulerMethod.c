
/*
オイラー法のプログラム
実行方法：
gcc EulerMethod.c
./a.out
*/

#include <stdio.h>
#include <math.h>

// 宣言
double func(double x, double y);
double euler(double (*func)(double, double), double x0, double y0, double xn, int n);

int main(void)
{
    // int n = 10; // ループ内で初期状態示してるから消す
    double x0 = 0.0;
    double y0 = 1.0;
    double xn = 1.0;
    // 出力する
    for (int n= 10; n<= 10000; n *=10) {
        printf("n: %d ans: y(%g) = %g\n",n,xn,euler(func,x0,y0,xn,n));
    }
    

    return 0;
}

double func(double x, double y)
{
    return y - 12*x-3;
}

double euler(double (*func)(double, double), double x0, double y0, double xn, int n)
{
    double h = (xn - x0)/n; // 刻み幅
    double x = x0;
    double y = y0;

    for (int i = 1; i <= n; i++) {
        y = y + func(x,y)*h;
        x = x0 + i*h;
        printf("%g %g\n",x,y);
    }
    return y;
}
