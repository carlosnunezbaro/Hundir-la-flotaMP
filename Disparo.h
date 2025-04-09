#ifndef Disparo_h_INCLUDED
#define Disparo_h_INCLUDED

void disparoJ1(int filas, int columnas, char **tablero2, char **tabop2, int *turnos, Barcos *barcosJ2, int *nbJ2, int *fin);
void disparoJ2(int filas, int columnas, char **tablero1, char **tabop1, int *turnos, Barcos *barcosJ1, int *nbJ1, int *fin);
void disparoIA(char **tablero1, char **tabop1, int filas, int columnas, int *turnos, Barcos *barcosJ1, int *nbJ1, int *fin);
void inicializador();
void chequeoH(int i, int j, char **tablero, char **tabop, Barcos *barcos, int *nBar) ;

#endif // Disparo_h_INCLUDED

