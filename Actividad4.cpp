#include <iostream>
#include <mpi.h>

int main(int argc, char **argv)
{
    int rank;                // Identificador del proceso actual
    int size;                // Número total de procesos
    int value_to_send = 100; // Valor a enviar
    int received_value;      // Valor recibido
    int source;              // Rango del proceso emisor
    MPI_Status status;       // Estado de la recepción

    // Inicializar el entorno MPI
    MPI_Init(&argc, &argv);

    // Obtener el rango del proceso actual
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Obtener el número total de procesos
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Comunicación punto a punto
    if (rank == 0)
    {
        std::cout << "Proceso " << rank << " enviando el valor " << value_to_send << " al proceso 1..." << std::endl;
        MPI_Send(&value_to_send, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    }
    else if (rank == 1)
    {
        MPI_Recv(&received_value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        source = status.MPI_SOURCE;
        std::cout << "Proceso " << rank << " recibió el valor " << received_value << " del proceso " << source << "." << std::endl;
    }

    // Finalizar el entorno MPI
    MPI_Finalize();

    return 0;
}