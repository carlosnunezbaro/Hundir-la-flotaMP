#ifndef ESTADO_BARCOS_H
#define ESTADO_BARCOS_H   

// #include "modulo_configuracion.h" cuando lo tengamos


int Imprimr_Tablero_1(int fila, int columnas, char **tablero1); 
int Imprimir_Tablero_2(int filas, int columnas, char **tablero2);
int Intentar_Colocar_1(int filas, int columnas, char **tablero1, Barco *barco);
int Colocar_Barcos_1(int filas, int columnas, char **tablero1, Barco *barco);
int Barcos_Pegados_1(int filas, int columnas, char **tablero1, Barco *barco);
int Intentar_Colocar_Tablero2(int filas, int columnas, char **tablero2, Barco *barco);
int Colocar_Barcos_Tablero_2(int filas, int columnas, char **tablero2, Barco *barco);
int Barcos_Pegados_Tablero_2(int filas, int columnas, char **tablero2, Barco *barco);

#endif 



