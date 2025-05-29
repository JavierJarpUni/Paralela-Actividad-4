# Paralela-Actividad-4
## Comunicación Punto a Punto con MPI

Este repositorio contiene un programa en C++ que demuestra la comunicación punto a punto utilizando la biblioteca MPI (Message Passing Interface).

## Descripción

El programa inicializa el entorno MPI, determina el rango de cada proceso y el número total de procesos. Luego, implementa una comunicación unidireccional:

-   El proceso con rango 0 define un valor entero y lo envía al proceso con rango 1.
-   El proceso con rango 1 recibe el valor enviado por el proceso 0 e imprime el valor recibido junto con el rango del emisor.

Finalmente, el programa finaliza el entorno MPI.

## Objetivos de la Actividad

-   Comprender los fundamentos de la comunicación punto a punto en MPI.
-   Implementar programas que utilicen las funciones básicas de MPI: `MPI_Init`, `MPI_Send`, `MPI_Recv`, y `MPI_Finalize`.
-   Familiarizarse con la identificación de procesos mediante `MPI_Comm_rank` y la obtención del número total de procesos con `MPI_Comm_size`.
-   Desarrollar habilidades para la programación paralela utilizando el modelo de paso de mensajes.

## Contenido del Repositorio

-   `Actividad4.cpp`: El código fuente en C++ que implementa la comunicación punto a punto con MPI.
-   `README.md`: Este archivo.

## Requisitos

Para compilar y ejecutar este programa, necesitas tener instalado lo siguiente:

-   Una implementación de MPI (como Open MPI).
-   Un compilador de C++ (como g++ o clang++).

En macOS, puedes instalar Open MPI usando Homebrew:

```bash
brew install open-mpi
```

## Compilación
Para compilar el código, utiliza el wrapper del compilador de MPI para C++:

```bash
mpic++ Actividad4.cpp -o punto_a_punto
```

Esto generará un ejecutable llamado punto_a_punto.

## Ejecución
Para ejecutar el programa, utiliza el comando mpirun. Debes especificar el número de procesos a utilizar (al menos 2 para este ejemplo):

```bash
mpirun -np 2 ./punto_a_punto
```
