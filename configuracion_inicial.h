
// Archivo: configuracion_inicial.h
// Definición de estructuras y prototipos de funciones para la configuración inicial

#ifndef CONFIGURACION_INICIAL_H
#define CONFIGURACION_INICIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juego.h"

// Definición de estructuras
typedef struct {
    int Id_jugador;
    char Nomb_jugador[20];
    char disparo;   // A (automático) o M (manual)
    int Num_disp;
    int ultimo_ganador; // 0 si ha perdido, 1 si ha ganado
    int empieza;
} Jugador;

typedef struct {
    char Nomb_barco[20];
    int Tam_barco;
    char Id_barco; // 1 caracter
    int impactos;
    int x;
    int y;
    char orientacion[3];
    int cantidad;   // v (vertical), h (horizontal), d (diagonal)
} Barco;

// Prototipos de funciones
int configuracion_inicial(void);
void configurar(Jugador *jugador1, Jugador *jugador2, Barco **flota, int *num_barcos, int *flota_total, 
                  char ***j1_Flota, char ***j1_Oponente, char ***j2_Flota, char ***j2_Oponente, int *tamano_tablero);
void salir(void);
void introducir_datos(Jugador *jugador1, Jugador *jugador2, Barco **flota, int *num_barcos, int *flota_total, 
                     char ***j1_Flota, char ***j1_Oponente, char ***j2_Flota, char ***j2_Oponente, int *tamano_tablero,
                     ConfiguracionJuego *configuracion,EstadoJuego *estado_juego);
void mostrar(Jugador jugador1, Jugador jugador2, int tamano_tablero);
void borrar(char **j1_Flota, char **j1_Oponente, char **j2_Flota, char **j2_Oponente, 
           int tamano_tablero, Barco *flota, int num_barcos, Jugador *jugador1, Jugador *jugador2);
void guardar(Barco *flota, int num_barcos, int flota_total,
           Jugador jugador1, Jugador jugador2,
           int tamano_tablero,
           char **j1_Flota, char **j1_Oponente,
           char **j2_Flota, char **j2_Oponente);
void cargar(Barco **flota, int *num_barcos, int *flota_total,
          Jugador *jugador1, Jugador *jugador2,
          int *tamano_tablero,
          char ***j1_Flota, char ***j1_Oponente,
          char ***j2_Flota, char ***j2_Oponente);
void volver(Jugador *jugador1, Jugador *jugador2, Barco **flota, int *num_barcos, int *flota_total, 
           char ***j1_Flota, char ***j1_Oponente, char ***j2_Flota, char ***j2_Oponente, int *tamano_tablero);
void imprimir_tablero(FILE *f, char **tablero, int tam);

#endif // CONFIGURACION_INICIAL_H
