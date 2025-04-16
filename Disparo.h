#ifndef Disparo_h_INCLUDED
#define Disparo_h_INCLUDED

void disparoJ1(int filas, int columnas, char **j2_Flota, char **j2_Oponente, int *turnos, Barcos *barcosJ2, int *nbJ2, int *fin);
void disparoJ2(int filas, int columnas, char **j1_Flota, char **j1_Oponente, int *turnos, Barcos *barcosJ1, int *nbJ1, int *fin);
void disparoIA(char **j1_Flota, char **j1_Oponente, int filas, int columnas, int *turnos, Barcos *barcosJ1, int *nbJ1, int *fin);
void inicializador();
void chequeoH(int i, int j, char **j_Flota, char **j_Oponente, Barcos *barcos, int *nBar);

#endif // Disparo_h_INCLUDED

