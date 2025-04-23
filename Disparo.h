#ifndef Disparo_h_INCLUDED
#define Disparo_h_INCLUDED
#include "estado_barcos.h"
#include "juego.h"
#include "configuracion_inicial.h"

void disparoJ1(int filas, int columnas, char **tablero_jugador2, int *disparos_realizados_jugador1,int *nbJ2, int *partida_finalizada);
void disparoJ2(int filas, int columnas, char **tablero_jugador1, int *disparos_realizados_jugador2,int *nbJ1, int *partida_finalizada);
void disparoIA(int filas, int columnas, char **tablero_jugador, int *disparos_realizados_jugador,int *nbJ, int *partida_finalizada);
void inicializador();
void chequeoH(int i, int j, char **j_Flota, char **j_Oponente, int *nBar);

#endif // Disparo_h_INCLUDED

