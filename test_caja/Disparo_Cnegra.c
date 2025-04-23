#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Disparo.h"

// Mock data for testing
#define FILAS 10
#define COLUMNAS 10

void inicializar_tablero(char tablero[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = '-'; // Representa agua
        }
    }
}

void colocar_barco(char tablero[FILAS][COLUMNAS], int fila, int columna) {
    tablero[fila][columna] = 'B'; // Representa un barco
}

void imprimir_tablero(char tablero[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tablero_jugador2[FILAS][COLUMNAS];
    char tablero_jugador1[FILAS][COLUMNAS];
    inicializar_tablero(tablero_jugador1);
    inicializar_tablero(tablero_jugador2);

    int disparos_realizados_jugador1 = 0;
    int disparos_realizados_jugador2 = 0;
    int nbJ1 = 3; // Número de barcos jugador 1
    int nbJ2 = 3; // Número de barcos jugador 2
    int partida_finalizada = 1;

    // Colocar barcos en posiciones conocidas para pruebas
    colocar_barco(tablero_jugador2, 2, 3);
    colocar_barco(tablero_jugador2, 4, 5);
    colocar_barco(tablero_jugador2, 7, 8);

    // Imprimir tablero inicial para jugador 2
    printf("Tablero inicial del Jugador 2:\n");
    imprimir_tablero(tablero_jugador2);

    // Prueba 1: Disparo fallido por parte del jugador 1
    printf("\nPrueba 1: Disparo fallido por parte del jugador 1\n");
    disparoJ1(FILAS, COLUMNAS, (char **)tablero_jugador2, &disparos_realizados_jugador1, &nbJ2, &partida_finalizada);
    printf("Disparos realizados por el Jugador 1: %d\n", disparos_realizados_jugador1);
    printf("Barcos restantes del Jugador 2: %d\n", nbJ2);

    // Prueba 2: Disparo exitoso por parte del jugador 1
    printf("\nPrueba 2: Disparo exitoso por parte del jugador 1\n");
    disparoJ1(FILAS, COLUMNAS, (char **)tablero_jugador2, &disparos_realizados_jugador1, &nbJ2, &partida_finalizada);
    printf("Disparos realizados por el Jugador 1: %d\n", disparos_realizados_jugador1);
    printf("Barcos restantes del Jugador 2: %d\n", nbJ2);

    // Prueba 3: Disparo automático de la IA
    printf("\nPrueba 3: Disparo automático de la IA\n");
    disparoIA(FILAS, COLUMNAS, (char **)tablero_jugador1, &disparos_realizados_jugador2, &nbJ1, &partida_finalizada);
    printf("Disparos realizados por la IA: %d\n", disparos_realizados_jugador2);
    printf("Barcos restantes del Jugador 1: %d\n", nbJ1);

    // Tablero final del Jugador 2
    printf("\nTablero final del Jugador 2:\n");
    imprimir_tablero(tablero_jugador2);

    return 0;
}
