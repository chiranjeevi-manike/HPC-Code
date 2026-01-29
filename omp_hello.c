#include <omp.h>
#include <stdio.h>

int main() {
    // This part of the code is sequential, executed by the master thread.
    printf("Sequential region: Master thread is running.\n");

    // The following pragma defines a parallel region.
    // A team of threads is created to execute the block in parallel.
    #pragma omp parallel
    {
        // Each thread executes this block of code independently.
        int ID = omp_get_thread_num();
        printf("Hello World from thread = %d\n", ID);

        // All threads synchronize and join the master thread at the end of the parallel region.
    }

    // This part of the code is sequential again.
    printf("Sequential region: Back to the master thread.\n");

    return 0;
}
