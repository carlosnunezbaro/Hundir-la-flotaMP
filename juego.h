#ifndef HUNDIR_LA_FLOTA_H
#define HUNDIR_LA_FLOTA_H

// Definición de la estructura para el estado del juego
typedef struct {
    int **tablero;
    int filas;
    int columnas;
    int barcos_hundidos;
    int disparos_realizados;
} EstadoJuego;

// Inicializa el estado del juego con el tamaño del tablero proporcionado
void inicializar_juego(EstadoJuego *estado_juego, int filas, int columnas);

// Reinicia el juego al estado inicial
void reiniciar_juego(EstadoJuego *estado_juego);

// Guarda el estado del juego en un archivo
void guardar_juego(const EstadoJuego *estado_juego, const char *nombre_archivo);

// Carga el estado del juego desde un archivo
void cargar_juego(EstadoJuego *estado_juego, const char *nombre_archivo);

// Muestra un resumen del estado actual del juego
void mostrar_resumen(const EstadoJuego *estado_juego);

// Contiene la lógica principal del juego
void jugar(EstadoJuego *estado_juego);

// Muestra el menú principal del juego
void mostrar_menu(EstadoJuego *estado_juego);

#endif // HUNDIR_LA_FLOTA_H