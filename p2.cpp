#include <stdio.h>
#include <omp.h>

int main() {
    int n, s[100], e[100];
    scanf_s("%d", &n);

    for (int i = 0; i < 100; i++) s[i] = -1;

#pragma omp parallel for num_threads(4) schedule(static,2)
    for (int i = 0; i < n; i++) {
        int t = omp_get_thread_num();
        if (s[t] == -1) s[t] = i;
        e[t] = i;
    }

    for (int i = 0; i < 100; i++)
        if (s[i] != -1)
            printf("Thread %d : Iterations %d -- %d\n", i, s[i], e[i]);

    return 0;
}
/*P2 Write an OpenMP program that divides the Iterations 
into chunks containing 2 iterations, respectively 
(OMP_SCHEDULE=static,2). Its input should be the 


























number of iterations, and its output should be 
which iterations of a parallelized for loop are 
executed by which thread. For example, if there 
are two threads and four iterations, the output 
might be the following: a. Thread 0 : 
Iterations 0 −− 1 . Thread 1 : 
Iterations 2 – 3*/