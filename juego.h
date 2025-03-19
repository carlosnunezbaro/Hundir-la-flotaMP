#ifndef JUEGO_H
#define JUEGO_H

#include "barcos.h"
#include "configuracion_inicial.h"

// Inicializa el juego cargando barcos y configurando jugadores
void inicializar_juego();

// Carga los datos de los barcos desde un archivo
void cargar_barcos(const char *nombre_archivo);

// Configura los datos de los jugadores, incluyendo sus tableros
void configurar_jugadores(int jugadores_vs_maquina);

// Inicia la partida colocando los barcos y preparando los tableros
void iniciar_partida();

// Empieza la partida cargando la configuración guardada
void empezar_partida();

// Guarda el estado actual de la partida en un archivo
void guardar_partida(const char *nombre_archivo);

// Carga el estado de una partida desde un archivo
void cargar_partida(const char *nombre_archivo);

// Muestra un resumen del estado actual de la partida
void mostrar_resumen();

#endif // JUEGO_H