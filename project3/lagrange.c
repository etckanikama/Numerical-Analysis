

#include <stdio.h>
#include <math.h>


double lagrange(double *px, double *py, int N, double y) 
{

    double x =0.0;
    for (int k=0; k < N; k++) {
        double l_k = 1.0;
        for (int j=0; j< N; j++) {
            if (k == j) continue;
            l_k *= (y - py[j]) / (py[k] - py[j]);
        }
        x += px[k] * l_k;
        printf("l_k[%d] = %1f\n", k, l_k);

    }
    return x;

}


int main(void) {

    double px[] = {1.0,1.3,1.6,2.0};
    double py[] = {-0.403,-0.158,0.896,1.513};
    double N = sizeof(px) / sizeof(px[0]);
    double y = 0.0;
    printf("y=%.1f,x=%.15f\n",y,lagrange(px, py, N, y));

    return 0;
}