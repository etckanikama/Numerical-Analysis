// ガウスジョルダン・健全系
#include <stdio.h>
#include <math.h>

#define a(i,j)a[(i)][(j)]
#define NMAX 5
#define EPSL 1.e-8

void gaussjordan(double a[NMAX][NMAX+1]);

int main(){
    double a[5][6]={
                    {2,7,-1,5,-3,6},
                    {1,-4,2,-1,6,1},
                    {3,1,-9,-2,1,-2},
                    {10,-2,-5,8,-7,4},
                    {-4,3,12,-4,-2,-10}};

    gaussjordan(a);

    printf("\n-normal end-\n");
    return 0;
}

void gaussjordan(double a[NMAX][NMAX+1]){
    int i,j,k;
    int imx,jmx;
    double akk,aik;
    double w;
    int idx[NMAX]={0,1,2,3};
    int iw;

    // 初期方程式出力
    printf("System of Equations:\n");
    for(i=0;i<NMAX;i++){
        for(j=0;j<=NMAX;j++){
            printf(" %10.5f",a(i,j));
        } printf("\n");
    } printf("\n");
    // ガウスジョルダンループ
    for(k=0;k<NMAX;k++){
        // 完全ピボット選択
        akk = fabs(a(k,k));
        imx = jmx = k;
        for(i=k+1;i<NMAX;i++){//さらに大きいのを探す
            for(j=k;j<NMAX;j++){
                if(fabs(a(i,j))>akk){
                    akk = fabs(a(i,j));
                    imx = i;
                    jmx = j;
                }
            }
        }
        // ピボット交換
        i = imx;
        for(j=k;j<=NMAX;j++){
            w=a(k,j);a(k,j)=a(i,j);a(i,j)=w;
        }
        j = jmx;
        for(i=0;i<NMAX;i++){
            w=a(i,k);a(i,k)=a(i,j);a(i,j)=w;
        }
        iw=idx[k];idx[k]=idx[j];idx[j]=iw;
        //検査
        akk = a(k,k);
        if(fabs(akk)<EPSL) {
            printf("\nピボット<%.0eのため中止\n",EPSL);
            return;
        }
        //消去
        for(j=k;j<=NMAX;j++){
            a(k,j) /= akk;
        }
        for(i=0;i<NMAX;i++){
            if(i==k) continue;
                aik = a(i,k);
            for(j=k;j<=NMAX;j++){
                a(i,j) -= aik*a(k,j);
            }
        }
        printf("pivot:a(%d,%d)\n",k,k);
        // for(j=0;j<NMAX;j++){
        //     printf(" %10d",idx[j]);
        // } printf("\n");
        for(i=0;i<NMAX;i++){
            for(j=0;j<=NMAX;j++){
                printf(" %10.5f",a(i,j));
            } printf("\n");
        } printf("\n");
    }
return;
}