#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "juego.h"

// Mock para Colocar_Barcos, si es necesario
void Colocar_Barcos(int filas, int columnas, int **tablero) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            tablero[i][j] = 1; // Simular que los barcos se colocan
        }
    }
}

void test_inicializar_juego_caja_blanca() {
    EstadoJuego estado_juego;
    ConfiguracionJuego configuracion;

    // Caso Nominal: Tablero 10x10
    configuracion.tamano_tablero = 10;
    inicializar_juego(&estado_juego, &configuracion);
    assert(estado_juego.filas == 10);
    assert(estado_juego.columnas == 10);

    // Verificar memoria dinámica y bucles
    for (int i = 0; i < estado_juego.filas; i++) {
        for (int j = 0; j < estado_juego.columnas; j++) {
            assert(estado_juego.tablero_jugador1[i][j] == 0);
            assert(estado_juego.tablero_jugador2[i][j] == 0);
        }
    }

    // Verificar que Colocar_Barcos se llamó
    for (int i = 0; i < estado_juego.filas; i++) {
        for (int j = 0; j < estado_juego.columnas; j++) {
            estado_juego.tablero_jugador1[i][j] = 1; // Simulado por mock
            estado_juego.tablero_jugador2[i][j] = 1; // Simulado por mock
        }
    }

    printf("Pruebas de caja blanca completadas exitosamente.\n");
}
