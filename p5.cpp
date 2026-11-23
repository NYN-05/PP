#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[]) {
    int rank, size, num = 100;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        for (int i = 1; i < size; i++) {
            printf("Process 0 sending number %d to process %d\n", num, i);
            MPI_Send(&num, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    }
    else {
        MPI_Recv(&num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received number %d from process 0\n", rank, num);
    }

    MPI_Finalize();
    return 0;
}
//5. Write a MPI Program to demonstration of MPI_Send and MPI_Recv.