#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int rank, num = 50;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
        printf("Process 0 broadcasting number %d\n", num);

    MPI_Bcast(&num, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received number %d\n", rank, num);

    MPI_Finalize();
    return 0;
}
// mpiexec -n 4 "C:\Users\JHASHANK\source\repos\PP_1\x64\Debug\PP_1.exe"    