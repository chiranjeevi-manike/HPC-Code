#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000

int main() {
    double *A = (double*)malloc(N * sizeof(double));
    double *B = (double*)malloc(N * sizeof(double));
    double *C = (double*)malloc(N * sizeof(double));

    for (int i = 0; i < N; i++) {
        A[i] = i * 1.0;
        B[i] = i * 2.0;
    }

    double start = omp_get_wtime();
    for (int i = 0; i < N; i++)
        C[i] = A[i] + B[i];
    double end = omp_get_wtime();
    printf("Normal loop time: %f seconds\n", end - start);

    start = omp_get_wtime();
    #pragma omp simd
    for (int i = 0; i < N; i++)
        C[i] = A[i] + B[i];
    end = omp_get_wtime();
    printf("SIMD loop time: %f seconds\n", end - start);

    free(A); free(B); free(C);
    return 0;
}
