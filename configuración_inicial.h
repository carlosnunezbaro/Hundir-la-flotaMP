#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void configuracion();
void salir();

//Opciones dentro de configuración
void introducir_datos();
void mostrar(Jugador jugador1, Jugador jugador2, int tamaño_tablero);
void borrar(char **j1_Flota, char **j1_Oponente, char **j2_Flota, char **j2_Oponente, int tamaño_tablero,
     Barco *flota, int num_barcos, Jugador *jugador1, Jugador *jugador2);
void guardar(Barco *flota, int num_barcos, int flota_total,
    Jugador jugador1, Jugador jugador2,
    int tamaño_tablero,
    char **j1_Flota, char **j1_Oponente,
    char **j2_Flota, char **j2_Oponente);
void cargar(Barco **flota, int *num_barcos, int *flota_total,
    Jugador *jugador1, Jugador *jugador2,
    int *tamaño_tablero,
    char ***j1_Flota, char ***j1_Oponente,
    char ***j2_Flota, char ***j2_Oponente);
void volver();