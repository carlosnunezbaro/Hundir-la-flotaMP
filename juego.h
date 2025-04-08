#ifndef JUEGO_H
#define JUEGO_H

typedef struct {
    int **tablero;
    int filas;
    int columnas;
    int barcos_hundidos;
    int disparos_realizados;
} EstadoJuego;

// Inicializa el estado del juego con el número de filas y columnas especificado
void inicializar_juego(EstadoJuego *estado_juego, int filas, int columnas);

// Reinicia el juego liberando la memoria del tablero actual y re-inicializando el tablero con las mismas dimensiones
void reiniciar_juego(EstadoJuego *estado_juego);

// Guarda el estado actual del juego en un archivo con el nombre especificado, en formato CSV
void guardar_juego(const EstadoJuego *estado_juego, const char *nombre_archivo);

// Carga el estado del juego desde un archivo con el nombre especificado, en formato CSV
void cargar_juego(EstadoJuego *estado_juego, const char *nombre_archivo);

// Muestra un resumen del juego, incluyendo el número de barcos hundidos y disparos realizados
void mostrar_resumen(const EstadoJuego *estado_juego);

// Ejecuta la lógica del juego, permitiendo al jugador realizar disparos y actualizando el estado del juego en consecuencia
void jugar(EstadoJuego *estado_juego);

// Muestra el menú principal del juego, permitiendo al usuario seleccionar opciones como jugar, reiniciar, mostrar resumen, guardar y cargar el juego, o salir
void mostrar_menu(EstadoJuego *estado_juego);

#endif // JUEGO_H