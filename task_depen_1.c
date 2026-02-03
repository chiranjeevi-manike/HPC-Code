#include <stdio.h>
int main() {
    int x = 1;
    #pragma omp parallel
    #pragma omp single {
        // Task T1: writes to x, so uses 'out'
        #pragma omp task shared(x) depend(out: x)
        x = 2;

        // Task T2: reads from x, so uses 'in'
        // T2 is dependent on T1 and will run after T1 completes
        #pragma omp task shared(x) depend(in: x)
        printf("x = %d\n", x);
    }
    return 0;
}
