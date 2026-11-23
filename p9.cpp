#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int rank, n, v, r[4], a[4];
    MPI_Op op[] = {MPI_SUM, MPI_PROD, MPI_MAX, MPI_MIN};

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &n);

    v = rank + 1;

    for (int i = 0; i < 4; i++) {
        MPI_Reduce(&v, &r[i], 1, MPI_INT, op[i], 0, MPI_COMM_WORLD);
        MPI_Allreduce(&v, &a[i], 1, MPI_INT, op[i], MPI_COMM_WORLD);
    }

    printf("Process %d: Sum=%d, Prod=%d, Max=%d, Min=%d\n",
           rank, a[0], a[1], a[2], a[3]);

    if (rank == 0)
        printf("Reduce: Sum=%d, Prod=%d, Max=%d, Min=%d\n",
               r[0], r[1], r[2], r[3]);

    MPI_Finalize();
    return 0;
}
/*9. Write a MPI Program to demonstration of MPI_Reduce and
MPI_Allreduce (MPI_MAX, MPI_MIN, MPI_SUM, MPI_PROD*/