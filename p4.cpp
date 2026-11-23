#include <stdio.h>
#include <omp.h>

int prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main() {
    int n;
    double s, e;
    scanf_s("%d", &n);

    for (int i = 1; i <= n; i++)
        if (prime(i)) printf("%d ", i);

    s = omp_get_wtime();
    for (int i = 1; i <= n; i++) prime(i);
    e = omp_get_wtime();
    printf("\nSerial: %f\n", e-s);

    s = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 1; i <= n; i++) prime(i);
    e = omp_get_wtime();
    printf("Parallel: %f\n", e-s);

    return 0;
}
/*
4. Write a OpenMP program to find the 
prime numbers from 1 to n employing 
parallel for directive. Record 
both serial and parallel 
execution times.
*/