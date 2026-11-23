
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <vector>
using namespace std;
void merge(int a[], int l, int m, int r)
{
    vector<int> t(r - l + 1);
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r)
        t[k++] = a[i] <= a[j] ? a[i++] : a[j++];
    while (i <= m)
        t[k++] = a[i++];
    while (j <= r)
        t[k++] = a[j++];
    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = t[k];
}
void seq(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        seq(a, l, m);
        seq(a, m + 1, r);
        merge(a, l, m, r);
    }
}
void par(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
#pragma omp parallel sections
        {
#pragma omp section
            seq(a, l, m);
#pragma omp section
            seq(a, m + 1, r);
        }
        merge(a, l, m, r);
    }
}
int main()
{
    int n = 100000;
    vector<int> a(n), b(n);
    double s, e;
    for (int i = 0; i < n; i++)
        a[i] = b[i] = rand() % 1000;
    s = omp_get_wtime();
    seq(a.data(), 0, n - 1);
    e = omp_get_wtime();
    printf("Sequential: %f seconds\n", e - s);
    s = omp_get_wtime();
    par(b.data(), 0, n - 1);
    e = omp_get_wtime();
    printf("Parallel: %f seconds\n", e - s);
    return 0;
}
//git init; git add .;git commit -m "first commit"; git branch -M main ;git remote add origin https://github.com/NYN-05/PP.git ;git push -u origin main