#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int rank, size, s[100], r, g[100];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
        for (int i = 0; i < size; i++) s[i] = i * 10;

    MPI_Scatter(s, 1, MPI_INT, &r, 1, MPI_INT, 0, MPI_COMM_WORLD);
    r += rank;
    MPI_Gather(&r, 1, MPI_INT, g, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
        for (int i = 0; i < size; i++)
            printf("gathered_data[%d] = %d\n", i, g[i]);

    MPI_Finalize();
    return 0;
}
/*
8. Write a MPI Program demonstration of MPI_Scatter and MPI_Gather.
*/