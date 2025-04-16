#ifndef ESTADO_BARCOS_H
#define ESTADO_BARCOS_H   

#include "configuracion_inicial.h"


int Imprimir_Tablero(int filas, int columnas, char **tablero);
int Intentar_Colocar(int filas, int columnas, char **tablero, int flota_total, Barco *barco);
int Colocar_Barco(int filas, int columnas, char **tablero, Barco *barco);
int Barcos_Pegados(int filas, int columnas, char **tablero, Barco *barco);
int Colocar_Barcos_BOT(int filas, int columnas, char **tablero, int flota_total, Barco *barcos);

#endif 



