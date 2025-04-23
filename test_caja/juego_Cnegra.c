#include <assert.h>
#include <stdlib.h>
#include "juego.h"

void test_inicializar_juego_caja_negra() {
    EstadoJuego estado_juego;
    ConfiguracionJuego configuracion;

    // Caso Nominal: Tablero 10x10
    configuracion.tamano_tablero = 10;
    inicializar_juego(&estado_juego, &configuracion);
    assert(estado_juego.filas == 10);
    assert(estado_juego.columnas == 10);
    for (int i = 0; i < estado_juego.filas; i++) {
        for (int j = 0; j < estado_juego.columnas; j++) {
            assert(estado_juego.tablero_jugador1[i][j] == 0);
            assert(estado_juego.tablero_jugador2[i][j] == 0);
        }
    }

    // Caso de Tama�o M�nimo: Tablero 1x1
    configuracion.tamano_tablero = 1;
    inicializar_juego(&estado_juego, &configuracion);
    assert(estado_juego.filas == 1);
    assert(estado_juego.columnas == 1);
    assert(estado_juego.tablero_jugador1[0][0] == 0);
    assert(estado_juego.tablero_jugador2[0][0] == 0);

    // Caso Inv�lido: Tama�o del tablero 0
    configuracion.tamano_tablero = 0;
    inicializar_juego(&estado_juego, &configuracion);
    // Dependiendo de la implementaci�n, verificar comportamiento esperado:
    // Si se lanza un error, manejarlo correctamente.
    // Aqu� asumimos que filas y columnas no se inicializan.
    assert(estado_juego.filas == 0);
    assert(estado_juego.columnas == 0);

    printf("Pruebas de caja negra completadas exitosamente.\n");
}
