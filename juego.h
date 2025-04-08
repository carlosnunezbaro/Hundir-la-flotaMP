#ifndef JUEGO_H
#define JUEGO_H

typedef struct {
    int **tablero_jugador1;
    int **tablero_jugador2;
    int filas;
    int columnas;
    int barcos_hundidos_jugador1;
    int barcos_hundidos_jugador2;
    int disparos_realizados_jugador1;
    int disparos_realizados_jugador2;
    int partida_finalizada;
} EstadoJuego;

typedef struct {
    char nombre_jugador1[20];
    char nombre_jugador2[20];
    char disparo_jugador1;
    char disparo_jugador2;
    int tamano_tablero;
} ConfiguracionJuego;

// Inicializa el estado del juego con el número de filas y columnas especificado
void inicializar_juego(EstadoJuego *estado_juego, const ConfiguracionJuego *configuracion);

// Reinicia el juego liberando la memoria del tablero actual y re-inicializando el tablero con las mismas dimensiones
void reiniciar_juego(EstadoJuego *estado_juego, const ConfiguracionJuego *configuracion);

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

// Abre un menú durante la partida al pulsar la barra espaciadora, permitiendo guardar la partida, continuar jugando o salir al menú principal
void menu_pausa(EstadoJuego *estado_juego);

#endif // JUEGO_H