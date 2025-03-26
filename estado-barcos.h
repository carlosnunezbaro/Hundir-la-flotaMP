#ifndef ESTADO_BARCOS_H
#define ESTADO_BARCOS_H   

// #include "modulo_configuracion.h" cuando lo tengamos


int Intentar_Colocar(int filas, int columnas, int tablero[filas][columnas], Barco *barco);
int Colocar_Barco(int filas, int columnas, int tablero[filas][columnas], Barco *barco); // Verifica si se puede colocar barco o no
void Imprimir_Tablero(int filas, int columnas, int tablero[filas][columnas]); // Imprime el tablero 
int Barcos_Pegados(int filas, int columnas, int tablero[filas][columnas]); // Verifica que no haya ningun barco junto 


#endif 



