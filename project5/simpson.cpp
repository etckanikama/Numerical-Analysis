
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;


double func(double x)
{
    return 1000*sqrt(x);
}

double simpson(double (*func)(double), double a, double b, int n)
{
    double h = (b-a) / n;
    double s = func(a) + func(b) + 4.0*func(a+h);
    for (int k = 1; k < n/2; k++) {
        s += 2.0 * func(a + 2 * k * h) + 4.0 * func(a+(2*k+1)*h);
    }



    return s * h/3.0;

}


int main(void)
{
    double a = 0.0;
    double b = 1.0;
    int n = 2;
    while(n<100){
        // printf("%f %f %d %.15f\n",a, b, n,simpson(func, a,b,n));
        for (int i=0;i < 5;i++) {
            cout << to_string(simpson(func, a,b,n))[i] << endl;
            

        }
        // cout << to_string(simpson(func, a,b,n)) << endl;

        n*=2;
    }
    // cout << to_string(n) << endl;


    return 0;
}
