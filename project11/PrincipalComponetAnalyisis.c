/*
主成分分析
実行方法：gcc PrincipalComponetAnalyisis.c -lm 
*/
#include <stdio.h>
#include <math.h>
#define P 5
#define N 23
#define EPS (1e-5)

void calc_cov(double data[N][P], double A[P][P]);

int poweigen(double A[N][P], double *x, double *eigen_value);

int multi_mat_vec(double y[], double A[][P], double x[]);

double inner_prod(double x[], double y[]);

int normalize_vec(double y[], double x[]);

int print_vec(double x[]);




int main(void) 
{
    double lambda; //固有値
    // double A[][N] = {{1,-1},{-1,2}};
    double data[N][P] = {
        {55,84,29,33,79},
        {72,97,71,68,64},
        {79,100,74,91,76},
        {58,85,52,56,60},
        {96,98,77,92,88},
        {66,88,60,85,66},
        {73,95,81,91,63},//7
        {72,92,61,84,78},
        {81,96,70,75,67},
        {73,92,53,70,51},
        {96,97,69,64,57},//11
        {90,100,87,89,85},
        {96,98,83,75,81},
        {67,86,76,61,57},
        {78,97,87,82,82},
        {78,94,77,80,70},
        {45,96,38,43,12},
        {78,95,67,73,67},
        {80,100,83,77,67},//19
        {56,95,47,61,21},
        {88,96,70,62,51},
        {63,92,81,51,66},
        {36,84,51,16,48}
        };
    double A[P][P];
    double x[P] = {1,0,0,0,0};
    double x0,x1,x2,x3,x4;


    //初期データ
    // for (int i=0;i<N;i++){
    //     for (int j =0;j<P;j++) {
    //         printf("%f ",data[i][j]);
    //     }
    //     printf("\n");
    // }
    calc_cov(data ,A);
    printf("第一主成分:固有値｜固有ベクトル");

    poweigen(A,x, &lambda); // x:固有ベクトル, lambda:固有値　を返す
    printf("*** eigen 1 : %f | ",lambda); // 固有値
    print_vec(x); //固有値ベクトルx
    // printf("%f \n",x[0]);

    x0 = x[0];
    x1 = x[1];
    x2 = x[2];
    x3 = x[3];
    x4 = x[4];

    double B[][N] = {{x0*x0,x0*x1,x0*x2,x0*x3,x0*x4},{x1*x0,x1*x1,x1*x2,x1*x3,x1*x4},{x2*x0,x2*x1,x2*x2,x2*x3,x2*x4},{x3*x0,x3*x1,x3*x2,x3*x3,x3*x4},{x4*x0,x4*x1,x4*x2,x4*x3,x4*x4}};
    for (int i=0; i< P; i++) {
        for (int j =0; j <P; j++) {
            A[i][j] = A[i][j]-lambda * B[i][j];
            // printf("%f ",A[i][j]);
        }
    }
    printf("\n");
    printf("第二主成分の固有値|固有値ベクトル(第二主成分)\n");

    poweigen(A,x, &lambda); // x:固有ベクトル, lambda:固有値　を返す
    printf("*** eigen 2 : %f | ",lambda); // 固有値
    print_vec(x); //固有値ベクトルx

    return 0;
}

void calc_cov(double data[N][P], double A[P][P]){
    // 平均値を求める
    double mean[P] ={0};
    for (int j=0; j<P;j++) {
        for (int i=0;i<N;i++) {
            mean[j] += data[i][j];
        }
        mean[j]/=N;
        // printf("%f\n",mean[j]);
    }
    // printf("平均値：%f\n",*mean);

    // 共分散行列を求める
    for (int k=0; k<P; k++){
        for (int l=0; l < P; l++){
            A[k][l] =0.0;
            for (int i=0;i < N; i++){
                A[k][l] += (data[i][k]-mean[k]) * (data[i][l] - mean[l]);
            }
            A[k][l] /= N;
            // printf("%f ",A[k][l]);
        }
        // printf("\n");

    }
    // printf("共分散：%f\n",**A);
    return;
}


// eigen_value: 固有値を返すための変数
int poweigen(double A[][P], double *x, double *eigen_value)
{
    double y[P];
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

int multi_mat_vec(double y[], double A[][P], double x[])
{
    for (int i=0; i<P; i++) {
        y[i] = 0.0;
        for (int j=0; j < P; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

double inner_prod(double x[], double y[])
{
    double prod = 0.0;
    for (int i = 0; i < P; i++) {
        prod += x[i] * y[i];
    }
    return prod;
}

int normalize_vec(double y[], double x[])
{
    double length = sqrt(inner_prod(y,y));
    for (int i=0; i < P; i++) {
        x[i] = y[i] / length;
    }
    return 0;
}

int print_vec(double x[])
{
    for (int i=0; i < P; i++) {
        printf("%6.3f ", x[i]);
    }
    printf("\n");
    return 0;
}



