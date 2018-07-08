#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "iomisc.h"
#include "alglin.h"
#define Tol 0.000001

int LUPDecompose(double **A, int N, int *P) {

    int i, j, k, imax; 
	double maxA, *ptr, absA;

    for (i = 0; i <= N; i++)
        P[i] = i; //Unit permutation matrix, P[N] initialized with N

    for (i = 0; i < N; i++) {
        maxA = 0.0;
        imax = i;

        for (k = i; k < N; k++)
            if ((absA = fabs(A[k][i])) > maxA) { 
                maxA = absA;
                imax = k;
            }

        if (maxA < Tol) return 0; //failure, matrix is degenerate

        if (imax != i) {
            //pivoting P
            j = P[i];
            P[i] = P[imax];
            P[imax] = j;

            //pivoting rows of A
            ptr = A[i];
            A[i] = A[imax];
            A[imax] = ptr;

            //counting pivots starting from N (for determinant)
            P[N]++;
        }

        for (j = i + 1; j < N; j++) {
            A[j][i] /= A[i][i];

            for (k = i + 1; k < N; k++)
                A[j][k] -= A[j][i] * A[i][k];
        }
    }

    return 1;  //decomposition done 
}

double *LUPSolve(double **A, int *P, double *b, int N) {
	double *x  = malloc ((N) * sizeof (double));
    for (int i = 0; i < N; i++) {
        x[i] = b[P[i]];

        for (int k = 0; k < i; k++)
            x[i] -= A[i][k] * x[k];
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int k = i + 1; k < N; k++)
            x[i] -= A[i][k] * x[k];

        x[i] = x[i] / A[i][i];
    }
    return x;
}


double **matrix_mult(double **A, double **B, int m, int n, int y) {
double **C;
C = creat_matrix(m,y);
int i,j,k;
	for (i = 0; i < m; i++)
    {
        for (j = 0; j < y; j++)
        { 
		    C[i][j] = 0;
			for (k = 0; k < n; k++)
            {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }

return C;
}

double **transpose(double **A,int m, int n) {
	double **B;
	int i,j;
	B = creat_matrix(n,m);
	
for(j = 0; j < n; j++){
     for(i = 0; i < m; i++){
       B[j][i] = A[i][j];
     }
   }
	return B;
}

double **basis(double *x, double *y, int N, int M) {
	int i,j;
	double **matrix;
	matrix = creat_matrix(2*N+1,M);
	for(i=0;i< N+1;i++) {
		matrix[i] = multiply(x,i,M);
		}
	
	for(j=0;j<N;j++) {
		matrix[i+j] = multiply(y,j+1,M);
	}
		return transpose(matrix,2*N+1,M);	

}	

double *olse(double *x, double *y, double *z, int N, int M) {
	
	double **A,**B, **C, *ans;
	A = basis(x,y,N,M);
	//show_matrix(A,M,2*N+1);
	B = transpose(A,M,2*N+1);
	//show_matrix(B,2*N+1,M);
	C = matrix_mult(B,A,2*N+1,M,2*N+1);
	//show_matrix(C,2*N+1,2*N+1);
	
	double *b = malloc ((2*N+1) * sizeof (double));
	int i,j,k;
	for (i = 0; i < (2*N+1); i++)
    {
        for (j = 0; j < 1; j++)
        { 
		    b[i] = 0;
			for (k = 0; k < M; k++)
            {
                b[i]+=B[i][k]*z[k];
            }
        }
    }
	//show_vector(b,2*N+1);
	
	int *P = malloc (((2*N+1)+1) * sizeof (int));
	LUPDecompose(C,2*N+1,P);
	//show_matrix(C,2*N+1,2*N+1);
	ans = LUPSolve(C,P,b,2*N+1);
	//show_vector(ans,2*N+1);
	
	free(A);
	free(B);
	free(C);
	return ans;
}




