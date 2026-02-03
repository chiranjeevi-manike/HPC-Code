#include <stdio.h>
#include <omp.h>

int main() {
    int x = 1;

    #pragma omp parallel
    {
        #pragma omp single
        {
            // Task T1: writes to x
            #pragma omp task shared(x)
            {
                x = 2;
            }

            // Ensure T1 completes before T2 starts
            #pragma omp taskwait

            // Task T2: reads x
            #pragma omp task shared(x)
            {
                printf("x = %d\n", x);
            }
        }
    }
    return 0;
}
