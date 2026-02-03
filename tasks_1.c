#include <stdio.h>
#include <omp.h>

void work(int id) {
    printf("Task %d executed by thread %d\n", id, omp_get_thread_num());
}

int main() {
    #pragma omp parallel
    {
        #pragma omp single // Only one thread creates tasks
        {
            for (int i = 0; i < 5; i++) {
                #pragma omp task
                work(i);
            }
        }
    }
    return 0;
}
