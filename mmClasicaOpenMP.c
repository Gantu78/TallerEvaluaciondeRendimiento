/***************************************************************
#         		Pontificia Universidad Javeriana
#     Autor: J. Corredor
#     Comentarios y modificaciones: Samuel Jerónimo Gantiva Garzón
#     Fecha: Mayo 2025
#     Materia: Sistemas Operativos
#     Taller de Evaluación de Rendimiento
#     Tema: 
#     - Programación Modular en C
# 	  - Programa Multiplicación de Matrices algoritmo clásico
# 	  - Paralelismo con OpenMP
#****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>  // Incluir cabecera para el uso de OpenMP
#include "Funciones.h"

// Función principal del programa
int main(int argc, char *argv[]) {
    // Verificar que se proporcionen los argumentos requeridos (tamaño de matriz y número de hilos)
    if (argc < 3) {
        printf("\n Use: $./clasicaOpenMP SIZE Hilos \n\n");
        exit(0); // Terminar el programa si los argumentos son insuficientes
    }

    // Convertir los argumentos de entrada a enteros
    int N = atoi(argv[1]);  // Tamaño de la matriz (N x N)
    int TH = atoi(argv[2]); // Número de hilos para OpenMP

    // Reservar memoria para las matrices A, B y C
    size_t *matrixA = (size_t *)calloc(N*N, sizeof(size_t)); // Matriz A
    size_t *matrixB = (size_t *)calloc(N*N, sizeof(size_t)); // Matriz B
    size_t *matrixC = (size_t *)calloc(N*N, sizeof(size_t)); // Matriz resultado C

    // Inicializar la semilla para la generación de números aleatorios
    srand(time(NULL));

    // Configurar el número de hilos que OpenMP utilizará
    omp_set_num_threads(TH);

    // Inicializar las matrices A y B con valores generados
    iniMatrixOpenMP(matrixA, matrixB, N);

    // Imprimir las matrices A y B (solo si N es pequeño, según la lógica de impMatrixOpenMP)
    impMatrixOpenMP(matrixA, N);
    impMatrixOpenMP(matrixB, N);

    // Iniciar la medición del tiempo de ejecución
    InicioMuestra();

    // Realizar la multiplicación de matrices A y B, almacenando el resultado en C
    multiMatrixOpenMP(matrixA, matrixB, matrixC, N);

    // Finalizar la medición del tiempo e imprimir el tiempo transcurrido
    FinMuestra();

    // Imprimir la matriz resultado C (solo si N es pequeño)
    impMatrixOpenMP(matrixC, N);

    // Liberar la memoria asignada para las matrices
    free(matrixA);
    free(matrixB);
    free(matrixC);

    // Terminar el programa con éxito
    return 0;
}