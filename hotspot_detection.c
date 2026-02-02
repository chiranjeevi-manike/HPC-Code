#include <stdio.h>
#include <omp.h>

void initialization() {
    double t = omp_get_wtime();
    for (long i = 0; i < 500000000; i++);
    printf("Initialization time: %f\n", omp_get_wtime() - t);
}

void computation() {
    double t = omp_get_wtime();
    #pragma omp parallel for
    for (long i = 0; i < 1000000000; i++);
    printf("Computation time: %f\n", omp_get_wtime() - t);
}

void io_operation() {
    double t = omp_get_wtime();
    for (long i = 0; i < 200000000; i++);
    printf("I/O time: %f\n", omp_get_wtime() - t);
}

int main() {
    initialization();
    computation();
    io_operation();
    return 0;
}
