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
# 	  - Paralelismo con Posix Threads
#****************************************************************/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "Funciones.h"

// Declarar MM_mutex como variable global
pthread_mutex_t MM_mutex;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Ingreso de argumentos \n $./ejecutable tamMatriz numHilos\n");
        exit(0);    
    }
    int SZ = atoi(argv[1]); 
    int n_threads = atoi(argv[2]); 
    pthread_t p[n_threads];
    pthread_attr_t atrMM;

    // Inicializar las matrices globales
    inicializarMatrices(SZ);

    // Inicializar matrices con valores aleatorios
    iniMatrixPosix(SZ);
    impMatrixPosix(SZ, mA);
    impMatrixPosix(SZ, mB);

    InicioMuestra();
    
    pthread_mutex_init(&MM_mutex, NULL);
    pthread_attr_init(&atrMM);
    pthread_attr_setdetachstate(&atrMM, PTHREAD_CREATE_JOINABLE);
    for (int j = 0; j < n_threads; j++) {
        struct parametros *datos = (struct parametros *) malloc(sizeof(struct parametros)); 
        datos->idH = j;
        datos->nH  = n_threads;
        datos->N   = SZ;
        pthread_create(&p[j], &atrMM, multiMatrixPosix, (void *)datos);
    }
    for (int j = 0; j < n_threads; j++)
        pthread_join(p[j], NULL);
    FinMuestra();
    impMatrixPosix(SZ, mC);
    pthread_attr_destroy(&atrMM);
    pthread_mutex_destroy(&MM_mutex);
    liberarMatrices();
    pthread_exit(NULL);
}
