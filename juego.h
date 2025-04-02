#ifndef HUNDIR_LA_FLOTA_H
#define HUNDIR_LA_FLOTA_H

typedef struct {
    int **tablero;
    int filas;
    int columnas;
    int barcos_hundidos;
    int disparos_realizados;
} EstadoJuego;

void inicializar_juego(EstadoJuego *estado_juego, int filas, int columnas);
void reiniciar_juego(EstadoJuego *estado_juego);
void guardar_juego(const EstadoJuego *estado_juego, const char *nombre_archivo);
void cargar_juego(EstadoJuego *estado_juego, const char *nombre_archivo);
void mostrar_resumen(const EstadoJuego *estado_juego);
void jugar(EstadoJuego *estado_juego);
void mostrar_menu(EstadoJuego *estado_juego);

#endif // HUNDIR_LA_FLOTA_H
