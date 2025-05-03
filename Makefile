# Makefile
CC = gcc
CFLAGS = -lm

all: mmClasicaFork mmClasicaPosix mmClasicaOpenMP

mmClasicaFork: Funciones.c mmClasicaFork.c
	$(CC) $(CFLAGS) Funciones.c mmClasicaFork.c -o mmClasicaFork

mmClasicaPosix: Funciones.c mmClasicaPosix.c
	$(CC) $(CFLAGS) Funciones.c mmClasicaPosix.c -o mmClasicaPosix -lpthread

mmClasicaOpenMP: Funciones.c mmClasicaOpenMP.c
	$(CC) $(CFLAGS) Funciones.c mmClasicaOpenMP.c -o mmClasicaOpenMP -fopenmp -O3

clean:
	rm -f mmClasicaOpenMP mmClasicaFork mmClasicaPosix
