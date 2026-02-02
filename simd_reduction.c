#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000

int main() {
    double *A = (double*)malloc(N * sizeof(double));
    for (int i = 0; i < N; i++)
        A[i] = 1.0;

    double sum = 0.0;
    double start = omp_get_wtime();
    for (int i = 0; i < N; i++)
        sum += A[i];
    double end = omp_get_wtime();
    printf("Normal sum: %f, Time: %f\n", sum, end - start);

    sum = 0.0;
    start = omp_get_wtime();
    #pragma omp simd reduction(+:sum)
    for (int i = 0; i < N; i++)
        sum += A[i];
    end = omp_get_wtime();
    printf("SIMD sum: %f, Time: %f\n", sum, end - start);

    free(A);
    return 0;
}
