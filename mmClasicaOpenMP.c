
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
#include <omp.h>  // Incluir cabecera de OpenMP
#include "Funciones.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("\n Use: $./clasicaOpenMP SIZE Hilos \n\n");
        exit(0);
    }
    int N = atoi(argv[1]);
    int TH = atoi(argv[2]);
    size_t *matrixA = (size_t *)calloc(N*N, sizeof(size_t));
    size_t *matrixB = (size_t *)calloc(N*N, sizeof(size_t));
    size_t *matrixC = (size_t *)calloc(N*N, sizeof(size_t));
    srand(time(NULL));
    omp_set_num_threads(TH);  // Esto pertenece aquí
    iniMatrixOpenMP(matrixA, matrixB, N);
    impMatrixOpenMP(matrixA, N);
    impMatrixOpenMP(matrixB, N);
    InicioMuestra();
    multiMatrixOpenMP(matrixA, matrixB, matrixC, N);
    FinMuestra();
    impMatrixOpenMP(matrixC, N);
    free(matrixA);
    free(matrixB);
    free(matrixC);
    return 0;
}
