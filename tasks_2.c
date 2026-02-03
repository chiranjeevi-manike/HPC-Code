#include <stdio.h>
#include <omp.h>

int main() {
    int a = 0, b = 0, c = 0;

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task depend(out:a)
            { a = 5; printf("Task A sets a = %d\n", a); }

            #pragma omp task depend(out:b)
            { b = 10; printf("Task B sets b = %d\n", b); }

            #pragma omp task depend(in:a, in:b) depend(out:c)
            { c = a + b; printf("Task C computes c = %d\n", c); }
        }
    }
    return 0;
}
