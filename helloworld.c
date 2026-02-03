#include <stdio.h>

int main() {
    #pragma omp parallel
    {
        #pragma omp task
        printf("Hello world!\n");
    }
    return 0;
}
