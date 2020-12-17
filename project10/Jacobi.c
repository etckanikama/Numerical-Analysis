#include <stdio.h>
#include <math.h>
#define N 3
#define EPS (1e-6)
#define sqr(x) ((x)*(x))


void jacobi_eigen(double A[][N], double eigen_vecs[][N]);
void jacobi_diag(double A[][N], int p, int q, double eigen_vecs[][N]);
void print_array(double A[][N],int n);
void set_identity_mat(double mat[][N]);

int main(void) 
{
    double A[][3] = {{3,1,1},{1,2,0},{1,0,2}};
    double eigen_vecs [N][N];

    jacobi_eigen(A, eigen_vecs);
    printf("*** eigen_vlaue\n");
    print_array(A,N);
    printf("*** eigen_vecs\n");
    print_array(eigen_vecs,N);

    return 0;
}

void jacobi_eigen(double A[][N], double eigen_vecs[][N])
{
    int cont_flg = 1;
    set_identity_mat(eigen_vecs);

    while (cont_flg == 1)
    {
        cont_flg = 0;
        for (int p =0;p<N;p++){
            for (int q=p+1;q<N;q++) {
                if (fabs(A[p][q]) < EPS) continue;
                cont_flg = 1;
                jacobi_diag(A,p,q,eigen_vecs);
            }
        }
    }
    return;
    
}

void jacobi_diag(double A[][N], int p, int q, double eigen_vecs[][N])
{
    double app = A[p][p];
    double aqq = A[q][q];
    double apq = A[p][q];

    double alpha = apq;
    double beta = (app - aqq)/2.0;
    double gamma = fabs(beta)/ sqrt(sqr(alpha)+sqr(beta));
    double s = sqrt((1.0 - gamma)/2.0);
    double c = sqrt((1.0+ gamma)/2.0);

    if (alpha * beta <= 0.0) s = -s;

    for (int j=0; j < N; j++) {
        double apj = A[p][j];
        A[p][j] = c*apj + s*A[q][j];
        A[q][j] = -s * apj+c*A[q][j];
    }
    for (int j=0;j<N;j++) {
        A[j][p] = A[p][j];
        A[j][q] = A[q][j];
    }

    A[p][p] = app*sqr(c) + 2*apq*s*c + aqq*sqr(s);
    A[q][q] = app*sqr(s) - 2*apq *s*c + aqq*sqr(c);
    A[p][q] = A[q][p] =0.0;   

    for (int i=0;i<N; i++) {
        double eip =eigen_vecs[i][p];
        eigen_vecs[i][p] = c*eip+s*eigen_vecs[i][q];
        eigen_vecs[i][q]= -s*eip+c*eigen_vecs[i][q];
    }
    return ;
}

void print_array(double A[][N],int n)
{
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            printf("%f",A[i][j]);
        }
        printf("\n");
    }
}

void set_identity_mat(double mat[][N])
{
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            mat[i][j] = 0.0;
        }
        mat[i][i] = 1.0;
    }
    return;
}