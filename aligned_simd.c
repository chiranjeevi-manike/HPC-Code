#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000

int main() {
    double *unaligned = (double*)malloc(N * sizeof(double));
    double *aligned;

    posix_memalign((void**)&aligned, 64, N * sizeof(double));

    for (int i = 0; i < N; i++) {
        unaligned[i] = i;
        aligned[i] = i;
    }

    double sum = 0;
    double start = omp_get_wtime();
    #pragma omp simd
    for (int i = 0; i < N; i++)
        sum += unaligned[i];
    double end = omp_get_wtime();
    printf("Unaligned SIMD time: %f\n", end - start);

    sum = 0;
    start = omp_get_wtime();
    #pragma omp simd aligned(aligned:64)
    for (int i = 0; i < N; i++)
        sum += aligned[i];
    end = omp_get_wtime();
    printf("Aligned SIMD time: %f\n", end - start);

    free(unaligned);
    free(aligned);
    return 0;
}
