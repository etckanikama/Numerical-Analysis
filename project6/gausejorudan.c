// ガウスジョルダン法

#include <stdio.h>
#define N 4


void gauss_jordan(double a[N][N+1], int size);

int main(void)
{

    double coeff[][N+1] = {
                    {2,4,1,-3,0},
                    {-1,-2,2,4,10},
                    {4,2,-3,5,2},
                    {5,-4,-3,1,6},
                            };
    gauss_jordan(coeff, N);

    // show answer
    printf("Answer\n");
    for (int i=0; i < N; i++) {
        printf("x%d = %.15f\n",i, coeff[i][N]);
    }

    return 0;
}


void gauss_jordan(double a[N][N+1], int size) 
{
    // show default
    printf("Default:\n");
    for (int i=0;i<N;i++) {
        for (int j=0;j<=N;j++){
            printf("%10.5f",a[i][j]);
        }printf("\n");
    }printf("\n");

    for (int k=0; k < size; k++){
        double pivot = a[k][k];
        printf("pivot=%f\n",pivot);
        // if (pivot == 0) {
        //     a[k][]
        // }
        //　make 1 for pivot
        for (int i =k; i < size+1; i++) {
            a[k][i] *= 1.0/pivot;

        }

        // substract 1*s(=a[k][i]*s) and make 0 
        for (int j=0; j< size; j++) {
            if (j == k) continue;
            double s = a[j][k];
            for (int p=k; p < size+1; p++) {
                a[j][p] = a[j][p] - s*a[k][p];
            }
        }
        // show a[][]
        printf("Loop：k=%d\n",k);
        for (int i=0;i<N;i++) {
            for (int j=0; j<=N;j++){
                printf(" %10.5f",a[i][j]);
            }printf("\n");
        }printf("\n");

    }
    return;
}