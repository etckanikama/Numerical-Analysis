// べき乗法
#define N 2
#define EPS (1e-5)
#include <stdio.h>
#include <math.h>

int poweigen(double A[][N], double *x, double *eigen_value);

int multi_mat_vec(double y[], double A[][N], double x[]);

double inner_prod(double x[], double y[]);

int normalize_vec(double y[], double x[]);

int print_vec(double x[]);

int main(void) 
{
    double lambda; //固有値
    double A[][N] = {{1,-1},{-1,2}};
    double x[] = {1,0};
    double x0,x1;

    // 一番目

    poweigen(A,x, &lambda); // x:固有ベクトル, lambda:固有値　を返す
    // printf("*** eigen 1 : %f | ",lambda); // 固有値
    // print_vec(x); //固有値ベクトルx

    x0 = x[0];
    x1 = x[1];
    double B[][N] = {{x0*x0,x0*x1},{x1*x0,x1*x1}};
    for (int i=0; i< N; i++) {
        for (int j =0; j <N; j++) {
            A[i][j] = A[i][j]-lambda * B[i][j];
            // printf("%f ",A[i][j]);

        }
        printf("\n");
    }
    printf("2番目の固有値|固有値ベクトル\n");

    poweigen(A,x, &lambda); // x:固有ベクトル, lambda:固有値　を返す
    printf("*** eigen 2 : %f | ",lambda); // 固有値
    print_vec(x); //固有値ベクトルx

    return 0;
}


// eigen_value: 固有値を返すための変数
int poweigen(double A[][N], double *x, double *eigen_value)
{
    double y[N];
    double l = 0.0, old_l = 1.0;

    // 収束条件
    while (fabs(l - old_l) > EPS * fabs(l)) {
        old_l = l;
        multi_mat_vec(y,A,x); // y = Ax 行列xベクトルをyに返す関数
        l = inner_prod(x,y); // l = x・y　内積計算(固有値を求めている)
        normalize_vec(y,x); // x = y / |y|
    }
    *eigen_value = l; //固有値

    return 0;
}

int multi_mat_vec(double y[], double A[][N], double x[])
{
    for (int i=0; i<N; i++) {
        y[i] = 0.0;
        for (int j=0; j < N; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

double inner_prod(double x[], double y[])
{
    double prod = 0.0;
    for (int i = 0; i < N; i++) {
        prod += x[i] * y[i];
    }
    return prod;
}

int normalize_vec(double y[], double x[])
{
    double length = sqrt(inner_prod(y,y));
    for (int i=0; i < N; i++) {
        x[i] = y[i] / length;
    }
    return 0;
}

int print_vec(double x[])
{
    for (int i=0; i < N; i++) {
        printf("%6.3f ", x[i]);
    }
    printf("\n");
    return 0;
}