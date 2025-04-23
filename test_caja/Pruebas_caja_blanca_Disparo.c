#include <stdio.h>
#include <stdlib.h>
#include "Disparo.h"

// Función auxiliar para inicializar las matrices de prueba
void inicializarTableros(int filas, int columnas, char **flota, char **oponente) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            flota[i][j] = '-'; // Todas las posiciones están vacías inicialmente
            oponente[i][j] = '-';
        }
    }
}

// Función para verificar resultados manualmente
void verificarResultado(char valorObtenido, char valorEsperado, const char *mensaje) {
    if (valorObtenido == valorEsperado) {
        printf("[PASÓ] %s\n", mensaje);
    } else {
        printf("[FALLÓ] %s - Esperado: '%c', Obtenido: '%c'\n", mensaje, valorEsperado, valorObtenido);
    }
}

// Función principal para ejecutar las pruebas
int main() {
    // Configuración inicial
    int filas = 10, columnas = 10;
    int turnos = 0, fin = 0;
    int barcos_hundidos_jugador2 = 5;

    // Asignar memoria para los tableros
    char **j2_Flota = (char **)malloc(filas * sizeof(char *));
    char **j2_Oponente = (char **)malloc(filas * sizeof(char *));
    for (int i = 0; i < filas; i++) {
        j2_Flota[i] = (char *)malloc(columnas * sizeof(char));
        j2_Oponente[i] = (char *)malloc(columnas * sizeof(char));
    }

    // Inicializar los tableros
    inicializarTableros(filas, columnas, j2_Flota, j2_Oponente);

    // Caso 1: Disparo a una posición vacía (fallo)
    printf("Caso 1: Disparo a una posición vacía (fallo)\n");
    j2_Flota[0][0] = '-'; // Asegurarse de que la posición esté vacía
    disparoJ1(filas, columnas, j2_Flota, j2_Oponente, &turnos, NULL, &barcos_hundidos_jugador2, &fin);
    verificarResultado(j2_Flota[0][0], '*', "La posición en la flota debe marcarse como fallo");
    verificarResultado(j2_Oponente[0][0], '*', "La posición en el tablero del oponente debe marcarse como fallo");

    // Caso 2: Disparo a una posición con un barco (tocado)
    printf("\nCaso 2: Disparo a una posición con un barco (tocado)\n");
    j2_Flota[1][1] = 'B'; // Coloca un barco en la posición (1,1)
    disparoJ1(filas, columnas, j2_Flota, j2_Oponente, &turnos, NULL, &barcos_hundidos_jugador2, &fin);
    verificarResultado(j2_Flota[1][1], 'T', "La posición en la flota debe marcarse como tocado");
    verificarResultado(j2_Oponente[1][1], 'T', "La posición en el tablero del oponente debe marcarse como tocado");

    // Caso 3: Disparo a una posición previamente disparada
    printf("\nCaso 3: Disparo a una posición previamente disparada\n");
    disparoJ1(filas, columnas, j2_Flota, j2_Oponente, &turnos, NULL, &barcos_hundidos_jugador2, &fin);
    verificarResultado(j2_Flota[1][1], 'T', "La posición en la flota no debe cambiar");
    verificarResultado(j2_Oponente[1][1], 'T', "La posición en el tablero del oponente no debe cambiar");

    // Caso 4: Finalización de la partida
    printf("\nCaso 4: Finalización de la partida\n");
    barcos_hundidos_jugador2 = 1; // Solo queda un barco
    j2_Flota[2][2] = 'B'; // Coloca un barco en la posición (2,2)
    disparoJ1(filas, columnas, j2_Flota, j2_Oponente, &turnos, NULL, &barcos_hundidos_jugador2, &fin);
    verificarResultado(fin, 1, "La partida debe terminar cuando todos los barcos han sido hundidos");

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        free(j2_Flota[i]);
        free(j2_Oponente[i]);
    }
    free(j2_Flota);
    free(j2_Oponente);

    printf("\nTodas las pruebas finalizaron.\n");
    return 0;
}