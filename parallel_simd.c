#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000

int main() {
    double *A = (double*)malloc(N * sizeof(double));
    double *B = (double*)malloc(N * sizeof(double));

    for (int i = 0; i < N; i++)
        A[i] = i;

    double start = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++)
        B[i] = A[i] * 2.0;
    double end = omp_get_wtime();
    printf("Parallel for time: %f\n", end - start);

    start = omp_get_wtime();
    #pragma omp parallel for simd
    for (int i = 0; i < N; i++)
        B[i] = A[i] * 2.0;
    end = omp_get_wtime();
    printf("Parallel for SIMD time: %f\n", end - start);

    free(A); free(B);
    return 0;
}
